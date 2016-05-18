/*
 * fextract.h
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

#ifndef _SNIPPET_FEXTRACT_H
#define _SNIPPET_FEXTRACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this function returns a new null terminated string with the contents
 * found between 'start_pos' and 'end_pos' stream positions
 * returns NULL when it fails to allocate memory
 * returns NULL when range between 'start_pos' and 'end_pos' is <= 0
 * 
 * FIXME: make it return NULL when errno is set by fseek
 * FIXME: make it return NULL when EOF is reached
 */
char *fextract(FILE * const stream, const long start_pos, const long end_pos);

#endif

