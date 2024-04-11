/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "turtle.y"

    #include "turtle-types.h"
    #include "turtle.h"

    #include <stdio.h>
    #include <stdlib.h>

    treenode_t *root;

    extern FILE *yyin;
    extern FILE *src_file;

    extern int yylineno;

    treenode_t *new_node(type_t type) {
        treenode_t *node = malloc(sizeof(treenode_t));
        node->type = type;
        return node;
    }

#line 92 "turtle.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "turtle.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TNUMBER = 3,                    /* TNUMBER  */
  YYSYMBOL_TVAR = 4,                       /* TVAR  */
  YYSYMBOL_TBEGIN = 5,                     /* TBEGIN  */
  YYSYMBOL_TEND = 6,                       /* TEND  */
  YYSYMBOL_TWALK = 7,                      /* TWALK  */
  YYSYMBOL_TJUMP = 8,                      /* TJUMP  */
  YYSYMBOL_TTURN = 9,                      /* TTURN  */
  YYSYMBOL_TBACK = 10,                     /* TBACK  */
  YYSYMBOL_THOME = 11,                     /* THOME  */
  YYSYMBOL_TLEFT = 12,                     /* TLEFT  */
  YYSYMBOL_TRIGHT = 13,                    /* TRIGHT  */
  YYSYMBOL_TDIR = 14,                      /* TDIR  */
  YYSYMBOL_TCOLOR = 15,                    /* TCOLOR  */
  YYSYMBOL_TCLEAR = 16,                    /* TCLEAR  */
  YYSYMBOL_TSTOP = 17,                     /* TSTOP  */
  YYSYMBOL_TFINISH = 18,                   /* TFINISH  */
  YYSYMBOL_TCOMMA = 19,                    /* TCOMMA  */
  YYSYMBOL_TSTORE = 20,                    /* TSTORE  */
  YYSYMBOL_TIN = 21,                       /* TIN  */
  YYSYMBOL_TADD = 22,                      /* TADD  */
  YYSYMBOL_TTO = 23,                       /* TTO  */
  YYSYMBOL_TSUB = 24,                      /* TSUB  */
  YYSYMBOL_TFROM = 25,                     /* TFROM  */
  YYSYMBOL_TMUL = 26,                      /* TMUL  */
  YYSYMBOL_TBY = 27,                       /* TBY  */
  YYSYMBOL_TDIV = 28,                      /* TDIV  */
  YYSYMBOL_TMARK = 29,                     /* TMARK  */
  YYSYMBOL_TEQ = 30,                       /* TEQ  */
  YYSYMBOL_TNEQ = 31,                      /* TNEQ  */
  YYSYMBOL_TLT = 32,                       /* TLT  */
  YYSYMBOL_TLE = 33,                       /* TLE  */
  YYSYMBOL_TGT = 34,                       /* TGT  */
  YYSYMBOL_TGE = 35,                       /* TGE  */
  YYSYMBOL_TOBR = 36,                      /* TOBR  */
  YYSYMBOL_TCBR = 37,                      /* TCBR  */
  YYSYMBOL_TIF = 38,                       /* TIF  */
  YYSYMBOL_TTHEN = 39,                     /* TTHEN  */
  YYSYMBOL_TELSE = 40,                     /* TELSE  */
  YYSYMBOL_TENDIF = 41,                    /* TENDIF  */
  YYSYMBOL_TDO = 42,                       /* TDO  */
  YYSYMBOL_TTIMES = 43,                    /* TTIMES  */
  YYSYMBOL_TDONE = 44,                     /* TDONE  */
  YYSYMBOL_TCOUNTER = 45,                  /* TCOUNTER  */
  YYSYMBOL_TDOWNTO = 46,                   /* TDOWNTO  */
  YYSYMBOL_TSTEP = 47,                     /* TSTEP  */
  YYSYMBOL_TWHILE = 48,                    /* TWHILE  */
  YYSYMBOL_TREPEAT = 49,                   /* TREPEAT  */
  YYSYMBOL_TUNTIL = 50,                    /* TUNTIL  */
  YYSYMBOL_TPATH = 51,                     /* TPATH  */
  YYSYMBOL_TENDPATH = 52,                  /* TENDPATH  */
  YYSYMBOL_TCALC = 53,                     /* TCALC  */
  YYSYMBOL_TRETURNS = 54,                  /* TRETURNS  */
  YYSYMBOL_TENDCALC = 55,                  /* TENDCALC  */
  YYSYMBOL_TABS = 56,                      /* TABS  */
  YYSYMBOL_TPLUS = 57,                     /* TPLUS  */
  YYSYMBOL_TMINUS = 58,                    /* TMINUS  */
  YYSYMBOL_TSTAR = 59,                     /* TSTAR  */
  YYSYMBOL_TDASH = 60,                     /* TDASH  */
  YYSYMBOL_TPOW = 61,                      /* TPOW  */
  YYSYMBOL_TOR = 62,                       /* TOR  */
  YYSYMBOL_TAND = 63,                      /* TAND  */
  YYSYMBOL_TNOT = 64,                      /* TNOT  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_Program = 66,                   /* Program  */
  YYSYMBOL_OStatements = 67,               /* OStatements  */
  YYSYMBOL_Statements = 68,                /* Statements  */
  YYSYMBOL_Statement = 69,                 /* Statement  */
  YYSYMBOL_OArgs = 70,                     /* OArgs  */
  YYSYMBOL_BRArgs = 71,                    /* BRArgs  */
  YYSYMBOL_Args = 72,                      /* Args  */
  YYSYMBOL_Expression = 73,                /* Expression  */
  YYSYMBOL_WMode = 74,                     /* WMode  */
  YYSYMBOL_WUMode = 75,                    /* WUMode  */
  YYSYMBOL_TMode = 76,                     /* TMode  */
  YYSYMBOL_Condition = 77,                 /* Condition  */
  YYSYMBOL_CounterMode = 78,               /* CounterMode  */
  YYSYMBOL_Definitions = 79,               /* Definitions  */
  YYSYMBOL_Definition = 80,                /* Definition  */
  YYSYMBOL_BRParams = 81,                  /* BRParams  */
  YYSYMBOL_OParams = 82,                   /* OParams  */
  YYSYMBOL_Params = 83                     /* Params  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    56,    59,    63,    67,    71,    76,    80,
      85,    89,    93,    97,   103,   106,   109,   112,   117,   122,
     127,   132,   137,   140,   146,   152,   157,   171,   185,   190,
     195,   205,   210,   216,   221,   227,   237,   244,   248,   252,
     259,   264,   269,   274,   279,   284,   288,   291,   296,   299,
     303,   306,   310,   313,   316,   320,   324,   329,   334,   339,
     344,   349,   354,   359,   364,   368,   371,   374,   376,   379,
     391,   404,   409,   415,   420,   426,   436
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TNUMBER", "TVAR",
  "TBEGIN", "TEND", "TWALK", "TJUMP", "TTURN", "TBACK", "THOME", "TLEFT",
  "TRIGHT", "TDIR", "TCOLOR", "TCLEAR", "TSTOP", "TFINISH", "TCOMMA",
  "TSTORE", "TIN", "TADD", "TTO", "TSUB", "TFROM", "TMUL", "TBY", "TDIV",
  "TMARK", "TEQ", "TNEQ", "TLT", "TLE", "TGT", "TGE", "TOBR", "TCBR",
  "TIF", "TTHEN", "TELSE", "TENDIF", "TDO", "TTIMES", "TDONE", "TCOUNTER",
  "TDOWNTO", "TSTEP", "TWHILE", "TREPEAT", "TUNTIL", "TPATH", "TENDPATH",
  "TCALC", "TRETURNS", "TENDCALC", "TABS", "TPLUS", "TMINUS", "TSTAR",
  "TDASH", "TPOW", "TOR", "TAND", "TNOT", "$accept", "Program",
  "OStatements", "Statements", "Statement", "OArgs", "BRArgs", "Args",
  "Expression", "WMode", "WUMode", "TMode", "Condition", "CounterMode",
  "Definitions", "Definition", "BRParams", "OParams", "Params", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,     2,    15,    35,    33,    18,    49,    49,   -33,   146,
     -33,     0,   -33,   146,   146,    36,    36,     9,    12,    12,
     -33,   -33,   -33,    12,    12,    12,    89,    93,   -33,    47,
      12,    95,    47,   146,   100,   103,   146,   -33,   -33,    -6,
      63,    73,   -33,   -33,   -33,   -33,    12,   -33,    12,   -33,
     -33,   -33,    12,   -33,    85,    12,    12,    12,   204,    59,
      71,    -5,   142,   108,   110,    47,    47,   180,   -29,   193,
     113,    17,    91,    85,   -33,   -33,   135,   -33,   -33,    12,
     204,   204,   204,     8,   -33,   -32,   199,     1,    12,    12,
      12,    12,    12,    12,   139,   145,   147,    12,    12,   148,
     -20,   -33,    12,    12,    12,    12,    12,    12,   146,    47,
      47,   146,    12,   146,    47,   -33,   -33,   -33,   165,   -33,
      75,   204,   -33,   -33,     1,     1,    97,    97,    97,    65,
     -33,   -33,   -33,   204,   204,   -33,   204,   204,   204,   204,
     204,   204,    67,    96,   -33,   112,    87,   121,    51,   -33,
      12,   -33,    12,   146,   -33,   -33,   -33,   -33,    12,   -33,
     204,   204,   128,   174,   -33,   146,    12,   127,   185,   -33,
     146,   129,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      67,     0,     0,     0,     0,    67,    73,     0,     1,     0,
      68,     0,    74,     0,     3,    48,    48,    52,     0,     0,
      14,    15,    16,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     6,    76,    71,     0,
       0,     0,     4,    49,    50,    51,     0,     8,     0,    10,
      53,    54,     0,    37,    38,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     2,     5,     0,    72,    69,     0,
       7,     9,    11,     0,    39,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    32,    75,     0,    33,
       0,    36,    46,    47,    40,    41,    42,    43,    44,     0,
      17,    18,    19,    20,    21,    64,    58,    59,    60,    61,
      62,    63,     0,    57,    56,     0,     0,     0,    29,    70,
       0,    34,     0,     0,    23,    25,    65,    66,     0,    28,
      35,    13,     0,     0,    24,     0,     0,     0,     0,    26,
       0,     0,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   -33,   -33,   -13,   -33,   -33,   104,   -33,   -16,   160,
     170,   -33,    -8,   -33,   182,   -33,   183,   -33,   -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    41,    35,    36,   115,    84,   120,    67,    46,
      47,    52,    68,   158,     4,     5,    12,    13,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    42,    58,    59,    37,   122,     6,    60,    61,    62,
     108,    53,    54,    76,    69,    53,    54,   135,    95,     7,
      72,    50,    51,    75,    71,    88,    89,    90,    91,    92,
      80,    77,    81,   109,   110,     8,    82,    38,     9,    85,
      86,    87,   109,   110,    55,   119,    43,    44,    55,    99,
      53,    54,    88,    89,    90,    91,    92,   100,   101,   113,
      90,    91,    92,   118,    56,    45,    57,   121,    56,     1,
      57,     2,   124,   125,   126,   127,   128,   129,    93,   109,
     110,   133,   134,    65,   152,    11,   136,   137,   138,   139,
     140,   141,    94,    63,   150,   142,   146,    64,   145,    70,
     147,   143,   144,    56,    73,    57,   148,   153,   154,    74,
     156,    66,   151,   109,   110,    78,    88,    89,    90,    91,
      92,    83,    88,    89,    90,    91,    92,    79,    88,    89,
      90,    91,    92,   157,   160,    97,   161,    98,   112,   117,
     162,   114,   163,   130,    88,    89,    90,    91,    92,   131,
     168,   132,   167,    15,    16,    17,   155,   171,    92,   110,
      18,    19,    20,    21,    22,   159,    23,    96,    24,   164,
      25,   169,    26,   172,    27,    28,    48,   116,   102,   103,
     104,   105,   106,   107,    29,   122,    49,    10,    30,     0,
      14,    31,     0,     0,    32,    33,     0,    34,     0,    88,
      89,    90,    91,    92,     0,    88,    89,    90,    91,    92,
     102,   103,   104,   105,   106,   107,   165,     0,     0,     0,
     149,   166,    88,    89,    90,    91,    92,   170,     0,     0,
       0,    88,    89,    90,    91,    92,   111,    88,    89,    90,
      91,    92,    88,    89,    90,    91,    92,     0,     0,     0,
      88,    89,    90,    91,    92,   123,    88,    89,    90,    91,
      92,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      13,    14,    18,    19,     4,    37,     4,    23,    24,    25,
      39,     3,     4,    19,    30,     3,     4,    37,    23,     4,
      33,    12,    13,    36,    32,    57,    58,    59,    60,    61,
      46,    37,    48,    62,    63,     0,    52,    37,     5,    55,
      56,    57,    62,    63,    36,    37,    10,    11,    36,    65,
       3,     4,    57,    58,    59,    60,    61,    65,    66,    42,
      59,    60,    61,    79,    56,    29,    58,    83,    56,    51,
      58,    53,    88,    89,    90,    91,    92,    93,    19,    62,
      63,    97,    98,    36,    19,    36,   102,   103,   104,   105,
     106,   107,    21,     4,    19,   108,   112,     4,   111,     4,
     113,   109,   110,    56,     4,    58,   114,    40,    41,     6,
      23,    64,    37,    62,    63,    52,    57,    58,    59,    60,
      61,    36,    57,    58,    59,    60,    61,    54,    57,    58,
      59,    60,    61,    46,   150,    27,   152,    27,    25,     4,
     153,    50,   158,     4,    57,    58,    59,    60,    61,     4,
     166,     4,   165,     7,     8,     9,    44,   170,    61,    63,
      14,    15,    16,    17,    18,    44,    20,    25,    22,    41,
      24,    44,    26,    44,    28,    29,    16,    73,    30,    31,
      32,    33,    34,    35,    38,    37,    16,     5,    42,    -1,
       7,    45,    -1,    -1,    48,    49,    -1,    51,    -1,    57,
      58,    59,    60,    61,    -1,    57,    58,    59,    60,    61,
      30,    31,    32,    33,    34,    35,    42,    -1,    -1,    -1,
      55,    47,    57,    58,    59,    60,    61,    42,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    43,    57,    58,    59,
      60,    61,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    56,    57,    58,    59,    60,
      61,    57,    58,    59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    53,    66,    79,    80,     4,     4,     0,     5,
      79,    36,    81,    82,    81,     7,     8,     9,    14,    15,
      16,    17,    18,    20,    22,    24,    26,    28,    29,    38,
      42,    45,    48,    49,    51,    68,    69,     4,    37,    83,
      68,    67,    68,    10,    11,    29,    74,    75,    74,    75,
      12,    13,    76,     3,     4,    36,    56,    58,    73,    73,
      73,    73,    73,     4,     4,    36,    64,    73,    77,    73,
       4,    77,    68,     4,     6,    68,    19,    37,    52,    54,
      73,    73,    73,    36,    71,    73,    73,    73,    57,    58,
      59,    60,    61,    19,    21,    23,    25,    27,    27,    73,
      77,    77,    30,    31,    32,    33,    34,    35,    39,    62,
      63,    43,    25,    42,    50,    70,    71,     4,    73,    37,
      72,    73,    37,    56,    73,    73,    73,    73,    73,    73,
       4,     4,     4,    73,    73,    37,    73,    73,    73,    73,
      73,    73,    68,    77,    77,    68,    73,    68,    77,    55,
      19,    37,    19,    40,    41,    44,    23,    46,    78,    44,
      73,    73,    68,    73,    41,    42,    47,    68,    73,    44,
      42,    68,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     1,     2,     1,     3,     2,     3,
       2,     3,     2,     6,     1,     1,     1,     4,     4,     4,
       4,     4,     1,     5,     7,     5,     9,    11,     5,     4,
       3,     0,     1,     2,     3,     3,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     2,     3,     3,     0,     1,
       1,     1,     0,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     0,     2,     5,
       7,     2,     3,     0,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: Definitions TBEGIN Statements TEND  */
