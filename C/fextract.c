/*
 * fextract.c
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

#include "fextract.h"


char *fextract(FILE * const stream, const long start_pos, const long end_pos)
{
	//FIXME check errno on fseek call and handle it
	fseek(stream, start_pos, SEEK_SET);
	long buf_len = end_pos - start_pos;

	if(0 >= buf_len) {
		fprintf(stderr,"invalid extraction range\n");
		return NULL;
	}

	char *buf = NULL;
	// +1 for the null terminator
	if(NULL == (buf = malloc(buf_len+1))) {
		fprintf(stderr,"couldn't allocate memory for buffer\n");
		return NULL;
	}

	char *iter;

	//set the terminator ahead of time
	buf[buf_len] = '\0';

	for(iter=buf; buf_len--; ++iter) {
		*iter=fgetc(stream);
	}

	return buf;
}
