//
//	ID Engine
//	ID_US_1.c - User Manager - General routines
//	v1.1d1
//	By Jason Blochowiak
//	Hacked up for Catacomb 3D
//

//
//	This module handles dealing with user input & feedback
//
//	Depends on: Input Mgr, View Mgr, some variables from the Sound, Caching,
//		and Refresh Mgrs, Memory Mgr for background save/restore
//
//	Globals:
//		ingame - Flag set by game indicating if a game is in progress
//      abortgame - Flag set if the current game should be aborted (if a load
//			game fails)
//		loadedgame - Flag set if a game was loaded
//		abortprogram - Normally nil, this points to a terminal error message
//			if the program needs to abort
//		restartgame - Normally set to gd_Continue, this is set to one of the
//			difficulty levels if a new game should be started
//		PrintX, PrintY - Where the User Mgr will print (global coords)
//		WindowX,WindowY,WindowW,WindowH - The dimensions of the current
//			window
//

#include "id_heads.h"

#pragma	hdrstop

#pragma	warn	-pia


//	Global variables
		id0_char_t		*abortprogram;
		id0_boolean_t		NoWait;
		id0_word_t		PrintX,PrintY;
		id0_word_t		WindowX,WindowY,WindowW,WindowH;

//	Internal variables
#define	ConfigVersion	1

// *** S3DNA RESTORATION ***
#ifdef GAMEVER_NOAH3D
static	id0_char_t		*ParmStrings[] = {"LEVELWARP","NOWAIT"},
#else
static	id0_char_t		*ParmStrings[] = {"TEDLEVEL","NOWAIT"},
#endif
					*ParmStrings2[] = {"COMP","NOCOMP"};
static	id0_boolean_t		US_Started;

		id0_boolean_t		Button0,Button1,
					CursorBad;
		id0_int_t			CursorX,CursorY;

		void		(*USL_MeasureString)(id0_char_t id0_far *,id0_word_t *,id0_word_t *) = VW_MeasurePropString,
					(*USL_DrawString)(id0_char_t id0_far *) = VWB_DrawPropString;

		SaveGame	Games[MaxSaveGames];
		HighScore	Scores[MaxScores] =
					{
						// *** PRE-V1.4 APOGEE + S3DNA RESTORATION ***
#ifdef GAMEVER_NOAH3D
						{"Noah",10000,1},
						{"Eve",10000,1},
						{"Moses",10000,1},
						{"Ruth",10000,1},
						{"Adam",10000,1},
						{"Deborah",10000,1},
						{"Abraham",10000,1},
#else
// *** PRE-V1.4 APOGEE + ALPHA RESTORATION ***
#if (GAMEVER_WOLFREV <= GV_WR_WL6AP11)
						{"Id Software - '92",10000,1},
#else
						{"id software-'92",10000,1},
#endif
#if (GAMEVER_WOLFREV <= GV_WR_WL920312)
						{"",10000,1},
						{"John Carmack",10000,1},
						{"",10000,1},
						{"Adrian Carmack",10000,1},
						{"Tom Hall",10000,1},
						{"John Romero",10000,1},
#else
						{"Adrian Carmack",10000,1},
						{"John Carmack",10000,1},
						{"Kevin Cloud",10000,1},
						{"Tom Hall",10000,1},
						{"John Romero",10000,1},
						{"Jay Wilbur",10000,1},
#endif
#endif
					};

//	Internal routines

//	Public routines

