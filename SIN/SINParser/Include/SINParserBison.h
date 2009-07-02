
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
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     FOR = 261,
     FUNCTION = 262,
     RETURN = 263,
     BREAK = 264,
     CONTINUE = 265,
     LOCAL = 266,
     GLOBAL = 267,
     TRUE = 268,
     FALSE = 269,
     NIL = 270,
     ASSIGN = 271,
     ADD = 272,
     MIN = 273,
     MUL = 274,
     DIV = 275,
     MOD = 276,
     EQ = 277,
     NOTEQ = 278,
     INCR = 279,
     DECR = 280,
     GT = 281,
     LT = 282,
     GE = 283,
     LE = 284,
     AND = 285,
     OR = 286,
     NOT = 287,
     DOT_LT = 288,
     DOT_GT = 289,
     DOT_TILDE = 290,
     DOT_EXCl_MARK = 291,
     DOT_NUM_SIGN = 292,
     DOT_AT = 293,
     DOUBLEDOT = 294,
     NUMBER = 295,
     ID = 296,
     STRING = 297,
     UMINUS = 298
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define FUNCTION 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define LOCAL 266
#define GLOBAL 267
#define TRUE 268
#define FALSE 269
#define NIL 270
#define ASSIGN 271
#define ADD 272
#define MIN 273
#define MUL 274
#define DIV 275
#define MOD 276
#define EQ 277
#define NOTEQ 278
#define INCR 279
#define DECR 280
#define GT 281
#define LT 282
#define GE 283
#define LE 284
#define AND 285
#define OR 286
#define NOT 287
#define DOT_LT 288
#define DOT_GT 289
#define DOT_TILDE 290
#define DOT_EXCl_MARK 291
#define DOT_NUM_SIGN 292
#define DOT_AT 293
#define DOUBLEDOT 294
#define NUMBER 295
#define ID 296
#define STRING 297
#define UMINUS 298




//#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    char *		stringValue;
    double		realValue;
//    SIN::ASTNode *	AST;



} YYSTYPE;
//# define YYSTYPE_IS_TRIVIAL 1
//# define yystype YYSTYPE /* obsolescent; will be withdrawn */
//# define YYSTYPE_IS_DECLARED 1
//#endif

extern YYSTYPE yylval;


