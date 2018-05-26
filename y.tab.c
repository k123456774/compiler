/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "test.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Trace(t)  {if(Opt_P) printf(t);}
int Opt_P = 1;


int symtab_counter;
int current_symtab;
int symtab_pre[100];
int id_num[100];
struct node* ids[100][46];

void create(int,int);
int insert(char*,int,int,float);
int lookup(char*,int);
void update_value(char*,int,float);
float get_value(char*,int);
int   get_type(char*,int);
int   check_in_scope(char*,int);

int yylex();
int yyerror(const char*);



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
/* Line 193 of yacc.c.  */
#line 236 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 249 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    35,    59,     2,
      24,    25,    32,    30,    21,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,    23,
      62,    34,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,    58,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    63,    64,
      65,    66,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    17,    25,    30,    35,
      36,    42,    43,    46,    47,    49,    51,    53,    55,    59,
      66,    69,    71,    73,    77,    81,    85,    89,    93,    97,
     101,   104,   108,   110,   112,   118,   122,   126,   127,   131,
     135,   139,   142,   144,   148,   152,   155,   159,   163,   167,
     171,   175,   179,   182,   183,   185,   187,   189,   195,   200,
     206,   214,   219,   222,   227,   234,   243,   245,   247,   249,
     251,   253,   255,   257,   259,   261,   262,   268,   270,   272,
     280,   286
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    84,    71,    -1,    72,    71,    -1,    -1,
       8,     7,    24,    74,    25,    73,    -1,    31,    61,    90,
      26,    84,    76,    27,    -1,    26,    84,    76,    27,    -1,
       7,    22,    90,    75,    -1,    -1,    21,     7,    22,    90,
      75,    -1,    -1,    77,    76,    -1,    -1,    79,    -1,    78,
      -1,    94,    -1,    95,    -1,     7,    34,    79,    -1,     7,
      28,     4,    29,    34,    79,    -1,    20,    79,    -1,    20,
      -1,    80,    -1,     7,    34,    80,    -1,    79,    30,    79,
      -1,    79,    31,    79,    -1,    79,    32,    79,    -1,    79,
      33,    79,    -1,    79,    35,    79,    -1,    79,    67,    79,
      -1,    31,    79,    -1,    24,    79,    25,    -1,     7,    -1,
      89,    -1,     7,    24,    79,    81,    25,    -1,     7,    24,
      25,    -1,    21,    79,    81,    -1,    -1,    24,    82,    25,
      -1,    82,    59,    82,    -1,    82,    58,    82,    -1,    60,
      82,    -1,    83,    -1,    79,    58,    79,    -1,    79,    59,
      79,    -1,    60,    79,    -1,    79,    66,    79,    -1,    79,
      64,    79,    -1,    79,    63,    79,    -1,    79,    65,    79,
      -1,    79,    61,    79,    -1,    79,    62,    79,    -1,    85,
      84,    -1,    -1,    86,    -1,    87,    -1,    88,    -1,    11,
       9,     7,    34,    89,    -1,    11,     9,     7,    23,    -1,
      11,     9,     7,    22,    90,    -1,    11,     9,     7,    22,
      90,    34,    89,    -1,    11,     7,    34,    89,    -1,    11,
       7,    -1,    11,     7,    22,    90,    -1,    11,     7,    22,
      90,    34,    89,    -1,    11,     9,     7,    28,    90,    21,
       4,    29,    -1,     6,    -1,     4,    -1,     5,    -1,    45,
      -1,    46,    -1,    14,    -1,    12,    -1,    16,    -1,    13,
      -1,    -1,    26,    92,    84,    76,    27,    -1,    91,    -1,
      78,    -1,    40,    24,    82,    25,    93,    41,    93,    -1,
      40,    24,    82,    25,    93,    -1,    48,    24,    82,    25,
      93,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    95,    96,    99,   104,   107,   111,   112,
     115,   116,   119,   120,   123,   124,   125,   126,   129,   143,
     144,   145,   146,   147,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   166,   169,   170,   173,   174,   177,   178,
     179,   180,   181,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   199,   200,   203,   204,   205,   208,   211,   214,
     217,   225,   228,   231,   234,   241,   245,   246,   247,   248,
     249,   252,   253,   254,   255,   262,   261,   267,   268,   271,
     272,   275
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "integer", "float_",
  "string", "id_name", "FUNC", "MUT", "STRUCT", "LET", "INTEGER", "BOOL",
  "STRING", "CHAR", "FLOAT", "ENUM", "EXTERN", "MATCH", "RETURN", "','",
  "':'", "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'+'", "'-'",
  "'*'", "'/'", "'='", "'%'", "Plus_on", "Minus_on", "Multi_on",
  "Divide_on", "IF", "ELSE", "BREAK", "CONTINUE", "IN", "TRUE", "FALSE",
  "FOR", "WHILE", "DO", "LOOP", "PRINT", "PRINTLN", "PUB", "SELF",
  "STATIC", "USE", "WHERE", "'||'", "'&&'", "'!'", "'>'", "'<'", "SE",
  "GE", "NE", "E", "'^'", "UMINUS", "$accept", "program",
  "func_declarations", "func_declaration", "example", "formal_arguments",
  "next_argument", "statements", "statement", "simple_statement",
  "expression", "func_invocation", "more_expression", "bool_exps",
  "bool_exp", "declarations", "declaration", "var_declaration",
  "const_declaration", "array_declaration", "constant_exp", "type",
  "compound", "@1", "simple_or_compound", "condition", "loop", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    44,    58,    59,    40,    41,   123,   125,    91,    93,
      43,    45,    42,    47,    61,    37,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   124,    38,
      33,    62,    60,   298,   299,   300,   301,    94,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    85,    85,    85,    86,    86,    86,
      86,    87,    87,    87,    87,    88,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    92,    91,    93,    93,    94,
      94,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     7,     4,     4,     0,
       5,     0,     2,     0,     1,     1,     1,     1,     3,     6,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     5,     3,     3,     0,     3,     3,
       3,     2,     1,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     2,     0,     1,     1,     1,     5,     4,     5,
       7,     4,     2,     4,     6,     8,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     1,     1,     7,
       5,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      53,     0,     0,     4,    53,    54,    55,    56,    62,     0,
       1,     0,     2,     4,    52,     0,     0,     0,     0,     3,
      72,    74,    71,    73,    63,    67,    68,    66,    69,    70,
      61,     0,    58,     0,     0,     9,     0,    59,     0,    57,
       0,     0,    64,     0,     0,     0,     0,    60,     0,    11,
      53,     0,     5,    65,     0,     8,    13,     0,     0,    32,
      21,     0,     0,     0,     0,     0,    13,    15,    14,    22,
      33,    16,    17,     0,     0,     0,     0,     0,    32,    20,
       0,    30,     0,     0,     7,    12,     0,     0,     0,     0,
       0,     0,    53,    11,    35,    37,     0,    32,    18,    23,
      31,     0,     0,     0,     0,    42,     0,    24,    25,    26,
      27,    28,    29,    13,    10,     0,     0,     0,     0,     0,
      45,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    34,     0,    38,    43,
      44,    50,    51,    48,    47,    49,    46,     0,    75,    78,
      77,    80,    40,    39,    81,     6,    36,    19,    53,     0,
      13,    79,     0,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,    13,    52,    41,    55,    65,    66,    67,
      68,    69,   116,   104,   105,     3,     4,     5,     6,     7,
      70,    24,   150,   158,   151,    71,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
      30,    -2,    15,    19,    30,  -123,  -123,  -123,   -16,    44,
    -123,    51,  -123,    19,  -123,   180,     4,   175,    35,  -123,
    -123,  -123,  -123,  -123,    26,  -123,  -123,  -123,  -123,  -123,
    -123,   180,  -123,   180,     4,    65,     4,    47,    77,  -123,
      78,    74,  -123,     4,    97,   180,   142,  -123,    80,    90,
      30,    59,  -123,  -123,   115,  -123,    86,   180,   101,    11,
     154,   154,   154,   100,   109,    98,    86,  -123,   139,  -123,
    -123,  -123,  -123,   114,   180,   131,   147,   159,  -123,   139,
      72,  -123,    16,    16,  -123,  -123,   154,   154,   154,   154,
     154,   154,    30,    90,  -123,    54,   128,   119,   139,  -123,
    -123,    16,    16,   149,    69,  -123,    71,    45,    45,   108,
     108,   108,  -123,    86,  -123,   154,   170,   133,    83,    94,
     156,  -123,   154,   154,   154,   154,   154,   154,   154,   154,
     217,    16,    16,   217,   174,    54,  -123,   154,  -123,   139,
     139,   139,   139,   139,   139,   139,   139,    11,  -123,  -123,
    -123,   161,   166,  -123,  -123,  -123,  -123,   139,    30,   217,
      86,  -123,   199,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,   214,  -123,  -123,  -123,   135,   -65,  -123,  -117,
     -58,   152,    95,   -49,  -123,    -4,  -123,  -123,  -123,  -123,
      20,   -19,  -123,  -123,  -122,  -123,  -123
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    85,    79,    80,    81,     8,    15,     9,    25,    26,
      27,   154,    37,   149,    38,    10,   149,    95,    16,    98,
      25,    26,    27,    78,   103,   103,    49,    11,   107,   108,
     109,   110,   111,   112,   106,    75,    30,   161,    73,    76,
     101,     1,   149,   118,   120,    77,    56,    62,   134,    28,
      29,    17,   119,   121,    39,    93,    42,   135,    18,    35,
      36,    28,    29,    47,   139,   140,   141,   142,   143,   144,
     145,   146,    40,   103,   103,   115,   102,    88,    89,   157,
      90,    43,   152,   153,    86,    87,    88,    89,   113,    90,
      25,    26,    27,    59,   130,   162,   133,   100,    44,    46,
      45,    48,    86,    87,    88,    89,    60,    90,   100,    53,
      61,    54,    91,    86,    87,    88,    89,    62,    90,   138,
      57,    91,    58,    74,    82,    84,    63,   131,   132,   131,
     132,    28,    29,    83,    64,    25,    26,    27,    78,    91,
      92,   122,   123,    75,   124,   125,   126,   127,   128,   129,
      91,    96,   131,   132,   160,    61,    94,   117,    25,    26,
      27,    78,    62,    25,    26,    27,    97,   137,    50,    86,
      87,    88,    89,    51,    90,    91,    28,    29,    61,    86,
      87,    88,    89,    61,    90,    62,    86,    87,    88,    89,
      62,    90,    20,    21,    22,   136,    23,    31,    32,    28,
      29,   155,   159,    33,    28,    29,    91,   122,   123,    34,
     124,   125,   126,   127,   128,   129,    91,   124,   125,   126,
     127,   128,   129,    91,   147,   132,   163,    19,   114,    99,
     156,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,   148
};