///////////////////////////////////////////////////////////////////////////
//
//	USL_HardError() - Handles the Abort/Retry/Fail sort of errors passed
//			from DOS.
//
///////////////////////////////////////////////////////////////////////////
#pragma	warn	-par
#pragma	warn	-rch
id0_int_t
USL_HardError(id0_word_t errval,id0_int_t ax,id0_int_t bp,id0_int_t si)
{
#define IGNORE  0
#define RETRY   1
#define	ABORT   2
extern	void	ShutdownId(void);

static	id0_char_t		buf[32];
static	WindowRec	wr;
		id0_int_t			di;
		id0_char_t		c,*s,*t;


	di = _DI;

	if (ax < 0)
		s = "Device Error";
	else
	{
		if ((di & 0x00ff) == 0)
			s = "Drive ~ is Write Protected";
		else
			s = "Error on Drive ~";
		for (t = buf;*s;s++,t++)	// Can't use sprintf()
			if ((*t = *s) == '~')
				*t = (ax & 0x00ff) + 'A';
		*t = '\0';
		s = buf;
	}

	c = peekb(0x40,0x49);	// Get the current screen mode
	if ((c < 4) || (c == 7))
		goto oh_kill_me;

	// DEBUG - handle screen cleanup

	US_SaveWindow(&wr);
	US_CenterWindow(30,3);
	US_CPrint(s);
	US_CPrint("(R)etry or (A)bort?");
	VW_UpdateScreen();
	IN_ClearKeysDown();

asm	sti	// Let the keyboard interrupts come through

	while (true)
	{
		switch (IN_WaitForASCII())
		{
		case key_Escape:
		case 'a':
		case 'A':
			goto oh_kill_me;
			break;
		case key_Return:
		case key_Space:
		case 'r':
		case 'R':
			US_ClearWindow();
			VW_UpdateScreen();
			US_RestoreWindow(&wr);
			return(RETRY);
			break;
		}
	}

oh_kill_me:
	abortprogram = s;
	ShutdownId();
	fprintf(stderr,"Terminal Error: %s\n",s);
	if (tedlevel)
		// *** S3DNA RESTORATION ***
#ifdef GAMEVER_NOAH3D
		fprintf(stderr,"Warning! Fatal error detected.  Please REBOOT!\n");
#else
		fprintf(stderr,"You launched from TED. I suggest that you reboot...\n");
#endif

	return(ABORT);
#undef	IGNORE
#undef	RETRY
#undef	ABORT
}
#pragma	warn	+par
#pragma	warn	+rch


///////////////////////////////////////////////////////////////////////////
//
//	US_Startup() - Starts the User Mgr
//
///////////////////////////////////////////////////////////////////////////
void
US_Startup(void)
{
	id0_int_t	i,n;

	if (US_Started)
		return;
	// *** S3DNA RESTORATION ***
#ifdef GAMEVER_NOAH3D
	printf("US_Startup: ");
#endif

	harderr(USL_HardError);	// Install the fatal error handler

	US_InitRndT(true);		// Initialize the random number generator

	for (i = 1;i < id0_argc;i++)
	{
		switch (US_CheckParm(id0_argv[i],ParmStrings2))
		{
		case 0:
			compatability = true;
			break;
		case 1:
			compatability = false;
			break;
		}
	}

	// Check for TED launching here
	for (i = 1;i < id0_argc;i++)
	{
		n = US_CheckParm(id0_argv[i],ParmStrings);
		// *** ALPHA RESTORATION ***
		// Use code from US_TextScreen in Catacomb 3-D
		// (the earlier Keen Dreams version is also similar)
#if (GAMEVER_WOLFREV <= GV_WR_WL920312)
		if (n == 0)
		{
			tedlevelnum = atoi(id0_argv[i + 1]);
			if (tedlevelnum >= 0)
			{
				tedlevel = true;
				return;
			}
			else
				break;
		}
		else if (n == 1)
		{
			NoWait = true;
			return;
		}
#else
		switch(n)
		{
		 case 0:
		   tedlevelnum = atoi(id0_argv[i + 1]);
		   // *** PRE-V1.4 APOGEE RESTORATION ***
#if (GAMEVER_WOLFREV > GV_WR_WL6AP11)
		   if (tedlevelnum >= 0)
#endif
		   // *** S3DNA RESTORATION ***
#ifdef GAMEVER_NOAH3D
		   {
		     printf("Warp to level %d\n", tedlevelnum+1);
		     tedlevel = true;
		   }
#else
		     tedlevel = true;
#endif
		   break;

		 case 1:
		   // *** S3DNA RESTORATION ***
#ifdef GAMEVER_NOAH3D
		   printf("NOWAIT enabled\n");
#endif
		   NoWait = true;
		   break;
		}
#endif // GAMEVER_WOLFREV <= GV_WR_WL920312
	}

	// *** S3DNA RESTORATION ***
#ifdef GAMEVER_NOAH3D
	if (!tedlevel && !NoWait)
		printf("Ok\n");
#endif
	US_Started = true;
}


///////////////////////////////////////////////////////////////////////////
//
//	US_Shutdown() - Shuts down the User Mgr
//
///////////////////////////////////////////////////////////////////////////
void
US_Shutdown(void)
{
	if (!US_Started)
		return;

	US_Started = false;
}

