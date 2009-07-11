
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
     DOUBLEDOT = 261,
     IF = 262,
     ELSE = 263,
     WHILE = 264,
     FOR = 265,
     FUNCTION = 266,
     RETURN = 267,
     BREAK = 268,
     CONTINUE = 269,
     LOCAL = 270,
     GLOBAL = 271,
     TRUE = 272,
     FALSE = 273,
     NIL = 274,
     ASSIGN = 275,
     ADD = 276,
     MIN = 277,
     MUL = 278,
     DIV = 279,
     MOD = 280,
     EQ = 281,
     NOTEQ = 282,
     INCR = 283,
     DECR = 284,
     GT = 285,
     LT = 286,
     GE = 287,
     LE = 288,
     AND = 289,
     OR = 290,
     NOT = 291,
     DOT_LT = 292,
     GT_DOT = 293,
     DOT_TILDE = 294,
     DOT_EXCl_MARK = 295,
     DOT_NUM_SIGN = 296,
     DOT_AT = 297,
     UMINUS = 298
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define STRING 260
#define DOUBLEDOT 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define FUNCTION 266
#define RETURN 267
#define BREAK 268
#define CONTINUE 269
#define LOCAL 270
#define GLOBAL 271
#define TRUE 272
#define FALSE 273
#define NIL 274
#define ASSIGN 275
#define ADD 276
#define MIN 277
#define MUL 278
#define DIV 279
#define MOD 280
#define EQ 281
#define NOTEQ 282
#define INCR 283
#define DECR 284
#define GT 285
#define LT 286
#define GE 287
#define LE 288
#define AND 289
#define OR 290
#define NOT 291
#define DOT_LT 292
#define GT_DOT 293
#define DOT_TILDE 294
#define DOT_EXCl_MARK 295
#define DOT_NUM_SIGN 296
#define DOT_AT 297
#define UMINUS 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    char *			stringV;
    double			realV;
    SIN::ASTNode *	AST;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