static const yytype_int16 yycheck[] =
{
       4,    66,    60,    61,    62,     7,    22,     9,     4,     5,
       6,   133,    31,   130,    33,     0,   133,    75,    34,    77,
       4,     5,     6,     7,    82,    83,    45,     8,    86,    87,
      88,    89,    90,    91,    83,    24,    16,   159,    57,    28,
      24,    11,   159,   101,   102,    34,    50,    31,   113,    45,
      46,     7,   101,   102,    34,    74,    36,   115,     7,    24,
      34,    45,    46,    43,   122,   123,   124,   125,   126,   127,
     128,   129,     7,   131,   132,    21,    60,    32,    33,   137,
      35,    34,   131,   132,    30,    31,    32,    33,    92,    35,
       4,     5,     6,     7,    25,   160,    25,    25,    21,    25,
      22,     4,    30,    31,    32,    33,    20,    35,    25,    29,
      24,    21,    67,    30,    31,    32,    33,    31,    35,    25,
      61,    67,     7,    22,    24,    27,    40,    58,    59,    58,
      59,    45,    46,    24,    48,     4,     5,     6,     7,    67,
      26,    58,    59,    24,    61,    62,    63,    64,    65,    66,
      67,     4,    58,    59,   158,    24,    25,    29,     4,     5,
       6,     7,    31,     4,     5,     6,     7,    34,    26,    30,
      31,    32,    33,    31,    35,    67,    45,    46,    24,    30,
      31,    32,    33,    24,    35,    31,    30,    31,    32,    33,
      31,    35,    12,    13,    14,    25,    16,    22,    23,    45,
      46,    27,    41,    28,    45,    46,    67,    58,    59,    34,
      61,    62,    63,    64,    65,    66,    67,    61,    62,    63,
      64,    65,    66,    67,     7,    59,    27,    13,    93,    77,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    70,    84,    85,    86,    87,    88,     7,     9,
       0,     8,    71,    72,    84,    22,    34,     7,     7,    71,
      12,    13,    14,    16,    90,     4,     5,     6,    45,    46,
      89,    22,    23,    28,    34,    24,    34,    90,    90,    89,
       7,    74,    89,    34,    21,    22,    25,    89,     4,    90,
      26,    31,    73,    29,    21,    75,    84,    61,     7,     7,
      20,    24,    31,    40,    48,    76,    77,    78,    79,    80,
      89,    94,    95,    90,    22,    24,    28,    34,     7,    79,
      79,    79,    24,    24,    27,    76,    30,    31,    32,    33,
      35,    67,    26,    90,    25,    79,     4,     7,    79,    80,
      25,    24,    60,    79,    82,    83,    82,    79,    79,    79,
      79,    79,    79,    84,    75,    21,    81,    29,    79,    82,
      79,    82,    58,    59,    61,    62,    63,    64,    65,    66,
      25,    58,    59,    25,    76,    79,    25,    34,    25,    79,
      79,    79,    79,    79,    79,    79,    79,     7,    26,    78,
      91,    93,    82,    82,    93,    27,    81,    79,    92,    41,
      84,    93,    76,    27
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 89 "test.y"
    {Trace("Reduce program OK!\n");}
    break;

  case 5:
#line 100 "test.y"
    { insert((yyvsp[(2) - (6)].id_value.name),current_symtab,0,0);create(symtab_counter,current_symtab); current_symtab=symtab_counter;symtab_counter+=1;}
    break;

  case 6:
#line 105 "test.y"
    { if(current_symtab!=0) current_symtab=symtab_pre[current_symtab];}
    break;

  case 7:
#line 108 "test.y"
    { if(current_symtab!=0) current_symtab=symtab_pre[current_symtab];}
    break;

  case 8:
#line 111 "test.y"
    {insert((yyvsp[(1) - (4)].id_value.name),current_symtab,(yyvsp[(3) - (4)].type),0);}
    break;

  case 10:
#line 115 "test.y"
    {insert((yyvsp[(2) - (5)].id_value.name),current_symtab,(yyvsp[(4) - (5)].type),0);}
    break;

  case 18:
#line 129 "test.y"
    {  if(check_in_scope((yyvsp[(1) - (3)].id_value.name),current_symtab)==-1){yyerror("ERROR : id is not in scope");}
                                          else{
                                                int i;
                                                i=current_symtab;
                                                while(lookup((yyvsp[(1) - (3)].id_value.name),i)==-1){i=symtab_pre[i];}
                                                (yyvsp[(1) - (3)].id_value.type)=get_type((yyvsp[(1) - (3)].id_value.name),i);
                                                if( ((yyvsp[(1) - (3)].id_value.type)==(yyvsp[(3) - (3)].value.type)) || ((yyvsp[(1) - (3)].type)==2 && (yyvsp[(3) - (3)].value.type)==1))
                                                    {
                                                        update_value((yyvsp[(1) - (3)].id_value.name),i,(yyvsp[(3) - (3)].value.fval));
                                                        printf("Update %s = %g\n",(yyvsp[(1) - (3)].id_value.name),(yyvsp[(3) - (3)].value.fval));
                                                    }
                                                else{ yyerror("ERROR : id assignment type error"); printf("%d=%d\n",(yyvsp[(1) - (3)].id_value.type),(yyvsp[(3) - (3)].value.type));}
                                            }
                                        }
    break;

  case 19:
#line 143 "test.y"
    {if(check_in_scope((yyvsp[(1) - (6)].id_value.name),current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
    break;

  case 23:
#line 147 "test.y"
    {if(check_in_scope((yyvsp[(1) - (3)].id_value.name),current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
    break;

  case 24:
#line 150 "test.y"
    {(yyval.value)=(yyvsp[(1) - (3)].value); (yyval.value.fval) = (yyvsp[(1) - (3)].value.fval)+(yyvsp[(3) - (3)].value.fval);}
    break;

  case 25:
#line 151 "test.y"
    {(yyval.value)=(yyvsp[(1) - (3)].value); (yyval.value.fval) = (yyvsp[(1) - (3)].value.fval)-(yyvsp[(3) - (3)].value.fval);}
    break;

  case 26:
#line 152 "test.y"
    {(yyval.value)=(yyvsp[(1) - (3)].value); (yyval.value.fval) = (yyvsp[(1) - (3)].value.fval)*(yyvsp[(3) - (3)].value.fval);}
    break;

  case 27:
#line 153 "test.y"
    {(yyval.value)=(yyvsp[(1) - (3)].value); (yyval.value.fval) = (yyvsp[(1) - (3)].value.fval)/(yyvsp[(3) - (3)].value.fval);}
    break;

  case 28:
#line 154 "test.y"
    {(yyval.value)=(yyvsp[(1) - (3)].value); (yyval.value.fval) = (int)(yyvsp[(1) - (3)].value.fval)%(int)(yyvsp[(3) - (3)].value.fval);}
    break;

  case 29:
#line 155 "test.y"
    {}
    break;

  case 30:
#line 156 "test.y"
    {(yyval.value)=(yyvsp[(2) - (2)].value); (yyval.value.fval)=-(yyvsp[(2) - (2)].value.fval);}
    break;

  case 31:
#line 157 "test.y"
    {}
    break;

  case 32:
#line 158 "test.y"
    {   if(check_in_scope((yyvsp[(1) - (1)].id_value.name),current_symtab)==-1){yyerror("ERROR : id is not in scope");}
                            else{
                                int i;
                                i=current_symtab;
                                while(lookup((yyvsp[(1) - (1)].id_value.name),i)==-1){i=symtab_pre[i];}
                                (yyval.value.fval)=get_value((yyvsp[(1) - (1)].id_value.name),i); (yyval.value.type)=get_type((yyvsp[(1) - (1)].id_value.name),i);
                                }
                         }
    break;

  case 34:
#line 169 "test.y"
    {if(check_in_scope((yyvsp[(1) - (5)].id_value.name),current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
    break;

  case 35:
#line 170 "test.y"
    {if(check_in_scope((yyvsp[(1) - (3)].id_value.name),current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
    break;

  case 43:
#line 184 "test.y"
    {}
    break;

  case 44:
#line 185 "test.y"
    {}
    break;

  case 45:
#line 186 "test.y"
    {}
    break;

  case 46:
#line 187 "test.y"
    {}
    break;

  case 47:
#line 188 "test.y"
    {}
    break;

  case 48:
#line 189 "test.y"
    {}
    break;

  case 49:
#line 190 "test.y"
    {}
    break;

  case 50:
#line 191 "test.y"
    {}
    break;

  case 51:
#line 192 "test.y"
    {}
    break;

  case 57:
#line 209 "test.y"
    {insert((yyvsp[(3) - (5)].id_value.name),current_symtab,(yyvsp[(5) - (5)].type),(yyvsp[(5) - (5)].value.fval));}
    break;

  case 58:
#line 212 "test.y"
    {insert((yyvsp[(3) - (4)].id_value.name),current_symtab,0,0);}
    break;

  case 59:
#line 215 "test.y"
    { insert((yyvsp[(3) - (5)].id_value.name),current_symtab,(yyvsp[(5) - (5)].type),0); }
    break;

  case 60:
#line 217 "test.y"
    { 
                if( ((yyvsp[(5) - (7)].type)==(yyvsp[(7) - (7)].value.type)) || ((yyvsp[(5) - (7)].type)==2 && (yyvsp[(7) - (7)].value.type)==1))
                {
                insert((yyvsp[(3) - (7)].id_value.name),current_symtab,(yyvsp[(5) - (7)].type),(yyvsp[(7) - (7)].value.fval));} 
                else{yyerror("ERROR : Var declaration type checking fail");}
                }
    break;

  case 61:
#line 226 "test.y"
    {insert((yyvsp[(2) - (4)].id_value.name),current_symtab,(yyvsp[(4) - (4)].type),(yyvsp[(4) - (4)].value.fval));}
    break;

  case 62:
#line 229 "test.y"
    {insert((yyvsp[(2) - (2)].id_value.name),current_symtab,0,0);}
    break;

  case 63:
#line 232 "test.y"
    { insert((yyvsp[(2) - (4)].id_value.name),current_symtab,(yyvsp[(4) - (4)].type),0); }
    break;

  case 64:
#line 234 "test.y"
    { 
                if( ((yyvsp[(4) - (6)].type)==(yyvsp[(6) - (6)].value.type)) || ((yyvsp[(4) - (6)].type)==2 && (yyvsp[(6) - (6)].value.type)==1))
                {
                insert((yyvsp[(2) - (6)].id_value.name),current_symtab,(yyvsp[(4) - (6)].type),(yyvsp[(6) - (6)].value.fval));} 
                else{yyerror("ERROR : Var declaration type checking fail");}
                }
    break;

  case 69:
#line 248 "test.y"
    {}
    break;

  case 70:
#line 249 "test.y"
    {}
    break;

  case 71:
#line 252 "test.y"
    {(yyval.type)=3;}
    break;

  case 72:
#line 253 "test.y"
    {(yyval.type)=1;}
    break;

  case 73:
#line 254 "test.y"
    {(yyval.type)=2;}
    break;

  case 74:
#line 255 "test.y"
    {}
    break;

  case 75:
#line 262 "test.y"
    { create(symtab_counter,current_symtab); current_symtab=symtab_counter; symtab_counter+=1;}
    break;

  case 76:
#line 264 "test.y"
    { if(current_symtab!=0) current_symtab=symtab_pre[current_symtab];}
    break;


/* Line 1267 of yacc.c.  */
#line 1868 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 280 "test.y"



//symbol tables                  ------------

struct node{
    int index;
    char id[256];
    int type;
    float fval;
    struct node* next;
};

void create(int tab_num, int pretab_num){
    id_num[tab_num]=0;
    symtab_pre[tab_num]=pretab_num;
    for (int i=0;i<46;i++){
        ids[tab_num][i]=NULL;
    }
}

int lookup(char *input, int tab_num){
    int alphabet;
    if(input[0]<='Z')
    alphabet=input[0]-'A';
    else
    alphabet=input[0]-'a'+23;

    if(ids[tab_num][alphabet]!=NULL){
        struct node *temp=ids[tab_num][alphabet];
        while(temp!=NULL){
            if(strcmp(temp->id,input)==0){
                return temp->index;
            }
            temp=temp->next;
        }
    }
    return -1;
}

int insert(char *input,int tab_num,int type,float value){
    if(lookup(input,tab_num)!=-1){
        return -1;
    }

    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *new_node;
    new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->id,input);
    id_num[tab_num]+=1;
    new_node->index=id_num[tab_num];
    new_node->type=type;
    new_node->fval=value;
    new_node->next=NULL;

    if(ids[tab_num][alphabet]==NULL){
        ids[tab_num][alphabet]=new_node;
    }
    else{
        struct node *temp=ids[tab_num][alphabet];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    
    return id_num[tab_num];
}

void dump(int tab_num){
    for(int i=0;i<46;i++){
        if(ids[tab_num][i]!=NULL){
            struct node *temp=ids[tab_num][i];
            do{
                if(temp->type==1){
                printf("index:%d , id:%s , type:int  , value:%g\n",temp->index,temp->id,temp->fval);
                }
                else if(temp->type==2){
                printf("index:%d , id:%s , type:float, value:%g\n",temp->index,temp->id,temp->fval);
                }
                else if(temp->type==3){
                printf("index:%d , id:%s , type:string, value:%g\n",temp->index,temp->id,temp->fval);
                }
                temp=temp->next;
                }while(temp!=NULL);
        }
    }
}

void update_value(char *input,int tab_num,float the_val){
    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *temp=ids[tab_num][alphabet];
    while(temp!=NULL){
        if(strcmp(temp->id,input)==0){
            temp->fval=the_val;
            return;
        }
        temp=temp->next;
    }
}

float get_value(char *input,int tab_num){
    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *temp=ids[tab_num][alphabet];
    while(temp!=NULL){
        if(strcmp(temp->id,input)==0){
            return temp->fval;
        }
        temp=temp->next;
    }
    return -1;
}


int get_type(char *input,int tab_num){
    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *temp=ids[tab_num][alphabet];
    while(temp!=NULL){
        if(strcmp(temp->id,input)==0){
            return temp->type;
        }
        temp=temp->next;
    }
    return -1;
}

int check_in_scope(char *input,int tab_num){
    int tab;
    tab=tab_num;
    while(lookup(input,tab)==-1 && tab!=0){
        tab=symtab_pre[tab];
    }
    if(lookup(input,tab)==-1)
    return -1;
    else
    return 1;
}


//          symtab  end          ------------

int yyerror(const char *s)
{
 fprintf(stderr, "%s in Line\n", s);
 return 0;
}

int main()
{   
    //initial all symbol_table
    for(int w=0;w<100;w++){
    id_num[w]=-1;
    symtab_pre[w]=-1;
    }

    //create global symbol_table0
    current_symtab=0;
    symtab_counter=1;
    create(0,-1);

    /* perform parsing */
    yyparse();                 /* parsing */
        
    //dump all symbol table and layers of scope
    for(int q=0;q<symtab_counter;q++){
        printf("Symbol_table %d : (",q);
        for(int p=q;p!=0;p=symtab_pre[p]){
            printf("%d<-",p);
        }
        printf("0)\n");
        dump(q);
    }

    return 0;
}
