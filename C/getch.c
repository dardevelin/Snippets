/*
 * getch.c
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

#include "getch.h"

/* windows like getch function */
int getch()
{
	int ch;
	struct termios oldt, newt;
	
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

	return ch;
}

