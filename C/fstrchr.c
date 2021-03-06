/*
 * fstrchr.h
 * This file is part of snippets_collection
 *
 * Copyright (C) 2016 - Darcy Brás da Silva
 *
 * getch is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * getch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with getch. If not, see <http://www.gnu.org/licenses/>.
 */

#include "fstrchr.h"

long fstrchr(FILE * const stream, const long pos, const int c)
{
	fseek(stream, pos, SEEK_SET);
	int ch = 0;
	while(EOF != (ch = fgetc(stream))) {
		if( c == ch ) {
			ungetc(ch, stream);
			return ftell(stream);
		}
	}

	return NOT_FOUND;
}
