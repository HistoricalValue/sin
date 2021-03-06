
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
	#include <utility>
	#include <assert.h>
	#include <iostream>
	#include <string.h>
	
	
	// Bison assumes alloca is the memory allocation
	// function.
	//
	#ifndef	alloca
	#define alloca malloc
	#endif



	#include "SINString.h"
	#include "SINASTNode.h"
	#include "SINParserManage.h"
	#include "LexAndBisonParseArguments.h"
	

	////////////////////////////////////////////////////////////////////////
	// defines
	


	////////////////////////////////////////////////////////////////////////
	// functions definitions
	
	int yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage);
	int PrepareForFile(const char * filePath);
	int PrepareForString(const char * str);


	int yylex(SIN::LexAndBisonParseArguments & fabpa);
	//
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
     DOT_LT = 293,
     GT_DOT = 294,
     DOT_TILDE = 295,
     DOT_EXCl_MARK = 296,
     DOT_AT = 297,
     DOT_HASH = 298,
     KEYS_MEMBER = 299,
     SIZE_MEMBER = 300,
     UMINUS = 301
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
#define DOT_LT 293
#define GT_DOT 294
#define DOT_TILDE 295
#define DOT_EXCl_MARK 296
#define DOT_AT 297
#define DOT_HASH 298
#define KEYS_MEMBER 299
#define SIZE_MEMBER 300
#define UMINUS 301




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
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  229

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      10,    11,     2,     2,    14,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    13,    12,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     6,     2,     7,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     8,     2,     9,     2,     2,     2,     2,
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
       5,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    23,    26,    28,    30,    32,    34,    38,    42,    46,
      50,    54,    58,    62,    66,    70,    74,    78,    82,    86,
      88,    91,    93,    97,   101,   104,   107,   110,   113,   117,
     120,   123,   126,   129,   132,   135,   137,   141,   143,   145,
     147,   151,   153,   155,   158,   161,   163,   167,   172,   176,
     180,   184,   189,   192,   195,   202,   209,   211,   213,   217,
     223,   226,   227,   231,   232,   235,   239,   242,   247,   250,
     254,   260,   264,   265,   266,   271,   274,   275,   276,   284,
     285,   292,   293,   301,   302,   309,   310,   318,   319,   326,
     328,   330,   332,   334,   336,   339,   340,   344,   345,   351,
     359,   360,   367,   368,   379,   382
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,    59,    58,    -1,    -1,    60,
      12,    -1,    91,    -1,    92,    -1,    94,    -1,    96,    -1,
      23,    12,    -1,    24,    12,    -1,    76,    -1,    85,    -1,
      12,    -1,    63,    -1,    60,    31,    60,    -1,    60,    32,
      60,    -1,    60,    33,    60,    -1,    60,    34,    60,    -1,
      60,    35,    60,    -1,    60,    40,    60,    -1,    60,    42,
      60,    -1,    60,    41,    60,    -1,    60,    43,    60,    -1,
      60,    36,    60,    -1,    60,    37,    60,    -1,    60,    44,
      60,    -1,    60,    45,    60,    -1,    61,    -1,    52,    61,
      -1,    62,    -1,    47,    57,    48,    -1,    47,    60,    48,
      -1,    49,    65,    -1,    49,    67,    -1,    50,    61,    -1,
      51,    65,    -1,    10,    60,    11,    -1,    32,    60,    -1,
      46,    60,    -1,    38,    65,    -1,    65,    38,    -1,    39,
      65,    -1,    65,    39,    -1,    64,    -1,    65,    30,    60,
      -1,    65,    -1,    67,    -1,    73,    -1,    10,    82,    11,
      -1,    88,    -1,     4,    -1,    25,     4,    -1,    26,     4,
      -1,    66,    -1,    65,    15,     4,    -1,    65,     6,    60,
       7,    -1,    65,    15,    53,    -1,    65,    15,    54,    -1,
      67,    15,     4,    -1,    67,     6,    60,     7,    -1,    67,
      68,    -1,    65,    68,    -1,    10,    60,    11,    10,    71,
      11,    -1,    10,    82,    11,    10,    71,    11,    -1,    69,
      -1,    70,    -1,    10,    71,    11,    -1,    16,     4,    10,
      71,    11,    -1,    60,    72,    -1,    -1,    14,    60,    72,
      -1,    -1,     6,     7,    -1,     6,    74,     7,    -1,    60,
      75,    -1,    60,    13,    60,    75,    -1,    85,    75,    -1,
      14,    60,    75,    -1,    14,    60,    13,    60,    75,    -1,
      14,    79,    75,    -1,    -1,    -1,     8,    77,    78,     9,
      -1,    59,    78,    -1,    -1,    -1,    21,    80,     4,    10,
      89,    11,    76,    -1,    -1,    21,    81,    10,    89,    11,
      76,    -1,    -1,    21,    83,     4,    10,    89,    11,    76,
      -1,    -1,    21,    84,    10,    89,    11,    76,    -1,    -1,
      21,    86,     4,    10,    89,    11,    76,    -1,    -1,    21,
      87,    10,    89,    11,    76,    -1,     3,    -1,     5,    -1,
      29,    -1,    27,    -1,    28,    -1,     4,    90,    -1,    -1,
      14,     4,    90,    -1,    -1,    17,    10,    60,    11,    59,
      -1,    17,    10,    60,    11,    59,    18,    59,    -1,    -1,
      19,    93,    10,    60,    11,    59,    -1,    -1,    20,    95,
      10,    71,    12,    60,    12,    71,    11,    59,    -1,    22,
      12,    -1,    22,    60,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   111,   112,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   153,   154,   155,   156,   157,   158,   163,   164,
     165,   166,   167,   168,   169,   170,   175,   180,   181,   182,
     183,   184,   189,   190,   191,   192,   197,   198,   199,   200,
     201,   202,   208,   209,   210,   211,   215,   216,   221,   226,
     231,   232,   237,   238,   243,   244,   249,   250,   251,   256,
     257,   258,   259,   264,   264,   269,   270,   273,   273,   275,
     275,   279,   279,   281,   281,   286,   286,   288,   288,   293,
     294,   295,   296,   297,   301,   302,   307,   308,   313,   314,
     317,   317,   321,   321,   325,   326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STRING", "'['", "']'",
  "'{'", "'}'", "'('", "')'", "';'", "':'", "','", "DOT", "DOUBLEDOT",
  "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE",
  "LOCAL", "GLOBAL", "TRUE", "FALSE", "NIL", "ASSIGN", "ADD", "MIN", "MUL",
  "DIV", "MOD", "EQ", "NOTEQ", "INCR", "DECR", "GT", "LT", "GE", "LE",
  "AND", "OR", "NOT", "DOT_LT", "GT_DOT", "DOT_TILDE", "DOT_EXCl_MARK",
  "DOT_AT", "DOT_HASH", "KEYS_MEMBER", "SIZE_MEMBER", "UMINUS", "$accept",
  "SinCode", "stmts", "stmt", "expr", "metaexpr", "term", "assignexpr",
  "primary", "lvalue", "member", "call", "callsuffix", "normalcall",
  "methodcall", "elist", "elists", "objectdef", "objectlist",
  "objectlists", "block", "$@1", "stmtd", "objectfuncdef", "$@2", "$@3",
  "fvaluedef", "$@4", "$@5", "funcdef", "$@6", "$@7", "const", "idlist",
  "idlists", "ifstmt", "whilestmt", "$@8", "forstmt", "$@9", "returnstmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,    91,    93,   123,   125,
      40,    41,    59,    58,    44,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    64,
      64,    64,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    69,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    75,
      75,    75,    75,    77,    76,    78,    78,    80,    79,    81,
      79,    83,    82,    84,    82,    86,    85,    87,    85,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      93,    92,    95,    94,    96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     1,     3,     3,     2,     2,     2,     2,     3,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     1,     1,
       3,     1,     1,     2,     2,     1,     3,     4,     3,     3,
       3,     4,     2,     2,     6,     6,     1,     1,     3,     5,
       2,     0,     3,     0,     2,     3,     2,     4,     2,     3,
       5,     3,     0,     0,     4,     2,     0,     0,     7,     0,
       6,     0,     7,     0,     6,     0,     7,     0,     6,     1,
       1,     1,     1,     1,     2,     0,     3,     0,     5,     7,
       0,     6,     0,    10,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    99,    52,   100,     0,    83,     0,    14,     0,   110,
     112,    95,     0,     0,     0,     0,     0,   102,   103,   101,
       0,     0,     0,     0,     4,     0,     0,     0,     0,     0,
       2,     4,     0,    29,    31,    15,    45,    47,    55,    48,
      49,    12,    13,    51,     6,     7,     8,     9,    74,    82,
       0,    82,    86,    91,     0,     0,     0,     0,     0,     0,
       0,   114,     0,    10,    11,    53,    54,    39,     0,    41,
       0,    43,    40,     0,     0,    34,    35,    36,    37,    30,
       1,     3,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,    42,    44,    63,    66,    67,     0,     0,    62,     0,
       0,    76,    75,    78,    86,     0,     0,     0,    38,    50,
       0,     0,    71,     0,   105,   115,     0,     0,    32,    33,
      16,    17,    18,    19,    20,    25,    26,    21,    23,    22,
      24,    27,    28,     0,    73,     0,    56,    58,    59,     0,
      46,     0,    60,    82,    87,    82,    82,    85,    84,     0,
     105,    71,    71,     0,     0,     0,   105,   107,     0,     0,
       0,    57,     0,    70,    68,    71,    61,    77,     0,     0,
       0,    79,    81,   105,     0,     0,     0,   108,     0,     0,
       0,     0,   104,     0,    73,     0,     0,   105,    82,     0,
       0,    64,    65,     0,   111,     0,     0,   107,    98,    72,
      69,   105,     0,    80,     0,    94,   109,    71,    96,   106,
       0,     0,    92,     0,     0,    90,     0,    88,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   103,   104,   105,   145,   173,    40,    50,   111,
      41,    52,   115,   156,   178,   179,    55,   116,   117,    42,
      59,    60,    43,   168,   192,    44,    45,    57,    46,    58,
      47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -189
