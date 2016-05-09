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

#ifndef _SNIPPET_FSTRCHR_H
#define _SNIPPET_FSTRCHR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * this functions finds c in stream starting from pos
 * returns the result of ftell-1 once it's found
 * so that c can be read via fgetc
 *
 * if c is not found returns -1
 *
 * notice that the steam will not be rewinded
 * FIXME: 
 * add return error for EOF cases
 */
long fstrchr(FILE **stream, const long pos, const int c);

#endif
