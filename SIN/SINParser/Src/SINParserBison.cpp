
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
	#define MESSAGE(STR)	fabpa.WriteFine(#STR " destructed")



	////////////////////////////////////////////////////////////////////////
	// functions definitions
	
	void yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage);
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
     DOT_KEYS_MEMBER = 299,
     DOT_SIZE_MEMBER = 300,
     KEYS_MEMBER = 301,
     SIZE_MEMBER = 302,
     UMINUS = 303
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
#define DOT_KEYS_MEMBER 299
#define DOT_SIZE_MEMBER 300
#define KEYS_MEMBER 301
#define SIZE_MEMBER 302
#define UMINUS 303




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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    18,     2,     2,     2,     2,
      10,    11,     2,     2,    14,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    13,    12,
       2,     2,     2,     2,    17,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     6,     2,     7,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     8,     2,     9,    15,     2,     2,     2,
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
       5,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    23,    26,    28,    30,    32,    34,    36,    40,    44,
      48,    52,    56,    60,    64,    68,    72,    76,    80,    84,
      88,    90,    93,    95,    99,   104,   107,   110,   113,   116,
     120,   123,   126,   129,   132,   135,   138,   140,   144,   146,
     148,   150,   154,   156,   158,   161,   164,   166,   170,   174,
     178,   183,   187,   192,   195,   198,   205,   207,   209,   213,
     219,   222,   223,   227,   228,   231,   235,   238,   243,   246,
     250,   256,   260,   261,   262,   267,   270,   271,   278,   284,
     291,   297,   299,   301,   303,   305,   307,   310,   311,   315,
     316,   322,   330,   336,   346,   349
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    -1,    65,    64,    -1,    -1,    66,
      12,    -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,
      27,    12,    -1,    28,    12,    -1,    82,    -1,    86,    -1,
      12,    -1,     1,    -1,    69,    -1,    66,    35,    66,    -1,
      66,    36,    66,    -1,    66,    37,    66,    -1,    66,    38,
      66,    -1,    66,    39,    66,    -1,    66,    44,    66,    -1,
      66,    46,    66,    -1,    66,    45,    66,    -1,    66,    47,
      66,    -1,    66,    40,    66,    -1,    66,    41,    66,    -1,
      66,    48,    66,    -1,    66,    49,    66,    -1,    67,    -1,
      56,    67,    -1,    68,    -1,    51,    66,    52,    -1,    53,
      10,    66,    11,    -1,    53,     4,    -1,    53,    73,    -1,
      54,    67,    -1,    55,     5,    -1,    10,    66,    11,    -1,
      36,    66,    -1,    50,    66,    -1,    42,    71,    -1,    71,
      42,    -1,    43,    71,    -1,    71,    43,    -1,    70,    -1,
      71,    34,    66,    -1,    71,    -1,    73,    -1,    79,    -1,
      10,    86,    11,    -1,    87,    -1,     4,    -1,    29,     4,
      -1,    30,     4,    -1,    72,    -1,    71,    19,     4,    -1,
      71,    19,    59,    -1,    71,    19,    60,    -1,    71,     6,
      66,     7,    -1,    73,    19,     4,    -1,    73,     6,    66,
       7,    -1,    73,    74,    -1,    71,    74,    -1,    10,    86,
      11,    10,    77,    11,    -1,    75,    -1,    76,    -1,    10,
      77,    11,    -1,    20,     4,    10,    77,    11,    -1,    66,
      78,    -1,    -1,    14,    66,    78,    -1,    -1,     6,     7,
      -1,     6,    80,     7,    -1,    66,    81,    -1,    66,    13,
      66,    81,    -1,    86,    81,    -1,    14,    66,    81,    -1,
      14,    66,    13,    66,    81,    -1,    14,    85,    81,    -1,
      -1,    -1,     8,    83,    84,     9,    -1,    65,    84,    -1,
      -1,    25,     4,    10,    88,    11,    82,    -1,    25,    10,
      88,    11,    82,    -1,    25,     4,    10,    88,    11,    82,
      -1,    25,    10,    88,    11,    82,    -1,     3,    -1,     5,
      -1,    33,    -1,    31,    -1,    32,    -1,     4,    89,    -1,
      -1,    14,     4,    89,    -1,    -1,    21,    10,    66,    11,
      65,    -1,    21,    10,    66,    11,    65,    22,    65,    -1,
      23,    10,    66,    11,    65,    -1,    24,    10,    77,    12,
      66,    12,    77,    11,    65,    -1,    26,    12,    -1,    26,
      66,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   150,   151,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   192,   193,   194,   195,   196,   197,   202,
     203,   204,   205,   206,   207,   208,   209,   214,   219,   220,
     221,   222,   223,   228,   229,   230,   231,   236,   237,   238,
     239,   240,   241,   247,   248,   249,   254,   255,   260,   265,
     270,   271,   276,   277,   282,   283,   288,   289,   290,   295,
     296,   297,   298,   303,   303,   308,   309,   312,   313,   317,
     318,   322,   323,   324,   325,   326,   330,   331,   336,   337,
     342,   343,   346,   349,   352,   353
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STRING", "'['", "']'",
  "'{'", "'}'", "'('", "')'", "';'", "':'", "','", "'~'", "'!'", "'@'",
  "'#'", "DOT", "DOUBLEDOT", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "BREAK", "CONTINUE", "LOCAL", "GLOBAL", "TRUE", "FALSE", "NIL",
  "ASSIGN", "ADD", "MIN", "MUL", "DIV", "MOD", "EQ", "NOTEQ", "INCR",
  "DECR", "GT", "LT", "GE", "LE", "AND", "OR", "NOT", "DOT_LT", "GT_DOT",
  "DOT_TILDE", "DOT_EXCl_MARK", "DOT_AT", "DOT_HASH", "DOT_KEYS_MEMBER",
  "DOT_SIZE_MEMBER", "KEYS_MEMBER", "SIZE_MEMBER", "UMINUS", "$accept",
  "SinCode", "stmts", "stmt", "expr", "metaexpr", "term", "assignexpr",
  "primary", "lvalue", "member", "call", "callsuffix", "normalcall",
  "methodcall", "elist", "elists", "objectdef", "objectlist",
  "objectlists", "block", "$@1", "stmtd", "objectfuncdef", "funcdef",
  "const", "idlist", "idlists", "ifstmt", "whilestmt", "forstmt",
  "returnstmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,    91,    93,   123,   125,
      40,    41,    59,    58,    44,   126,    33,    64,    35,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    74,    74,    75,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    81,
      81,    81,    81,    83,    82,    84,    84,    85,    85,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    92,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     1,     3,     4,     2,     2,     2,     2,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     3,     3,
       4,     3,     4,     2,     2,     6,     1,     1,     3,     5,
       2,     0,     3,     0,     2,     3,     2,     4,     2,     3,
       5,     3,     0,     0,     4,     2,     0,     6,     5,     6,
       5,     1,     1,     1,     1,     1,     2,     0,     3,     0,
       5,     7,     5,     9,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,    91,    53,    92,     0,    83,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,    30,    32,    16,    46,    48,    56,
      49,    50,    12,    13,    52,     6,     7,     8,     9,    74,
      82,     0,    82,     0,     0,     0,     0,     0,    71,     0,
      97,   104,     0,    10,    11,    54,    55,    40,     0,    42,
       0,    44,    41,     0,    35,     0,     0,    36,    37,    38,
      31,     1,     3,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
       0,     0,    43,    45,    64,    66,    67,     0,     0,    63,
       0,     0,    76,    75,    78,     0,     0,    39,    51,     0,
       0,    73,     0,    97,    99,     0,   105,     0,    33,     0,
      17,    18,    19,    20,    21,    26,    27,    22,    24,    23,
      25,    28,    29,     0,     0,    57,    58,    59,     0,    47,
       0,    61,    82,     0,    82,    82,    85,    84,    71,     0,
       0,     0,    70,     0,     0,     0,    96,     0,     0,    34,
      60,    68,    71,    62,    77,     0,    97,     0,    79,    81,
       0,   100,   102,    73,     0,     0,    99,    90,     0,    97,
       0,    82,    65,     0,    72,    71,    89,    98,    69,     0,
       0,    80,   101,     0,     0,    88,     0,    87,   103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,   104,   105,   106,   122,   162,    41,    51,   112,
      42,    53,   116,   155,    43,    44,   125,   166,    45,    46,
      47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const yytype_int16 yypact[] =
{
     170,  -144,  -144,  -144,  -144,   316,  -144,   350,  -144,    15,
      16,    17,    18,   384,     3,     6,    29,    52,  -144,  -144,
    -144,   452,   100,   100,   452,   452,   109,    44,    55,    44,
      62,  -144,   170,   536,  -144,  -144,  -144,  -144,   145,  -144,
      11,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
     595,    58,    57,   226,   475,    66,   452,   452,   452,    59,
      96,  -144,   551,  -144,  -144,  -144,  -144,  -144,    78,   140,
      11,   140,  -144,   668,   198,   350,   140,    11,  -144,  -144,
    -144,  -144,  -144,  -144,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   452,     8,
     110,   452,  -144,  -144,  -144,  -144,  -144,   452,   111,  -144,
     452,   418,  -144,  -144,  -144,   226,   107,  -144,   108,   490,
     506,   638,   105,    96,   106,   126,  -144,   129,  -144,   521,
      37,    37,  -144,  -144,  -144,   625,   625,   228,   228,   228,
     228,   701,   581,     0,   131,  -144,  -144,  -144,   133,   686,
      87,  -144,   653,    19,   610,    57,  -144,  -144,   452,   282,
     282,   452,  -144,   452,   134,   117,  -144,   136,   108,  -144,
    -144,  -144,   452,  -144,  -144,   137,    96,   452,  -144,  -144,
     138,   130,  -144,   638,   566,   136,   106,  -144,   146,    96,
     150,   653,  -144,   282,  -144,   452,  -144,  -144,  -144,   151,
     136,  -144,  -144,   152,   136,  -144,   282,  -144,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   149,   -52,    -5,     5,  -144,  -144,  -144,   -12,
    -144,    32,   -27,  -144,  -144,   -94,   -17,  -144,  -144,   -43,
    -143,  -144,    53,  -144,    -2,  -144,  -117,    -9,  -144,  -144,
    -144,  -144
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -87
static const yytype_int16 yytable[] =
{
      50,   115,    54,    52,   144,    55,   164,   170,    62,   114,
      69,    71,   145,   109,    76,    63,    67,   107,    64,    72,
      73,    98,    59,   175,   187,    56,    57,    58,    60,   176,
     108,   100,    78,    65,    80,    84,    85,    86,    87,    88,
      89,    90,   196,   109,    91,    92,    93,    94,    95,    96,
     109,   119,   120,   121,    70,    70,    66,   205,    77,   190,
      79,   207,    81,   115,   180,   113,   127,   146,   147,   123,
     129,   111,   199,   127,    86,    87,    88,   118,   188,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   121,   173,    25,   149,    26,    27,    28,
     124,   203,   150,    12,     3,   152,   154,   181,   182,   174,
      68,   178,   179,    74,   148,   151,   157,   163,   158,    75,
     165,   186,    84,    85,    86,    87,    88,    89,    90,    16,
      17,    91,    92,    93,    94,    95,    96,   167,    16,    17,
     168,   202,   171,   172,     6,   185,    97,   189,   201,   192,
      98,    97,   193,   121,   208,    98,   183,   198,   184,    99,
     100,   200,   204,   206,    99,   100,   194,   121,   156,     0,
      -4,     1,   191,     2,     3,     4,     5,   197,     6,   101,
       7,    82,     8,     0,     0,     0,     0,   102,   103,     0,
     121,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   -53,     0,    21,     0,   -53,     0,
       0,     0,    22,    23,     0,     0,     0,   -53,   -53,     0,
      24,    25,     0,    26,    27,    28,    29,     1,     0,     2,
       3,     4,     5,     0,     6,   -86,     7,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,    21,    84,    85,    86,    87,    88,    22,    23,
       0,     0,   -87,   -87,   -87,   -87,    24,    25,     0,    26,
      27,    28,    29,     1,     0,     2,     3,     4,     5,     0,
       6,     0,     7,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,    21,     2,
       3,     4,     5,    49,    22,    23,     7,     0,     0,     0,
       0,     0,    24,    25,     0,    26,    27,    28,    29,     0,
       0,    12,     0,     0,     0,    16,    17,    18,    19,    20,
       0,     0,    21,     2,     3,     4,     5,     0,    22,    23,
       7,     0,     0,     0,     0,     0,    24,    25,     0,    26,
      27,    28,    29,     0,     0,    12,     0,     0,     0,    16,
      17,    18,    19,    20,     0,     0,    21,     2,     3,     4,
       5,     0,    22,    23,     7,     0,    61,     0,     0,     0,
      24,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,    20,     0,     0,
      21,     2,     3,     4,     5,     0,    22,    23,     7,     0,
       0,     0,     0,     0,    24,    25,     0,    26,    27,    28,
      29,     0,     0,   153,     0,     0,     0,    16,    17,    18,
      19,    20,     0,     0,    21,     2,     3,     4,     5,     0,
      22,    23,     7,     0,     0,     0,     0,     0,    24,    25,
       0,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,    16,    17,    18,    19,    20,   117,     0,    21,     0,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
       0,   159,    24,    25,     0,    26,    27,    28,    29,     0,
      84,    85,    86,    87,    88,    89,    90,   160,     0,    91,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,   169,     0,    91,    92,    93,    94,    95,    96,
       0,    84,    85,    86,    87,    88,    89,    90,    83,     0,
      91,    92,    93,    94,    95,    96,    84,    85,    86,    87,
      88,    89,    90,   126,     0,    91,    92,    93,    94,    95,
      96,    84,    85,    86,    87,    88,    89,    90,   195,     0,
      91,    92,    93,    94,    95,    96,    84,    85,    86,    87,
      88,    89,    90,     0,     0,    91,    92,    93,    94,    95,
      96,    84,    85,    86,    87,    88,    89,    90,   110,   111,
      91,    92,    93,    94,    95,    96,    84,    85,    86,    87,
      88,    89,    90,   177,   111,    91,    92,    93,    94,    95,
      84,    85,    86,    87,    88,    89,    90,     0,     0,    91,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,   161,     0,    91,    92,    93,    94,    95,    96,
      84,    85,    86,    87,    88,   -87,   -87,   111,     0,    91,
      92,    93,    94,    84,    85,    86,    87,    88,    89,    90,
       0,     0,    91,    92,    93,    94,    95,    96,    84,    85,
      86,    87,    88,    89,    90,     0,     0,    91,    92,    93,
      94,    95,    96,    84,    85,    86,    87,    88,    89,    90,
       0,     0,    91,    92,    93,    94,    95,    96,     0,     0,
     128,    84,    85,    86,    87,    88,    89,    90,     0,     0,
      91,    92,    93,    94,    95,    96,    84,    85,    86,    87,
      88,    89,    90,     0,     0,    91,    92,    93,    94
};

static const yytype_int16 yycheck[] =
{
       5,    53,     7,     5,    98,     7,   123,     7,    13,    52,
      22,    23,     4,    40,    26,    12,    21,     6,    12,    24,
      25,    10,     4,     4,   167,    10,    10,    10,    10,    10,
      19,    20,    27,     4,    29,    35,    36,    37,    38,    39,
      40,    41,   185,    70,    44,    45,    46,    47,    48,    49,
      77,    56,    57,    58,    22,    23,     4,   200,    26,   176,
       5,   204,     0,   115,   158,     7,    68,    59,    60,    10,
      75,    14,   189,    75,    37,    38,    39,    11,   172,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     7,    51,   101,    53,    54,    55,
       4,   195,   107,    25,     4,   110,   111,   159,   160,   152,
      10,   154,   155,     4,     4,     4,     9,    12,    10,    10,
      14,     4,    35,    36,    37,    38,    39,    40,    41,    29,
      30,    44,    45,    46,    47,    48,    49,    11,    29,    30,
      11,   193,    11,    10,     8,    11,     6,    10,   191,    11,
      10,     6,    22,   158,   206,    10,   161,    11,   163,    19,
      20,    11,    11,    11,    19,    20,   183,   172,   115,    -1,
       0,     1,   177,     3,     4,     5,     6,   186,     8,    34,
      10,    32,    12,    -1,    -1,    -1,    -1,    42,    43,    -1,
     195,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     6,    -1,    36,    -1,    10,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    19,    20,    -1,
      50,    51,    -1,    53,    54,    55,    56,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    35,    36,    37,    38,    39,    42,    43,
      -1,    -1,    44,    45,    46,    47,    50,    51,    -1,    53,
      54,    55,    56,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,     3,
       4,     5,     6,     7,    42,    43,    10,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    53,    54,    55,    56,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    36,     3,     4,     5,     6,    -1,    42,    43,
      10,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,
      54,    55,    56,    -1,    -1,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    36,     3,     4,     5,
       6,    -1,    42,    43,    10,    -1,    12,    -1,    -1,    -1,
      50,    51,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      36,     3,     4,     5,     6,    -1,    42,    43,    10,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    53,    54,    55,
      56,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    36,     3,     4,     5,     6,    -1,
      42,    43,    10,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    11,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    11,    50,    51,    -1,    53,    54,    55,    56,    -1,
      35,    36,    37,    38,    39,    40,    41,    11,    -1,    44,
      45,    46,    47,    48,    49,    35,    36,    37,    38,    39,
      40,    41,    11,    -1,    44,    45,    46,    47,    48,    49,
      -1,    35,    36,    37,    38,    39,    40,    41,    12,    -1,
      44,    45,    46,    47,    48,    49,    35,    36,    37,    38,
      39,    40,    41,    12,    -1,    44,    45,    46,    47,    48,
      49,    35,    36,    37,    38,    39,    40,    41,    12,    -1,
      44,    45,    46,    47,    48,    49,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47,    48,
      49,    35,    36,    37,    38,    39,    40,    41,    13,    14,
      44,    45,    46,    47,    48,    49,    35,    36,    37,    38,
      39,    40,    41,    13,    14,    44,    45,    46,    47,    48,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    49,    35,    36,    37,    38,    39,
      40,    41,    14,    -1,    44,    45,    46,    47,    48,    49,
      35,    36,    37,    38,    39,    40,    41,    14,    -1,    44,
      45,    46,    47,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    45,    46,
      47,    48,    49,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    -1,    -1,
      52,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,    10,    12,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    36,    42,    43,    50,    51,    53,    54,    55,    56,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    79,    82,    86,    87,    90,    91,    92,    93,     7,
      66,    80,    86,    83,    66,    86,    10,    10,    10,     4,
      10,    12,    66,    12,    12,     4,     4,    66,    10,    71,
      73,    71,    66,    66,     4,    10,    71,    73,    67,     5,
      67,     0,    64,    12,    35,    36,    37,    38,    39,    40,
      41,    44,    45,    46,    47,    48,    49,     6,    10,    19,
      20,    34,    42,    43,    74,    75,    76,     6,    19,    74,
      13,    14,    81,     7,    81,    65,    84,    11,    11,    66,
      66,    66,    77,    10,     4,    88,    12,    86,    52,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    77,     4,    59,    60,     4,    66,
      66,     4,    66,    25,    66,    85,    84,     9,    10,    11,
      11,    14,    78,    12,    88,    14,    89,    11,    11,    11,
       7,    11,    10,     7,    81,     4,    10,    13,    81,    81,
      77,    65,    65,    66,    66,    11,     4,    82,    77,    10,
      88,    66,    11,    22,    78,    12,    82,    89,    11,    88,
      11,    81,    65,    77,    11,    82,    11,    82,    65
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
							SIN::ParserManage::Manage_SinCode((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	
							fabpa.SetRoot((yyval.AST));
						}
    break;

  case 3:

    {	SIN::ParserManage::Manage_Statements((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 4:

    {	SIN::ParserManage::Manage_Statements_Empty(&((yyval.AST)), &fabpa);		}
    break;

  case 5:

    {	SIN::ParserManage::Manage_Statement_Expression((yyvsp[(1) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 6:

    {	SIN::ParserManage::Manage_Statement_IfStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 7:

    {	SIN::ParserManage::Manage_Statement_WhileStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 8:

    {	SIN::ParserManage::Manage_Statement_ForStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 9:

    {	SIN::ParserManage::Manage_Statement_ReturnStatement((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 10:

    {	SIN::ParserManage::Manage_Statement_Break(&((yyval.AST)), &fabpa);					}
    break;

  case 11:

    {	SIN::ParserManage::Manage_Statement_Continue(&((yyval.AST)), &fabpa);				}
    break;

  case 12:

    {	SIN::ParserManage::Manage_Statement_Block((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 13:

    {	SIN::ParserManage::Manage_Statement_FunctionDefinition((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 14:

    {	SIN::ParserManage::Manage_Statement_Semicolon(&((yyval.AST)), &fabpa);				}
    break;

  case 15:

    {	SIN::ParserManage::Manage_Statement_Error(&((yyval.AST)), &fabpa);		yyclearin;	}
    break;

  case 16:

    {	SIN::ParserManage::Manage_Expression_AssignExpression((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 17:

    {	SIN::ParserManage::Manage_Expression_ExpressionADDExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 18:

    {	SIN::ParserManage::Manage_Expression_ExpressionMINExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 19:

    {	SIN::ParserManage::Manage_Expression_ExpressionMULExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 20:

    {	SIN::ParserManage::Manage_Expression_ExpressionDIVExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 21:

    {	SIN::ParserManage::Manage_Expression_ExpressionMODExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 22:

    {	SIN::ParserManage::Manage_Expression_ExpressionGTExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 23:

    {	SIN::ParserManage::Manage_Expression_ExpressionGEExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 24:

    {	SIN::ParserManage::Manage_Expression_ExpressionLTExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 25:

    {	SIN::ParserManage::Manage_Expression_ExpressionLEExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 26:

    {	SIN::ParserManage::Manage_Expression_ExpressionEQExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 27:

    {	SIN::ParserManage::Manage_Expression_ExpressionNOTEQExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 28:

    {	SIN::ParserManage::Manage_Expression_ExpressionANDExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 29:

    {	SIN::ParserManage::Manage_Expression_ExpressionORExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 30:

    {	SIN::ParserManage::Manage_Expression_MetaExpression((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 31:

    {	SIN::ParserManage::Manage_Expression_UnparseMetaExpression((yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 32:

    {	SIN::ParserManage::Manage_Expression_Term((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);							}
    break;

  case 33:

    {	SIN::ParserManage::Manage_MetaExpression_ShiftToMetaExpression((yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 34:

    {}
    break;

  case 35:

    {	SIN::ParserManage::Manage_MetaExpression_PreserveAST_ID((yyvsp[(2) - (2)].stringV), &((yyval.AST)), &fabpa);			}
    break;

  case 36:

    {}
    break;

  case 37:

    {	SIN::ParserManage::Manage_MetaExpression_CompileMetaExpression((yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 38:

    {	SIN::ParserManage::Manage_MetaExpression_ParseString((yyvsp[(2) - (2)].stringV), &((yyval.AST)), &fabpa);			}
    break;

  case 39:

    {	SIN::ParserManage::Manage_Term_ExpressionParentheses((yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 40:

    {	SIN::ParserManage::Manage_Term_MINExpression((yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 41:

    {	SIN::ParserManage::Manage_Term_NOTExpression((yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 42:

    {	SIN::ParserManage::Manage_Term_INCRLValue((yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 43:

    {	SIN::ParserManage::Manage_Term_LValueINCR((yyvsp[(1) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 44:

    {	SIN::ParserManage::Manage_Term_DECRLValue((yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 45:

    {	SIN::ParserManage::Manage_Term_LValueDECR((yyvsp[(1) - (2)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 46:

    {	SIN::ParserManage::Manage_Term_Primary((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 47:

    {	SIN::ParserManage::Manage_AssignExpression((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 48:

    {	SIN::ParserManage::Manage_Primary_LValue((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);						}
    break;

  case 49:

    {	SIN::ParserManage::Manage_Primary_Call((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);							}
    break;

  case 50:

    {	SIN::ParserManage::Manage_Primary_ObjectDefinition((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);				}
    break;

  case 51:

    {	SIN::ParserManage::Manage_Primary_FunctionDefinitionParentheses((yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 52:

    {	SIN::ParserManage::Manage_Primary_Constant((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);						}
    break;

  case 53:

    {	SIN::ParserManage::Manage_LValue_ID((yyvsp[(1) - (1)].stringV), &((yyval.AST)), &fabpa);			}
    break;

  case 54:

    {	SIN::ParserManage::Manage_LValue_LocalID((yyvsp[(2) - (2)].stringV), &((yyval.AST)), &fabpa);	}
    break;

  case 55:

    {	SIN::ParserManage::Manage_LValue_GlobalID((yyvsp[(2) - (2)].stringV), &((yyval.AST)), &fabpa);	}
    break;

  case 56:

    {	SIN::ParserManage::Manage_LValue_Member((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 57:

    {	SIN::ParserManage::Manage_Member_LValueID((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].stringV), &((yyval.AST)), &fabpa);			}
    break;

  case 58:

    {	}
    break;

  case 59:

    {	}
    break;

  case 60:

    {	SIN::ParserManage::Manage_Member_LValueExpression((yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 61:

    {	SIN::ParserManage::Manage_Member_CallID((yyvsp[(1) - (3)].AST), (yyvsp[(3) - (3)].stringV), &((yyval.AST)), &fabpa);				}
    break;

  case 62:

    {	SIN::ParserManage::Manage_Member_CallExpression((yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), &((yyval.AST)), &fabpa);		}
    break;

  case 63:

    {	SIN::ParserManage::Manage_Call_CallCallSuffix((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 64:

    {	SIN::ParserManage::Manage_Call_LValueCallSuffix((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 65:

    {	SIN::ParserManage::Manage_Call_FunctionDefinitionExpressionList((yyvsp[(2) - (6)].AST), (yyvsp[(5) - (6)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 66:

    {	SIN::ParserManage::Manage_CallSuffix_NormalCall((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 67:

    {	SIN::ParserManage::Manage_CallSuffix_MethodCall((yyvsp[(1) - (1)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 68:

    {	SIN::ParserManage::Manage_NormalCall((yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 69:

    {	SIN::ParserManage::Manage_MethodCall((yyvsp[(2) - (5)].stringV), (yyvsp[(4) - (5)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 70:

    {	SIN::ParserManage::Manage_ExpressionList((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 71:

    {	SIN::ParserManage::Manage_ExpressionList_Empty(&((yyval.AST)), &fabpa);		}
    break;

  case 72:

    {	SIN::ParserManage::Manage_ExpressionList((yyvsp[(2) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 73:

    {	SIN::ParserManage::Manage_ExpressionList_Empty(&((yyval.AST)), &fabpa);		}
    break;

  case 74:

    {	SIN::ParserManage::Manage_ObjectDefinition_EmptyObject(&((yyval.AST)), &fabpa);		}
    break;

  case 75:

    {	SIN::ParserManage::Manage_ObjectDefinition_ObjectList((yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 76:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 77:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists((yyvsp[(1) - (4)].AST), (yyvsp[(3) - (4)].AST), (yyvsp[(4) - (4)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 78:

    {}
    break;

  case 79:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionObjectLists((yyvsp[(2) - (3)].AST), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);					}
    break;

  case 80:

    {	SIN::ParserManage::Manage_ObjectList_ExpressionExpressionObjectLists((yyvsp[(2) - (5)].AST), (yyvsp[(4) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 81:

    {}
    break;

  case 82:

    {	SIN::ParserManage::Manage_ObjectList_Empty(&((yyval.AST)), &fabpa);											}
    break;

  case 83:

    {}
    break;

  case 84:

    {	SIN::ParserManage::Manage_Block((yyvsp[(3) - (4)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 85:

    {	SIN::ParserManage::Manage_Statements((yyvsp[(1) - (2)].AST), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 86:

    {	SIN::ParserManage::Manage_Statements_Empty(&((yyval.AST)), &fabpa);		}
    break;

  case 87:

    {}
    break;

  case 88:

    {}
    break;

  case 89:

    {	SIN::ParserManage::Manage_FunctionDefinition_Function((yyvsp[(2) - (6)].stringV), (yyvsp[(4) - (6)].AST), (yyvsp[(6) - (6)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 90:

    {	SIN::ParserManage::Manage_FunctionDefinition_LamdaFunction((yyvsp[(3) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 91:

    {	SIN::ParserManage::Manage_Constant_Number(atof(yytext), &((yyval.AST)), &fabpa);	}
    break;

  case 92:

    {	SIN::ParserManage::Manage_Constant_String((yyvsp[(1) - (1)].stringV), &((yyval.AST)), &fabpa);			}
    break;

  case 93:

    {	SIN::ParserManage::Manage_Constant_Nil(&((yyval.AST)), &fabpa);					}
    break;

  case 94:

    {	SIN::ParserManage::Manage_Constant_True(&((yyval.AST)), &fabpa);					}
    break;

  case 95:

    {	SIN::ParserManage::Manage_Constant_False(&((yyval.AST)), &fabpa);				}
    break;

  case 96:

    {	SIN::ParserManage::Manage_IDList((yyvsp[(1) - (2)].stringV), (yyvsp[(2) - (2)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 97:

    {	SIN::ParserManage::Manage_IDList_Empty(&((yyval.AST)), &fabpa);		}
    break;

  case 98:

    {	SIN::ParserManage::Manage_IDList((yyvsp[(2) - (3)].stringV), (yyvsp[(3) - (3)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 99:

    {	SIN::ParserManage::Manage_IDList_Empty(&((yyval.AST)), &fabpa);		}
    break;

  case 100:

    {	SIN::ParserManage::Manage_IfStatement_If((yyvsp[(3) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)), &fabpa);			}
    break;

  case 101:

    {	SIN::ParserManage::Manage_IfStatement_IfElse((yyvsp[(3) - (7)].AST), (yyvsp[(5) - (7)].AST), (yyvsp[(7) - (7)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 102:

    {	SIN::ParserManage::Manage_WhileStatement((yyvsp[(3) - (5)].AST), (yyvsp[(5) - (5)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 103:

    {	SIN::ParserManage::Manage_ForStatement((yyvsp[(3) - (9)].AST), (yyvsp[(5) - (9)].AST), (yyvsp[(7) - (9)].AST), (yyvsp[(9) - (9)].AST), &((yyval.AST)), &fabpa);	}
    break;

  case 104:

    {	SIN::ParserManage::Manage_ReturnStatement_Return(&((yyval.AST)), &fabpa);				}
    break;

  case 105:

    {	SIN::ParserManage::Manage_ReturnStatement_ReturnExpression((yyvsp[(2) - (3)].AST), &((yyval.AST)), &fabpa);	}
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





void yyerror (SIN::LexAndBisonParseArguments & fabpa, char const* yaccProvidedMessage)
{
	//fprintf(stderr, "%s: at line %d, before token: >%s<\n", yaccProvidedMessage, yylineno, yytext);
	SIN::String error = SIN::String() << yaccProvidedMessage;
	
	if (*yytext == 0)
		error << " maybe missing ';'";
	else
		error << ", before token: " << yytext;
	fabpa.SetError(std::make_pair(error, yylineno));
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
//	//yy_scan_string(const char * str);
	return 0;
}