///////////////////////////////////////////////////////////////////////////
//
//	US_CheckParm() - checks to see if a string matches one of a set of
//		strings. The check is case insensitive. The routine returns the
//		index of the string that matched, or -1 if no matches were found
//
///////////////////////////////////////////////////////////////////////////
id0_int_t
US_CheckParm(id0_char_t *parm,id0_char_t **strings)
{
	id0_char_t	cp,cs,
			*p,*s;
	id0_int_t		i;

	while (!isalpha(*parm))	// Skip non-alphas
		parm++;

	for (i = 0;*strings && **strings;i++)
	{
		for (s = *strings++,p = parm,cs = cp = 0;cs == cp;)
		{
			cs = *s++;
			if (!cs)
				return(i);
			cp = *p++;

			if (isupper(cs))
				cs = tolower(cs);
			if (isupper(cp))
				cp = tolower(cp);
		}
	}
	return(-1);
}


//	Window/Printing routines

///////////////////////////////////////////////////////////////////////////
//
//	US_SetPrintRoutines() - Sets the routines used to measure and print
//		from within the User Mgr. Primarily provided to allow switching
//		between masked and non-masked fonts
//
///////////////////////////////////////////////////////////////////////////
void
US_SetPrintRoutines(void (*measure)(id0_char_t id0_far *,id0_word_t *,id0_word_t *),void (*print)(id0_char_t id0_far *))
{
	USL_MeasureString = measure;
	USL_DrawString = print;
}

///////////////////////////////////////////////////////////////////////////
//
//	US_Print() - Prints a string in the current window. Newlines are
//		supported.
//
///////////////////////////////////////////////////////////////////////////
void
US_Print(id0_char_t GAMEVER_COND_FARPTR *s)
{
	id0_char_t	c,GAMEVER_COND_FARPTR *se;
	id0_word_t	w,h;

	while (*s)
	{
		se = s;
		while ((c = *se) && (c != '\n'))
			se++;
		*se = '\0';

		USL_MeasureString(s,&w,&h);
		px = PrintX;
		py = PrintY;
		USL_DrawString(s);

		s = se;
		if (c)
		{
			*se = c;
			s++;

			PrintX = WindowX;
			PrintY += h;
		}
		else
			PrintX += w;
	}
}

///////////////////////////////////////////////////////////////////////////
//
//	US_PrintUnsigned() - Prints an unsigned long
//
///////////////////////////////////////////////////////////////////////////
void
US_PrintUnsigned(id0_longword_t n)
{
	id0_char_t	buffer[32];

	US_Print(ultoa(n,buffer,10));
}

///////////////////////////////////////////////////////////////////////////
//
//	US_PrintSigned() - Prints a signed long
//
///////////////////////////////////////////////////////////////////////////
void
US_PrintSigned(id0_long_t n)
{
	id0_char_t	buffer[32];

	US_Print(ltoa(n,buffer,10));
}

///////////////////////////////////////////////////////////////////////////
//
//	USL_PrintInCenter() - Prints a string in the center of the given rect
//
///////////////////////////////////////////////////////////////////////////
void
USL_PrintInCenter(id0_char_t GAMEVER_COND_FARPTR *s,Rect r)
{
	id0_word_t	w,h,
			rw,rh;

	USL_MeasureString(s,&w,&h);
	rw = r.lr.x - r.ul.x;
	rh = r.lr.y - r.ul.y;

	px = r.ul.x + ((rw - w) / 2);
	py = r.ul.y + ((rh - h) / 2);
	USL_DrawString(s);
}

///////////////////////////////////////////////////////////////////////////
//
//	US_PrintCentered() - Prints a string centered in the current window.
//
///////////////////////////////////////////////////////////////////////////
void
US_PrintCentered(id0_char_t GAMEVER_COND_FARPTR *s)
{
	Rect	r;

	r.ul.x = WindowX;
	r.ul.y = WindowY;
	r.lr.x = r.ul.x + WindowW;
	r.lr.y = r.ul.y + WindowH;

	USL_PrintInCenter(s,r);
}

///////////////////////////////////////////////////////////////////////////
//
//	US_CPrintLine() - Prints a string centered on the current line and
//		advances to the next line. Newlines are not supported.
//
///////////////////////////////////////////////////////////////////////////
void
US_CPrintLine(id0_char_t GAMEVER_COND_FARPTR *s)
{
	id0_word_t	w,h;

	USL_MeasureString(s,&w,&h);

	if (w > WindowW)
		Quit("US_CPrintLine() - String exceeds width");
	px = WindowX + ((WindowW - w) / 2);
	py = PrintY;
	USL_DrawString(s);
	PrintY += h;
}