#line 52 "turtle.y"
                                       {
        root = (yyvsp[-1].node);
    }
#line 1292 "turtle.tab.c"
    break;

  case 3: /* OStatements: %empty  */
#line 56 "turtle.y"
                {
        (yyval.node) = NULL;
    }
#line 1300 "turtle.tab.c"
    break;

  case 4: /* OStatements: Statements  */
#line 59 "turtle.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1308 "turtle.tab.c"
    break;

  case 5: /* Statements: Statement Statements  */
#line 63 "turtle.y"
                         {
        (yyvsp[-1].node)->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1317 "turtle.tab.c"
    break;

  case 6: /* Statements: Statement  */
#line 67 "turtle.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1325 "turtle.tab.c"
    break;

  case 7: /* Statement: TWALK WMode Expression  */
#line 71 "turtle.y"
                           {
        (yyval.node) = new_node(keyw_walk);
        (yyval.node)->d.walk = (yyvsp[-1].type);
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1335 "turtle.tab.c"
    break;

  case 8: /* Statement: TWALK WUMode  */
#line 76 "turtle.y"
                  {
        (yyval.node) = new_node(keyw_walk);
        (yyval.node)->d.walk = (yyvsp[0].type);
    }
#line 1344 "turtle.tab.c"
    break;

  case 9: /* Statement: TJUMP WMode Expression  */
#line 80 "turtle.y"
                            {
        (yyval.node) = new_node(keyw_jump);
        (yyval.node)->d.walk = (yyvsp[-1].type);
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1354 "turtle.tab.c"
    break;

  case 10: /* Statement: TJUMP WUMode  */
#line 85 "turtle.y"
                  {
        (yyval.node) = new_node(keyw_jump);
        (yyval.node)->d.walk = (yyvsp[0].type);
    }
#line 1363 "turtle.tab.c"
    break;

  case 11: /* Statement: TTURN TMode Expression  */
#line 89 "turtle.y"
                            {
        (yyval.node) = new_node((yyvsp[-1].type));
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1372 "turtle.tab.c"
    break;

  case 12: /* Statement: TDIR Expression  */
#line 93 "turtle.y"
                     {
        (yyval.node) = new_node(keyw_direction);
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1381 "turtle.tab.c"
    break;

  case 13: /* Statement: TCOLOR Expression TCOMMA Expression TCOMMA Expression  */
#line 97 "turtle.y"
                                                           {
        (yyval.node) = new_node(keyw_color);
        (yyval.node)->son[0] = (yyvsp[-4].node);
        (yyval.node)->son[1] = (yyvsp[-2].node);
        (yyval.node)->son[2] = (yyvsp[0].node);
    }
#line 1392 "turtle.tab.c"
    break;

  case 14: /* Statement: TCLEAR  */
#line 103 "turtle.y"
            {
        (yyval.node) = new_node(keyw_clear);
    }
#line 1400 "turtle.tab.c"
    break;

  case 15: /* Statement: TSTOP  */
#line 106 "turtle.y"
           {
        (yyval.node) = new_node(keyw_stop);
    }
#line 1408 "turtle.tab.c"
    break;

  case 16: /* Statement: TFINISH  */
#line 109 "turtle.y"
             {
        (yyval.node) = new_node(keyw_finish);
    }
#line 1416 "turtle.tab.c"
    break;

  case 17: /* Statement: TSTORE Expression TIN TVAR  */
#line 112 "turtle.y"
                                {
        (yyval.node) = new_node(keyw_store);
        (yyval.node)->d.p_name = (yyvsp[0].var);
        (yyval.node)->son[0] = (yyvsp[-2].node);
    }
#line 1426 "turtle.tab.c"
    break;

  case 18: /* Statement: TADD Expression TTO TVAR  */
#line 117 "turtle.y"
                              {
        (yyval.node) = new_node(keyw_add);
        (yyval.node)->d.p_name = (yyvsp[0].var);
        (yyval.node)->son[0] = (yyvsp[-2].node);
    }
#line 1436 "turtle.tab.c"
    break;

  case 19: /* Statement: TSUB Expression TFROM TVAR  */
#line 122 "turtle.y"
                                {
        (yyval.node) = new_node(keyw_sub);
        (yyval.node)->d.p_name = (yyvsp[0].var);
        (yyval.node)->son[0] = (yyvsp[-2].node);
    }
#line 1446 "turtle.tab.c"
    break;

  case 20: /* Statement: TMUL TVAR TBY Expression  */
#line 127 "turtle.y"
                              {
        (yyval.node) = new_node(keyw_mul);
        (yyval.node)->d.p_name = (yyvsp[-2].var);
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1456 "turtle.tab.c"
    break;

  case 21: /* Statement: TDIV TVAR TBY Expression  */
#line 132 "turtle.y"
                              {
        (yyval.node) = new_node(keyw_div);
        (yyval.node)->d.p_name = (yyvsp[-2].var);
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1466 "turtle.tab.c"
    break;

  case 22: /* Statement: TMARK  */
#line 137 "turtle.y"
           {
        (yyval.node) = new_node(keyw_mark);
    }
#line 1474 "turtle.tab.c"
    break;

  case 23: /* Statement: TIF Condition TTHEN Statements TENDIF  */
#line 140 "turtle.y"
                                           {
        (yyval.node) = new_node(keyw_if);
        (yyval.node)->son[0] = (yyvsp[-3].node);
        (yyval.node)->son[1] = (yyvsp[-1].node);
        (yyval.node)->son[2] = NULL;
    }
#line 1485 "turtle.tab.c"
    break;

  case 24: /* Statement: TIF Condition TTHEN Statements TELSE Statements TENDIF  */
#line 146 "turtle.y"
                                                            {
        (yyval.node) = new_node(keyw_if);
        (yyval.node)->son[0] = (yyvsp[-5].node);
        (yyval.node)->son[1] = (yyvsp[-3].node);
        (yyval.node)->son[2] = (yyvsp[-1].node);
    }
#line 1496 "turtle.tab.c"
    break;

  case 25: /* Statement: TDO Expression TTIMES Statements TDONE  */
#line 152 "turtle.y"
                                            {
        (yyval.node) = new_node(keyw_do);
        (yyval.node)->son[0] = (yyvsp[-3].node);
        (yyval.node)->son[1] = (yyvsp[-1].node);
    }
#line 1506 "turtle.tab.c"
    break;

  case 26: /* Statement: TCOUNTER TVAR TFROM Expression CounterMode Expression TDO Statements TDONE  */
#line 157 "turtle.y"
                                                                                {
        (yyval.node) = new_node(keyw_counter);
        (yyval.node)->d.p_name = (yyvsp[-7].var);
        (yyval.node)->son[0] = (yyvsp[-5].node);
        if ((yyvsp[-4].type) == keyw_countto) {
            (yyval.node)->son[1] = (yyvsp[-3].node);
            (yyval.node)->son[2] = NULL;
        } else {
            (yyval.node)->son[1] = NULL;
            (yyval.node)->son[2] = (yyvsp[-3].node);
        }
        (yyval.node)->son[3] = NULL;
        (yyval.node)->son[4] = (yyvsp[-1].node);
    }
#line 1525 "turtle.tab.c"
    break;

  case 27: /* Statement: TCOUNTER TVAR TFROM Expression CounterMode Expression TSTEP Expression TDO Statements TDONE  */
#line 171 "turtle.y"
                                                                                                 {
        (yyval.node) = new_node(keyw_counter);
        (yyval.node)->d.p_name = (yyvsp[-9].var);
        (yyval.node)->son[0] = (yyvsp[-7].node);
        if ((yyvsp[-6].type) == keyw_countto) {
            (yyval.node)->son[1] = (yyvsp[-5].node);
            (yyval.node)->son[2] = NULL;
        } else {
            (yyval.node)->son[1] = NULL;
            (yyval.node)->son[2] = (yyvsp[-5].node);
        }
        (yyval.node)->son[3] = (yyvsp[-3].node);
        (yyval.node)->son[4] = (yyvsp[-1].node);
    }
#line 1544 "turtle.tab.c"
    break;

  case 28: /* Statement: TWHILE Condition TDO Statements TDONE  */
#line 185 "turtle.y"
                                           {
        (yyval.node) = new_node(keyw_while);
        (yyval.node)->son[0] = (yyvsp[-3].node);
        (yyval.node)->son[1] = (yyvsp[-1].node);
    }
#line 1554 "turtle.tab.c"
    break;

  case 29: /* Statement: TREPEAT Statements TUNTIL Condition  */
#line 190 "turtle.y"
                                         {
        (yyval.node) = new_node(keyw_repeat);
        (yyval.node)->son[0] = (yyvsp[0].node);
        (yyval.node)->son[1] = (yyvsp[-2].node);
    }
#line 1564 "turtle.tab.c"
    break;

  case 30: /* Statement: TPATH TVAR OArgs  */
#line 195 "turtle.y"
                      {
        (yyval.node) = new_node(keyw_path);
        (yyval.node)->d.p_name = (yyvsp[-1].var);
        if ((yyvsp[0].args)) {
            for (int i = 0; i < MAX_ARGS; i++) {
                (yyval.node)->son[i] = (yyvsp[0].args)[i];
            }
        }
    }
#line 1578 "turtle.tab.c"
    break;

  case 31: /* OArgs: %empty  */
#line 205 "turtle.y"
                {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.args)[i] = NULL;
        }
    }
#line 1588 "turtle.tab.c"
    break;

  case 32: /* OArgs: BRArgs  */
#line 210 "turtle.y"
            {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.args)[i] = (yyvsp[0].args)[i];
        }
    }
#line 1598 "turtle.tab.c"
    break;

  case 33: /* BRArgs: TOBR TCBR  */
#line 216 "turtle.y"
              {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.args)[i] = NULL;
        }
    }
#line 1608 "turtle.tab.c"
    break;

  case 34: /* BRArgs: TOBR Args TCBR  */
#line 221 "turtle.y"
                    {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.args)[i] = (yyvsp[-1].args)[i];
        }
    }
