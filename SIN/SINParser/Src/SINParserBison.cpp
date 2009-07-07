
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


	#include <stdio.h>
	#include <assert.h>
	#include <iostream>
	#include <string.h>
	
	
	// Bison assumes alloca is the memory allocation
	// function.
	//
	#ifndef	alloca
	#define alloca malloc
	#endif



	#include "SINASTNode.h"
	#include "SINParserManageSinCode.h"
	#include "SINParserManageStatements.h"
	#include "SINParserManageStatement.h"
	#include "SINParserManageExpression.h"
	#include "SINParserManageTerm.h"
	#include "SINParserManageAssignExpression.h"
	#include "SINParserManagePrimary.h"
	#include "SINParserManageLValue.h"
	#include "SINParserManageMember.h"
	#include "SINParserManageCall.h"
	#include "SINParserManageCallSuffix.h"
	#include "SINParserManageNormalCall.h"
	#include "SINParserManageMethodCall.h"
	#include "SINParserManageExpressionList.h"
	#include "SINParserManageObjectDefinition.h"
	#include "SINParserManageObjectList.h"
	#include "SINParserManageBlock.h"
	#include "SINParserManageFunctionDefinition.h"
	#include "SINParserManageConstant.h"
	#include "SINParserManageIDList.h"
	#include "SINParserManageIfStatement.h"
	#include "SINParserManageWhileStatement.h"
	#include "SINParserManageForStatement.h"
	#include "SINParserManageReturnStatement.h"


	int yyerror (char* yaccProvidedMessage);
	int PrepareForFile(const char * filePath);
	int PrepareForString(const char * str);

	int yylex (void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
     GT_DOT = 289,
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
#define GT_DOT 289
#define DOT_TILDE 290
#define DOT_EXCl_MARK 291
#define DOT_NUM_SIGN 292
#define DOT_AT 293
#define DOUBLEDOT 294
#define NUMBER 295
#define ID 296
#define STRING 297
#define UMINUS 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    char *		stringV;
    double		realV;
    SIN::ASTNode *	AST;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   792

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,     2,     2,    48,     2,    47,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    23,    26,    28,    30,    32,    34,    36,    40,    44,
      48,    52,    56,    60,    64,    68,    72,    76,    80,    84,
      88,    92,    94,    96,   100,   103,   106,   109,   112,   116,
     119,   122,   125,   128,   131,   134,   136,   140,   142,   144,
     146,   150,   152,   154,   157,   160,   162,   166,   171,   175,
     180,   183,   186,   193,   195,   197,   201,   207,   210,   211,
     215,   216,   219,   223,   226,   231,   235,   241,   242,   243,
     248,   251,   252,   259,   265,   267,   269,   271,   273,   275,
     278,   279,   283,   284,   290,   298,   304,   314,   317
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    57,    56,    -1,    -1,    58,
      45,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
       9,    45,    -1,    10,    45,    -1,    74,    -1,    77,    -1,
      45,    -1,     1,    -1,    61,    -1,    58,    17,    58,    -1,
      58,    18,    58,    -1,    58,    19,    58,    -1,    58,    20,
      58,    -1,    58,    21,    58,    -1,    58,    26,    58,    -1,
      58,    28,    58,    -1,    58,    27,    58,    -1,    58,    29,
      58,    -1,    58,    22,    58,    -1,    58,    23,    58,    -1,
      58,    30,    58,    -1,    58,    31,    58,    -1,    58,    32,
      58,    -1,    59,    -1,    60,    -1,    33,    58,    34,    -1,
      35,    51,    -1,    36,    59,    -1,    37,    52,    -1,    38,
      59,    -1,    43,    58,    44,    -1,    18,    58,    -1,    32,
      58,    -1,    24,    63,    -1,    63,    24,    -1,    25,    63,
      -1,    63,    25,    -1,    62,    -1,    63,    16,    58,    -1,
      63,    -1,    65,    -1,    71,    -1,    43,    77,    44,    -1,
      78,    -1,    51,    -1,    11,    51,    -1,    12,    51,    -1,
      64,    -1,    63,    47,    51,    -1,    63,    39,    58,    40,
      -1,    65,    47,    51,    -1,    65,    39,    58,    40,    -1,
      65,    66,    -1,    63,    66,    -1,    43,    77,    44,    43,
      69,    44,    -1,    67,    -1,    68,    -1,    43,    69,    44,
      -1,    49,    51,    43,    69,    44,    -1,    58,    70,    -1,
      -1,    48,    58,    70,    -1,    -1,    39,    40,    -1,    39,
      72,    40,    -1,    58,    73,    -1,    58,    46,    58,    73,
      -1,    48,    58,    73,    -1,    48,    58,    46,    58,    73,
      -1,    -1,    -1,    41,    75,    76,    42,    -1,    57,    76,
      -1,    -1,     7,    51,    43,    79,    44,    74,    -1,     7,
      43,    79,    44,    74,    -1,    50,    -1,    52,    -1,    15,
      -1,    13,    -1,    14,    -1,    51,    80,    -1,    -1,    48,
      51,    80,    -1,    -1,     3,    43,    58,    44,    57,    -1,
       3,    43,    58,    44,    57,     4,    57,    -1,     5,    43,
      58,    44,    57,    -1,     6,    43,    69,    45,    58,    45,
      69,    44,    57,    -1,     8,    45,    -1,     8,    58,    45,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   114,   115,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   156,   157,   158,   159,   160,   165,   166,
     167,   168,   169,   170,   171,   172,   177,   182,   183,   184,
     185,   186,   191,   192,   193,   194,   199,   200,   201,   202,
     208,   209,   210,   215,   216,   221,   226,   231,   232,   237,
     238,   243,   244,   249,   250,   255,   256,   257,   262,   262,
     267,   268,   273,   274,   278,   279,   280,   281,   282,   286,
     287,   292,   293,   298,   299,   302,   305,   308,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "BREAK", "CONTINUE", "LOCAL", "GLOBAL", "TRUE", "FALSE", "NIL",
  "ASSIGN", "ADD", "MIN", "MUL", "DIV", "MOD", "EQ", "NOTEQ", "INCR",
  "DECR", "GT", "LT", "GE", "LE", "AND", "OR", "NOT", "DOT_LT", "GT_DOT",
  "DOT_TILDE", "DOT_EXCl_MARK", "DOT_NUM_SIGN", "DOT_AT", "'['", "']'",
  "'{'", "'}'", "'('", "')'", "';'", "':'", "'.'", "','", "DOUBLEDOT",
  "NUMBER", "ID", "STRING", "UMINUS", "$accept", "SinCode", "stmts",
  "stmt", "expr", "metaexpr", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normalcall", "methodcall", "elist",
  "elists", "objectdef", "objectlist", "objectlists", "block", "$@1",
  "stmtd", "funcdef", "const", "idlist", "idlists", "ifstmt", "whilestmt",
  "forstmt", "returnstmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    91,
      93,   123,   125,    40,    41,    59,    58,    46,    44,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    75,    74,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    83,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     2,     2,     2,     2,     3,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     1,     1,
       3,     1,     1,     2,     2,     1,     3,     4,     3,     4,
       2,     2,     6,     1,     1,     3,     5,     2,     0,     3,
       0,     2,     3,     2,     4,     3,     5,     0,     0,     4,
       2,     0,     6,     5,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     5,     7,     5,     9,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,    14,    84,    52,    85,
       0,     2,     0,     0,    31,    32,    16,    45,    47,    55,
      48,    49,    12,    13,    51,     6,     7,     8,     9,     0,
       0,    68,    90,     0,    97,     0,    10,    11,    53,    54,
      39,     0,    41,     0,    43,    40,     0,    34,    35,    36,
      37,    71,    77,     0,     0,     0,     0,     1,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,    42,    44,     0,    68,     0,
       0,    61,    63,    64,     0,     0,    60,     0,     0,    70,
       0,    92,     0,    90,    98,     0,    33,     0,     0,    73,
      72,     0,     0,    38,    50,    17,    18,    19,    20,    21,
      26,    27,    22,    24,    23,    25,    28,    29,    30,    46,
       0,     0,    56,     0,     0,    58,     0,     0,     0,    67,
       0,     0,    89,     0,     0,     0,    77,    77,    80,    79,
      68,    57,    65,    68,    59,    93,    95,    70,     0,    92,
      83,     0,    74,     0,    75,     0,     0,     0,    69,    68,
      91,    82,    77,    62,    66,    94,     0,    76,     0,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,   101,   102,   103,   110,   149,    41,    73,   119,
      42,    74,   122,    43,    44,   112,   152,    45,    46,    47,
      48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -152
static const yytype_int16 yypact[] =
{
     169,  -152,   -39,   -33,   -27,   -36,   315,   -25,   -10,   -13,
      -5,  -152,  -152,  -152,   399,    -9,    -9,   399,   399,     5,
      94,   -11,    94,   357,  -152,    15,  -152,  -152,  -152,  -152,
      49,  -152,   169,   545,  -152,  -152,  -152,  -152,    79,  -152,
      58,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   399,
     399,   399,    11,    20,  -152,   565,  -152,  -152,  -152,  -152,
      32,    62,    70,    58,    70,    32,   694,  -152,  -152,  -152,
    -152,  -152,   435,    30,   221,   605,    27,  -152,  -152,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,  -152,   399,  -152,  -152,   399,   399,    38,
      45,  -152,  -152,  -152,   399,    48,  -152,   624,   643,   499,
      55,    54,    64,    11,  -152,    66,  -152,   399,   399,  -152,
    -152,   221,    72,  -152,    73,    40,    40,    32,    32,    32,
     744,   744,   119,   119,   119,   119,   760,   728,    32,   712,
     662,    71,  -152,    77,   678,  -152,   273,   273,   399,  -152,
     399,    74,  -152,    80,    89,    73,   522,   467,  -152,  -152,
     399,  -152,  -152,   399,  -152,   130,  -152,   499,   585,    54,
    -152,    80,  -152,   399,  -152,    97,    99,   273,  -152,   399,
    -152,  -152,   522,  -152,  -152,  -152,   105,  -152,   273,  -152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,    91,   -53,    -6,    35,  -152,  -152,  -152,    -2,
    -152,     8,   -31,  -152,  -152,   -73,   -17,  -152,  -152,  -151,
    -135,  -152,    31,   -24,  -152,    42,   -16,  -152,  -152,  -152,
    -152
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
      55,    76,     9,    10,    49,   172,   174,    52,    60,   106,
      50,    65,    66,    62,    64,    53,    51,    72,   170,    75,
      56,   121,     5,    63,    63,   141,     9,    10,    11,    12,
      13,   187,   106,    14,    61,    57,   181,   115,    58,    15,
      16,    69,    28,   107,   108,   109,    59,    17,    18,    77,
      19,    20,    21,    22,    23,    68,    67,    70,    25,    81,
      82,    83,   111,   113,    92,    27,    28,    29,   121,     5,
     120,   124,    92,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   175,   139,   142,
     176,   140,   109,   165,   166,    94,   143,   104,   144,   145,
     150,    98,   151,    95,    96,   105,   186,   100,   153,    97,
     155,   156,   157,    98,   159,   162,   160,    99,    97,   100,
     163,    24,    98,    78,   185,   169,    99,    18,   100,    19,
      20,    21,    22,   171,   177,   189,    79,    80,    81,    82,
      83,   183,   167,   184,   168,   -82,   -82,   -82,   -82,   188,
     178,    92,   158,   180,   109,   154,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,     0,    -4,
       1,     0,     2,   109,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,    14,     0,     0,
       0,     0,     0,    15,    16,     0,     0,     0,     0,     0,
       0,    17,    18,     0,    19,    20,    21,    22,    23,     0,
      24,     0,    25,     0,    26,     0,     0,     0,     0,    27,
      28,    29,     1,     0,     2,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,    14,
       0,     0,     0,     0,     0,    15,    16,     0,     0,     0,
       0,     0,     0,    17,    18,     0,    19,    20,    21,    22,
      23,     0,    24,   -81,    25,     0,    26,     0,     0,     0,
       0,    27,    28,    29,     1,     0,     2,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,    14,     0,     0,     0,     0,     0,    15,    16,     0,
       0,     0,     0,     0,     0,    17,    18,     0,    19,    20,
      21,    22,    23,     0,    24,     0,    25,     0,    26,     0,
       0,     0,     0,    27,    28,    29,     9,    10,    11,    12,
      13,     0,     0,    14,     0,     0,     0,     0,     0,    15,
      16,     0,     0,     0,     0,     0,     0,    17,    18,     0,
      19,    20,    21,    22,    23,     0,     0,     0,    25,     0,
      54,     0,     0,     0,     0,    27,    28,    29,     9,    10,
      11,    12,    13,     0,     0,    14,     0,     0,     0,     0,
       0,    15,    16,     0,     0,     0,     0,     0,     0,    17,
      18,     0,    19,    20,    21,    22,    23,    71,     0,     0,
      25,     0,     0,     0,     0,     0,     0,    27,    28,    29,
       9,    10,    11,    12,    13,     0,     0,    14,     0,     0,
       0,     0,     0,    15,    16,     0,     0,     0,     0,     0,
       0,    17,    18,     0,    19,    20,    21,    22,    23,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,    27,
      28,    29,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,   118,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,   118,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,     0,   148,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,     0,
     118,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,     0,
      93,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,     0,
     114,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,     0,
     179,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,     0,   123,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,     0,   146,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,     0,   147,    86,    87,
      88,    89,    90,    91,    92,    79,    80,    81,    82,    83,
      84,    85,   161,     0,    86,    87,    88,    89,    90,    91,
      92,    79,    80,    81,    82,    83,    84,    85,   164,     0,
      86,    87,    88,    89,    90,    91,    92,     0,   116,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    90,     0,
      92,    79,    80,    81,    82,    83,   -82,   -82,     0,     0,
      86,    87,    88,    89,     0,     0,    92,    79,    80,    81,
      82,    83,    84,    85,     0,     0,    86,    87,    88,    89,
       0,     0,    92
};

static const yytype_int16 yycheck[] =
{
       6,    25,    11,    12,    43,   156,   157,    43,    14,    40,
      43,    17,    18,    15,    16,    51,    43,    23,   153,    25,
      45,    74,     7,    15,    16,    98,    11,    12,    13,    14,
      15,   182,    63,    18,    43,    45,   171,    61,    51,    24,
      25,    52,    51,    49,    50,    51,    51,    32,    33,     0,
      35,    36,    37,    38,    39,    20,    51,    22,    43,    19,
      20,    21,    51,    43,    32,    50,    51,    52,   121,     7,
      40,    44,    32,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   160,    94,    51,
     163,    97,    98,   146,   147,    16,    51,    39,   104,    51,
      45,    43,    48,    24,    25,    47,   179,    49,    44,    39,
      44,   117,   118,    43,    42,    44,    43,    47,    39,    49,
      43,    41,    43,    32,   177,    51,    47,    33,    49,    35,
      36,    37,    38,    44,     4,   188,    17,    18,    19,    20,
      21,    44,   148,    44,   150,    26,    27,    28,    29,    44,
     167,    32,   121,   169,   160,   113,    -1,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,     0,
       1,    -1,     3,   179,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    -1,
      41,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,     1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    -1,    41,    -1,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    51,    52,    11,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    50,    51,    52,    11,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      11,    12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    48,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    -1,    48,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      48,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      45,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      45,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      45,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    44,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    44,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    -1,    44,    26,    27,
      28,    29,    30,    31,    32,    17,    18,    19,    20,    21,
      22,    23,    40,    -1,    26,    27,    28,    29,    30,    31,
      32,    17,    18,    19,    20,    21,    22,    23,    40,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      32,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    18,    24,    25,    32,    33,    35,
      36,    37,    38,    39,    41,    43,    45,    50,    51,    52,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    71,    74,    77,    78,    81,    82,    83,    84,    43,
      43,    43,    43,    51,    45,    58,    45,    45,    51,    51,
      58,    43,    63,    65,    63,    58,    58,    51,    59,    52,
      59,    40,    58,    72,    75,    58,    77,     0,    56,    17,
      18,    19,    20,    21,    22,    23,    26,    27,    28,    29,
      30,    31,    32,    45,    16,    24,    25,    39,    43,    47,
      49,    66,    67,    68,    39,    47,    66,    58,    58,    58,
      69,    51,    79,    43,    45,    77,    34,    46,    48,    73,
      40,    57,    76,    44,    44,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    69,    51,    51,    58,    51,    44,    44,    48,    70,
      45,    48,    80,    44,    79,    44,    58,    58,    76,    42,
      43,    40,    44,    43,    40,    57,    57,    58,    58,    51,
      74,    44,    73,    46,    73,    69,    69,     4,    70,    45,
      80,    74,    58,    44,    44,    57,    69,    73,    44,    57
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {	SIN::Manage_SinCode((yyvsp[(1) - (1)].AST), &((yyval.AST)));	}
    break;

  case 3:

    {	SIN::Manage_Statements((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)));	}
    break;

  case 4:

    {	SIN::Manage_Statements_Empty(&((yyval.AST)));	}
    break;

  case 5:

    {	SIN::Manage_Statement_Expression((yyvsp[(1) - (2)].AST), &((yyval.AST)));			}
    break;

  case 6:

    {	SIN::Manage_Statement_IfStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)));			}
    break;

  case 7:

    {	SIN::Manage_Statement_WhileStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)));		}
    break;

  case 8:

    {	SIN::Manage_Statement_ForStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)));			}
    break;

  case 9:

    {	SIN::Manage_Statement_ReturnStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)));		}
    break;

  case 10:

    {	SIN::Manage_Statement_Break(&((yyval.AST)));						}
    break;

  case 11:

    {	SIN::Manage_Statement_Continue(&((yyval.AST)));					}
    break;

  case 12:

    {	SIN::Manage_Statement_Block((yyvsp[(1) - (1)].AST), &((yyval.AST)));					}
    break;

  case 13:

    {	SIN::Manage_Statement_FunctionDefinition((yyvsp[(1) - (1)].AST), &((yyval.AST)));	}
    break;

  case 14:

    {	SIN::Manage_Statement_Semicolon(&((yyval.AST)));					}
    break;

  case 15:

    {yyclearin;}
    break;

  case 16:

    {	SIN::Manage_Expression_AssignExpression((yyvsp[(1) - (1)].AST), &((yyval.AST)));					}
    break;

  case 17:

    {	SIN::Manage_Expression_ExpressionADDExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 18:

    {	SIN::Manage_Expression_ExpressionMINExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 19:

    {	SIN::Manage_Expression_ExpressionMULExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 20:

    {	SIN::Manage_Expression_ExpressionDIVExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 21:

    {	SIN::Manage_Expression_ExpressionMODExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 22:

    {	SIN::Manage_Expression_ExpressionGTExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 23:

    {	SIN::Manage_Expression_ExpressionGEExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 24:

    {	SIN::Manage_Expression_ExpressionLTExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 25:

    {	SIN::Manage_Expression_ExpressionLEExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 26:

    {	SIN::Manage_Expression_ExpressionEQExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 27:

    {	SIN::Manage_Expression_ExpressionNOTEQExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));	}
    break;

  case 28:

    {	SIN::Manage_Expression_ExpressionANDExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 29:

    {	SIN::Manage_Expression_ExpressionORExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 30:

    {	SIN::Manage_Expression_ExpressionNOTExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));		}
    break;

  case 31:

    {	SIN::Manage_Expression_MetaExpression((yyvsp[(1) - (1)].AST), &((yyval.AST)));					}
    break;

  case 32:

    {	SIN::Manage_Expression_Term((yyvsp[(1) - (1)].AST), &((yyval.AST)));								}
    break;

  case 33:

    {}
    break;

  case 34:

    {/*i am not sure if this is corect*/}
    break;

  case 35:

    {}
    break;

  case 36:

    {}
    break;

  case 37:

    {}
    break;

  case 38:

    {	SIN::Manage_Term_ExpressionParentheses((yyvsp[(2) - (3)].AST), &((yyval.AST)));	}
    break;

  case 39:

    {	SIN::Manage_Term_MINExpression((yyvsp[(2) - (2)].AST), &((yyval.AST)));			}
    break;

  case 40:

    {	SIN::Manage_Term_NOTExpression((yyvsp[(2) - (2)].AST), &((yyval.AST)));			}
    break;

  case 41:

    {	SIN::Manage_Term_INCRLValue((yyvsp[(2) - (2)].AST), &((yyval.AST)));				}
    break;

  case 42:

    {	SIN::Manage_Term_LValueINCR((yyvsp[(1) - (2)].AST), &((yyval.AST)));				}
    break;

  case 43:

    {	SIN::Manage_Term_DECRLValue((yyvsp[(2) - (2)].AST), &((yyval.AST)));				}
    break;

  case 44:

    {	SIN::Manage_Term_LValueDECR((yyvsp[(1) - (2)].AST), &((yyval.AST)));				}
    break;

  case 45:

    {	SIN::Manage_Term_Primary((yyvsp[(1) - (1)].AST), &((yyval.AST)));				}
    break;

  case 46:

    {	SIN::Manage_AssignExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));	}
    break;

  case 47:

    {	SIN::Manage_Primary_LValue((yyvsp[(1) - (1)].AST), &((yyval.AST)));							}
    break;

  case 48:

    {	SIN::Manage_Primary_Call((yyvsp[(1) - (1)].AST), &((yyval.AST)));							}
    break;

  case 49:

    {	SIN::Manage_Primary_ObjectDefinition((yyvsp[(1) - (1)].AST), &((yyval.AST)));				}
    break;

  case 50:

    {	SIN::Manage_Primary_FunctionDefinitionParentheses((yyvsp[(2) - (3)].AST), &((yyval.AST)));	}
    break;

  case 51:

    {	SIN::Manage_Primary_Constant((yyvsp[(1) - (1)].AST), &((yyval.AST)));						}
    break;

  case 52:

    {	SIN::Manage_LValue_ID(yytext, &((yyval.AST)));		}
    break;

  case 53:

    {	SIN::Manage_LValue_LocalID(yytext, &((yyval.AST)));	}
    break;

  case 54:

    {	SIN::Manage_LValue_GlobalID(yytext, &((yyval.AST)));	}
    break;

  case 55:

    {	SIN::Manage_LValue_Member((yyvsp[(1) - (1)].AST), &((yyval.AST)));				}
    break;

  case 56:

    {	SIN::Manage_Member_LValueID((yyvsp[(1) - (3)].AST), yytext, &((yyval.AST)));	}
    break;

  case 57:

    {	SIN::Manage_Member_LValueExpression((yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), &((yyval.AST)));		}
    break;

  case 58:

    {	SIN::Manage_Member_CallID((yyvsp[(1) - (3)].AST), yytext, &((yyval.AST)));	}
    break;

  case 59:

    {	SIN::Manage_Member_CallExpression((yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), &((yyval.AST)));		}
    break;

  case 60:

    {	SIN::Manage_Call_CallCallSuffix((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)));						}
    break;

  case 61:

    {	SIN::Manage_Call_LValueCallSuffix((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)));					}
    break;

  case 62:

    {	SIN::Manage_Call_FunctionDefinitionExpressionList((yyvsp[(2) - (6)].AST), (yyvsp[(5) - (6)].AST), &((yyval.AST)));	}
    break;

  case 63:

    {	SIN::Manage_CallSuffix_NormalCall((yyvsp[(1) - (1)].AST), &((yyval.AST)));	}
    break;

  case 64:

    {	SIN::Manage_CallSuffix_MethodCall((yyvsp[(1) - (1)].AST), &((yyval.AST)));	}
    break;

  case 65:

    {	SIN::Manage_NormalCall((yyvsp[(2) - (3)].AST), &((yyval.AST)));	}
    break;

  case 66:

    {	SIN::Manage_MethodCall(yytext, (yyvsp[(4) - (5)].AST), &((yyval.AST)));	}
    break;

  case 67:

    {	SIN::Manage_ExpressionList((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)));	}
    break;

  case 68:

    {	SIN::Manage_ExpressionList_Empty(&((yyval.AST)));	}
    break;

  case 69:

    {	SIN::Manage_ExpressionList((yyvsp[(2) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));	}
    break;

  case 70:

    {	SIN::Manage_ExpressionList_Empty(&((yyval.AST)));	}
    break;

  case 71:

    {	SIN::Manage_ObjectDefinition_EmptyObject(&((yyval.AST)));	}
    break;

  case 72:

    {	SIN::Manage_ObjectDefinition_ObjectList((yyvsp[(2) - (3)].AST), &((yyval.AST)));	}
    break;

  case 73:

    {	SIN::Manage_ObjectList_ExpressionObjectLists((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)));				}
    break;

  case 74:

    {	SIN::Manage_ObjectList_ExpressionExpressionObjectLists((yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), (yyvsp[(4) - (4)].AST), &((yyval.AST)));	}
    break;

  case 75:

    {	SIN::Manage_ObjectList_ExpressionObjectLists((yyvsp[(2) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)));				}
    break;

  case 76:

    {	SIN::Manage_ObjectList_ExpressionExpressionObjectLists((yyvsp[(2) - (5)].AST), (yyvsp[(4) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)));	}
    break;

  case 77:

    {	SIN::Manage_ObjectList_Empty(&((yyval.AST)));										}
    break;

  case 78:

    {}
    break;

  case 79:

    {	SIN::Manage_Block((yyvsp[(3) - (4)].AST), &((yyval.AST)));	}
    break;

  case 80:

    {	SIN::Manage_Statements((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)));	}
    break;

  case 81:

    {	SIN::Manage_Statements_Empty(&((yyval.AST)));	}
    break;

  case 82:

    {	SIN::Manage_FunctionDefinition_Function(yytext, (yyvsp[(4) - (6)].AST), (yyvsp[(6) - (6)].AST), &((yyval.AST)));	}
    break;

  case 83:

    {	SIN::Manage_FunctionDefinition_LamdaFunction((yyvsp[(3) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)));			}
    break;

  case 84:

    {	SIN::Manage_Constant_Number(atof(yytext), &((yyval.AST)));	}
    break;

  case 85:

    {	SIN::Manage_Constant_String(yytext, &((yyval.AST)));	}
    break;

  case 86:

    {	SIN::Manage_Constant_Nil(&((yyval.AST)));					}
    break;

  case 87:

    {	SIN::Manage_Constant_True(&((yyval.AST)));					}
    break;

  case 88:

    {	SIN::Manage_Constant_False(&((yyval.AST)));					}
    break;

  case 89:

    {	SIN::Manage_IDList(yytext, (yyvsp[(2) - (2)].AST), &((yyval.AST)));	}
    break;

  case 90:

    {	SIN::Manage_IDList_Empty(&((yyval.AST)));		}
    break;

  case 91:

    {	SIN::Manage_IDList(yytext, (yyvsp[(3) - (3)].AST), &((yyval.AST)));	}
    break;

  case 92:

    {	SIN::Manage_IDList_Empty(&((yyval.AST)));		}
    break;

  case 93:

    {	SIN::Manage_IfStatement_If((yyvsp[(3) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)));			}
    break;

  case 94:

    {	SIN::Manage_IfStatement_IfElse((yyvsp[(3) - (7)].AST), (yyvsp[(5) - (7)].AST), (yyvsp[(7) - (7)].AST), &((yyval.AST)));	}
    break;

  case 95:

    {	SIN::Manage_WhileStatement((yyvsp[(3) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)));	}
    break;

  case 96:

    {	SIN::Manage_ForStatement((yyvsp[(3) - (9)].AST), (yyvsp[(5) - (9)].AST), (yyvsp[(7) - (9)].AST), (yyvsp[(9) - (9)].AST), &((yyval.AST)));	}
    break;

  case 97:

    {	SIN::Manage_ReturnStatement_Return(&((yyval.AST)));					}
    break;

  case 98:

    {	SIN::Manage_ReturnStatement_ReturnExpression((yyvsp[(2) - (3)].AST), &((yyval.AST)));	}
    break;



      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





int yyerror (char* yaccProvidedMessage)
{
	fprintf(stderr, "%s: at line %d, before token: >%s<\n", yaccProvidedMessage, yylineno, yytext);
	return -1;
}


int PrepareForFile(const char * filePath) {
	assert (filePath);
	if (!(yyin = fopen(filePath, "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", filePath);
			return 1;
	}
	return 0;
}

int PrepareForString(const char * str) {
	//yy_scan_string(const char * str);
	return 0;
}

