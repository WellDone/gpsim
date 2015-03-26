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
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ABORT = 258,
     ATTACH = 259,
     BREAK = 260,
     BUS = 261,
     CLEAR = 262,
     DISASSEMBLE = 263,
     DUMP = 264,
     ENDM = 265,
     FREQUENCY = 266,
     HELP = 267,
     LOAD = 268,
     LOG = 269,
     LIST = 270,
     NODE = 271,
     MACRO = 272,
     MODULE = 273,
     PROCESSOR = 274,
     QUIT = 275,
     RESET = 276,
     RUN = 277,
     SET = 278,
     SHELL = 279,
     STEP = 280,
     STIMULUS = 281,
     SYMBOL = 282,
     TRACE = 283,
     gpsim_VERSION = 284,
     X = 285,
     ICD = 286,
     END_OF_COMMAND = 287,
     MACROBODY_T = 288,
     MACROINVOCATION_T = 289,
     INDIRECT = 290,
     END_OF_INPUT = 291,
     BIT_FLAG = 292,
     EXPRESSION_OPTION = 293,
     NUMERIC_OPTION = 294,
     STRING_OPTION = 295,
     CMD_SUBTYPE = 296,
     SYMBOL_OPTION = 297,
     LITERAL_INT_T = 298,
     LITERAL_BOOL_T = 299,
     LITERAL_FLOAT_T = 300,
     LITERAL_STRING_T = 301,
     LITERAL_ARRAY_T = 302,
     SYMBOL_T = 303,
     GPSIMOBJECT_T = 304,
     PORT_T = 305,
     EQU_T = 306,
     AND_T = 307,
     COLON_T = 308,
     COMMENT_T = 309,
     DIV_T = 310,
     EOLN_T = 311,
     MINUS_T = 312,
     MPY_T = 313,
     OR_T = 314,
     PLUS_T = 315,
     SHL_T = 316,
     SHR_T = 317,
     XOR_T = 318,
     INDEXERLEFT_T = 319,
     INDEXERRIGHT_T = 320,
     DECLARE_TYPE = 321,
     DECLARE_INT_T = 322,
     DECLARE_FLOAT_T = 323,
     DECLARE_BOOL_T = 324,
     DECLARE_CHAR_T = 325,
     LOR_T = 326,
     LAND_T = 327,
     NE_T = 328,
     EQ_T = 329,
     ABS_T = 330,
     MAX_T = 331,
     MIN_T = 332,
     GE_T = 333,
     GT_T = 334,
     LE_T = 335,
     LT_T = 336,
     IND_T = 337,
     BITS_T = 338,
     BIT_T = 339,
     WORD_T = 340,
     LADDR_T = 341,
     HIGH_T = 342,
     LOW_T = 343,
     INDEXED_T = 344,
     UNARYOP_PREC = 345,
     ONESCOMP_T = 346,
     LNOT_T = 347,
     POW_T = 348,
     REG_T = 349
   };
#endif
/* Tokens.  */
#define ABORT 258
#define ATTACH 259
#define BREAK 260
#define BUS 261
#define CLEAR 262
#define DISASSEMBLE 263
#define DUMP 264
#define ENDM 265
#define FREQUENCY 266
#define HELP 267
#define LOAD 268
#define LOG 269
#define LIST 270
#define NODE 271
#define MACRO 272
#define MODULE 273
#define PROCESSOR 274
#define QUIT 275
#define RESET 276
#define RUN 277
#define SET 278
#define SHELL 279
#define STEP 280
#define STIMULUS 281
#define SYMBOL 282
#define TRACE 283
#define gpsim_VERSION 284
#define X 285
#define ICD 286
#define END_OF_COMMAND 287
#define MACROBODY_T 288
#define MACROINVOCATION_T 289
#define INDIRECT 290
#define END_OF_INPUT 291
#define BIT_FLAG 292
#define EXPRESSION_OPTION 293
#define NUMERIC_OPTION 294
#define STRING_OPTION 295
#define CMD_SUBTYPE 296
#define SYMBOL_OPTION 297
#define LITERAL_INT_T 298
#define LITERAL_BOOL_T 299
#define LITERAL_FLOAT_T 300
#define LITERAL_STRING_T 301
#define LITERAL_ARRAY_T 302
#define SYMBOL_T 303
#define GPSIMOBJECT_T 304
#define PORT_T 305
#define EQU_T 306
#define AND_T 307
#define COLON_T 308
#define COMMENT_T 309
#define DIV_T 310
#define EOLN_T 311
#define MINUS_T 312
#define MPY_T 313
#define OR_T 314
#define PLUS_T 315
#define SHL_T 316
#define SHR_T 317
#define XOR_T 318
#define INDEXERLEFT_T 319
#define INDEXERRIGHT_T 320
#define DECLARE_TYPE 321
#define DECLARE_INT_T 322
#define DECLARE_FLOAT_T 323
#define DECLARE_BOOL_T 324
#define DECLARE_CHAR_T 325
#define LOR_T 326
#define LAND_T 327
#define NE_T 328
#define EQ_T 329
#define ABS_T 330
#define MAX_T 331
#define MIN_T 332
#define GE_T 333
#define GT_T 334
#define LE_T 335
#define LT_T 336
#define IND_T 337
#define BITS_T 338
#define BIT_T 339
#define WORD_T 340
#define LADDR_T 341
#define HIGH_T 342
#define LOW_T 343
#define INDEXED_T 344
#define UNARYOP_PREC 345
#define ONESCOMP_T 346
#define LNOT_T 347
#define POW_T 348
#define REG_T 349




/* Copy the first part of user declarations.  */
#line 2 "parse.yy"

/* Parser for gpsim
   Copyright (C) 1999 Scott Dattalo

This file is part of gpsim.

gpsim is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

gpsim is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with gpsim; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <typeinfo>
#include <unistd.h>
#include <glib.h>
using namespace std;

#include "misc.h"
#include "command.h"

#include "cmd_attach.h"
#include "cmd_break.h"
#include "cmd_bus.h"
#include "cmd_clear.h"
#include "cmd_disasm.h"
#include "cmd_dump.h"
#include "cmd_frequency.h"
#include "cmd_help.h"
#include "cmd_list.h"
#include "cmd_load.h"
#include "cmd_log.h"
#include "cmd_node.h"
#include "cmd_macro.h"
#include "cmd_module.h"
#include "cmd_processor.h"
#include "cmd_quit.h"
#include "cmd_reset.h"
#include "cmd_run.h"
#include "cmd_set.h"
#include "cmd_step.h"
#include "cmd_shell.h"
#include "cmd_stimulus.h"
#include "cmd_symbol.h"
#include "cmd_trace.h"
#include "cmd_version.h"
#include "cmd_x.h"
#include "cmd_icd.h"
#include "../src/expr.h"
#include "../src/operator.h"

#include "../src/symbol.h"
#include "../src/stimuli.h"
#include "../src/processor.h"

extern void lexer_setMacroBodyMode();
extern void lexer_InvokeMacro(Macro *m);
extern void lexer_setDeclarationMode();

#define YYERROR_VERBOSE

extern char *yytext; 
int quit_parse=0;
int abort_gpsim=0;
int parser_warnings;
int parser_spanning_lines=0;
int gAbortParserOnSyntaxError=0;
extern int use_gui;
extern int quit_state;

extern command *getLastKnownCommand();
extern void init_cmd_state();
extern const char * GetLastFullCommand();
// From scan.ll
void FlushLexerBuffer();

void yyerror(const char *message)
{
  printf("***ERROR: %s while parsing:\n'%s'\n",message, yytext);
  const char *last = GetLastFullCommand();
  if (last)
    printf(" Last command: %s\n", last);
  init_cmd_state();
  // JRH - I added this hoping that it is an appropriate
  //       place to clear the lexer buffer. An example of
  //       failed command where this is needed is to index
  //       into an undefined symbol. (i.e. undefinedsymbol[0])
  FlushLexerBuffer();
}


int toInt(Expression *expr)
{

  try {
    if(expr) {

      Value *v = expr->evaluate();
      if (v) {
	int i;
	v->get(i);
        delete v;
	return i;
      }
    }

  }

  catch (Error *err) {
    if(err)
      cout << "ERROR:" << err->toString() << endl;
    delete err;
  }

  return -1;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 140 "parse.yy"
{
  guint32              i;
  guint64             li;
  float                f;
  char                *s;
  cmd_options        *co;
  cmd_options_num   *con;
  cmd_options_str   *cos;
  cmd_options_expr  *coe;

  BinaryOperator*           BinaryOperator_P;
  Boolean*                  Boolean_P;
  Expression*               Expression_P;
  Float*                    Float_P;
  Integer*                  Integer_P;
  String*                   String_P;
  gpsimObject*              Symbol_P;
  gpsimObject*              gpsimObject_P;

  StringList_t             *StringList_P;
  ExprList_t               *ExprList_P;
  gpsimObjectList_t        *gpsimObjectList_P;

  Macro                    *Macro_P;
}
/* Line 193 of yacc.c.  */
#line 443 "parse.cc"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 168 "parse.yy"

