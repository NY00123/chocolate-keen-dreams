/* Copyright (C) 2014-2021 NY00123
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BE_ST_SDL_H
#define BE_ST_SDL_H

#include "be_st.h"

// WARNING: This struct is used by BE_ST_SDL ONLY (except for controller stuff)

#ifdef REFKEEN_HAS_VER_KDREAMS
#define BE_ST_SDL_ENABLE_ABSMOUSEMOTION_SETTING
#endif

typedef enum { VSYNC_AUTO, VSYNC_OFF, VSYNC_ON } VSyncSettingType;
typedef enum { SCALE_ASPECT, SCALE_FILL } ScaleTypeSettingType;
typedef enum { TOUCHINPUT_AUTO, TOUCHINPUT_OFF, TOUCHINPUT_FORCED } TouchInputSettingType;
typedef enum { MOUSEGRAB_AUTO, MOUSEGRAB_OFF, MOUSEGRAB_COMMONLY } MouseGrabSettingType;

#ifdef REFKEEN_ENABLE_LAUNCHER
#define LAUNCHER_EXE_ARGS_BUFFERLEN 80
typedef enum { LAUNCHER_WINDOW_DEFAULT, LAUNCHER_WINDOW_FULL, LAUNCHER_WINDOW_SOFTWARE } LauncherWindowSettingType;
#endif

#define SELECTED_EXE_FILENAME_BUFFERLEN 13

typedef struct
{
	bool isFullscreen;
	int fullWidth, fullHeight;
	int winWidth, winHeight;
#ifdef REFKEEN_ENABLE_LAUNCHER
	// Now using just winWidth and winHeight due to seamless launcher->game transitions
	//int launcherWinWidth, launcherWinHeight;
	LauncherWindowSettingType launcherWinType;
	char launcherExeArgs[LAUNCHER_EXE_ARGS_BUFFERLEN];
#endif
	char lastSelectedGameExe[SELECTED_EXE_FILENAME_BUFFERLEN];
	int lastSelectedGameVer;
	int displayNum;
	bool rememberDisplayNum;
	int sdlRendererDriver;
	VSyncSettingType vSync;
	bool isBilinear;
	ScaleTypeSettingType scaleType;
	int scaleFactor;
	bool forceFullSoftScaling;
	MouseGrabSettingType mouseGrab;
#ifdef BE_ST_SDL_ENABLE_ABSMOUSEMOTION_SETTING
	bool absMouseMotion;
#endif
	int sndInterThreadBufferRatio;
	int sndSampleRate;
	bool sndSubSystem;
	bool oplEmulation;
#ifndef REFKEEN_RESAMPLER_NONE
	bool useResampler;
#endif
	TouchInputSettingType touchInputToggle;
	bool touchInputDebugging;
	struct
	{
		int actionMappings[BE_ST_CTRL_CFG_BUTMAP_AFTERLAST]; // Buttons/triggers
		bool useLeftStick;
		bool useRightStick;
		bool analogMotion;
		bool isEnabled;
	} altControlScheme;
	bool manualGameVerMode;
	unsigned int farPtrSegOffset; // Actually used just in The Catacomb Armageddon/Apocalypse
} RefKeenConfig;

extern RefKeenConfig g_refKeenCfg;

#endif // BE_ST_SDL_H
