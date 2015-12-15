/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compilateur.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "Lib/symbol.h"
  #include "Lib/quad.h"
  #include "Lib/matrix.h"
  #include "Lib/mips.h"
  
  extern FILE *yyin;
  int yylex();
  int yyerror(char *);
  //void lex_free();
  void errorManagement(char * str);

  struct symbol* tds = NULL;
  struct quad* code = NULL;
  int nextquad = 0;
  int nb_string = 0;

#line 87 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUSPLUS = 258,
    MOINSMOINS = 259,
    MAIN = 260,
    PRINT = 261,
    PRINTF = 262,
    PRINTMAT = 263,
    RETURN = 264,
    INT = 265,
    FLOAT = 266,
    ID = 267,
    NOT = 268,
    OR = 269,
    AND = 270,
    IF = 271,
    ELSE = 272,
    WHILE = 273,
    FOR = 274,
    STRING = 275,
    TYPE = 276,
    DIFF = 277,
    SUPEQ = 278,
    INFEQ = 279,
    EQUAL = 280,
    SUP = 281,
    INF = 282,
    UMOINS = 287
  };
#endif
/* Tokens.  */
#define PLUSPLUS 258
#define MOINSMOINS 259
#define MAIN 260
#define PRINT 261
#define PRINTF 262
#define PRINTMAT 263
#define RETURN 264
#define INT 265
#define FLOAT 266
#define ID 267
#define NOT 268
#define OR 269
#define AND 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define FOR 274
#define STRING 275
#define TYPE 276
#define DIFF 277
#define SUPEQ 278
#define INFEQ 279
#define EQUAL 280
#define SUP 281
#define INF 282
#define UMOINS 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "compilateur.y" /* yacc.c:355  */

  float value;
  char* string;
  struct symbol* label;
  
  struct {
    char* type;
    float value;
  } num;
    
  struct {
      struct symbol *result;
      struct quad* code;
  } codegen;

  struct {
    struct quad *code;
    struct quad_list* truelist;
    struct quad_list* falselist;
  } code_condition;
  
  struct {
    struct quad *code;
    struct quad_list* nextlist;
  } code_statement;
  
  
  struct {
    struct symbol *quad;
    struct quad *code;
    struct quad_list* nextlist;
  } code_goto;

#line 217 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 232 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    37,    35,    45,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      30,    28,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    44,    48,     2,     2,     2,
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
      25,    26,    27,    31,    32,    33,    34,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    99,   112,   119,   133,   145,   158,   166,
     173,   177,   185,   201,   217,   230,   246,   266,   287,   304,
     324,   346,   350,   358,   370,   377,   393,   409,   425,   443,
     447,   452,   463,   469,   479,   483,   487,   494,   495,   499,
     510,   521,   532,   545,   551,   561,   567,   573,   578,   582,
     593,   602,   613,   625,   634,   647,   660,   675,   688,   697,
     702,   707,   725,   726,   727,   728,   729,   730,   739,   744,
     751,   759,   764,   777,   785
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUSPLUS", "MOINSMOINS", "MAIN",
  "PRINT", "PRINTF", "PRINTMAT", "RETURN", "INT", "FLOAT", "ID", "NOT",
  "OR", "AND", "IF", "ELSE", "WHILE", "FOR", "STRING", "TYPE", "DIFF",
  "SUPEQ", "INFEQ", "EQUAL", "SUP", "INF", "'='", "'>'", "'<'", "\">=\"",
  "\"<=\"", "\"==\"", "\"!=\"", "'+'", "'-'", "'*'", "'/'", "UMOINS",
  "'('", "')'", "'{'", "';'", "'}'", "','", "'['", "']'", "'~'", "$accept",
  "axiom", "affect1", "list_expr", "ids_matrix", "ids_matrix1",
  "ids_matrix2", "affect2", "affect_matrix", "expr", "matrix_expr",
  "number", "increment", "tag", "tagoto", "list", "print", "statement",
  "condition", "op", "row1", "row2", "list_row", "list_elem", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    61,    62,
      60,   283,   284,   285,   286,    43,    45,    42,    47,   287,
      40,    41,   123,    59,   125,    44,    91,    93,   126
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -49

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,    29,    11,     5,  -112,   -27,     8,   152,    35,    52,
      26,    39,    93,    12,    56,    49,  -112,  -112,  -112,    95,
     125,   102,  -112,  -112,    97,   129,   124,  -112,  -112,    27,
     141,   -19,  -112,  -112,  -112,  -112,    79,   112,  -112,   113,
      79,   111,    79,  -112,  -112,   121,   122,   133,   142,     9,
     111,   136,   145,   173,  -112,  -112,  -112,   147,   136,    56,
     161,  -112,   114,   165,   116,  -112,   163,  -112,  -112,  -112,
    -112,  -112,   185,  -112,    19,   166,  -112,   136,   136,   136,
     136,   167,   130,  -112,   168,   114,   114,   162,     3,   114,
     169,   170,   171,  -112,    92,    92,  -112,  -112,   206,    56,
      28,  -112,   155,    55,  -112,  -112,  -112,  -112,  -112,  -112,
     136,  -112,  -112,   175,    75,  -112,  -112,   174,   172,  -112,
     179,   210,   213,  -112,   173,   114,   114,  -112,   182,   114,
     215,   198,    32,   183,   181,  -112,   184,   214,  -112,    91,
    -112,     6,   186,  -112,  -112,   187,   190,   210,    -4,   191,
      91,    68,  -112,   111,  -112,  -112,   188,   210,   219,   193,
     197,  -112,   179,   194,  -112,   199,  -112,   200,   195,   201,
     210,  -112,  -112,   179,  -112,  -112,    91,    91,  -112,   202,
     203,  -112,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     4,    21,    22,     0,
       0,     0,    40,    42,     0,     0,     0,    39,    41,     0,
       0,     8,     3,     9,    10,    11,    43,     0,    43,     0,
      43,     0,    43,    37,    38,     0,     0,     0,     0,    31,
       0,     0,     0,    20,    23,    33,    30,     0,     0,     0,
       0,    46,     0,     0,     0,    45,     0,    47,    49,    50,
      51,    52,     0,    32,    31,     0,    34,     0,     0,     0,
       0,     0,     7,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    25,    26,    27,    28,     0,     0,
      15,    59,     0,     0,    64,    65,    66,    67,    62,    63,
       0,    43,    43,     0,     0,    43,     2,    36,     0,     5,
       0,     0,     0,    60,    61,     0,     0,    43,     0,     0,
       0,     0,     0,    14,     0,    13,     0,    57,    58,    43,
      43,     0,     0,    24,    69,    74,     0,     0,    19,     0,
      43,     0,    35,     0,    68,    12,     0,     0,    53,     0,
       0,    73,     0,    18,    17,     0,    55,     0,    71,     0,
       0,    44,    43,     0,    70,    16,    43,    43,    72,     0,
       0,    54,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,   180,   -51,  -111,  -112,  -112,    98,  -112,   -26,
    -112,   -22,    -7,   -34,  -112,   -35,  -112,  -112,   -24,  -112,
     123,  -112,    77,    99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    15,    32,    33,    34,    35,    16,    17,    87,
      54,    55,    56,    19,   176,    20,    21,    40,    88,   110,
     168,   163,   169,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    61,    46,    53,    63,    65,     1,    67,    83,    58,
     135,     4,    27,    28,     6,    27,    28,   111,   112,    66,
     111,   112,    27,    28,   156,    75,    59,    60,    73,    18,
       8,     9,    82,    18,     3,    18,   155,    43,    44,    49,
      29,   157,    43,    44,   113,     5,   164,    22,   119,   151,
       7,    94,    95,    96,    97,    72,   120,    18,    30,   175,
     102,   101,   103,    50,    23,   114,    24,    51,    31,   111,
     112,     8,     9,   121,   122,    52,   144,   125,   126,    25,
      13,   129,     8,     9,   124,    10,    11,    12,   -48,   111,
     112,    13,    36,   139,     8,     9,   123,    10,    11,    12,
      14,   137,   138,    13,   149,   141,   150,    43,    44,    45,
     145,    37,    14,    38,    39,   159,   128,     8,     9,     8,
       9,    43,    44,   -48,    43,    44,    74,    85,    13,    79,
      80,   145,    18,    26,    41,   -48,    48,    14,   177,     8,
       9,   179,   180,    18,    18,    42,    43,    44,    74,    47,
      50,    57,    62,    64,    86,     8,     9,    76,    10,    11,
      12,   -48,    68,    69,    13,    77,    78,    79,    80,    18,
      18,    84,    50,    14,    70,    99,    51,   104,   105,   106,
     107,   108,   109,    71,   104,   105,   106,   107,   108,   109,
      77,    78,    79,    80,    81,    92,    93,    77,    78,    79,
      80,    77,    78,    79,    80,    89,    91,    93,    77,    78,
      79,    80,   115,    98,   116,   100,   118,   127,   117,   131,
     130,   132,   134,   136,   140,   142,   143,    60,   147,   112,
     162,   148,   153,   152,   154,   158,   165,   166,   167,   170,
     173,   171,   172,   133,    90,   174,   181,   182,     0,   160,
     178,     0,   161
};