/* Define the interface to the lexer */
extern int yylex(YYSTYPE* lvalP);


/* Line 216 of yacc.c.  */
#line 460 "parse.cc"

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
#define YYFINAL  137
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNRULES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      95,    96,     2,     2,    97,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    98,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    99,     2,   100,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    71,    73,    75,    77,    80,
      81,    83,    85,    89,    91,    94,    96,    98,   101,   105,
     109,   112,   115,   117,   120,   125,   128,   130,   133,   135,
     138,   142,   147,   149,   153,   157,   162,   169,   174,   181,
     183,   186,   188,   191,   194,   196,   199,   203,   208,   211,
     214,   218,   222,   224,   227,   229,   232,   235,   239,   241,
     244,   247,   251,   253,   256,   258,   260,   262,   265,   269,
     271,   274,   277,   279,   281,   284,   287,   290,   292,   295,
     298,   301,   303,   308,   311,   314,   316,   319,   322,   325,
     328,   331,   333,   335,   338,   340,   343,   345,   347,   349,
     350,   351,   360,   361,   363,   367,   368,   370,   372,   375,
     377,   380,   381,   382,   388,   389,   391,   393,   395,   397,
     399,   401,   404,   407,   410,   413,   415,   418,   420,   422,
     427,   431,   436,   441,   443,   445,   448,   450,   454,   458,
     462,   466,   470,   474,   478,   482,   486,   490,   494,   498,
     502,   506,   510,   514,   518,   522,   526,   528,   531,   534,
     537,   540,   543,   546,   550,   552,   554,   556,   558,   560,
     565
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     102,     0,    -1,   103,   104,    -1,   102,   103,   104,    -1,
      -1,   106,    -1,   107,    -1,   108,    -1,   111,    -1,   112,
      -1,   113,    -1,   145,    -1,   114,    -1,   115,    -1,   116,
      -1,   117,    -1,   118,    -1,   119,    -1,   109,    -1,   120,
      -1,   121,    -1,   137,    -1,   122,    -1,   123,    -1,   124,
      -1,   125,    -1,   126,    -1,   127,    -1,   128,    -1,   129,
      -1,   130,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,    36,    -1,     1,    -1,   105,    56,    -1,
      -1,    54,    -1,     3,    -1,     4,    48,   158,    -1,     5,
      -1,     5,    43,    -1,   110,    -1,    14,    -1,    14,   149,
      -1,    14,   149,   159,    -1,     5,   149,   159,    -1,     5,
     149,    -1,     5,    48,    -1,     6,    -1,     6,   154,    -1,
      48,    95,   159,    96,    -1,     7,   155,    -1,     8,    -1,
       8,   155,    -1,     9,    -1,     9,   149,    -1,     9,   149,
      48,    -1,     9,   149,    48,    46,    -1,    48,    -1,    95,
     155,    96,    -1,    48,    51,   155,    -1,    48,    64,   159,
      65,    -1,    48,    64,   159,    65,    51,   155,    -1,    94,
      95,   155,    96,    -1,    94,    95,   155,    96,    51,   155,
      -1,    11,    -1,    11,   155,    -1,    12,    -1,    12,    46,
      -1,    12,    48,    -1,    15,    -1,    15,   149,    -1,    13,
     149,    46,    -1,    13,   149,    48,    46,    -1,    13,    46,
      -1,    13,    48,    -1,    13,    48,    48,    -1,    13,    46,
      46,    -1,    16,    -1,    16,   154,    -1,    18,    -1,    18,
     149,    -1,    18,   153,    -1,    18,   153,   154,    -1,    19,
      -1,    19,   149,    -1,    19,    46,    -1,    19,    46,    46,
      -1,    20,    -1,    20,   155,    -1,    21,    -1,    22,    -1,
      23,    -1,    23,   149,    -1,    23,   149,   155,    -1,    25,
      -1,    25,   155,    -1,    25,   149,    -1,    24,    -1,    26,
      -1,    26,   150,    -1,   130,   131,    -1,   130,    32,    -1,
     151,    -1,   131,   149,    -1,   131,   153,    -1,   131,   156,
      -1,    27,    -1,    27,    46,    51,   162,    -1,    27,    46,
      -1,    27,    48,    -1,    28,    -1,    28,   155,    -1,    28,
     152,    -1,    28,   153,    -1,    28,   149,    -1,    28,   151,
      -1,    29,    -1,    30,    -1,    30,   155,    -1,    31,    -1,
      31,   153,    -1,    17,    -1,   138,    -1,    34,    -1,    -1,
      -1,    46,    17,   139,   141,   104,   140,   142,   144,    -1,
      -1,    46,    -1,   141,    97,    46,    -1,    -1,   143,    -1,
      33,    -1,   143,    33,    -1,    10,    -1,    46,    10,    -1,
      -1,    -1,    98,   146,   148,   147,    46,    -1,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    37,    -1,    41,
      -1,    38,   155,    -1,    39,   155,    -1,    40,    46,    -1,
      40,    48,    -1,    46,    -1,   154,    46,    -1,   160,    -1,
     161,    -1,    94,    95,   155,    96,    -1,    99,   159,   100,
      -1,    49,    95,    48,    96,    -1,    49,    95,    43,    96,
      -1,    48,    -1,   157,    -1,   158,   157,    -1,   155,    -1,
     159,    97,   155,    -1,   155,    60,   155,    -1,   155,    57,
     155,    -1,   155,    58,   155,    -1,   155,    55,   155,    -1,
     155,    52,   155,    -1,   155,    59,   155,    -1,   155,    63,
     155,    -1,   155,    61,   155,    -1,   155,    62,   155,    -1,
     155,    74,   155,    -1,   155,    73,   155,    -1,   155,    81,
     155,    -1,   155,    79,   155,    -1,   155,    80,   155,    -1,
     155,    78,   155,    -1,   155,    72,   155,    -1,   155,    71,
     155,    -1,   155,    53,   155,    -1,   162,    -1,    60,   161,
      -1,    57,   161,    -1,    91,   161,    -1,    92,   161,    -1,
      58,   161,    -1,    52,   161,    -1,    95,   155,    96,    -1,
      43,    -1,    44,    -1,    46,    -1,    45,    -1,    48,    -1,
      48,    64,   159,    65,    -1,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   313,   313,   317,   323,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   366,   383,   387,
     389,   393,   402,   409,   410,   411,   415,   416,   417,   422,
     423,   424,   428,   429,   432,   439,   443,   444,   448,   449,
     450,   456,   470,   478,   482,   497,   503,   510,   517,   527,
     528,   532,   533,   534,   538,   539,   542,   553,   564,   578,
     591,   605,   625,   626,   630,   631,   632,   637,   647,   651,
     655,   660,   668,   673,   682,   686,   690,   691,   692,   696,
     697,   698,   702,   705,   709,   713,   717,   727,   733,   739,
     745,   755,   756,   762,   763,   768,   769,   770,   771,   772,
     773,   776,   780,   781,   785,   786,   807,   808,   809,   815,
     817,   814,   822,   824,   829,   837,   839,   843,   844,   848,
     849,   870,   875,   869,   886,   887,   888,   889,   890,   914,
     920,   926,   929,   938,   946,   967,   968,   974,   975,   976,
     980,   983,   999,  1005,  1026,  1027,  1031,  1032,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1057,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1067,  1068,  1069,  1070,  1071,  1072,
    1073
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABORT", "ATTACH", "BREAK", "BUS",
  "CLEAR", "DISASSEMBLE", "DUMP", "ENDM", "FREQUENCY", "HELP", "LOAD",
  "LOG", "LIST", "NODE", "MACRO", "MODULE", "PROCESSOR", "QUIT", "RESET",
  "RUN", "SET", "SHELL", "STEP", "STIMULUS", "SYMBOL", "TRACE",
  "gpsim_VERSION", "X", "ICD", "END_OF_COMMAND", "MACROBODY_T",
  "MACROINVOCATION_T", "INDIRECT", "END_OF_INPUT", "BIT_FLAG",
  "EXPRESSION_OPTION", "NUMERIC_OPTION", "STRING_OPTION", "CMD_SUBTYPE",
  "SYMBOL_OPTION", "LITERAL_INT_T", "LITERAL_BOOL_T", "LITERAL_FLOAT_T",
  "LITERAL_STRING_T", "LITERAL_ARRAY_T", "SYMBOL_T", "GPSIMOBJECT_T",
  "PORT_T", "EQU_T", "AND_T", "COLON_T", "COMMENT_T", "DIV_T", "EOLN_T",
  "MINUS_T", "MPY_T", "OR_T", "PLUS_T", "SHL_T", "SHR_T", "XOR_T",
  "INDEXERLEFT_T", "INDEXERRIGHT_T", "DECLARE_TYPE", "DECLARE_INT_T",
  "DECLARE_FLOAT_T", "DECLARE_BOOL_T", "DECLARE_CHAR_T", "LOR_T", "LAND_T",
  "NE_T", "EQ_T", "ABS_T", "MAX_T", "MIN_T", "GE_T", "GT_T", "LE_T",
  "LT_T", "IND_T", "BITS_T", "BIT_T", "WORD_T", "LADDR_T", "HIGH_T",
  "LOW_T", "INDEXED_T", "UNARYOP_PREC", "ONESCOMP_T", "LNOT_T", "POW_T",
  "REG_T", "'('", "')'", "','", "'\\\\'", "'{'", "'}'", "$accept",
  "list_of_commands", "cmd", "rol", "opt_comment", "aborting",
  "attach_cmd", "break_cmd", "log_cmd", "break_set", "bus_cmd", "call_cmd",
  "clear_cmd", "disassemble_cmd", "dump_cmd", "eval_cmd", "frequency_cmd",
  "help_cmd", "list_cmd", "load_cmd", "node_cmd", "module_cmd",
  "processor_cmd", "quit_cmd", "reset_cmd", "run_cmd", "set_cmd",
  "step_cmd", "shell_cmd", "stimulus_cmd", "stimulus_opt", "symbol_cmd",
  "trace_cmd", "version_cmd", "x_cmd", "icd_cmd", "macro_cmd",
  "macrodef_directive", "@1", "@2", "opt_mdef_arglist", "mdef_body",
  "mdef_body_", "mdef_end", "declaration_cmd", "@3", "@4",
  "opt_declaration_type", "bit_flag", "cmd_subtype", "expression_option",
  "numeric_option", "string_option", "string_list", "expr", "array",
  "gpsimObject", "gpsimObject_list", "expr_list", "binary_expr",
  "unary_expr", "literal", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,    40,    41,    44,    92,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   105,
     105,   106,   107,   108,   108,   108,   109,   109,   109,   110,
     110,   110,   111,   111,   112,   113,   114,   114,   115,   115,
     115,   115,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   118,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   122,   122,   123,   123,
     123,   123,   124,   124,   125,   126,   127,   127,   127,   128,
     128,   128,   129,   130,   130,   130,   130,   131,   131,   131,
     131,   132,   132,   132,   132,   133,   133,   133,   133,   133,
     133,   134,   135,   135,   136,   136,   137,   137,   137,   139,
     140,   138,   141,   141,   141,   142,   142,   143,   143,   144,
     144,   146,   147,   145,   148,   148,   148,   148,   148,   149,
     150,   151,   152,   153,   153,   154,   154,   155,   155,   155,
     156,   157,   157,   157,   158,   158,   159,   159,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   162,   162,   162,   162,
     162
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       1,     1,     3,     1,     2,     1,     1,     2,     3,     3,
       2,     2,     1,     2,     4,     2,     1,     2,     1,     2,
       3,     4,     1,     3,     3,     4,     6,     4,     6,     1,
       2,     1,     2,     2,     1,     2,     3,     4,     2,     2,
       3,     3,     1,     2,     1,     2,     2,     3,     1,     2,
       2,     3,     1,     2,     1,     1,     1,     2,     3,     1,
       2,     2,     1,     1,     2,     2,     2,     1,     2,     2,
       2,     1,     4,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     2,     1,     2,     1,     1,     1,     0,
       0,     8,     0,     1,     3,     0,     1,     1,     2,     1,
       2,     0,     0,     5,     0,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     1,     1,     4,
       3,     4,     4,     1,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     2,     2,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     4,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    37,    41,     0,    43,    52,     0,    56,    58,    69,
      71,     0,    46,    74,    82,   126,    84,    88,    92,    94,
      95,    96,   102,    99,   103,   111,   115,   121,   122,   124,
     128,    36,     0,    62,     0,     0,   141,     0,    39,     5,
       6,     7,    18,    45,     8,     9,    10,    12,    13,    14,
      15,    16,    17,    19,    20,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    21,
     127,    11,     0,   149,    44,    51,    50,   155,    53,   194,
     195,   197,   196,   200,   198,     0,     0,     0,     0,     0,
       0,     0,     0,    55,   157,   158,   186,    57,    59,    70,
      72,    73,    78,    79,     0,    47,    75,    83,     0,    85,
      86,    90,    89,    93,    97,   101,   100,   150,   104,   113,
     114,     0,     0,   119,   120,   117,   118,   116,   123,   125,
     129,     0,     0,     0,     0,     0,   144,     1,    39,    40,
       2,     0,   106,   105,   107,   163,     0,   164,    42,   166,
      49,   156,     0,   192,   188,   191,   187,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      81,    80,    76,     0,    48,   153,   154,    87,    91,    98,
       0,   151,   152,   132,    64,     0,     0,     0,    63,   145,
     146,   147,   148,   142,     3,    38,     0,   108,   109,   110,
       0,   165,     0,     0,     0,   193,   172,   185,   171,   169,
     170,   173,   168,   175,   176,   174,   184,   183,   178,   177,
     182,   180,   181,   179,    61,    77,   112,   133,    39,    65,
      54,    67,     0,     0,     0,     0,   167,   199,   159,     0,
     130,     0,     0,   143,   160,   162,   161,   134,   135,    66,
      68,   137,     0,   136,   139,     0,   131,   138,   140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    37,    38,   140,   141,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     143,    64,    65,    66,    67,    68,    69,    70,   193,   258,
     238,   262,   263,   266,    71,   136,   242,   203,    76,   118,
     124,   125,   110,    78,   149,   209,   147,   148,   150,    94,
      95,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
     173,  -132,  -132,   -20,   -10,    -7,   236,   236,    39,   236,
     -30,   -12,    39,    39,    -7,  -132,    73,    66,   236,  -132,
    -132,    39,  -132,   168,    55,    56,   195,  -132,   236,    78,
    -132,  -132,    63,   -21,    11,   236,  -132,    41,    70,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,    52,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,    82,  -132,  -132,  -132,   236,  -132,    81,  -132,
    -132,  -132,  -132,  -132,    83,   254,   254,   254,   254,   254,
     254,    42,   236,   385,  -132,  -132,  -132,   385,    86,   385,
    -132,  -132,   108,   125,    92,   236,  -132,    81,   100,  -132,
      -7,   129,  -132,   385,   236,  -132,   385,  -132,  -132,   132,
    -132,   236,   236,  -132,  -132,  -132,  -132,   385,   385,  -132,
    -132,   236,   236,   236,   236,   263,    53,  -132,    70,  -132,
    -132,   152,  -132,   -14,  -132,  -132,   115,  -132,    82,   385,
     126,  -132,   236,  -132,  -132,  -132,  -132,  -132,  -132,   236,
     295,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   176,
    -132,  -132,  -132,   178,   126,  -132,  -132,    81,  -132,   385,
     317,   385,   385,   184,   385,   -57,   121,   325,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,   236,  -132,  -132,  -132,
      40,  -132,   236,    14,   355,  -132,    71,   415,    20,    71,
      20,    71,    71,   426,   426,    71,   436,   196,   170,   170,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   -19,   180,
    -132,   185,   191,    17,   148,   158,   385,  -132,  -132,   210,
    -132,   236,   236,  -132,  -132,  -132,  -132,  -132,   224,   385,
     385,  -132,    27,   225,  -132,   251,  -132,  -132,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   227,  -131,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    -2,  -132,
     202,  -132,   -24,    -1,    -6,  -132,   118,  -132,  -101,  -132,
     394,    88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
      93,    97,   126,    99,   184,   129,    98,   204,   239,   104,
     105,   106,   113,   107,   109,   112,   100,   116,   101,   114,
     127,   115,   128,    73,   123,    73,   108,    73,    72,   135,
     131,   195,   196,    74,   102,   139,   103,   264,    75,    77,
     212,   137,     1,   132,     2,     3,     4,     5,     6,     7,
       8,   213,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,   265,   133,    30,    73,    31,   249,   247,
     130,   168,   169,   244,   142,   206,   160,    32,   245,    33,
     121,   171,   172,   173,   174,    -4,   117,    -4,   175,   176,
     177,   178,   119,    73,   120,   243,   134,   250,   189,   187,
      73,   212,   111,   108,   212,   191,   192,   254,   108,   208,
     199,   200,   201,   202,   139,   194,   163,   151,   197,   165,
     145,   146,   168,   169,   179,    34,    35,   159,   182,    36,
     183,   207,   171,   172,   173,   174,   185,   152,   186,   175,
     176,   177,   178,   214,   180,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   181,     1,   188,     2,     3,     4,     5,
       6,     7,     8,   190,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    73,   246,    30,   205,    31,
     210,    79,    80,    81,    82,    83,    84,   240,   212,    32,
      85,    33,   234,   212,   235,    86,    87,    -4,    88,    -4,
     237,   251,    73,   121,   122,   108,   252,   253,    79,    80,
      81,    82,    83,    84,   255,   259,   260,    85,   175,   176,
     177,   178,    86,    87,   256,    88,   257,   261,   267,    89,
      90,   268,    91,    92,   138,   144,   211,    34,    35,   173,
     174,    36,     0,     0,   175,   176,   177,   178,   236,    79,
      80,    81,    82,    83,    84,     0,    89,    90,    85,    91,
      92,     0,     0,    86,    87,     0,    88,    79,    80,    81,
      82,    83,    84,     0,     0,     0,    85,     0,     0,     0,
       0,    86,    87,     0,    88,   161,   162,     0,   163,     0,
     164,   165,   166,   167,   168,   169,   170,    89,    90,     0,
      91,    92,     0,     0,   171,   172,   173,   174,     0,     0,
       0,   175,   176,   177,   178,    89,    90,   161,   162,    92,
     163,     0,   164,   165,   166,   167,   168,   169,   170,   198,
      79,    80,    81,    82,    83,    84,   171,   172,   173,   174,
       0,     0,     0,   175,   176,   177,   178,   161,   162,     0,
     163,     0,   164,   165,   166,   167,   168,   169,   170,     0,
       0,   215,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,   175,   176,   177,   178,   161,   162,     0,
     163,     0,   164,   165,   166,   167,   168,   169,   170,     0,
       0,   241,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,   175,   176,   177,   178,   161,   162,     0,
     163,     0,   164,   165,   166,   167,   168,   169,   170,     0,
       0,   248,     0,     0,     0,     0,   171,   172,   173,   174,
       0,     0,     0,   175,   176,   177,   178,   161,    -5,     0,
     163,     0,   164,   165,   166,   167,   168,   169,   170,   153,
     154,   155,   156,   157,   158,     0,   171,   172,   173,   174,
       0,     0,     0,   175,   176,   177,   178,   171,   172,   173,
     174,     0,     0,     0,   175,   176,   177,   178,   172,   173,
     174,     0,     0,     0,   175,   176,   177,   178
};