///////////////////////////////////////////////////////////////////////////
//
//	US_CPrint() - Prints a string in the current window. Newlines are
//		supported.
//
///////////////////////////////////////////////////////////////////////////
void
US_CPrint(id0_char_t GAMEVER_COND_FARPTR *s)
{
	id0_char_t	c,GAMEVER_COND_FARPTR *se;

	while (*s)
	{
		se = s;
		while ((c = *se) && (c != '\n'))
			se++;
		*se = '\0';

		US_CPrintLine(s);

		s = se;
		if (c)
		{
			*se = c;
			s++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//
//	US_ClearWindow() - Clears the current window to white and homes the
//		cursor
//
///////////////////////////////////////////////////////////////////////////
void
US_ClearWindow(void)
{
	VWB_Bar(WindowX,WindowY,WindowW,WindowH,WHITE);
	PrintX = WindowX;
	PrintY = WindowY;
}

///////////////////////////////////////////////////////////////////////////
//
//	US_DrawWindow() - Draws a frame and sets the current window parms
//
///////////////////////////////////////////////////////////////////////////
void
US_DrawWindow(id0_word_t x,id0_word_t y,id0_word_t w,id0_word_t h)
{
	id0_word_t	i,
			sx,sy,sw,sh;

	WindowX = x * 8;
	WindowY = y * 8;
	WindowW = w * 8;
	WindowH = h * 8;

	PrintX = WindowX;
	PrintY = WindowY;

	sx = (x - 1) * 8;
	sy = (y - 1) * 8;
	sw = (w + 1) * 8;
	sh = (h + 1) * 8;

	US_ClearWindow();

	VWB_DrawTile8(sx,sy,0),VWB_DrawTile8(sx,sy + sh,5);
	for (i = sx + 8;i <= sx + sw - 8;i += 8)
		VWB_DrawTile8(i,sy,1),VWB_DrawTile8(i,sy + sh,6);
	VWB_DrawTile8(i,sy,2),VWB_DrawTile8(i,sy + sh,7);

	for (i = sy + 8;i <= sy + sh - 8;i += 8)
		VWB_DrawTile8(sx,i,3),VWB_DrawTile8(sx + sw,i,4);
}

///////////////////////////////////////////////////////////////////////////
//
//	US_CenterWindow() - Generates a window of a given width & height in the
//		middle of the screen
//
///////////////////////////////////////////////////////////////////////////
void
US_CenterWindow(id0_word_t w,id0_word_t h)
{
	US_DrawWindow(((MaxX / 8) - w) / 2,((MaxY / 8) - h) / 2,w,h);
}

///////////////////////////////////////////////////////////////////////////
//
//	US_SaveWindow() - Saves the current window parms into a record for
//		later restoration
//
///////////////////////////////////////////////////////////////////////////
void
US_SaveWindow(WindowRec *win)
{
	win->x = WindowX;
	win->y = WindowY;
	win->w = WindowW;
	win->h = WindowH;

	win->px = PrintX;
	win->py = PrintY;
}

///////////////////////////////////////////////////////////////////////////
//
//	US_RestoreWindow() - Sets the current window parms to those held in the
//		record
//
///////////////////////////////////////////////////////////////////////////
void
US_RestoreWindow(WindowRec *win)
{
	WindowX = win->x;
	WindowY = win->y;
	WindowW = win->w;
	WindowH = win->h;

	PrintX = win->px;
	PrintY = win->py;
}

//	Input routines

///////////////////////////////////////////////////////////////////////////
//
//	USL_XORICursor() - XORs the I-bar text cursor. Used by US_LineInput()
//
///////////////////////////////////////////////////////////////////////////
static void
USL_XORICursor(id0_int_t x,id0_int_t y,id0_char_t *s,id0_word_t cursor)
{
	static	id0_boolean_t	status;		// VGA doesn't XOR...
	id0_char_t	buf[MaxString];
	id0_int_t		temp;
	id0_word_t	w,h;

	strcpy(buf,s);
	buf[cursor] = '\0';
	USL_MeasureString(buf,&w,&h);

	px = x + w - 1;
	py = y;
	if (status^=1)
		USL_DrawString("\x80");
	else
	{
		temp = fontcolor;
		fontcolor = backcolor;
		USL_DrawString("\x80");
		fontcolor = temp;
	}

}

///////////////////////////////////////////////////////////////////////////
//
//	US_LineInput() - Gets a line of user input at (x,y), the string defaults
//		to whatever is pointed at by def. Input is restricted to maxchars
//		chars or maxwidth pixels wide. If the user hits escape (and escok is
//		true), nothing is copied into buf, and false is returned. If the
//		user hits return, the current string is copied into buf, and true is
//		returned
//
///////////////////////////////////////////////////////////////////////////
id0_boolean_t
US_LineInput(id0_int_t x,id0_int_t y,id0_char_t *buf,id0_char_t *def,id0_boolean_t escok,
				id0_int_t maxchars,id0_int_t maxwidth)
{
	id0_boolean_t		redraw,
				cursorvis,cursormoved,
				done,result;
	ScanCode	sc;
	id0_char_t		c,
				s[MaxString],olds[MaxString];
	id0_word_t		i,
				cursor,
				w,h,
				len,temp;
	id0_longword_t	lasttime;

	if (def)
		strcpy(s,def);
	else
		*s = '\0';
	*olds = '\0';
	cursor = strlen(s);
	cursormoved = redraw = true;

	cursorvis = done = false;
	lasttime = TimeCount;
	LastASCII = key_None;
	LastScan = sc_None;

	while (!done)
	{
		if (cursorvis)
			USL_XORICursor(x,y,s,cursor);

	asm	pushf
	asm	cli

		sc = LastScan;
		LastScan = sc_None;
		c = LastASCII;
		LastASCII = key_None;

	asm	popf

		switch (sc)
		{
		case sc_LeftArrow:
			if (cursor)
				cursor--;
			c = key_None;
			cursormoved = true;
			break;
		case sc_RightArrow:
			if (s[cursor])
				cursor++;
			c = key_None;
			cursormoved = true;
			break;
		case sc_Home:
			cursor = 0;
			c = key_None;
			cursormoved = true;
			break;
		case sc_End:
			cursor = strlen(s);
			c = key_None;
			cursormoved = true;
			break;

		case sc_Return:
			strcpy(buf,s);
			done = true;
			result = true;
			c = key_None;
			break;
		case sc_Escape:
			if (escok)
			{
				done = true;
				result = false;
			}
			c = key_None;
			break;

		case sc_BackSpace:
			if (cursor)
			{
				strcpy(s + cursor - 1,s + cursor);
				cursor--;
				redraw = true;
			}
			c = key_None;
			cursormoved = true;
			break;
		case sc_Delete:
			if (s[cursor])
			{
				strcpy(s + cursor,s + cursor + 1);
				redraw = true;
			}
			c = key_None;
			cursormoved = true;
			break;

		case 0x4c:	// Keypad 5
		case sc_UpArrow:
		case sc_DownArrow:
		case sc_PgUp:
		case sc_PgDn:
		case sc_Insert:
			c = key_None;
			break;
		}

		if (c)
		{
			len = strlen(s);
			USL_MeasureString(s,&w,&h);

			if
			(
				isprint(c)
			&&	(len < MaxString - 1)
			&&	((!maxchars) || (len < maxchars))
			&&	((!maxwidth) || (w < maxwidth))
			)
			{
				for (i = len + 1;i > cursor;i--)
					s[i] = s[i - 1];
				s[cursor++] = c;
				redraw = true;
			}
		}

		if (redraw)
		{
			px = x;
			py = y;
			temp = fontcolor;
			fontcolor = backcolor;
			USL_DrawString(olds);
			fontcolor = temp;
			strcpy(olds,s);

			px = x;
			py = y;
			USL_DrawString(s);

			redraw = false;
		}

		if (cursormoved)
		{
			cursorvis = false;
			lasttime = TimeCount - TickBase;

			cursormoved = false;
		}
		if (TimeCount - lasttime > TickBase / 2)
		{
			lasttime = TimeCount;

			cursorvis ^= true;
		}
		if (cursorvis)
			USL_XORICursor(x,y,s,cursor);

		VW_UpdateScreen();
	}

	if (cursorvis)
		USL_XORICursor(x,y,s,cursor);
	if (!result)
	{
		px = x;
		py = y;
		USL_DrawString(olds);
	}
	VW_UpdateScreen();

	IN_ClearKeysDown();
	return(result);
}
