/*
 * mkdir.h
 * This file is part of snippet_collections
 *
 * Copyright (C) 2012 - Darcy Brás da Silva
 *
 * MACRO_MKDIR is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MACRO_MKDIR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MACRO_MKDIR. If not, see <http://www.gnu.org/licenses/>.
 */

#if (defined _WIN32 || _WIN64 )
#include <conio.h>
#include <process.h>
#include <dir.h>
#define MKDIR(x) mkdir(x)

#else

#include <sys/types.h>
#include <sys/stat.h>
#define PERMISSION_FLAG 0777
#define MKDIR(x) mkdir(x,PERMISSION_FLAG)

#endif

