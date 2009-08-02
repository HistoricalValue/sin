
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     NUMBER = 258,
     ID = 259,
     STRING = 260,
     DOT = 261,
     DOUBLEDOT = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     FUNCTION = 267,
     RETURN = 268,
     BREAK = 269,
     CONTINUE = 270,
     LOCAL = 271,
     GLOBAL = 272,
     TRUE = 273,
     FALSE = 274,
     NIL = 275,
     ASSIGN = 276,
     ADD = 277,
     MIN = 278,
     MUL = 279,
     DIV = 280,
     MOD = 281,
     EQ = 282,
     NOTEQ = 283,
     INCR = 284,
     DECR = 285,
     GT = 286,
     LT = 287,
     GE = 288,
     LE = 289,
     AND = 290,
     OR = 291,
     NOT = 292,
     KEYS_MEMBER = 293,
     SIZE_MEMBER = 294,
     UMINUS = 295
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define STRING 260
#define DOT 261
#define DOUBLEDOT 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define FOR 266
#define FUNCTION 267
#define RETURN 268
#define BREAK 269
#define CONTINUE 270
#define LOCAL 271
#define GLOBAL 272
#define TRUE 273
#define FALSE 274
#define NIL 275
#define ASSIGN 276
#define ADD 277
#define MIN 278
#define MUL 279
#define DIV 280
#define MOD 281
#define EQ 282
#define NOTEQ 283
#define INCR 284
#define DECR 285
#define GT 286
#define LT 287
#define GE 288
#define LE 289
#define AND 290
#define OR 291
#define NOT 292
#define KEYS_MEMBER 293
#define SIZE_MEMBER 294
#define UMINUS 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    char *	stringV;
    double			realV;
    SIN::ASTNode *	AST;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


