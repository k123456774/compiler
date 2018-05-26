/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEMICOLON = 258,
     integer = 259,
     float_ = 260,
     string = 261,
     id_name = 262,
     FUNC = 263,
     MUT = 264,
     STRUCT = 265,
     LET = 266,
     INTEGER = 267,
     BOOL = 268,
     STRING = 269,
     CHAR = 270,
     FLOAT = 271,
     ENUM = 272,
     EXTERN = 273,
     MATCH = 274,
     RETURN = 275,
     Plus_on = 276,
     Minus_on = 277,
     Multi_on = 278,
     Divide_on = 279,
     IF = 280,
     ELSE = 281,
     BREAK = 282,
     CONTINUE = 283,
     IN = 284,
     TRUE = 285,
     FALSE = 286,
     FOR = 287,
     WHILE = 288,
     DO = 289,
     LOOP = 290,
     PRINT = 291,
     PRINTLN = 292,
     PUB = 293,
     SELF = 294,
     STATIC = 295,
     USE = 296,
     WHERE = 297,
     SE = 298,
     GE = 299,
     NE = 300,
     E = 301,
     UMINUS = 302
   };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define integer 259
#define float_ 260
#define string 261
#define id_name 262
#define FUNC 263
#define MUT 264
#define STRUCT 265
#define LET 266
#define INTEGER 267
#define BOOL 268
#define STRING 269
#define CHAR 270
#define FLOAT 271
#define ENUM 272
#define EXTERN 273
#define MATCH 274
#define RETURN 275
#define Plus_on 276
#define Minus_on 277
#define Multi_on 278
#define Divide_on 279
#define IF 280
#define ELSE 281
#define BREAK 282
#define CONTINUE 283
#define IN 284
#define TRUE 285
#define FALSE 286
#define FOR 287
#define WHILE 288
#define DO 289
#define LOOP 290
#define PRINT 291
#define PRINTLN 292
#define PUB 293
#define SELF 294
#define STATIC 295
#define USE 296
#define WHERE 297
#define SE 298
#define GE 299
#define NE 300
#define E 301
#define UMINUS 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "test.y"
{
        int type;          // 0=void 1=int 2=float 3=string, for non-terminal(type)

        struct{            //for const value or non-terminal
            float fval;
            int ival;
            char sval[256];
            int type;
            } value;
        
        struct {           //for id
             char name[30];
             int  type;
             float fval;
             int   ival;
                } id_value;
        }
/* Line 1529 of yacc.c.  */
#line 161 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