static const yytype_int16 yycheck[] =
{
       6,     7,    26,     9,   105,    29,     8,   138,    65,    11,
      12,    13,    18,    14,    16,    17,    46,    23,    48,    21,
      26,    23,    28,    37,    26,    37,    40,    37,    48,    35,
      51,   132,   133,    43,    46,    54,    48,    10,    48,    46,
      97,     0,     1,    64,     3,     4,     5,     6,     7,     8,
       9,   152,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    46,    95,    34,    37,    36,    97,    65,
      17,    61,    62,    43,    32,    99,    92,    46,    48,    48,
      38,    71,    72,    73,    74,    54,    41,    56,    78,    79,
      80,    81,    46,    37,    48,   206,    95,   238,   114,   110,
      37,    97,    46,    40,    97,   121,   122,   100,    40,   143,
      67,    68,    69,    70,    54,   131,    55,    46,   134,    58,
      48,    49,    61,    62,    48,    94,    95,    95,    46,    98,
      48,   143,    71,    72,    73,    74,    46,    64,    48,    78,
      79,    80,    81,   159,    46,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,    48,     1,    46,     3,     4,     5,     6,
       7,     8,     9,    51,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    37,   212,    34,    56,    36,
      95,    43,    44,    45,    46,    47,    48,    96,    97,    46,
      52,    48,    46,    97,    46,    57,    58,    54,    60,    56,
      46,    51,    37,    38,    39,    40,    51,    46,    43,    44,
      45,    46,    47,    48,    96,   251,   252,    52,    78,    79,
      80,    81,    57,    58,    96,    60,    46,    33,    33,    91,
      92,    10,    94,    95,    37,    63,   148,    94,    95,    73,
      74,    98,    -1,    -1,    78,    79,    80,    81,   190,    43,
      44,    45,    46,    47,    48,    -1,    91,    92,    52,    94,
      95,    -1,    -1,    57,    58,    -1,    60,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    57,    58,    -1,    60,    52,    53,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    91,    92,    -1,
      94,    95,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    79,    80,    81,    91,    92,    52,    53,    95,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    96,
      43,    44,    45,    46,    47,    48,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    81,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    81,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    81,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    81,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    85,
      86,    87,    88,    89,    90,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    81,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    81,    72,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      34,    36,    46,    48,    94,    95,    98,   102,   103,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   132,   133,   134,   135,   136,   137,
     138,   145,    48,    37,    43,    48,   149,    46,   154,    43,
      44,    45,    46,    47,    48,    52,    57,    58,    60,    91,
      92,    94,    95,   155,   160,   161,   162,   155,   149,   155,
      46,    48,    46,    48,   149,   149,   149,   154,    40,   149,
     153,    46,   149,   155,   149,   149,   155,    41,   150,    46,
      48,    38,    39,   149,   151,   152,   153,   155,   155,   153,
      17,    51,    64,    95,    95,   155,   146,     0,   103,    54,
     104,   105,    32,   131,   151,    48,    49,   157,   158,   155,
     159,    46,    64,   161,   161,   161,   161,   161,   161,    95,
     155,    52,    53,    55,    57,    58,    59,    60,    61,    62,
      63,    71,    72,    73,    74,    78,    79,    80,    81,    48,
      46,    48,    46,    48,   159,    46,    48,   154,    46,   155,
      51,   155,   155,   139,   155,   159,   159,   155,    96,    67,
      68,    69,    70,   148,   104,    56,    99,   149,   153,   156,
      95,   157,    97,   159,   155,    96,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,    46,    46,   162,    46,   141,    65,
      96,    96,   147,   159,    43,    48,   155,    65,    96,    97,
     104,    51,    51,    46,   100,    96,    96,    46,   140,   155,
     155,    33,   142,   143,    10,    46,   144,    33,    10
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

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
#line 313 "parse.yy"
    { 
        init_cmd_state();

      }
    break;

  case 3:
#line 318 "parse.yy"
    { 
        init_cmd_state();
      }
    break;

  case 36:
#line 357 "parse.yy"
    {
       //if(verbose&2)
         cout << "got an END_OF_INPUT\n";
        /* If we're processing a command file then quit parsing 
         * when we run out of input */
	 //if(Gcmd_file_ref_count)
       	 //quit_parse = 1;
       YYABORT;
     }
    break;

  case 37:
#line 366 "parse.yy"
    {

       init_cmd_state();
       yyclearin;
       // FIXME
       // In some cases we may wish to abort parsing while in others not.
       if (gAbortParserOnSyntaxError) {
         YYABORT;
       }
     }
    break;

  case 41:
#line 394 "parse.yy"
    {
       	  abort_gpsim = 1;
          quit_parse = 1;
          YYABORT;
          }
    break;

  case 42:
#line 403 "parse.yy"
    {
            attach.attach((yyvsp[(2) - (3)].Symbol_P),(yyvsp[(3) - (3)].gpsimObjectList_P));
          }
    break;

  case 43:
#line 409 "parse.yy"
    {c_break.list();}
    break;

  case 44:
#line 410 "parse.yy"
    {c_break.list((yyvsp[(2) - (2)].Integer_P)->getVal());delete (yyvsp[(2) - (2)].Integer_P);}
    break;

  case 45:
#line 411 "parse.yy"
    {  }
    break;

  case 46:
#line 415 "parse.yy"
    {c_log.log();}
    break;

  case 47:
#line 416 "parse.yy"
    {c_log.log((yyvsp[(2) - (2)].co));}
    break;

  case 48:
#line 417 "parse.yy"
    {c_log.log((yyvsp[(2) - (3)].co),(yyvsp[(3) - (3)].ExprList_P));}
    break;

  case 49:
#line 422 "parse.yy"
    {(yyval.i)=c_break.set_break((yyvsp[(2) - (3)].co),(yyvsp[(3) - (3)].ExprList_P));}
    break;

  case 50:
#line 423 "parse.yy"
    {(yyval.i)=c_break.set_break((yyvsp[(2) - (2)].co));}
    break;

  case 51:
#line 424 "parse.yy"
    {(yyval.i)=c_break.set_break((yyvsp[(2) - (2)].Symbol_P));}
    break;

  case 52:
#line 428 "parse.yy"
    {c_bus.list_busses();}
    break;

  case 53:
#line 429 "parse.yy"
    {c_bus.add_busses((yyvsp[(2) - (2)].StringList_P)); delete (yyvsp[(2) - (2)].StringList_P);}
    break;

  case 54:
#line 433 "parse.yy"
    {
          cout << " call\n"; 
          //$$ = $3;
        }
    break;

  case 55:
#line 439 "parse.yy"
    {clear.clear((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 56:
#line 443 "parse.yy"
    {disassemble.disassemble(0);}
    break;

  case 57:
#line 444 "parse.yy"
    {disassemble.disassemble((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 58:
#line 448 "parse.yy"
    {dump.dump(2);}
    break;

  case 59:
#line 449 "parse.yy"
    {dump.dump((yyvsp[(2) - (2)].co)->value);}
    break;

  case 60:
#line 452 "parse.yy"
    {
            //                   key,  module_name
            quit_parse = dump.dump((yyvsp[(2) - (3)].co)->value, (yyvsp[(3) - (3)].Symbol_P), NULL) == 0;
          }
    break;

  case 61:
#line 458 "parse.yy"
    {
            //                   key,  module_name, filename
            //quit_parse = dump.dump($2->value, $3, $4->getVal()) == 0;
            if (dump.dump((yyvsp[(2) - (4)].co)->value, (yyvsp[(3) - (4)].Symbol_P), (yyvsp[(4) - (4)].String_P)->getVal()) == 0) 
              cout << "dump to file failed\n";
            delete (yyvsp[(4) - (4)].String_P);

          }
    break;

  case 62:
#line 470 "parse.yy"
    {c_symbol.dump_one((yyvsp[(1) - (1)].Symbol_P));}
    break;

  case 63:
#line 478 "parse.yy"
    {
                                          c_symbol.EvaluateAndDisplay((yyvsp[(2) - (3)].Expression_P));
                                          delete (yyvsp[(2) - (3)].Expression_P);
                                        }
    break;

  case 64:
#line 482 "parse.yy"
    {

            Value *pValue = dynamic_cast<Value *>((yyvsp[(1) - (3)].Symbol_P));
            if (pValue) {
              try {
                pValue->set((yyvsp[(3) - (3)].Expression_P));
              }
              catch(Error Message)  {
                GetUserInterface().DisplayMessage("%s (maybe missing quotes?)\n", Message.toString().c_str());
              }
              pValue->update();
            }
            delete (yyvsp[(3) - (3)].Expression_P);
          }
    break;

  case 65:
#line 498 "parse.yy"
    {
                                          c_symbol.dump((yyvsp[(1) - (4)].Symbol_P),(yyvsp[(3) - (4)].ExprList_P));
                                          (yyvsp[(3) - (4)].ExprList_P)->clear();
                                          delete (yyvsp[(3) - (4)].ExprList_P);
                                        }
    break;

  case 66:
#line 504 "parse.yy"
    {
                                          c_symbol.Set((yyvsp[(1) - (6)].Symbol_P), (yyvsp[(3) - (6)].ExprList_P), (yyvsp[(6) - (6)].Expression_P));
                                          (yyvsp[(3) - (6)].ExprList_P)->clear();
                                          delete (yyvsp[(3) - (6)].ExprList_P);
                                          delete (yyvsp[(6) - (6)].Expression_P);
                                        }
    break;

  case 67:
#line 511 "parse.yy"
    {
					  int i=toInt((yyvsp[(3) - (4)].Expression_P));
					  if (i>=0)
					    c_x.x(toInt((yyvsp[(3) - (4)].Expression_P)));
                                          delete (yyvsp[(3) - (4)].Expression_P);
                                        }
    break;

  case 68:
#line 518 "parse.yy"
    {
					  int i=toInt((yyvsp[(3) - (6)].Expression_P));
					  if (i>=0)
					    c_x.x(toInt((yyvsp[(3) - (6)].Expression_P)), (yyvsp[(6) - (6)].Expression_P));
                                          delete (yyvsp[(3) - (6)].Expression_P);
                                        }
    break;

  case 69:
#line 527 "parse.yy"
    {frequency.print();}
    break;

  case 70:
#line 528 "parse.yy"
    {frequency.set((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 71:
#line 532 "parse.yy"
    {help.help(); }
    break;

  case 72:
#line 533 "parse.yy"
    {help.help((yyvsp[(2) - (2)].String_P)->getVal()); delete (yyvsp[(2) - (2)].String_P);}
    break;

  case 73:
#line 534 "parse.yy"
    {help.help((yyvsp[(2) - (2)].Symbol_P));}
    break;

  case 74:
#line 538 "parse.yy"
    {c_list.list();}
    break;

  case 75:
#line 539 "parse.yy"
    {c_list.list((yyvsp[(2) - (2)].co));}
    break;

  case 76:
#line 543 "parse.yy"
    {
            quit_parse = c_load.load((yyvsp[(2) - (3)].co)->value,(yyvsp[(3) - (3)].String_P)->getVal()) == 0;
            delete (yyvsp[(3) - (3)].String_P);

            if(quit_parse)
            {
              quit_parse = 0;
              YYABORT;
            }
          }
    break;

  case 77:
#line 554 "parse.yy"
    {
            quit_parse = c_load.load((yyvsp[(2) - (4)].co)->value, (yyvsp[(3) - (4)].Symbol_P), (yyvsp[(4) - (4)].String_P)->getVal()) == 0;
            delete (yyvsp[(4) - (4)].String_P);

            if(quit_parse)
            {
              quit_parse = 0;
              YYABORT;
            }
	  }
    break;

  case 78:
#line 566 "parse.yy"
    {
            quit_parse = c_load.load((yyvsp[(2) - (2)].String_P)->getVal(), (const char *)NULL) == 0;
            delete (yyvsp[(2) - (2)].String_P);
            quit_parse =0;

            if(quit_parse)
            {
              quit_parse = 0;
              YYABORT;
            }

          }
    break;

  case 79:
#line 580 "parse.yy"
    {
            quit_parse = c_load.load((yyvsp[(2) - (2)].Symbol_P)) == 0;
            quit_parse =0;

            if(quit_parse)
            {
              quit_parse = 0;
              YYABORT;
            }

          }
    break;

  case 80:
#line 593 "parse.yy"
    {
            //                        filename,   processor
            quit_parse = c_load.load((yyvsp[(3) - (3)].Symbol_P), (yyvsp[(2) - (3)].Symbol_P)) == 0;
            delete (yyvsp[(2) - (3)].Symbol_P);
            delete (yyvsp[(3) - (3)].Symbol_P);

            if(quit_parse)
            {
              quit_parse = 0;
              YYABORT;
            }
          }
    break;

  case 81:
#line 609 "parse.yy"
    {
            //                        filename,   processor
            quit_parse = c_load.load((yyvsp[(3) - (3)].String_P), (yyvsp[(2) - (3)].String_P)) == 0;
            delete (yyvsp[(2) - (3)].String_P);
            delete (yyvsp[(3) - (3)].String_P);

            if(quit_parse)
            {
              quit_parse = 0;
              YYABORT;
            }
          }
    break;

  case 82:
#line 625 "parse.yy"
    {c_node.list_nodes();}
    break;

  case 83:
#line 626 "parse.yy"
    {c_node.add_nodes((yyvsp[(2) - (2)].StringList_P));  delete (yyvsp[(2) - (2)].StringList_P);}
    break;

  case 84:
#line 630 "parse.yy"
    {c_module.module();}
    break;

  case 85:
#line 631 "parse.yy"
    {c_module.module((yyvsp[(2) - (2)].co));}
    break;

  case 86:
#line 633 "parse.yy"
    { 
            c_module.module((yyvsp[(2) - (2)].cos),(list <string> *)0);
            delete (yyvsp[(2) - (2)].cos);
          }
    break;

  case 87:
#line 638 "parse.yy"
    {
	    if ((yyvsp[(2) - (3)].cos) != NULL && (yyvsp[(3) - (3)].StringList_P) != NULL)
                c_module.module((yyvsp[(2) - (3)].cos), (yyvsp[(3) - (3)].StringList_P)); 
            if ((yyvsp[(2) - (3)].cos) != NULL) delete (yyvsp[(2) - (3)].cos); 
            if ((yyvsp[(3) - (3)].StringList_P) != NULL) delete (yyvsp[(3) - (3)].StringList_P);
          }
    break;

  case 88:
#line 648 "parse.yy"
    {
            c_processor.processor();
          }
    break;

  case 89:
#line 652 "parse.yy"
    {
            c_processor.processor((yyvsp[(2) - (2)].co)->value);
          }
    break;

  case 90:
#line 656 "parse.yy"
    {
            c_processor.processor((yyvsp[(2) - (2)].String_P)->getVal(),0);
            delete (yyvsp[(2) - (2)].String_P);
          }
    break;

  case 91:
#line 661 "parse.yy"
    { 
            c_processor.processor((yyvsp[(2) - (3)].String_P)->getVal(),(yyvsp[(3) - (3)].String_P)->getVal());
            delete (yyvsp[(2) - (3)].String_P);
            delete (yyvsp[(3) - (3)].String_P);
          }
    break;

  case 92:
#line 669 "parse.yy"
    { 
            quit_parse = 1;
	    YYABORT;
          }
    break;

  case 93:
#line 674 "parse.yy"
    {
            quit_parse = 1;
	    //quit_state = $2;  // FIXME need to evaluate expr
	    YYABORT;
	  }
    break;

  case 94:
#line 682 "parse.yy"
    { reset.reset(); }
    break;

  case 95:
#line 686 "parse.yy"
    { c_run.run();}
    break;

  case 96:
#line 690 "parse.yy"
    {c_set.set();}
    break;

  case 97:
#line 691 "parse.yy"
    {c_set.set((yyvsp[(2) - (2)].co)->value,0);}
    break;

  case 98:
#line 692 "parse.yy"
    {c_set.set((yyvsp[(2) - (3)].co)->value,(yyvsp[(3) - (3)].Expression_P));}
    break;

  case 99:
#line 696 "parse.yy"
    {step.step(1);}
    break;

  case 100:
#line 697 "parse.yy"
    {step.step((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 101:
#line 698 "parse.yy"
    {step.over();}
    break;

  case 102:
#line 702 "parse.yy"
    {c_shell.shell((yyvsp[(1) - (1)].String_P)); delete (yyvsp[(1) - (1)].String_P);}
    break;

  case 103:
#line 706 "parse.yy"
    {
          c_stimulus.stimulus();
          }
    break;

  case 104:
#line 710 "parse.yy"
    {
          c_stimulus.stimulus((yyvsp[(2) - (2)].co)->value);
          }
    break;

  case 105:
#line 714 "parse.yy"
    {
          /* do nothing */
          }
    break;

  case 106:
#line 718 "parse.yy"
    { 
            if(verbose)
              cout << " end of stimulus command\n";
            c_stimulus.end();
          }
    break;

  case 107:
#line 728 "parse.yy"
    {
            if(verbose)
              cout << "parser sees stimulus with numeric option\n";
            c_stimulus.stimulus((yyvsp[(1) - (1)].coe));
          }
    break;

  case 108:
#line 734 "parse.yy"
    {
            if(verbose)
              cout << "parser sees stimulus with bit flag: " << (yyvsp[(2) - (2)].co)->value << '\n';
            c_stimulus.stimulus((yyvsp[(2) - (2)].co)->value);
          }
    break;

  case 109:
#line 740 "parse.yy"
    {
            if(verbose)
              cout << "parser sees stimulus with string option\n";
            c_stimulus.stimulus((yyvsp[(2) - (2)].cos));
          }
    break;

  case 110:
#line 746 "parse.yy"
    { 
            if(verbose)
              cout << "parser sees stimulus with an array\n";
            c_stimulus.stimulus((yyvsp[(2) - (2)].ExprList_P));
          }
    break;

  case 111:
#line 755 "parse.yy"
    {c_symbol.dump_all();}
    break;

  case 112:
#line 757 "parse.yy"
    {
            c_symbol.add_one((yyvsp[(2) - (4)].String_P)->getVal(), (yyvsp[(4) - (4)].Expression_P)); 
            delete (yyvsp[(2) - (4)].String_P); 
            delete (yyvsp[(4) - (4)].Expression_P);
          }
    break;

  case 113:
#line 762 "parse.yy"
    {c_symbol.dump_one((yyvsp[(2) - (2)].String_P)->getVal()); delete (yyvsp[(2) - (2)].String_P);}
    break;

  case 114:
#line 763 "parse.yy"
    {c_symbol.dump_one((yyvsp[(2) - (2)].Symbol_P));}
    break;

  case 115:
#line 768 "parse.yy"
    { c_trace.trace(); }
    break;

  case 116:
#line 769 "parse.yy"
    { c_trace.trace((yyvsp[(2) - (2)].Expression_P)); }
    break;

  case 117:
#line 770 "parse.yy"
    { c_trace.trace((yyvsp[(2) - (2)].con)); }
    break;

  case 118:
#line 771 "parse.yy"
    { c_trace.trace((yyvsp[(2) - (2)].cos)); }
    break;

  case 119:
#line 772 "parse.yy"
    { c_trace.trace((yyvsp[(2) - (2)].co)); }
    break;

  case 120:
#line 773 "parse.yy"
    { c_trace.trace((yyvsp[(2) - (2)].coe)); }
    break;

  case 121:
#line 776 "parse.yy"
    {version.version();}
    break;

  case 122:
#line 780 "parse.yy"
    { c_x.x();}
    break;

  case 123:
#line 781 "parse.yy"
    { c_x.x((yyvsp[(2) - (2)].Expression_P)); }
    break;

  case 124:
#line 785 "parse.yy"
    { c_icd.icd(); }
    break;

  case 125:
#line 786 "parse.yy"
    { c_icd.icd((yyvsp[(2) - (2)].cos)); }
    break;

  case 126:
#line 807 "parse.yy"
    { c_macro.list();}
    break;

  case 127:
#line 808 "parse.yy"
    { }
    break;

  case 128:
#line 809 "parse.yy"
    { lexer_InvokeMacro((yyvsp[(1) - (1)].Macro_P)); }
    break;

  case 129:
#line 815 "parse.yy"
    {c_macro.define((yyvsp[(1) - (2)].String_P)->getVal()); delete (yyvsp[(1) - (2)].String_P);}
    break;

  case 130:
#line 817 "parse.yy"
    {lexer_setMacroBodyMode();}
    break;

  case 133:
#line 825 "parse.yy"
    {
            c_macro.add_parameter((yyvsp[(1) - (1)].String_P)->getVal());
	    delete (yyvsp[(1) - (1)].String_P);
	  }
    break;

  case 134:
#line 830 "parse.yy"
    {
	    c_macro.add_parameter((yyvsp[(3) - (3)].String_P)->getVal());
	    delete (yyvsp[(3) - (3)].String_P);
	  }
    break;

  case 136:
#line 839 "parse.yy"
    {; }
    break;

  case 137:
#line 843 "parse.yy"
    {c_macro.add_body((yyvsp[(1) - (1)].s));}
    break;

  case 138:
#line 844 "parse.yy"
    {c_macro.add_body((yyvsp[(2) - (2)].s));}
    break;

  case 139:
#line 848 "parse.yy"
    {c_macro.end_define();}
    break;

  case 140:
#line 849 "parse.yy"
    {c_macro.end_define((yyvsp[(1) - (2)].String_P)->getVal()); delete (yyvsp[(1) - (2)].String_P); }
    break;

  case 141:
#line 870 "parse.yy"
    {
		       cout << "declaration\n";
		       lexer_setDeclarationMode();
		     }
    break;

  case 142:
#line 875 "parse.yy"
    {
		       cout << " type:" << (yyvsp[(3) - (3)].i) << endl;
		     }
    break;

  case 143:
#line 879 "parse.yy"
    {
		       cout << "identifier: " << (yyvsp[(5) - (5)].String_P)->getVal() << endl;  delete (yyvsp[(5) - (5)].String_P);
		     }
    break;

  case 144:
#line 886 "parse.yy"
    { (yyval.i)=0; }
    break;

  case 145:
#line 887 "parse.yy"
    { (yyval.i) = 1; cout <<"int type\n";}
    break;

  case 146:
#line 888 "parse.yy"
    { (yyval.i) = 2; cout <<"float type\n";}
    break;

  case 147:
#line 889 "parse.yy"
    { (yyval.i) = 3; cout <<"bool type\n";}
    break;

  case 148:
#line 890 "parse.yy"
    { (yyval.i) = 4; cout <<"char type\n";}
    break;

  case 149:
#line 915 "parse.yy"
    {
	 (yyval.co) = (yyvsp[(1) - (1)].co);
      }
    break;

  case 150:
#line 921 "parse.yy"
    {
	 (yyval.co) = (yyvsp[(1) - (1)].co);
      }
    break;

  case 151:
#line 926 "parse.yy"
    { (yyval.coe) = new cmd_options_expr((yyvsp[(1) - (2)].co),(yyvsp[(2) - (2)].Expression_P)); }
    break;

  case 152:
#line 930 "parse.yy"
    { 

	        (yyval.con) = new cmd_options_num;
	        (yyval.con)->co = (yyvsp[(1) - (2)].co);
	      }
    break;

  case 153:
#line 939 "parse.yy"
    { 
          (yyval.cos) = new cmd_options_str((yyvsp[(2) - (2)].String_P)->getVal());
          (yyval.cos)->co  = (yyvsp[(1) - (2)].co);
          if(verbose&2)
            cout << " name " << (yyval.cos)->co->name << " value " << (yyval.cos)->str << " got a string option \n"; 
          delete (yyvsp[(2) - (2)].String_P);
        }
    break;

  case 154:
#line 947 "parse.yy"
    { 
          String *pValue = dynamic_cast<String*>((yyvsp[(2) - (2)].Symbol_P));
          if(pValue != NULL) {
            (yyval.cos) = new cmd_options_str(pValue->getVal());
            (yyval.cos)->co  = (yyvsp[(1) - (2)].co);
            if(verbose&2)
              cout << " name " << (yyval.cos)->co->name << " value " << (yyval.cos)->str << " got a symbol option \n"; 
          }
          else {
            cout << " symbol option '"
                 << (yyvsp[(2) - (2)].Symbol_P)->name()
                 << "' is not a string"
                 << endl; 
	    (yyval.cos) = NULL;
          }
          //delete $2;
        }
    break;

  case 155:
#line 967 "parse.yy"
    {(yyval.StringList_P) = new StringList_t(); (yyval.StringList_P)->push_back((yyvsp[(1) - (1)].String_P)->getVal()); delete (yyvsp[(1) - (1)].String_P);}
    break;

  case 156:
#line 968 "parse.yy"
    {(yyvsp[(1) - (2)].StringList_P)->push_back((yyvsp[(2) - (2)].String_P)->getVal()); delete (yyvsp[(2) - (2)].String_P);}
    break;

  case 157:
#line 974 "parse.yy"
    {(yyval.Expression_P)=(yyvsp[(1) - (1)].BinaryOperator_P);}
    break;

  case 158:
#line 975 "parse.yy"
    {(yyval.Expression_P)=(yyvsp[(1) - (1)].Expression_P);}
    break;

  case 159:
#line 976 "parse.yy"
    {(yyval.Expression_P)=new RegisterExpression(toInt((yyvsp[(3) - (4)].Expression_P)));
                                                         delete (yyvsp[(3) - (4)].Expression_P); }
    break;

  case 160:
#line 980 "parse.yy"
    {(yyval.ExprList_P)=(yyvsp[(2) - (3)].ExprList_P);}
    break;

  case 161:
#line 984 "parse.yy"
    {
            // Ex: pin(MyVariable)  -- where MyVariable is the name of a symbol 
            //  This allows one to programmatically select a particular pin number.

	    // If Symbol has an integer type, assume it is a CPU pin number
	    // otherwise assume it is a stimulus such as a pin name
	    if (typeid(*(yyvsp[(3) - (4)].Symbol_P)) == typeid(Integer))
	    {
                (yyval.gpsimObject_P) = toStimulus((yyvsp[(3) - (4)].Symbol_P));
   	    }
            else
	        (yyval.gpsimObject_P) = (yyvsp[(3) - (4)].Symbol_P);

            //$$=new Pin_t(Pin_t::ePackageBased | Pin_t::eActiveProc, $3);
          }
    break;

  case 162:
#line 1000 "parse.yy"
    {
            // Ex: pin(8)  -- select a particular pin in the package
            (yyval.gpsimObject_P) = toStimulus((yyvsp[(3) - (4)].Integer_P)->getVal());
            delete (yyvsp[(3) - (4)].Integer_P);
          }
    break;

  case 163:
#line 1006 "parse.yy"
    {
            // The symbol should be a stimulus. This is for the attach command.
            // Ex:  attach Node1 portb0
            // The scanner will find portb0 and return it to us here as a SYMBOL_T
            (yyval.gpsimObject_P) = (yyvsp[(1) - (1)].Symbol_P); //dynamic_cast<stimulus *>($1);
          }
    break;

  case 164:
#line 1026 "parse.yy"
    {(yyval.gpsimObjectList_P) = new gpsimObjectList_t(); (yyval.gpsimObjectList_P)->push_back((yyvsp[(1) - (1)].gpsimObject_P));}
    break;

  case 165:
#line 1027 "parse.yy"
    {if ((yyvsp[(2) - (2)].gpsimObject_P)) (yyvsp[(1) - (2)].gpsimObjectList_P)->push_back((yyvsp[(2) - (2)].gpsimObject_P));}
    break;

  case 166:
#line 1031 "parse.yy"
    {(yyval.ExprList_P) = new ExprList_t(); (yyval.ExprList_P)->push_back((yyvsp[(1) - (1)].Expression_P));}
    break;

  case 167:
#line 1032 "parse.yy"
    {(yyvsp[(1) - (3)].ExprList_P)->push_back((yyvsp[(3) - (3)].Expression_P)); }
    break;

  case 168:
#line 1036 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpAdd((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 169:
#line 1037 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpSub((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 170:
#line 1038 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpMpy((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 171:
#line 1039 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpDiv((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 172:
#line 1040 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpAnd((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 173:
#line 1041 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpOr((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 174:
#line 1042 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpXor((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 175:
#line 1043 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpShl((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 176:
#line 1044 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpShr((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 177:
#line 1045 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpEq((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 178:
#line 1046 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpNe((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 179:
#line 1047 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpLt((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 180:
#line 1048 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpGt((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 181:
#line 1049 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpLe((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 182:
#line 1050 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpGe((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 183:
#line 1051 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpLogicalAnd((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 184:
#line 1052 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpLogicalOr((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 185:
#line 1053 "parse.yy"
    {(yyval.BinaryOperator_P) = new OpAbstractRange((yyvsp[(1) - (3)].Expression_P), (yyvsp[(3) - (3)].Expression_P));}
    break;

  case 186:
#line 1057 "parse.yy"
    {(yyval.Expression_P)=(yyvsp[(1) - (1)].Expression_P);}
    break;

  case 187:
#line 1058 "parse.yy"
    {(yyval.Expression_P) = new OpPlus((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 188:
#line 1059 "parse.yy"
    {(yyval.Expression_P) = new OpNegate((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 189:
#line 1060 "parse.yy"
    {(yyval.Expression_P) = new OpOnescomp((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 190:
#line 1061 "parse.yy"
    {(yyval.Expression_P) = new OpLogicalNot((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 191:
#line 1062 "parse.yy"
    {(yyval.Expression_P) = new OpIndirect((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 192:
#line 1063 "parse.yy"
    {(yyval.Expression_P) = new OpAddressOf((yyvsp[(2) - (2)].Expression_P));}
    break;

  case 193:
#line 1064 "parse.yy"
    {(yyval.Expression_P)=(yyvsp[(2) - (3)].Expression_P);}
    break;

  case 194:
#line 1067 "parse.yy"
    {(yyval.Expression_P) = new LiteralInteger((yyvsp[(1) - (1)].Integer_P));}
    break;

  case 195:
#line 1068 "parse.yy"
    {(yyval.Expression_P) = new LiteralBoolean((yyvsp[(1) - (1)].Boolean_P));}
    break;

  case 196:
#line 1069 "parse.yy"
    {(yyval.Expression_P) = new LiteralString((yyvsp[(1) - (1)].String_P));}
    break;

  case 197:
#line 1070 "parse.yy"
    {(yyval.Expression_P) = new LiteralFloat((yyvsp[(1) - (1)].Float_P));}
    break;

  case 198:
#line 1071 "parse.yy"
    {(yyval.Expression_P) = new LiteralSymbol((yyvsp[(1) - (1)].Symbol_P));}
    break;

  case 199:
#line 1072 "parse.yy"
    {(yyval.Expression_P) = new IndexedSymbol((yyvsp[(1) - (4)].Symbol_P),(yyvsp[(3) - (4)].ExprList_P));}
    break;

  case 200:
#line 1073 "parse.yy"
    {(yyval.Expression_P) = new LiteralArray((yyvsp[(1) - (1)].ExprList_P)); }
    break;


/* Line 1267 of yacc.c.  */
#line 3079 "parse.cc"
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


#line 1076 "parse.yy"


       // parsing is over 

//--------------------------
// This initialization could be done by the compiler. However
// it requires two passes through because the token values are
// defined by the parser output (eg. y.tab.h) while at the same
// time the parser depends on the .h files in which these classes
// are defined.

void initialize_commands(void)
{
  static bool initialized = 0;

  if(initialized)
    return;

  if(verbose)
    cout << __FUNCTION__ << "()\n";

  attach.token_value = ATTACH;
  c_break.token_value = BREAK;
  // c_bus.token_value = BUS;
  clear.token_value = CLEAR;
  disassemble.token_value = DISASSEMBLE;
  dump.token_value = DUMP;
  frequency.token_value = FREQUENCY;
  help.token_value = HELP;
  c_list.token_value = LIST;
  c_load.token_value = LOAD;
  c_log.token_value = LOG;
  c_macro.token_value = MACRO;
  c_module.token_value = MODULE;
  c_node.token_value = NODE;
  c_processor.token_value = PROCESSOR;
  quit.token_value = QUIT;
  reset.token_value = RESET;
  c_run.token_value = RUN;
  c_set.token_value = SET;
  step.token_value = STEP;
  c_stimulus.token_value = STIMULUS;
  c_symbol.token_value = SYMBOL;
  c_trace.token_value = TRACE;
  version.token_value = gpsim_VERSION;
  c_x.token_value = X;
  c_icd.token_value = ICD;
  c_shell.token_value = SHELL;

  initialized = 1;

  parser_spanning_lines = 0;
  parser_warnings = 1; // display parser warnings.
}

