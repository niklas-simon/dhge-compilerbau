/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TURTLE_TAB_H_INCLUDED
# define YY_YY_TURTLE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TNUMBER = 258,                 /* TNUMBER  */
    TVAR = 259,                    /* TVAR  */
    TBEGIN = 260,                  /* TBEGIN  */
    TEND = 261,                    /* TEND  */
    TWALK = 262,                   /* TWALK  */
    TJUMP = 263,                   /* TJUMP  */
    TTURN = 264,                   /* TTURN  */
    TBACK = 265,                   /* TBACK  */
    THOME = 266,                   /* THOME  */
    TLEFT = 267,                   /* TLEFT  */
    TRIGHT = 268,                  /* TRIGHT  */
    TDIR = 269,                    /* TDIR  */
    TCOLOR = 270,                  /* TCOLOR  */
    TCLEAR = 271,                  /* TCLEAR  */
    TSTOP = 272,                   /* TSTOP  */
    TFINISH = 273,                 /* TFINISH  */
    TCOMMA = 274,                  /* TCOMMA  */
    TSTORE = 275,                  /* TSTORE  */
    TIN = 276,                     /* TIN  */
    TADD = 277,                    /* TADD  */
    TTO = 278,                     /* TTO  */
    TSUB = 279,                    /* TSUB  */
    TFROM = 280,                   /* TFROM  */
    TMUL = 281,                    /* TMUL  */
    TBY = 282,                     /* TBY  */
    TDIV = 283,                    /* TDIV  */
    TMARK = 284,                   /* TMARK  */
    TEQ = 285,                     /* TEQ  */
    TNEQ = 286,                    /* TNEQ  */
    TLT = 287,                     /* TLT  */
    TLE = 288,                     /* TLE  */
    TGT = 289,                     /* TGT  */
    TGE = 290,                     /* TGE  */
    TOBR = 291,                    /* TOBR  */
    TCBR = 292,                    /* TCBR  */
    TIF = 293,                     /* TIF  */
    TTHEN = 294,                   /* TTHEN  */
    TELSE = 295,                   /* TELSE  */
    TENDIF = 296,                  /* TENDIF  */
    TDO = 297,                     /* TDO  */
    TTIMES = 298,                  /* TTIMES  */
    TDONE = 299,                   /* TDONE  */
    TCOUNTER = 300,                /* TCOUNTER  */
    TDOWNTO = 301,                 /* TDOWNTO  */
    TSTEP = 302,                   /* TSTEP  */
    TWHILE = 303,                  /* TWHILE  */
    TREPEAT = 304,                 /* TREPEAT  */
    TUNTIL = 305,                  /* TUNTIL  */
    TPATH = 306,                   /* TPATH  */
    TENDPATH = 307,                /* TENDPATH  */
    TCALC = 308,                   /* TCALC  */
    TRETURNS = 309,                /* TRETURNS  */
    TENDCALC = 310,                /* TENDCALC  */
    TABS = 311,                    /* TABS  */
    TPLUS = 312,                   /* TPLUS  */
    TMINUS = 313,                  /* TMINUS  */
    TSTAR = 314,                   /* TSTAR  */
    TDASH = 315,                   /* TDASH  */
    TPOW = 316,                    /* TPOW  */
    TOR = 317,                     /* TOR  */
    TAND = 318,                    /* TAND  */
    TNOT = 319                     /* TNOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "turtle.y"

    treenode_t *node;
    double number;
    type_t type;
    nameentry_t *var;
    params_t params;
    args_t args;

#line 137 "turtle.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TURTLE_TAB_H_INCLUDED  */