#line 1618 "turtle.tab.c"
    break;

  case 35: /* Args: Args TCOMMA Expression  */
#line 227 "turtle.y"
                           {
        int i;
        for (i = 0; i < MAX_ARGS && (yyvsp[-2].args)[i]; i++) {
            (yyval.args)[i] = (yyvsp[-2].args)[i];
        }
        if (i >= MAX_ARGS) {
            yyerror("too many arguments!");
        }
        (yyval.args)[i] = (yyvsp[0].node);
    }
#line 1633 "turtle.tab.c"
    break;

  case 36: /* Args: Expression  */
#line 237 "turtle.y"
                {
        (yyval.args)[0] = (yyvsp[0].node);
        for (int i = 1; i < MAX_ARGS; i++) {
            (yyval.args)[i] = NULL;
        }
    }
#line 1644 "turtle.tab.c"
    break;

  case 37: /* Expression: TNUMBER  */
#line 244 "turtle.y"
            {
        (yyval.node) = new_node(oper_const);
        (yyval.node)->d.val = (yyvsp[0].number);
    }
#line 1653 "turtle.tab.c"
    break;

  case 38: /* Expression: TVAR  */
#line 248 "turtle.y"
          {
        (yyval.node) = new_node(name_any);
        (yyval.node)->d.p_name = (yyvsp[0].var);
    }
