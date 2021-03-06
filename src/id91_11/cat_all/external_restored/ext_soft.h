/* Keen Dreams Source Code
 * Copyright (C) 2014 Javier M. Chavez
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

REFKEEN_NS_B

//memptr InitBufferedIO(int handle, BufferedIO *bio);
//void FreeBufferedIO(BufferedIO *bio);
//byte bio_readch(BufferedIO *bio);

struct Shape;

id0_unsigned_long_t ext_BLoad(const id0_char_t *SourceFile, memptr *DstPtr);
memptr LoadLIBFile(const id0_char_t *LibName,const id0_char_t *FileName,memptr *MemPtr);
id0_int_t LoadLIBShape(const id0_char_t *SLIB_Filename, const id0_char_t *Filename,struct Shape *SHP);

REFKEEN_NS_E