static const yytype_int16 yypact[] =
{
     176,  -189,  -189,  -189,   214,  -189,   252,  -189,     1,  -189,
    -189,     4,   282,     3,    12,    25,    28,  -189,  -189,  -189,
     350,    24,    24,   350,   176,    24,    50,    24,    50,    35,
    -189,   176,   478,  -189,  -189,  -189,  -189,     7,  -189,    15,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,   528,
      32,    40,   176,    30,   409,    46,   350,    62,    63,    90,
     104,  -189,   495,  -189,  -189,  -189,  -189,  -189,   252,   145,
      15,   145,  -189,    68,   391,   145,    15,  -189,   145,  -189,
    -189,  -189,  -189,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,     5,   122,
     350,  -189,  -189,  -189,  -189,  -189,   350,   123,  -189,   350,
     320,  -189,  -189,  -189,   176,   125,   131,   126,   135,   136,
     426,   350,   350,   144,   152,  -189,   444,   148,  -189,  -189,
      27,    27,  -189,  -189,  -189,   107,   107,   352,   352,   352,
     352,   622,    34,    88,   568,   151,  -189,  -189,  -189,   153,
     607,   373,  -189,   592,   154,   553,    40,  -189,  -189,   155,
     152,   350,   350,   176,   461,   157,   152,   156,   161,   135,
     136,  -189,   350,  -189,  -189,   350,  -189,  -189,   162,   163,
     350,  -189,  -189,   152,   166,   167,   172,   149,   176,   350,
     178,   170,  -189,   179,   568,   180,   182,   152,   592,   183,
     179,  -189,  -189,   176,  -189,   512,   179,   156,  -189,  -189,
    -189,   152,   195,  -189,   179,  -189,  -189,   350,  -189,  -189,
     196,   179,  -189,   198,   179,  -189,   176,  -189,  -189
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,   186,   159,   -51,    -4,    87,  -189,  -189,  -189,    26,
    -189,    82,   -32,  -189,  -189,  -119,    17,  -189,  -189,   -45,
    -188,  -189,    98,  -189,  -189,  -189,   164,  -189,  -189,   212,
    -189,  -189,  -189,  -156,    22,  -189,  -189,  -189,  -189,  -189,
    -189
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -98
static const yytype_int16 yytable[] =
{
      49,   114,    54,   165,   184,   208,   113,   108,    62,   146,
     190,    56,   215,    96,   -97,    63,    67,    97,   218,    72,
      74,   106,    98,    99,    64,    97,   222,   199,     2,    65,
     107,    99,    66,   225,    68,    80,   227,   100,   108,   112,
     -93,   212,   185,   186,   108,   101,   102,    69,    71,    15,
      16,    75,   120,    78,   110,   220,   195,   119,   147,   148,
      85,    86,    87,   114,   126,    83,    84,    85,    86,    87,
      88,    89,   121,   122,    90,    91,    92,    93,    94,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   123,   171,   150,    24,   223,    25,
      26,    27,   151,    70,    70,   153,   155,    76,   177,    70,
     181,   182,   187,    77,   124,    79,   128,   164,   144,    83,
      84,    85,    86,    87,    88,    89,   149,   152,    90,    91,
      92,    93,    94,    95,   158,   159,   160,   204,    83,    84,
      85,    86,    87,   -98,   -98,   161,   162,    90,    91,    92,
      93,    96,   216,   213,   166,    97,   167,   144,   144,   170,
      98,    99,   174,   175,   -89,   183,   196,   203,   194,   189,
     191,   144,   193,   197,   207,   228,   198,   200,   201,     1,
       2,     3,     4,   202,     5,   205,     6,     5,     7,   206,
      81,   210,   211,     8,   214,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   221,   224,    20,   226,
      73,   209,   157,   144,    21,    22,    51,     1,     2,     3,
       4,    48,    23,    24,     6,    25,    26,    27,    28,   219,
       0,     0,   127,     0,     0,    11,     0,     0,     0,    15,
      16,    17,    18,    19,     0,     0,    20,     0,     0,     0,
       0,     0,    21,    22,     0,     1,     2,     3,     4,     0,
      23,    24,     6,    25,    26,    27,    28,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,    15,    16,    17,
      18,    19,     0,     0,    20,     1,     2,     3,     4,     0,
      21,    22,     6,     0,    61,     0,     0,     0,    23,    24,
       0,    25,    26,    27,    28,     0,     0,    15,    16,    17,
      18,    19,     0,     0,    20,     0,     0,     0,     0,     0,
      21,    22,     0,     1,     2,     3,     4,     0,    23,    24,
       6,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,    15,    16,    17,    18,    19,
       0,     0,    20,     1,     2,     3,     4,     0,    21,    22,
       6,     0,     0,     0,     0,     0,    23,    24,     0,    25,
      26,    27,    28,     0,     0,    15,    16,    17,    18,    19,
     176,     0,    20,    83,    84,    85,    86,    87,    21,    22,
       0,     0,   -98,   -98,   -98,   -98,    23,    24,     0,    25,
      26,    27,    28,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,    90,    91,    92,    93,    94,    95,     0,
     118,     0,    83,    84,    85,    86,    87,    88,    89,     0,
       0,    90,    91,    92,    93,    94,    95,   163,     0,   129,
      83,    84,    85,    86,    87,    88,    89,     0,     0,    90,
      91,    92,    93,    94,    95,   169,     0,    83,    84,    85,
      86,    87,    88,    89,     0,     0,    90,    91,    92,    93,
      94,    95,   188,     0,     0,    83,    84,    85,    86,    87,
      88,    89,     0,     0,    90,    91,    92,    93,    94,    95,
      82,     0,    83,    84,    85,    86,    87,    88,    89,     0,
       0,    90,    91,    92,    93,    94,    95,   125,     0,    83,
      84,    85,    86,    87,    88,    89,     0,     0,    90,    91,
      92,    93,    94,    95,   217,     0,    83,    84,    85,    86,
      87,    88,    89,     0,     0,    90,    91,    92,    93,    94,
      95,   109,   110,    83,    84,    85,    86,    87,    88,    89,
       0,     0,    90,    91,    92,    93,    94,    95,     0,    83,
      84,    85,    86,    87,    88,    89,   180,   110,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,   172,     0,    83,    84,    85,    86,    87,    88,
      89,     0,     0,    90,    91,    92,    93,    94,    95,    83,
      84,    85,    86,    87,    88,    89,   110,     0,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
       0,     0,    90,    91,    92,    93,    94,    95,    83,    84,
      85,    86,    87,    88,    89,     0,     0,    90,    91,    92,
      93,    94,    95,    83,    84,    85,    86,    87,    88,    89,
       0,     0,    90,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
       4,    52,     6,   122,   160,   193,    51,    39,    12,     4,
     166,    10,   200,     6,    10,    12,    20,    10,   206,    23,
      24,     6,    15,    16,    12,    10,   214,   183,     4,     4,
      15,    16,     4,   221,    10,     0,   224,    30,    70,     7,
      10,   197,   161,   162,    76,    38,    39,    21,    22,    25,
      26,    25,    56,    27,    14,   211,   175,    11,    53,    54,
      33,    34,    35,   114,    68,    31,    32,    33,    34,    35,
      36,    37,    10,    10,    40,    41,    42,    43,    44,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     4,     7,   100,    47,   217,    49,
      50,    51,   106,    21,    22,   109,   110,    25,   153,    27,
     155,   156,   163,    26,    10,    28,    48,   121,   122,    31,
      32,    33,    34,    35,    36,    37,     4,     4,    40,    41,
      42,    43,    44,    45,     9,     4,    10,   188,    31,    32,
      33,    34,    35,    36,    37,    10,    10,    40,    41,    42,
      43,     6,   203,   198,    10,    10,     4,   161,   162,    11,
      15,    16,    11,    10,    10,    10,     4,    18,   172,    12,
      14,   175,    11,    10,     4,   226,   180,    11,    11,     3,
       4,     5,     6,    11,     8,   189,    10,     8,    12,    11,
      31,    11,    10,    17,    11,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    11,    11,    32,    11,
      24,   194,   114,   217,    38,    39,     4,     3,     4,     5,
       6,     7,    46,    47,    10,    49,    50,    51,    52,   207,
      -1,    -1,    68,    -1,    -1,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,     3,     4,     5,     6,    -1,
      46,    47,    10,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    32,     3,     4,     5,     6,    -1,
      38,    39,    10,    -1,    12,    -1,    -1,    -1,    46,    47,
      -1,    49,    50,    51,    52,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,     3,     4,     5,     6,    -1,    46,    47,
      10,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      -1,    -1,    32,     3,     4,     5,     6,    -1,    38,    39,
      10,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    52,    -1,    -1,    25,    26,    27,    28,    29,
       7,    -1,    32,    31,    32,    33,    34,    35,    38,    39,
      -1,    -1,    40,    41,    42,    43,    46,    47,    -1,    49,
      50,    51,    52,    12,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    -1,
      11,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    11,    -1,    48,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    11,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    11,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      12,    -1,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    12,    -1,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    12,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    13,    14,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    31,
      32,    33,    34,    35,    36,    37,    13,    14,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    31,
      32,    33,    34,    35,    36,    37,    14,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    10,    12,    17,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      32,    38,    39,    46,    47,    49,    50,    51,    52,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      73,    76,    85,    88,    91,    92,    94,    96,     7,    60,
      74,    85,    77,    21,    60,    82,    10,    93,    95,    86,
      87,    12,    60,    12,    12,     4,     4,    60,    10,    65,
      67,    65,    60,    57,    60,    65,    67,    61,    65,    61,
       0,    58,    12,    31,    32,    33,    34,    35,    36,    37,
      40,    41,    42,    43,    44,    45,     6,    10,    15,    16,
      30,    38,    39,    68,    69,    70,     6,    15,    68,    13,
      14,    75,     7,    75,    59,    78,    83,    84,    11,    11,
      60,    10,    10,     4,    10,    12,    60,    82,    48,    48,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    71,     4,    53,    54,     4,
      60,    60,     4,    60,    21,    60,    79,    78,     9,     4,
      10,    10,    10,    11,    60,    71,    10,     4,    89,    11,
      11,     7,    14,    72,    11,    10,     7,    75,    80,    81,
      13,    75,    75,    10,    89,    71,    71,    59,    11,    12,
      89,    14,    90,    11,    60,    71,     4,    10,    60,    89,
      11,    11,    11,    18,    59,    60,    11,     4,    76,    72,
      11,    10,    89,    75,    11,    76,    59,    12,    76,    90,
      89,    11,    76,    71,    11,    76,    11,    76,    59
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
      yyerror (fabpa, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (fabpa)
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
		  Type, Value, fabpa); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SIN::LexAndBisonParseArguments & fabpa)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, fabpa)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    SIN::LexAndBisonParseArguments & fabpa;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (fabpa);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SIN::LexAndBisonParseArguments & fabpa)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, fabpa)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    SIN::LexAndBisonParseArguments & fabpa;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, fabpa);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, SIN::LexAndBisonParseArguments & fabpa)