#line 1662 "turtle.tab.c"
    break;

  case 39: /* Expression: TVAR BRArgs  */
#line 252 "turtle.y"
                 {
        (yyval.node) = new_node(oper_lpar);
        (yyval.node)->d.p_name = (yyvsp[-1].var);
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.node)->son[i] = (yyvsp[0].args)[i];
        }
    }
#line 1674 "turtle.tab.c"
    break;

  case 40: /* Expression: Expression TPLUS Expression  */
#line 259 "turtle.y"
                                 {
        (yyval.node) = new_node(oper_add);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1684 "turtle.tab.c"
    break;

  case 41: /* Expression: Expression TMINUS Expression  */
#line 264 "turtle.y"
                                  {
        (yyval.node) = new_node(oper_sub);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1694 "turtle.tab.c"
    break;

  case 42: /* Expression: Expression TSTAR Expression  */
#line 269 "turtle.y"
                                 {
        (yyval.node) = new_node(oper_mul);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1704 "turtle.tab.c"
    break;

  case 43: /* Expression: Expression TDASH Expression  */
#line 274 "turtle.y"
                                 {
        (yyval.node) = new_node(oper_div);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1714 "turtle.tab.c"
    break;

  case 44: /* Expression: Expression TPOW Expression  */
#line 279 "turtle.y"
                                {
        (yyval.node) = new_node(oper_pow);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1724 "turtle.tab.c"
    break;

  case 45: /* Expression: TMINUS Expression  */
#line 284 "turtle.y"
                       {
        (yyval.node) = new_node(oper_neg);
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1733 "turtle.tab.c"
    break;

  case 46: /* Expression: TOBR Expression TCBR  */
#line 288 "turtle.y"
                          {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1741 "turtle.tab.c"
    break;

  case 47: /* Expression: TABS Expression TABS  */
#line 291 "turtle.y"
                          {
        (yyval.node) = new_node(oper_abs);
        (yyval.node)->son[0] = (yyvsp[-1].node);
    }
#line 1750 "turtle.tab.c"
    break;

  case 48: /* WMode: %empty  */
#line 296 "turtle.y"
                {
        (yyval.type) = keyw_walk;
    }
#line 1758 "turtle.tab.c"
    break;

  case 49: /* WMode: TBACK  */
#line 299 "turtle.y"
           {
        (yyval.type) = keyw_back;
    }
#line 1766 "turtle.tab.c"
    break;

  case 50: /* WUMode: THOME  */
#line 303 "turtle.y"
          {
        (yyval.type) = keyw_home;
    }
#line 1774 "turtle.tab.c"
    break;

  case 51: /* WUMode: TMARK  */
#line 306 "turtle.y"
           {
        (yyval.type) = keyw_mark;
    }
#line 1782 "turtle.tab.c"
    break;

  case 52: /* TMode: %empty  */
#line 310 "turtle.y"
                {
        (yyval.type) = keyw_right;
    }
#line 1790 "turtle.tab.c"
    break;

  case 53: /* TMode: TLEFT  */
#line 313 "turtle.y"
           {
        (yyval.type) = keyw_left;
    }
#line 1798 "turtle.tab.c"
    break;

  case 54: /* TMode: TRIGHT  */
#line 316 "turtle.y"
            {
        (yyval.type) = keyw_right;
    }
#line 1806 "turtle.tab.c"
    break;

  case 55: /* Condition: TNOT Condition  */
#line 320 "turtle.y"
                   {
        (yyval.node) = new_node(keyw_not);
        (yyval.node)->son[0] = (yyvsp[0].node);
    }
#line 1815 "turtle.tab.c"
    break;

  case 56: /* Condition: Condition TAND Condition  */
#line 324 "turtle.y"
                              {
        (yyval.node) = new_node(keyw_and);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1825 "turtle.tab.c"
    break;

  case 57: /* Condition: Condition TOR Condition  */
#line 329 "turtle.y"
                             {
        (yyval.node) = new_node(keyw_or);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1835 "turtle.tab.c"
    break;

  case 58: /* Condition: Expression TEQ Expression  */
#line 334 "turtle.y"
                               {
        (yyval.node) = new_node(oper_equ);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1845 "turtle.tab.c"
    break;

  case 59: /* Condition: Expression TNEQ Expression  */
#line 339 "turtle.y"
                                {
        (yyval.node) = new_node(oper_nequ);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1855 "turtle.tab.c"
    break;

  case 60: /* Condition: Expression TLT Expression  */
#line 344 "turtle.y"
                               {
        (yyval.node) = new_node(oper_less);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1865 "turtle.tab.c"
    break;

  case 61: /* Condition: Expression TLE Expression  */
#line 349 "turtle.y"
                               {
        (yyval.node) = new_node(oper_lequ);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1875 "turtle.tab.c"
    break;

  case 62: /* Condition: Expression TGT Expression  */
#line 354 "turtle.y"
                               {
        (yyval.node) = new_node(oper_grtr);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1885 "turtle.tab.c"
    break;

  case 63: /* Condition: Expression TGE Expression  */
#line 359 "turtle.y"
                               {
        (yyval.node) = new_node(oper_gequ);
        (yyval.node)->son[0] = (yyvsp[-2].node);
        (yyval.node)->son[1] = (yyvsp[0].node);
    }
#line 1895 "turtle.tab.c"
    break;

  case 64: /* Condition: TOBR Condition TCBR  */
#line 364 "turtle.y"
                         {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1903 "turtle.tab.c"
    break;

  case 65: /* CounterMode: TTO  */
#line 368 "turtle.y"
        {
        (yyval.type) = keyw_countto;
    }
#line 1911 "turtle.tab.c"
    break;

  case 66: /* CounterMode: TDOWNTO  */
#line 371 "turtle.y"
             {
        (yyval.type) = keyw_downto;
    }
#line 1919 "turtle.tab.c"
    break;

  case 69: /* Definition: TPATH TVAR OParams Statements TENDPATH  */
#line 379 "turtle.y"
                                           {
        funcdef_t *func = malloc(sizeof(funcdef_t));
        func->body = (yyvsp[-1].node);
        func->ret = NULL;
        if ((yyvsp[-2].params)) {
            for (int i = 0; i < MAX_ARGS; i++) {
                func->params[i] = (yyvsp[-2].params)[i];
            }
        }
        (yyvsp[-3].var)->d.func = func;
        (yyvsp[-3].var)->type = name_path;
    }
#line 1936 "turtle.tab.c"
    break;

  case 70: /* Definition: TCALC TVAR BRParams OStatements TRETURNS Expression TENDCALC  */
#line 391 "turtle.y"
                                                                  {
        funcdef_t *func = malloc(sizeof(funcdef_t));
        func->body = (yyvsp[-3].node);
        func->ret = (yyvsp[-1].node);
        if ((yyvsp[-4].params)) {
            for (int i = 0; i < MAX_ARGS; i++) {
                func->params[i] = (yyvsp[-4].params)[i];
            }
        }
        (yyvsp[-5].var)->d.func = func;
        (yyvsp[-5].var)->type = name_calc;
    }
#line 1953 "turtle.tab.c"
    break;

  case 71: /* BRParams: TOBR TCBR  */
#line 404 "turtle.y"
              {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.params)[i] = NULL;
        }
    }
#line 1963 "turtle.tab.c"
    break;

  case 72: /* BRParams: TOBR Params TCBR  */
#line 409 "turtle.y"
                      {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.params)[i] = (yyvsp[-1].params)[i];
        }
    }
#line 1973 "turtle.tab.c"
    break;

  case 73: /* OParams: %empty  */
#line 415 "turtle.y"
                {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.params)[i] = NULL;
        }
    }
#line 1983 "turtle.tab.c"
    break;

  case 74: /* OParams: BRParams  */
#line 420 "turtle.y"
              {
        for (int i = 0; i < MAX_ARGS; i++) {
            (yyval.params)[i] = (yyvsp[0].params)[i];
        }
    }
#line 1993 "turtle.tab.c"
    break;

  case 75: /* Params: Params TCOMMA TVAR  */
#line 426 "turtle.y"
                       {
        int i;
        for (i = 0; i < MAX_ARGS && (yyvsp[-2].params)[i]; i++) {
            (yyval.params)[i] = (yyvsp[-2].params)[i];
        }
        if (i >= MAX_ARGS) {
            yyerror("too many params!");
        }
        (yyval.params)[i] = (yyvsp[0].var);
    }
#line 2008 "turtle.tab.c"
    break;

  case 76: /* Params: TVAR  */
#line 436 "turtle.y"
          {
        (yyval.params)[0] = (yyvsp[0].var);
        for (int i = 1; i < MAX_ARGS; i++) {
            (yyval.params)[i] = NULL;
        }
    }
#line 2019 "turtle.tab.c"
    break;


#line 2023 "turtle.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 442 "turtle.y"

// Das folgende wird an's hintere Ende des erzeugten .c-Programms kopiert

// Die Funktion yyerror wird aufgerufen,
// wenn yacc erkennt, das der eingetippte Input fehlerhaft ist
// wir geben einfach die von yacc gelieferte Fehlermeldung aus
int yyerror(char *s) {
    printf("line %d: %s\n", yylineno, s);
}

// Das Hauptprogramm
// Wir rufen einfach die von yacc generierte Parser-Funktion auf
treenode_t *parse(void) {
    yyin = src_file;

    yyparse();

    return root;
}