static const yytype_int16 yycheck[] =
{
       7,    36,    24,    29,    38,    40,    21,    42,    59,    28,
     121,     0,     3,     4,    41,     3,     4,    14,    15,    41,
      14,    15,     3,     4,    28,    51,    45,    46,    50,    36,
       3,     4,    58,    40,     5,    42,   147,    10,    11,    12,
      28,    45,    10,    11,    41,    40,   157,    12,    99,    43,
      42,    77,    78,    79,    80,    46,    28,    64,    46,   170,
      86,    85,    86,    36,    12,    89,    40,    40,    12,    14,
      15,     3,     4,    45,    46,    48,    44,   111,   112,    40,
      12,   115,     3,     4,   110,     6,     7,     8,     9,    14,
      15,    12,    43,   127,     3,     4,    41,     6,     7,     8,
      21,   125,   126,    12,   139,   129,   140,    10,    11,    12,
     132,    16,    21,    18,    19,   150,    41,     3,     4,     3,
       4,    10,    11,    44,    10,    11,    12,    13,    12,    37,
      38,   153,   139,    40,     9,    44,    12,    21,   172,     3,
       4,   176,   177,   150,   151,    43,    10,    11,    12,    20,
      36,    10,    40,    40,    40,     3,     4,    12,     6,     7,
       8,     9,    41,    41,    12,    35,    36,    37,    38,   176,
     177,    10,    36,    21,    41,    45,    40,    22,    23,    24,
      25,    26,    27,    41,    22,    23,    24,    25,    26,    27,
      35,    36,    37,    38,    47,    10,    41,    35,    36,    37,
      38,    35,    36,    37,    38,    40,    43,    41,    35,    36,
      37,    38,    43,    46,    44,    47,    10,    42,    47,    47,
      46,    42,    12,    10,    42,    10,    28,    46,    45,    15,
      42,    47,    45,    47,    44,    44,    17,    44,    41,    45,
      45,    42,    42,   120,    64,    44,    44,    44,    -1,   151,
     173,    -1,   153
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    50,     5,     0,    40,    41,    42,     3,     4,
       6,     7,     8,    12,    21,    51,    56,    57,    61,    62,
      64,    65,    12,    12,    40,    40,    40,     3,     4,    28,
      46,    12,    52,    53,    54,    55,    43,    16,    18,    19,
      66,     9,    43,    10,    11,    12,    60,    20,    12,    12,
      36,    40,    48,    58,    59,    60,    61,    10,    28,    45,
      46,    64,    40,    62,    40,    64,    60,    64,    41,    41,
      41,    41,    46,    60,    12,    58,    12,    35,    36,    37,
      38,    47,    58,    52,    10,    13,    40,    58,    67,    40,
      51,    43,    10,    41,    58,    58,    58,    58,    46,    45,
      47,    67,    58,    67,    22,    23,    24,    25,    26,    27,
      68,    14,    15,    41,    67,    43,    44,    47,    10,    52,
      28,    45,    46,    41,    58,    62,    62,    42,    41,    62,
      46,    47,    42,    69,    12,    53,    10,    67,    67,    62,
      42,    67,    10,    28,    44,    60,    72,    45,    47,    64,
      62,    43,    47,    45,    44,    53,    28,    45,    44,    64,
      56,    72,    42,    70,    53,    17,    44,    41,    69,    71,
      45,    42,    42,    45,    44,    53,    63,    62,    71,    64,
      64,    44,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    61,    61,    62,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     2,     1,     5,     3,     3,     1,     1,
       1,     1,     8,     6,     6,     4,    11,     9,     9,     7,
       3,     1,     1,     3,     8,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     2,     7,     4,     1,     1,     2,
       2,     2,     2,     0,     0,     3,     3,     3,     0,     4,
       4,     4,     4,     8,    13,     9,    13,     4,     4,     2,
       3,     3,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     1,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 86 "compilateur.y" /* yacc.c:1646  */
    { 
                                                    printf("Match\n");
                                                    (yyval.code_statement).code = (yyvsp[-4].code_statement).code;
                                                    code = (yyvsp[-4].code_statement).code;
                                                    printf("---TDS---\n");
                                                    symbol_print(tds);
                                                    printf("---CODE---\n");
                                                    quad_print(code);
                                                    //exit(0);
                                                  }
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 100 "compilateur.y" /* yacc.c:1646  */
    {
            (yyval.codegen).result = (yyvsp[0].codegen).result;
            (yyval.codegen).result->type = (yyvsp[-1].string);
            /*struct symbol *temp=$2.result;
            while(temp!=NULL)
            {
              temp->type=$$.result->type;
              temp=temp->next;
            }*/
            (yyval.codegen).code = (yyvsp[0].codegen).code;
            symbol_complete(&tds,(yyvsp[-1].string));
          }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "compilateur.y" /* yacc.c:1646  */
    {
              (yyval.codegen).result = (yyvsp[0].codegen).result;
              (yyval.codegen).code = (yyvsp[0].codegen).code;
            }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 120 "compilateur.y" /* yacc.c:1646  */
    {
                                struct symbol * affect = symbol_add(&tds, (yyvsp[-4].string));
                                affect->value = (yyvsp[-2].codegen).result->value;
                                affect->isconstant = false;
                                (yyval.codegen).result = affect;
                                
                                (yyval.codegen).code = quad_gen(&nextquad, "=", (yyvsp[-2].codegen).result, NULL, affect);
                                quad_add(&(yyval.codegen).code, (yyvsp[-2].codegen).code);
                                quad_add(&(yyval.codegen).code, (yyvsp[0].codegen).code);
                                
                                // $$.code = concatQuad(quad_gen(&nextquad, "=", $3.result, NULL, affect),$5.code);
                                nextquad++;
                              }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 133 "compilateur.y" /* yacc.c:1646  */
    {
                      struct symbol * affect = symbol_add(&tds, (yyvsp[-2].string));
                      affect->isconstant = false;
                      (yyval.codegen).result = affect;
                      
                      (yyval.codegen).code = quad_gen(&nextquad, "", NULL, NULL, affect);
                      quad_add(&(yyval.codegen).code,(yyvsp[0].codegen).code);
                      
                      //$$.code = concatQuad(quad_gen(&nextquad, "", NULL, NULL, affect),$3.code);
                      nextquad++;
                    }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 145 "compilateur.y" /* yacc.c:1646  */
    {
                  struct symbol * affect = symbol_add(&tds, (yyvsp[-2].string));
                  affect->value = (yyvsp[0].codegen).result->value;
                  affect->isconstant = false;
                  (yyval.codegen).result = affect;
                  
                  (yyval.codegen).code = quad_gen(&nextquad, "=", (yyvsp[0].codegen).result, NULL, affect);
                  quad_add(&(yyval.codegen).code,(yyvsp[0].codegen).code);
                  nextquad++;
                  printf("hello\n");
                  quad_print((yyval.codegen).code);
                  printf("endHello\n");
                }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 158 "compilateur.y" /* yacc.c:1646  */
    {
          struct symbol * affect = symbol_add(&tds, (yyvsp[0].string));
          affect->isconstant = false;
          (yyval.codegen).result = affect;
          
          (yyval.codegen).code = quad_gen(&nextquad, "", NULL, NULL, affect);
          nextquad++;
        }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 166 "compilateur.y" /* yacc.c:1646  */
    {
                  (yyval.codegen).result = (yyvsp[0].codegen).result;
                  (yyval.codegen).code = (yyvsp[0].codegen).code;
                }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 173 "compilateur.y" /* yacc.c:1646  */
    {
                  (yyval.codegen).result = (yyvsp[0].codegen).result;
                  (yyval.codegen).code = (yyvsp[0].codegen).code;
                }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 177 "compilateur.y" /* yacc.c:1646  */
    {
                  (yyval.codegen).result = (yyvsp[0].codegen).result;
                  (yyval.codegen).code = (yyvsp[0].codegen).code;
                }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 185 "compilateur.y" /* yacc.c:1646  */
    {
                                              struct symbol * affect = symbol_add(&tds, (yyvsp[-7].string));
                                              affect->matrix=malloc(sizeof(struct matrix_float*));
                                              affect->matrix=malloc(sizeof(float*));
                                              affect->matrix->row = 1;
                                              affect->matrix->column = (int)(yyvsp[-5].value);
                                              affect->matrix->tab=malloc(sizeof(float*));
                                              affect->matrix->tab[0]=malloc((yyvsp[-5].value)*sizeof(float));
                                              affect->type="matrix";
                                              affect->isconstant = false;
                                              (yyval.codegen).result = affect;
                                              
                                              //$$.code = concatQuad($6.code,$8.code);
                                              (yyval.codegen).code=(yyvsp[-2].codegen).code;
                                              quad_add(&(yyval.codegen).code,(yyvsp[0].codegen).code);
                                            }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 201 "compilateur.y" /* yacc.c:1646  */
    {
                                    struct symbol * affect = symbol_add(&tds, (yyvsp[-5].string));
                                    affect->matrix=malloc(sizeof(struct matrix_float*));
                                    affect->matrix->row = 1;
                                    affect->matrix->column = (int)(yyvsp[-3].value);
                                    affect->matrix->tab=malloc(sizeof(float*));
                                    affect->matrix->tab[0]=malloc((yyvsp[-3].value)*sizeof(float));
                                    affect->type="matrix";
                                    affect->isconstant = false;
                                    (yyval.codegen).result = affect;
                                    
                                    //$$.code = concatQuad(quad_gen(&nextquad, "", NULL, NULL, affect),$6.code);
                                    (yyval.codegen).code=quad_gen(&nextquad, "", NULL, NULL, affect);
                                    quad_add(&(yyval.codegen).code,(yyvsp[0].codegen).code);
                                    nextquad++;
                                  }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "compilateur.y" /* yacc.c:1646  */
    {
                              struct symbol * affect = symbol_add(&tds, (yyvsp[-5].string));
                              affect->matrix=malloc(sizeof(struct matrix_float*));
                              affect->matrix->row = 1;
                              affect->matrix->column = (int)(yyvsp[-3].value);
                              affect->matrix->tab=malloc(sizeof(float*));
                              affect->matrix->tab[0]=malloc((yyvsp[-3].value)*sizeof(float));
                              affect->type="matrix";
                              affect->isconstant = false;
                              (yyval.codegen).result = affect;
                              
                              (yyval.codegen).code = (yyvsp[0].codegen).code;
                            }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 230 "compilateur.y" /* yacc.c:1646  */
    {
                      struct symbol * affect = symbol_add(&tds, (yyvsp[-3].string));
                      affect->matrix=malloc(sizeof(struct matrix_float*));
                      affect->matrix->row = 1;
                      affect->matrix->column = (int)(yyvsp[-1].value);
                      affect->matrix->tab=malloc(sizeof(float*));
                      affect->matrix->tab[0]=malloc((yyvsp[-1].value)*sizeof(float));
                      affect->type="matrix";
                      affect->isconstant = false;
                      (yyval.codegen).result = affect;
                      
                      (yyval.codegen).code = quad_gen(&nextquad, "", NULL, NULL, affect);
                    }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "compilateur.y" /* yacc.c:1646  */
    {
                                                          struct symbol * affect = symbol_add(&tds, (yyvsp[-10].string));
                                                          affect->matrix=malloc(sizeof(struct matrix_float*));
                                                          affect->matrix->row = (int)(yyvsp[-8].value);
                                                          affect->matrix->column = (int)(yyvsp[-5].value);
                                                          affect->matrix->tab=malloc((yyvsp[-8].value)*sizeof(float*));
                                                          int i;
                                                          for(i=0;i<(yyvsp[-8].value);i++)
                                                          {
                                                            affect->matrix->tab[i]=malloc((yyvsp[-5].value)*sizeof(float));
                                                          }
                                                          affect->type="matrix";
                                                          affect->isconstant = false;
                                                          (yyval.codegen).result = affect;
                                                          
                                                          (yyval.codegen).code=(yyvsp[-2].codegen).code;
                                                          quad_add(&(yyval.codegen).code,(yyvsp[0].codegen).code);
                                                          
                                                          //$$.code = concatQuad($9.code,$11.code);
                                                        }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 266 "compilateur.y" /* yacc.c:1646  */
    {
                                                struct symbol * affect = symbol_add(&tds, (yyvsp[-8].string));
                                                affect->matrix=malloc(sizeof(struct matrix_float*));
                                                affect->matrix->row = (int)(yyvsp[-6].value);
                                                affect->matrix->column = (int)(yyvsp[-3].value);
                                                affect->matrix->tab=malloc((yyvsp[-6].value)*sizeof(float*));
                                                int i;
                                                for(i=0;i<(yyvsp[-6].value);i++)
                                                {
                                                  affect->matrix->tab[i]=malloc((yyvsp[-3].value)*sizeof(float));
                                                }
                                                affect->type="matrix";
                                                affect->isconstant = false;
                                                (yyval.codegen).result = affect;
                                                
                                                // $$.code = concatQuad(quad_gen(&nextquad, "", NULL, NULL, affect),$9.code);
                                                
                                                (yyval.codegen).code = quad_gen(&nextquad, "", NULL, NULL, affect);
                                                quad_add(&(yyval.codegen).code,(yyvsp[0].codegen).code);
                                                nextquad++;
                                              }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 287 "compilateur.y" /* yacc.c:1646  */
    {
                                          struct symbol * affect = symbol_add(&tds, (yyvsp[-8].string));
                                          affect->matrix=malloc(sizeof(struct matrix_float*));
                                          affect->matrix->row = (int)(yyvsp[-6].value);
                                          affect->matrix->column = (int)(yyvsp[-3].value);
                                          affect->matrix->tab=malloc((yyvsp[-6].value)*sizeof(float*));
                                          int i;
                                          for(i=0;i<(yyvsp[-6].value);i++)
                                          {
                                            affect->matrix->tab[i]=malloc((yyvsp[-3].value)*sizeof(float));
                                          }
                                          affect->type="matrix";
                                          affect->isconstant = false;
                                          (yyval.codegen).result = affect;
                                          
                                          (yyval.codegen).code = (yyvsp[0].codegen).code;
                                        }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 304 "compilateur.y" /* yacc.c:1646  */
    {
                                  struct symbol * affect = symbol_add(&tds, (yyvsp[-6].string));
                                  affect->matrix=malloc(sizeof(struct matrix_float*));
                                  affect->matrix->row = (int)(yyvsp[-4].value);
                                  affect->matrix->column = (int)(yyvsp[-1].value);
                                  affect->matrix->tab=malloc((yyvsp[-4].value)*sizeof(float*));
                                  int i;
                                  for(i=0;i<(yyvsp[-4].value);i++)
                                  {
                                    affect->matrix->tab[i]=malloc((yyvsp[-1].value)*sizeof(float));
                                  }
                                  affect->type="matrix";
                                  affect->isconstant = false;
                                  (yyval.codegen).result = affect;
                                  
                                  (yyval.codegen).code = quad_gen(&nextquad, "", NULL, NULL, affect);
                                }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 324 "compilateur.y" /* yacc.c:1646  */
    {
                struct symbol * affect = symbol_lookup(tds, (yyvsp[-2].string));
                
                printf("%s value : %f\n",(yyvsp[0].codegen).result->id, (yyvsp[0].codegen).result->value);
                /*struct symbol *temp=affect;
                while(temp!=NULL)
                {
                  temp->type=affect->type;
                  temp=temp->next;
                }*/
                if(affect == NULL)
                {
                  errorManagement(strcat(strcat("L'id ",(yyvsp[-2].string)),"n'est pas exisant\n"));
                }
                affect->value = (yyvsp[0].codegen).result->value;
                
                (yyval.codegen).result = affect;
                
                (yyval.codegen).code = quad_gen(&nextquad, "=", (yyvsp[0].codegen).result, NULL, affect);
                quad_add(&(yyval.codegen).code,(yyvsp[0].codegen).code);
                nextquad++;
              }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 346 "compilateur.y" /* yacc.c:1646  */
    {
                    (yyval.codegen).code = (yyvsp[0].codegen).code;
                    (yyvsp[0].codegen).result = (yyvsp[0].codegen).result;
                  }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 350 "compilateur.y" /* yacc.c:1646  */
    {
                (yyval.codegen).result = (yyvsp[0].codegen).result;
                (yyval.codegen).code = (yyvsp[0].codegen).code;
              }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 358 "compilateur.y" /* yacc.c:1646  */
    {
                          struct symbol * affect = symbol_lookup(tds, (yyvsp[-2].string));
                          if(affect == NULL)
                          {
                            errorManagement(strcat(strcat("L'id ",(yyvsp[-2].string)),"n'est pas exisant\n"));
                          }
                          //affect->value = $3.result->value;
                          (yyval.codegen).result = affect;
                          
                          (yyval.codegen).code = quad_gen(&nextquad, "=", (yyvsp[0].codegen).result, NULL, affect);
                          nextquad++;
                        }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 370 "compilateur.y" /* yacc.c:1646  */
    {
                                      (yyval.codegen).result=NULL;
                                      (yyval.codegen).code=NULL;
                                    }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 377 "compilateur.y" /* yacc.c:1646  */
    {   
                        (yyval.codegen).result = symbol_newtemp(&tds);
                        (yyval.codegen).result->value = (yyvsp[-2].codegen).result->value + (yyvsp[0].codegen).result->value;
                        if(strcmp((yyvsp[-2].codegen).result->type,"int")==0 && strcmp((yyvsp[0].codegen).result->type,"int")==0)
                        {
                          (yyval.codegen).result->type = (yyvsp[-2].codegen).result->type;
                        }
                        else
                        {
                          (yyval.codegen).result->type = "float";
                        }
                        (yyval.codegen).code = (yyvsp[-2].codegen).code;
                        quad_add(&(yyval.codegen).code, (yyvsp[0].codegen).code);
                        quad_add(&(yyval.codegen).code, quad_gen(&nextquad,"+", (yyvsp[-2].codegen).result, (yyvsp[0].codegen).result, (yyval.codegen).result));
                        nextquad++;
                    }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 393 "compilateur.y" /* yacc.c:1646  */
    {   
                        (yyval.codegen).result = symbol_newtemp(&tds);
                        (yyval.codegen).result->value = (yyvsp[-2].codegen).result->value - (yyvsp[0].codegen).result->value;
                        if(strcmp((yyvsp[-2].codegen).result->type,"int") == 0 && strcmp((yyvsp[0].codegen).result->type,"int") ==0)
                        {
                          (yyval.codegen).result->type = (yyvsp[-2].codegen).result->type;
                        }
                        else
                        {
                          (yyval.codegen).result->type = "float";
                        }
                        (yyval.codegen).code = (yyvsp[-2].codegen).code;
                        quad_add(&(yyval.codegen).code, (yyvsp[0].codegen).code);
                        quad_add(&(yyval.codegen).code, quad_gen(&nextquad,"-", (yyvsp[-2].codegen).result, (yyvsp[0].codegen).result, (yyval.codegen).result));
                        nextquad++;
                    }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 409 "compilateur.y" /* yacc.c:1646  */
    {   
                        (yyval.codegen).result = symbol_newtemp(&tds);
                        (yyval.codegen).result->value = (yyvsp[-2].codegen).result->value * (yyvsp[0].codegen).result->value;
                        if(strcmp((yyvsp[-2].codegen).result->type,"int") == 0 && strcmp((yyvsp[0].codegen).result->type,"int") ==0)
                        {
                          (yyval.codegen).result->type = (yyvsp[-2].codegen).result->type;
                        }
                        else
                        {
                          (yyval.codegen).result->type = "float";
                        }
                        (yyval.codegen).code = (yyvsp[-2].codegen).code;
                        quad_add(&(yyval.codegen).code, (yyvsp[0].codegen).code);
                        quad_add(&(yyval.codegen).code, quad_gen(&nextquad,"*", (yyvsp[-2].codegen).result, (yyvsp[0].codegen).result, (yyval.codegen).result));
                        nextquad++;
                    }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 425 "compilateur.y" /* yacc.c:1646  */
    {   
                        (yyval.codegen).result = symbol_newtemp(&tds);
                       
                        (yyval.codegen).result->value = (yyvsp[-2].codegen).result->value / (yyvsp[0].codegen).result->value;
                        
                        if(strcmp((yyvsp[-2].codegen).result->type,"int") == 0 && strcmp((yyvsp[0].codegen).result->type,"int") ==0)
                        {
                          (yyval.codegen).result->type = (yyvsp[-2].codegen).result->type;
                        }
                        else
                        {
                          (yyval.codegen).result->type = "float";
                        }
                        (yyval.codegen).code = (yyvsp[-2].codegen).code;
                        quad_add(&(yyval.codegen).code, (yyvsp[0].codegen).code);
                        quad_add(&(yyval.codegen).code, quad_gen(&nextquad,"/", (yyvsp[-2].codegen).result, (yyvsp[0].codegen).result, (yyval.codegen).result));
                        nextquad++;
                    }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 443 "compilateur.y" /* yacc.c:1646  */
    {   
                        (yyval.codegen).result = (yyvsp[-1].codegen).result;
                        (yyval.codegen).code = (yyvsp[-1].codegen).code;
                    }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 447 "compilateur.y" /* yacc.c:1646  */
    {
                      (yyval.codegen).result = (yyvsp[0].codegen).result;
                      (yyval.codegen).code = (yyvsp[0].codegen).code;
                    }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 452 "compilateur.y" /* yacc.c:1646  */
    {   
                        struct symbol* temp = symbol_lookup(tds,(yyvsp[0].string));
                        if(temp == NULL)
                        {
                          errorManagement(strcat(strcat("L'id ",(yyvsp[0].string)),"n'est pas exisant\n"));
                        }
                        (yyval.codegen).result = temp;
                        (yyval.codegen).code = NULL;
                        // $$.result = symbol_add(&tds, $1);
                        // $$.code = NULL;
                    }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 463 "compilateur.y" /* yacc.c:1646  */
    {
                        (yyval.codegen).result = symbol_newtemp(&tds);
                        (yyval.codegen).result->type = (yyvsp[0].num).type;
                        (yyval.codegen).result->value = - (yyvsp[0].num).value;
                        (yyval.codegen).code = NULL;
                    }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 469 "compilateur.y" /* yacc.c:1646  */
    {   
                        (yyval.codegen).result = symbol_newtemp(&tds);
                        (yyval.codegen).result->type = (yyvsp[0].num).type;
                        (yyval.codegen).result->value = (yyvsp[0].num).value;
                        (yyval.codegen).code = NULL;
                    }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 479 "compilateur.y" /* yacc.c:1646  */
    {
              (yyval.codegen).code = NULL;
              (yyval.codegen).result = NULL;
            }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 483 "compilateur.y" /* yacc.c:1646  */
    {
                                  (yyval.codegen).code = NULL;
                                  (yyval.codegen).result = NULL;
                                }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 487 "compilateur.y" /* yacc.c:1646  */
    {
                      (yyval.codegen).code = NULL;
                      (yyval.codegen).result = NULL;
                    }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 494 "compilateur.y" /* yacc.c:1646  */
    { (yyval.num).value=(yyvsp[0].value); (yyval.num).type="int";}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 495 "compilateur.y" /* yacc.c:1646  */
    { (yyval.num).value=(yyvsp[0].value); (yyval.num).type="float";}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 499 "compilateur.y" /* yacc.c:1646  */
    {
                      struct symbol* temp = symbol_lookup(tds,(yyvsp[-1].string));
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",(yyvsp[-1].string)),"n'est pas exisant\n"));
                      }
                      temp->value += 1;
                      (yyval.codegen).result = temp;
                      (yyval.codegen).code = quad_gen(&nextquad,"++", temp, NULL, (yyval.codegen).result);
                      nextquad++;
                    }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 510 "compilateur.y" /* yacc.c:1646  */
    {
                      struct symbol* temp = symbol_lookup(tds,(yyvsp[0].string));
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",(yyvsp[0].string)),"n'est pas exisant\n"));
                      }
                      temp->value += 1;
                      (yyval.codegen).result = temp;
                      (yyval.codegen).code = quad_gen(&nextquad,"++", NULL, temp, (yyval.codegen).result);
                      nextquad++;
                    }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 521 "compilateur.y" /* yacc.c:1646  */
    {
                      struct symbol* temp = symbol_lookup(tds,(yyvsp[-1].string));
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",(yyvsp[-1].string)),"n'est pas exisant\n"));
                      }
                      temp->value -= 1;
                      (yyval.codegen).result = temp;
                      (yyval.codegen).code = quad_gen(&nextquad,"--", temp, NULL , (yyval.codegen).result);
                      nextquad++;
                    }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 532 "compilateur.y" /* yacc.c:1646  */
    {
                      struct symbol* temp = symbol_lookup(tds,(yyvsp[0].string));
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",(yyvsp[0].string)),"n'est pas exisant\n"));
                      }
                      temp->value -= 1;
                      (yyval.codegen).result = temp;
                      (yyval.codegen).code = quad_gen(&nextquad,"--", NULL, temp, (yyval.codegen).result);
                      nextquad++;
                    }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 545 "compilateur.y" /* yacc.c:1646  */
    {
        (yyval.label) = symbol_newlabel(&tds, nextquad);
        nextquad++;
      }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 551 "compilateur.y" /* yacc.c:1646  */
    {
            (yyval.code_goto).code = quad_gen(&nextquad,"goto", NULL, NULL, NULL);
            nextquad++;
            (yyval.code_goto).quad = symbol_newlabel(&tds, nextquad);
            nextquad++;
            (yyval.code_goto).nextlist = newlist((yyval.code_goto).code);
          }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 561 "compilateur.y" /* yacc.c:1646  */
    {
                          complete((yyvsp[0].code_statement).nextlist,(yyvsp[-2].label));
                          (yyval.code_statement).nextlist = (yyvsp[-1].code_statement).nextlist;
                          (yyval.code_statement).code = (yyvsp[-1].code_statement).code;
                          quad_add(&(yyval.code_statement).code,(yyvsp[0].code_statement).code);
                        }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 568 "compilateur.y" /* yacc.c:1646  */
    {
                      (yyval.code_statement).nextlist = newlist((yyvsp[-2].codegen).code);
                      (yyval.code_statement).code=(yyvsp[-2].codegen).code;
                      quad_add(&(yyval.code_statement).code,(yyvsp[0].code_statement).code);
                    }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 573 "compilateur.y" /* yacc.c:1646  */
    {
                      (yyval.code_statement).nextlist = newlist((yyvsp[-2].codegen).code);
                      (yyval.code_statement).code = (yyvsp[-2].codegen).code;
                      quad_add(&(yyval.code_statement).code,(yyvsp[0].code_statement).code);
                   }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 578 "compilateur.y" /* yacc.c:1646  */
    {(yyval.code_statement).code=NULL;/* empty */}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 583 "compilateur.y" /* yacc.c:1646  */
    {
      struct symbol * affect = symbol_lookup(tds, (yyvsp[-1].string));
      if(affect == NULL)
      {
        errorManagement(strcat(strcat("L'id ",(yyvsp[-1].string)),"n'est pas exisant\n"));
      }
      (yyval.codegen).code = quad_gen(&nextquad,"print",affect,NULL,NULL);
      (yyval.codegen).result = affect;
      nextquad++;
    }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 594 "compilateur.y" /* yacc.c:1646  */
    {
      struct symbol * temp = symbol_newtemp(&tds); 
      temp->type = (yyvsp[-1].num).type;
      temp->value = (yyvsp[-1].num).value;
      (yyval.codegen).code = quad_gen(&nextquad,"print",temp,NULL,NULL);
      (yyval.codegen).result = temp;
      nextquad++;
    }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 603 "compilateur.y" /* yacc.c:1646  */
    {
      struct symbol * temp = symbol_newtemp(&tds); 
      temp->type = "string";
      temp->id = strdup((yyvsp[-1].string));
      temp->value = nb_string;
      nb_string++;
      (yyval.codegen).code = quad_gen(&nextquad,"printf",temp,NULL,NULL);
      (yyval.codegen).result = temp;
      nextquad++;
   }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 614 "compilateur.y" /* yacc.c:1646  */
    {
      struct symbol * temp = symbol_newtemp(&tds); 
      temp->type = "string";
      temp->id = (yyvsp[-1].string);
      (yyval.codegen).code = quad_gen(&nextquad,"printmat",temp,NULL,NULL);
      (yyval.codegen).result = temp;
      nextquad++;
   }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 627 "compilateur.y" /* yacc.c:1646  */
    { 
        complete((yyvsp[-5].code_condition).truelist,(yyvsp[-2].label));
        (yyval.code_statement).nextlist = concatList((yyvsp[-1].code_statement).nextlist,(yyvsp[-5].code_condition).falselist);
        (yyval.code_statement).code = (yyvsp[-5].code_condition).code;
        quad_add(&(yyval.code_statement).code,(yyvsp[-1].code_statement).code);
      }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 636 "compilateur.y" /* yacc.c:1646  */
    { 
        complete((yyvsp[-10].code_condition).truelist,(yyvsp[-7].label));
        complete((yyvsp[-10].code_condition).falselist,(yyvsp[-2].code_goto).quad);
        (yyval.code_statement).nextlist=concatList(concatList((yyvsp[-6].code_statement).nextlist,(yyvsp[-1].code_statement).nextlist),(yyvsp[-2].code_goto).nextlist);
        (yyval.code_statement).code=(yyvsp[-10].code_condition).code;
        quad_add(&(yyval.code_statement).code,(yyvsp[-6].code_statement).code);
        quad_add(&(yyval.code_statement).code,(yyvsp[-2].code_goto).code);
        quad_add(&(yyval.code_statement).code,(yyvsp[-1].code_statement).code);
        //$$.code=concatQuad(concatQuad(concatQuad($3.code,$7.code),$11.code),$12.code);
      }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 649 "compilateur.y" /* yacc.c:1646  */
    { 
        complete((yyvsp[-5].code_condition).truelist,(yyvsp[-2].label));
        complete((yyvsp[-1].code_statement).nextlist,(yyvsp[-7].label));
        (yyval.code_statement).nextlist=(yyvsp[-5].code_condition).falselist;
        //$$.code=concatQuad(concatQuad($4.code,$8.code),quad_gen(&nextquad,"goto",NULL,NULL,$2));
        (yyval.code_statement).code=(yyvsp[-5].code_condition).code;
        quad_add(&(yyval.code_statement).code,(yyvsp[-1].code_statement).code);
        quad_add(&(yyval.code_statement).code,quad_gen(&nextquad,"goto",NULL,NULL,(yyvsp[-7].label)));
        nextquad++;
      }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 662 "compilateur.y" /* yacc.c:1646  */
    { 
        complete((yyvsp[-7].code_condition).truelist,(yyvsp[-2].label));
        complete((yyvsp[-1].code_statement).nextlist,(yyvsp[-8].label));
        (yyval.code_statement).nextlist=(yyvsp[-7].code_condition).falselist;
        //$$.code=concatQuad(concatQuad($6.code,$12.code),quad_gen(&nextquad,"goto",NULL,NULL,$5));
        (yyval.code_statement).code=(yyvsp[-7].code_condition).code;
        quad_add(&(yyval.code_statement).code,(yyvsp[-1].code_statement).code);
        quad_add(&(yyval.code_statement).code,quad_gen(&nextquad,"goto",NULL,NULL,(yyvsp[-8].label)));
        nextquad++;
      }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 675 "compilateur.y" /* yacc.c:1646  */
    { 
                                        symbol_print(tds);
                                        complete((yyvsp[-3].code_condition).falselist,(yyvsp[-1].label));
                                        
                                        (yyval.code_condition).code = (yyvsp[-3].code_condition).code;
                                        
                                        quad_add(&(yyval.code_condition).code, (yyvsp[0].code_condition).code);
                                        
                                        (yyval.code_condition).falselist = (yyvsp[0].code_condition).falselist;
                                        (yyval.code_condition).truelist = (yyvsp[-3].code_condition).truelist;
                                        
                                        concatList((yyval.code_condition).truelist,(yyvsp[0].code_condition).truelist);
                                     }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 688 "compilateur.y" /* yacc.c:1646  */
    {
                                        complete((yyvsp[-3].code_condition).truelist,(yyvsp[-1].label));
                                        (yyval.code_condition).code = (yyvsp[-3].code_condition).code;
                                        quad_add(&(yyval.code_condition).code, (yyvsp[0].code_condition).code);
                                        (yyval.code_condition).falselist = (yyvsp[0].code_condition).falselist;
                                        (yyval.code_condition).truelist = (yyvsp[-3].code_condition).truelist;
                                        concatList((yyval.code_condition).falselist,(yyvsp[0].code_condition).truelist);
                                        
                                     }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 697 "compilateur.y" /* yacc.c:1646  */
    {
                                        (yyval.code_condition).code = (yyvsp[0].code_condition).code;
                                        (yyval.code_condition).truelist = (yyvsp[0].code_condition).falselist;
                                        (yyval.code_condition).falselist = (yyvsp[0].code_condition).truelist;
                                     }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 702 "compilateur.y" /* yacc.c:1646  */
    {
                                        (yyval.code_condition).code = (yyvsp[-1].code_condition).code;
                                        (yyval.code_condition).truelist = (yyvsp[-1].code_condition).truelist;
                                        (yyval.code_condition).falselist = (yyvsp[-1].code_condition).falselist;
                                    }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 707 "compilateur.y" /* yacc.c:1646  */
    {
                                      (yyval.code_condition).code = NULL;
                                      
                                      struct quad* goto_true = quad_gen(&nextquad, (yyvsp[-1].string), (yyvsp[-2].codegen).result, (yyvsp[0].codegen).result, NULL);
                                      nextquad++;
                                      struct quad* goto_false = quad_gen(&nextquad, (yyvsp[-1].string), (yyvsp[-2].codegen).result, (yyvsp[0].codegen).result, NULL);
                                      nextquad++;
                                      
                                      quad_add(&(yyval.code_condition).code, goto_true);
                                      quad_add(&(yyval.code_condition).code, goto_false);
                                      
                                      // quad_print($$.code);
                                      
                                      (yyval.code_condition).truelist = newlist(goto_true);
                                      (yyval.code_condition).falselist = newlist(goto_false);
                                   }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 725 "compilateur.y" /* yacc.c:1646  */
    { (yyval.string)=(yyvsp[0].string); }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 726 "compilateur.y" /* yacc.c:1646  */
    { (yyval.string)=(yyvsp[0].string); }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 727 "compilateur.y" /* yacc.c:1646  */
    { (yyval.string)=(yyvsp[0].string); }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 728 "compilateur.y" /* yacc.c:1646  */
    { (yyval.string)=(yyvsp[0].string); }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 729 "compilateur.y" /* yacc.c:1646  */
    { (yyval.string)=(yyvsp[0].string); }
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 730 "compilateur.y" /* yacc.c:1646  */
    { (yyval.string)=(yyvsp[0].string); }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 739 "compilateur.y" /* yacc.c:1646  */
    {
                          (yyval.codegen).code=NULL;
                          (yyval.codegen).result=(yyvsp[-1].codegen).result;
                          (yyval.codegen).result=NULL;
                        }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 744 "compilateur.y" /* yacc.c:1646  */
    {
              (yyval.codegen).code=NULL;
              (yyval.codegen).result=NULL;
            }
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 751 "compilateur.y" /* yacc.c:1646  */
    {
                      (yyval.codegen).code=NULL;
                      (yyval.codegen).result=(yyvsp[-1].codegen).result;
                      (yyval.codegen).result=NULL;
                    }
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 759 "compilateur.y" /* yacc.c:1646  */
    {
            (yyval.codegen).code=NULL;
            (yyval.codegen).result=(yyvsp[0].codegen).result;
            (yyval.codegen).result=NULL;
          }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 764 "compilateur.y" /* yacc.c:1646  */
    {
                        (yyval.codegen).code=NULL;
                        (yyval.codegen).result=(yyvsp[-2].codegen).result;
                        struct symbol* temp=(yyvsp[-2].codegen).result;
                        while(temp->next!=NULL)
                        {
                          temp->next=(yyvsp[0].codegen).result;
                        }
                        (yyval.codegen).result=NULL;
                      }
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 777 "compilateur.y" /* yacc.c:1646  */
    {
                          (yyval.codegen).code=NULL;
                          (yyval.codegen).result = symbol_newtemp(&tds);
                          (yyval.codegen).result->type = (yyvsp[-2].num).type;
                          (yyval.codegen).result->value = (yyvsp[-2].num).value;
                          (yyval.codegen).result->next=(yyvsp[0].codegen).result;
                          (yyval.codegen).result=NULL;
                        }
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 785 "compilateur.y" /* yacc.c:1646  */
    {
            (yyval.codegen).code=NULL;
            (yyval.codegen).result = symbol_newtemp(&tds);
            (yyval.codegen).result->type = (yyvsp[0].num).type;
            (yyval.codegen).result->value = (yyvsp[0].num).value;
            //$$.result=NULL;
          }
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2419 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 793 "compilateur.y" /* yacc.c:1906  */


void errorManagement(char * str)
{
  fputs(str, stderr);
  //fprintf(stderr, str);
  symbol_free(tds);
  quad_free(code);
  exit(-1);
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
      yyin = fopen(argv[1], "r");
  }
  yyparse();
  if (argc > 1) {
      fclose(yyin);
  }
  convert(code,tds);
  // symbol_print(tds);
  symbol_free(tds);
  quad_free(code);
  //generateFile(code);
  //lex_free();
  return 0;
}