#else
static void
yy_reduce_print (yyvsp, yyrule, fabpa)
    YYSTYPE *yyvsp;
    int yyrule;
    SIN::LexAndBisonParseArguments & fabpa;
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
		       		       , fabpa);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, fabpa); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, SIN::LexAndBisonParseArguments & fabpa)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, fabpa)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    SIN::LexAndBisonParseArguments & fabpa;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (fabpa);

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
int yyparse (SIN::LexAndBisonParseArguments & fabpa);
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
yyparse (SIN::LexAndBisonParseArguments & fabpa)
#else
int
yyparse (fabpa)
    SIN::LexAndBisonParseArguments & fabpa;
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

    {	
							SIN::ParserManage::Manage_SinCode(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	
							fabpa.SetRoot((yyval.AST));
						}
    break;

  case 3:

    {	SIN::ParserManage::Manage_Statements(yylineno, (yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 4:

    {	SIN::ParserManage::Manage_Statements_Empty(yylineno, &((yyval.AST)), &fabpa);		}
    break;

  case 5:

    {	SIN::ParserManage::Manage_Statement_Expression(yylineno, (yyvsp[(1) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 6:

    {	SIN::ParserManage::Manage_Statement_IfStatement(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 7:

    {	SIN::ParserManage::Manage_Statement_WhileStatement(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 8:

    {	SIN::ParserManage::Manage_Statement_ForStatement(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 9:

    {	SIN::ParserManage::Manage_Statement_ReturnStatement(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 10:

    {	SIN::ParserManage::Manage_Statement_Break(yylineno, &((yyval.AST)), &fabpa);					}
    break;

  case 11:

    {	SIN::ParserManage::Manage_Statement_Continue(yylineno, &((yyval.AST)), &fabpa);				}
    break;

  case 12:

    {	SIN::ParserManage::Manage_Statement_Block(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 13:

    {	SIN::ParserManage::Manage_Statement_FunctionDefinition(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 14:

    {	SIN::ParserManage::Manage_Statement_Semicolon(yylineno, &((yyval.AST)), &fabpa);				}
    break;

  case 15:

    {	SIN::ParserManage::Manage_Expression_AssignExpression(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 16:

    {	SIN::ParserManage::Manage_Expression_ExpressionADDExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 17:

    {	SIN::ParserManage::Manage_Expression_ExpressionMINExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 18:

    {	SIN::ParserManage::Manage_Expression_ExpressionMULExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 19:

    {	SIN::ParserManage::Manage_Expression_ExpressionDIVExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 20:

    {	SIN::ParserManage::Manage_Expression_ExpressionMODExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 21:

    {	SIN::ParserManage::Manage_Expression_ExpressionGTExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 22:

    {	SIN::ParserManage::Manage_Expression_ExpressionGEExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 23:

    {	SIN::ParserManage::Manage_Expression_ExpressionLTExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 24:

    {	SIN::ParserManage::Manage_Expression_ExpressionLEExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 25:

    {	SIN::ParserManage::Manage_Expression_ExpressionEQExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 26:

    {	SIN::ParserManage::Manage_Expression_ExpressionNOTEQExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 27:

    {	SIN::ParserManage::Manage_Expression_ExpressionANDExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 28:

    {	SIN::ParserManage::Manage_Expression_ExpressionORExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 29:

    {	SIN::ParserManage::Manage_Expression_MetaExpression(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 30:

    {	SIN::ParserManage::Manage_Expression_UnparseMetaExpression(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 31:

    {	SIN::ParserManage::Manage_Expression_Term(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);							}
    break;

  case 32:

    {	SIN::ParserManage::Manage_MetaExpression_ShiftToMetaExpression(yylineno, (yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 33:

    {	SIN::ParserManage::Manage_MetaExpression_ShiftToMetaExpression(yylineno, (yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 34:

    {	SIN::ParserManage::Manage_MetaExpression_PreserveAST_Lvalue(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 35:

    {	SIN::ParserManage::Manage_MetaExpression_PreserveAST_CALL(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 36:

    {	SIN::ParserManage::Manage_MetaExpression_CompileMetaExpression(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 37:

    {	SIN::ParserManage::Manage_MetaExpression_ParseString(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 38:

    {	SIN::ParserManage::Manage_Term_ExpressionParentheses(yylineno, (yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 39:

    {	SIN::ParserManage::Manage_Term_MINExpression(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 40:

    {	SIN::ParserManage::Manage_Term_NOTExpression(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 41:

    {	SIN::ParserManage::Manage_Term_INCRLValue(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 42:

    {	SIN::ParserManage::Manage_Term_LValueINCR(yylineno, (yyvsp[(1) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 43:

    {	SIN::ParserManage::Manage_Term_DECRLValue(yylineno, (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 44:

    {	SIN::ParserManage::Manage_Term_LValueDECR(yylineno, (yyvsp[(1) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 45:

    {	SIN::ParserManage::Manage_Term_Primary(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 46:

    {	SIN::ParserManage::Manage_AssignExpression(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 47:

    {	SIN::ParserManage::Manage_Primary_LValue(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);							}
    break;

  case 48:

    {	SIN::ParserManage::Manage_Primary_Call(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);							}
    break;

  case 49:

    {	SIN::ParserManage::Manage_Primary_ObjectDefinition(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 50:

    {	SIN::ParserManage::Manage_Primary_FunctionDefinitionParentheses(yylineno, (yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 51:

    {	SIN::ParserManage::Manage_Primary_Constant(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);						}
    break;

  case 52:

    {	SIN::ParserManage::Manage_LValue_ID(yylineno, (yyvsp[(1) - (1)].stringV), &((yyval.AST)), &fabpa);		}
    break;

  case 53:

    {	SIN::ParserManage::Manage_LValue_LocalID(yylineno, (yyvsp[(2) - (2)].stringV), &((yyval.AST)), &fabpa);	}
    break;

  case 54:

    {	SIN::ParserManage::Manage_LValue_GlobalID(yylineno, (yyvsp[(2) - (2)].stringV), &((yyval.AST)), &fabpa);	}
    break;

  case 55:

    {	SIN::ParserManage::Manage_LValue_Member(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 56:

    {	SIN::ParserManage::Manage_Member_LValueID(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].stringV), &((yyval.AST)), &fabpa);			}
    break;

  case 57:

    {	SIN::ParserManage::Manage_Member_LValueExpression(yylineno, (yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 58:

    {	SIN::ParserManage::Manage_Member_LValueKEYS(yylineno, (yyvsp[(1) - (3)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 59:

    {	SIN::ParserManage::Manage_Member_LValueSIZE(yylineno, (yyvsp[(1) - (3)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 60:

    {	SIN::ParserManage::Manage_Member_CallID(yylineno, (yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].stringV), &((yyval.AST)), &fabpa);			}
    break;

  case 61:

    {	SIN::ParserManage::Manage_Member_CallExpression(yylineno, (yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 62:

    {	SIN::ParserManage::Manage_Call_CallCallSuffix(yylineno, (yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 63:

    {	SIN::ParserManage::Manage_Call_LValueCallSuffix(yylineno, (yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 64:

    {	SIN::ParserManage::Manage_Call_ExpressionCall(yylineno, (yyvsp[(2) - (6)].AST), (yyvsp[(5) - (6)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 65:

    {	SIN::ParserManage::Manage_Call_FunctionDefinitionCall(yylineno, (yyvsp[(2) - (6)].AST), (yyvsp[(5) - (6)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 66:

    {	SIN::ParserManage::Manage_CallSuffix_NormalCall(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 67:

    {	SIN::ParserManage::Manage_CallSuffix_MethodCall(yylineno, (yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 68:

    {	SIN::ParserManage::Manage_NormalCall(yylineno, (yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 69:

    {	SIN::ParserManage::Manage_MethodCall(yylineno, (yyvsp[(2) - (5)].stringV), (yyvsp[(4) - (5)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 70:

    {	SIN::ParserManage::Manage_ExpressionList(yylineno, (yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 71:

    {	SIN::ParserManage::Manage_ExpressionList_Empty(yylineno, &((yyval.AST)), &fabpa);	}
    break;

  case 72:

    {	SIN::ParserManage::Manage_ExpressionList(yylineno, (yyvsp[(2) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 73:

    {	SIN::ParserManage::Manage_ExpressionList_Empty(yylineno, &((yyval.AST)), &fabpa);	}
    break;

  case 74:

    {	SIN::ParserManage::Manage_ObjectDefinition_EmptyObject(yylineno, &((yyval.AST)), &fabpa);	}
    break;

  case 75:

    {	SIN::ParserManage::Manage_ObjectDefinition_ObjectList(yylineno, (yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 76:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists(yylineno, (yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 77:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists(yylineno, (yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), (yyvsp[(4) - (4)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 78:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists(yylineno, (yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 79:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists(yylineno, (yyvsp[(2) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 80:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists(yylineno, (yyvsp[(2) - (5)].AST), (yyvsp[(4) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 81:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionFunckdefObjectLists(yylineno, (yyvsp[(2) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 82:

    {	SIN::ParserManage::Manage_ObjectList_Empty(yylineno, &((yyval.AST)), &fabpa);											}
    break;

  case 83:

    {}
    break;

  case 84:

    {	SIN::ParserManage::Manage_Block(yylineno, (yyvsp[(3) - (4)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 85:

    {	SIN::ParserManage::Manage_Statements(yylineno, (yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 86:

    {	SIN::ParserManage::Manage_Statements_Empty(yylineno, &((yyval.AST)), &fabpa);	}
    break;

  case 87:

    {	++fabpa.parsingCounters.functions;																}
    break;

  case 88:

    {	SIN::ParserManage::Manage_FunctionDefinition_Function(yylineno, (yyvsp[(3) - (7)].stringV), (yyvsp[(5) - (7)].AST), (yyvsp[(7) - (7)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 89:

    {	++fabpa.parsingCounters.functions;																}
    break;

  case 90:

    {	SIN::ParserManage::Manage_FunctionDefinition_LamdaFunction(yylineno, (yyvsp[(4) - (6)].AST), (yyvsp[(6) - (6)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 91:

    {	++fabpa.parsingCounters.functions;																}
    break;

  case 92:

    {	SIN::ParserManage::Manage_FunctionValueDefinition(yylineno, (yyvsp[(5) - (7)].AST), (yyvsp[(7) - (7)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 93:

    {	++fabpa.parsingCounters.functions;																}
    break;

  case 94:

    {	SIN::ParserManage::Manage_FunctionValueDefinition(yylineno, (yyvsp[(4) - (6)].AST), (yyvsp[(6) - (6)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 95:

    {	++fabpa.parsingCounters.functions;																}
    break;

  case 96:

    {	SIN::ParserManage::Manage_FunctionDefinition_Function(yylineno, (yyvsp[(3) - (7)].stringV), (yyvsp[(5) - (7)].AST), (yyvsp[(7) - (7)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 97:

    {	++fabpa.parsingCounters.functions;																}
    break;

  case 98:

    {	SIN::ParserManage::Manage_FunctionDefinition_LamdaFunction(yylineno, (yyvsp[(4) - (6)].AST), (yyvsp[(6) - (6)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 99:

    {	SIN::ParserManage::Manage_Constant_Number(yylineno, atof(yytext), &((yyval.AST)), &fabpa);	}
    break;

  case 100:

    {	SIN::ParserManage::Manage_Constant_String(yylineno, (yyvsp[(1) - (1)].stringV), &((yyval.AST)), &fabpa);				}
    break;

  case 101:

    {	SIN::ParserManage::Manage_Constant_Nil(yylineno, &((yyval.AST)), &fabpa);					}
    break;

  case 102:

    {	SIN::ParserManage::Manage_Constant_True(yylineno, &((yyval.AST)), &fabpa);					}
    break;

  case 103:

    {	SIN::ParserManage::Manage_Constant_False(yylineno, &((yyval.AST)), &fabpa);					}
    break;

  case 104:

    {	SIN::ParserManage::Manage_IDList(yylineno, (yyvsp[(1) - (2)].stringV), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 105:

    {	SIN::ParserManage::Manage_IDList_Empty(yylineno, &((yyval.AST)), &fabpa);	}
    break;

  case 106:

    {	SIN::ParserManage::Manage_IDList(yylineno, (yyvsp[(2) - (3)].stringV), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 107:

    {	SIN::ParserManage::Manage_IDList_Empty(yylineno, &((yyval.AST)), &fabpa);	}
    break;

  case 108:

    {	SIN::ParserManage::Manage_IfStatement_If(yylineno, (yyvsp[(3) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 109:

    {	SIN::ParserManage::Manage_IfStatement_IfElse(yylineno, (yyvsp[(3) - (7)].AST), (yyvsp[(5) - (7)].AST), (yyvsp[(7) - (7)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 110:

    {	++fabpa.parsingCounters.loops;												}
    break;

  case 111:

    {	SIN::ParserManage::Manage_WhileStatement(yylineno, (yyvsp[(4) - (6)].AST), (yyvsp[(6) - (6)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 112:

    {	++fabpa.parsingCounters.loops;														}
    break;

  case 113:

    {	SIN::ParserManage::Manage_ForStatement(yylineno, (yyvsp[(4) - (10)].AST), (yyvsp[(6) - (10)].AST), (yyvsp[(8) - (10)].AST), (yyvsp[(10) - (10)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 114:

    {	SIN::ParserManage::Manage_ReturnStatement_Return(yylineno, &((yyval.AST)), &fabpa);					}
    break;

  case 115:

    {	SIN::ParserManage::Manage_ReturnStatement_ReturnExpression(yylineno, (yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
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
      yyerror (fabpa, YY_("syntax error"));
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
	    yyerror (fabpa, yymsg);
	  }
	else
	  {
	    yyerror (fabpa, YY_("syntax error"));
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
		      yytoken, &yylval, fabpa);
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
		  yystos[yystate], yyvsp, fabpa);
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
  yyerror (fabpa, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, fabpa);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, fabpa);
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





int yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage)
{
	//fprintf(stderr, "%s: at line %d, before token: >%s<\n", yaccProvidedMessage, yylineno, yytext);
	SIN::String error = SIN::String() << yaccProvidedMessage;
	
	if (*yytext == 0)
		error << " maybe missing ';'";
	else
		error << ", before token: " << yytext;
	fabpa.SetError(std::make_pair(error, yylineno));
	return 1;
}


int PrepareForFile(const char * filePath) {
	assert (filePath);
	if (!(yyin = fopen(filePath, "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", filePath);
			return 1;
	}
	return 0;
}
