/*
 * getch.h
 * This file is part of snippets_collection
 *
 * Copyright (C) 2012 - Darcy Brás da Silva
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

#ifndef _SNIPPET_GETCH_H
#define _SNIPPET_GETCH_H

#if (defined _WIN32 || _WIN64 )
#include <stdio.h>
#include <conio.h>

#else

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

int getch(void);

#endif
