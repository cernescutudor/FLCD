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
#line 1 "lang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Symbol Table
#define MAX_VARIABLES 100

typedef struct {
    char name[50];
    int value;
} Variable;

Variable symbolTable[MAX_VARIABLES];
int symbolCount = 0;

int lookupVariable(char *name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void setVariable(char *name, int value) {
    int index = lookupVariable(name);
    if (index == -1) {
        // Add new variable
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].value = value;
        symbolCount++;
    } else {
        // Update existing variable
        symbolTable[index].value = value;
    }
}

int getVariable(char *name) {
    int index = lookupVariable(name);
    if (index != -1) {
        return symbolTable[index].value;
    }
    printf("Error: Variable '%s' not declared.\n", name);
    exit(1);
}

// Lexer prototype
extern int yylex();



void yyerror(const char *s);
int yylex();
extern int yylineno;

#line 128 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TRUE = 258,                    /* TRUE  */
    FALSE = 259,                   /* FALSE  */
    INTCONST = 260,                /* INTCONST  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    CHARCONST = 262,               /* CHARCONST  */
    PROG_BEGIN = 263,              /* PROG_BEGIN  */
    END = 264,                     /* END  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    READINT = 268,                 /* READINT  */
    READCHAR = 269,                /* READCHAR  */
    READBOOL = 270,                /* READBOOL  */
    PRINT = 271,                   /* PRINT  */
    INT = 272,                     /* INT  */
    BOOL = 273,                    /* BOOL  */
    CHAR = 274,                    /* CHAR  */
    EQ = 275,                      /* EQ  */
    NEQ = 276,                     /* NEQ  */
    LEQ = 277,                     /* LEQ  */
    GEQ = 278,                     /* GEQ  */
    LT = 279,                      /* LT  */
    GT = 280,                      /* GT  */
    ASSIGN = 281,                  /* ASSIGN  */
    PLUS = 282,                    /* PLUS  */
    MINUS = 283,                   /* MINUS  */
    MULT = 284,                    /* MULT  */
    DIV = 285,                     /* DIV  */
    MOD = 286,                     /* MOD  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LBRACE = 289,                  /* LBRACE  */
    RBRACE = 290,                  /* RBRACE  */
    LBRACKET = 291,                /* LBRACKET  */
    RBRACKET = 292,                /* RBRACKET  */
    SEMICOLON = 293,               /* SEMICOLON  */
    COMMA = 294,                   /* COMMA  */
    ERROR = 295                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TRUE 258
#define FALSE 259
#define INTCONST 260
#define IDENTIFIER 261
#define CHARCONST 262
#define PROG_BEGIN 263
#define END 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define READINT 268
#define READCHAR 269
#define READBOOL 270
#define PRINT 271
#define INT 272
#define BOOL 273
#define CHAR 274
#define EQ 275
#define NEQ 276
#define LEQ 277
#define GEQ 278
#define LT 279
#define GT 280
#define ASSIGN 281
#define PLUS 282
#define MINUS 283
#define MULT 284
#define DIV 285
#define MOD 286
#define LPAREN 287
#define RPAREN 288
#define LBRACE 289
#define RBRACE 290
#define LBRACKET 291
#define RBRACKET 292
#define SEMICOLON 293
#define COMMA 294
#define ERROR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "lang.y"

    int intval;
    char *strval;
    char charval;

#line 267 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TRUE = 3,                       /* TRUE  */
  YYSYMBOL_FALSE = 4,                      /* FALSE  */
  YYSYMBOL_INTCONST = 5,                   /* INTCONST  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_CHARCONST = 7,                  /* CHARCONST  */
  YYSYMBOL_PROG_BEGIN = 8,                 /* PROG_BEGIN  */
  YYSYMBOL_END = 9,                        /* END  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_READINT = 13,                   /* READINT  */
  YYSYMBOL_READCHAR = 14,                  /* READCHAR  */
  YYSYMBOL_READBOOL = 15,                  /* READBOOL  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_INT = 17,                       /* INT  */
  YYSYMBOL_BOOL = 18,                      /* BOOL  */
  YYSYMBOL_CHAR = 19,                      /* CHAR  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LEQ = 22,                       /* LEQ  */
  YYSYMBOL_GEQ = 23,                       /* GEQ  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_MULT = 29,                      /* MULT  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_MOD = 31,                       /* MOD  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 34,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 35,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 36,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 37,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 38,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_ERROR = 40,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_S = 42,                         /* S  */
  YYSYMBOL_Block = 43,                     /* Block  */
  YYSYMBOL_StatementList = 44,             /* StatementList  */
  YYSYMBOL_Statement = 45,                 /* Statement  */
  YYSYMBOL_DeclStmt = 46,                  /* DeclStmt  */
  YYSYMBOL_Type = 47,                      /* Type  */
  YYSYMBOL_Identifier = 48,                /* Identifier  */
  YYSYMBOL_AssignStmt = 49,                /* AssignStmt  */
  YYSYMBOL_Expression = 50,                /* Expression  */
  YYSYMBOL_Term = 51,                      /* Term  */
  YYSYMBOL_Factor = 52,                    /* Factor  */
  YYSYMBOL_Constant = 53,                  /* Constant  */
  YYSYMBOL_IfStmt = 54,                    /* IfStmt  */
  YYSYMBOL_Condition = 55,                 /* Condition  */
  YYSYMBOL_WhileStmt = 56,                 /* WhileStmt  */
  YYSYMBOL_InputStmt = 57,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 58                 /* OutputStmt  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    82,    87,    90,    95,    96,    97,    98,
      99,   100,   103,   108,   113,   114,   115,   118,   123,   127,
     132,   133,   136,   141,   142,   145,   148,   153,   156,   159,
     164,   167,   170,   173,   179,   184,   194,   198,   202,   206,
     210,   214,   220,   225,   229,   232,   237
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
  "\"end of file\"", "error", "\"invalid token\"", "TRUE", "FALSE",
  "INTCONST", "IDENTIFIER", "CHARCONST", "PROG_BEGIN", "END", "IF", "ELSE",
  "WHILE", "READINT", "READCHAR", "READBOOL", "PRINT", "INT", "BOOL",
  "CHAR", "EQ", "NEQ", "LEQ", "GEQ", "LT", "GT", "ASSIGN", "PLUS", "MINUS",
  "MULT", "DIV", "MOD", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "SEMICOLON", "COMMA", "ERROR", "$accept", "S", "Block",
  "StatementList", "Statement", "DeclStmt", "Type", "Identifier",
  "AssignStmt", "Expression", "Term", "Factor", "Constant", "IfStmt",
  "Condition", "WhileStmt", "InputStmt", "OutputStmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -5,   -12,    33,    31,    29,   -70,   -70,    10,    19,    24,
      37,    40,    46,   -70,   -70,   -70,    44,    42,   -70,    75,
     -17,   -70,   -70,   -70,   -70,   -70,   -70,     8,     8,    75,
      75,    75,     8,   -70,    31,    47,     8,     8,   -70,   -70,
     -70,   -70,     8,   -70,    43,    28,   -70,   -70,    49,    51,
      52,    53,    54,    -7,   -70,     8,   -10,   -21,    27,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
     -12,   -12,   -70,   -70,   -70,   -70,    25,    62,   -70,   -10,
     -10,   -10,   -10,   -10,   -10,    28,    28,   -70,   -70,   -70,
      78,   -70,   -70,     8,   -12,   -10,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,    17,     0,     0,     0,
       0,     0,     0,    14,    15,    16,     0,     0,     6,     0,
       0,     7,    10,    11,     8,     9,     2,     0,     0,     0,
       0,     0,     0,     3,     5,    12,     0,     0,    31,    32,
      30,    33,     0,    27,     0,    20,    23,    28,     0,     0,
       0,     0,     0,     0,     4,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    29,    36,
      37,    40,    41,    38,    39,    21,    22,    24,    25,    26,
      34,    42,    13,     0,     0,    19,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -69,    56,   -70,   -70,   -70,     5,   -70,   -32,
      11,     6,   -70,   -70,    63,   -70,   -70,   -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     4,    16,    17,    18,    19,    43,    21,    44,
      45,    46,    47,    22,    48,    23,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      53,    90,    91,     1,    56,    57,    65,    66,    20,    36,
      58,    38,    39,    40,     6,    41,    77,    65,    66,    37,
      65,    66,     3,    76,    35,    96,    75,    79,    80,    81,
      82,    83,    84,     5,    50,    51,    52,     6,    26,    20,
      42,     7,    27,     8,     9,    10,    11,    12,    13,    14,
      15,    28,    65,    66,    65,    66,    29,    67,    68,    69,
      78,    95,    92,    59,    60,    61,    62,    63,    64,    30,
      65,    66,    31,    87,    88,    89,    85,    86,    32,    33,
      34,     6,    70,    55,    71,    72,    73,    74,    93,    94,
      54,    49
};

static const yytype_int8 yycheck[] =
{
      32,    70,    71,     8,    36,    37,    27,    28,     3,    26,
      42,     3,     4,     5,     6,     7,    37,    27,    28,    36,
      27,    28,    34,    55,    19,    94,    33,    59,    60,    61,
      62,    63,    64,     0,    29,    30,    31,     6,     9,    34,
      32,    10,    32,    12,    13,    14,    15,    16,    17,    18,
      19,    32,    27,    28,    27,    28,    32,    29,    30,    31,
      33,    93,    37,    20,    21,    22,    23,    24,    25,    32,
      27,    28,    32,    67,    68,    69,    65,    66,    32,    35,
      38,     6,    33,    36,    33,    33,    33,    33,    26,    11,
      34,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    42,    34,    43,     0,     6,    10,    12,    13,
      14,    15,    16,    17,    18,    19,    44,    45,    46,    47,
      48,    49,    54,    56,    57,    58,     9,    32,    32,    32,
      32,    32,    32,    35,    38,    48,    26,    36,     3,     4,
       5,     7,    32,    48,    50,    51,    52,    53,    55,    55,
      48,    48,    48,    50,    44,    36,    50,    50,    50,    20,
      21,    22,    23,    24,    25,    27,    28,    29,    30,    31,
      33,    33,    33,    33,    33,    33,    50,    37,    33,    50,
      50,    50,    50,    50,    50,    51,    51,    52,    52,    52,
      43,    43,    37,    26,    11,    50,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    46,    46,    47,    47,    47,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      53,    53,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    57,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     0,     1,     1,     1,     1,
       1,     1,     2,     5,     1,     1,     1,     1,     3,     6,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     3,
       1,     1,     1,     1,     5,     7,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4
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
  case 2: /* S: PROG_BEGIN Block END  */
#line 77 "lang.y"
                        {
        printf("Parsed Program Successfully.\n");
    }
#line 1362 "y.tab.c"
    break;

  case 3: /* Block: LBRACE StatementList RBRACE  */
#line 82 "lang.y"
                                   {
        printf("Parsed Block.\n");
    }
#line 1370 "y.tab.c"
    break;

  case 4: /* StatementList: Statement SEMICOLON StatementList  */
#line 87 "lang.y"
                                                 {

    }
#line 1378 "y.tab.c"
    break;

  case 5: /* StatementList: %empty  */
#line 90 "lang.y"
                           {

    }
#line 1386 "y.tab.c"
    break;

  case 12: /* DeclStmt: Type Identifier  */
#line 103 "lang.y"
                          {
        printf("Declared variable: %s\n", (yyvsp[0].strval));
        setVariable((yyvsp[0].strval), 0);
        
    }
#line 1396 "y.tab.c"
    break;

  case 13: /* DeclStmt: Type Identifier LBRACKET Expression RBRACKET  */
#line 108 "lang.y"
                                                       {
        printf("Declared array: %s of size %d\n", (yyvsp[-3].strval), (yyvsp[-1].intval));
    }
#line 1404 "y.tab.c"
    break;

  case 14: /* Type: INT  */
#line 113 "lang.y"
                { (yyval.strval) = strdup("int"); }
#line 1410 "y.tab.c"
    break;

  case 15: /* Type: BOOL  */
#line 114 "lang.y"
                { (yyval.strval) = strdup("bool"); }
#line 1416 "y.tab.c"
    break;

  case 16: /* Type: CHAR  */
#line 115 "lang.y"
                { (yyval.strval) = strdup("char"); }
#line 1422 "y.tab.c"
    break;

  case 17: /* Identifier: IDENTIFIER  */
#line 118 "lang.y"
                       {
        (yyval.strval) = (yyvsp[0].strval);
    }
#line 1430 "y.tab.c"
    break;

  case 18: /* AssignStmt: Identifier ASSIGN Expression  */
#line 123 "lang.y"
                                         {
        printf("Assigned value to %s.\n", (yyvsp[-2].strval));
        setVariable((yyvsp[-2].strval), (yyvsp[0].intval));
    }
#line 1439 "y.tab.c"
    break;

  case 19: /* AssignStmt: Identifier LBRACKET Expression RBRACKET ASSIGN Expression  */
#line 127 "lang.y"
                                                                       {
        printf("Assigned value to array %s at index %d.\n", (yyvsp[-5].strval), (yyvsp[-3].intval));
    }
#line 1447 "y.tab.c"
    break;

  case 21: /* Expression: Expression PLUS Term  */
#line 133 "lang.y"
                                  {
                 (yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);
             }
#line 1455 "y.tab.c"
    break;

  case 22: /* Expression: Expression MINUS Term  */
#line 136 "lang.y"
                                   {
                 (yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);
             }
#line 1463 "y.tab.c"
    break;

  case 24: /* Term: Term MULT Factor  */
#line 142 "lang.y"
                       {
          (yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);
      }
#line 1471 "y.tab.c"
    break;

  case 25: /* Term: Term DIV Factor  */
#line 145 "lang.y"
                      {
          (yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);
      }
#line 1479 "y.tab.c"
    break;

  case 26: /* Term: Term MOD Factor  */
#line 148 "lang.y"
                      {
          (yyval.intval) = (yyvsp[-2].intval) % (yyvsp[0].intval);
      }
#line 1487 "y.tab.c"
    break;

  case 27: /* Factor: Identifier  */
#line 153 "lang.y"
                   {
          (yyval.intval) = getVariable((yyvsp[0].strval)); /* Assume Identifier resolves to an integer */
      }
#line 1495 "y.tab.c"
    break;

  case 28: /* Factor: Constant  */
#line 156 "lang.y"
                 {
          (yyval.intval) = (yyvsp[0].strval);
      }
#line 1503 "y.tab.c"
    break;

  case 29: /* Factor: LPAREN Expression RPAREN  */
#line 159 "lang.y"
                                 {
          (yyval.intval) = (yyvsp[-1].intval);
      }
#line 1511 "y.tab.c"
    break;

  case 30: /* Constant: INTCONST  */
#line 164 "lang.y"
                   {
        (yyval.strval) = (yyvsp[0].intval); // $1 is an integer, and $$ is also <intval>
    }
#line 1519 "y.tab.c"
    break;

  case 31: /* Constant: TRUE  */
#line 167 "lang.y"
           {
        (yyval.strval) = 1; // TRUE is treated as an integer literal
    }
#line 1527 "y.tab.c"
    break;

  case 32: /* Constant: FALSE  */
#line 170 "lang.y"
            {
        (yyval.strval) = 0; // FALSE is treated as an integer literal
    }
#line 1535 "y.tab.c"
    break;

  case 33: /* Constant: CHARCONST  */
#line 173 "lang.y"
                {
        (yyval.strval) = (int) (yyvsp[0].strval)[1]; // Assuming CHARCONST is a string like "'A'", take the character value
    }
#line 1543 "y.tab.c"
    break;

  case 34: /* IfStmt: IF LPAREN Condition RPAREN Block  */
#line 179 "lang.y"
                                         {
    if ((yyvsp[-2].intval)) {
        printf("Condition true: Executing If block.\n");
    }
}
#line 1553 "y.tab.c"
    break;

  case 35: /* IfStmt: IF LPAREN Condition RPAREN Block ELSE Block  */
#line 184 "lang.y"
                                              {
    if ((yyvsp[-4].intval)) {
        printf("Condition true: Executing If block.\n");
        /* Execute the if block */
    } else {
        printf("Condition false: Executing Else block.\n");
        /* Execute the else block */
    }
}
#line 1567 "y.tab.c"
    break;

  case 36: /* Condition: Expression EQ Expression  */
#line 194 "lang.y"
                                    {
               (yyval.intval) = ((yyvsp[-2].intval) == (yyvsp[0].intval));
               printf("Condition: %d == %d evaluates to %d\n", (yyvsp[-2].intval), (yyvsp[0].intval), (yyvsp[-2].intval) == (yyvsp[0].intval));
           }
#line 1576 "y.tab.c"
    break;

  case 37: /* Condition: Expression NEQ Expression  */
#line 198 "lang.y"
                                      {
               (yyval.intval) = ((yyvsp[-2].intval) != (yyvsp[0].intval));
               printf("Condition: %d != %d evaluates to %d\n", (yyvsp[-2].intval), (yyvsp[0].intval), (yyvsp[-2].intval) != (yyvsp[0].intval));
           }
#line 1585 "y.tab.c"
    break;

  case 38: /* Condition: Expression LT Expression  */
#line 202 "lang.y"
                                     {
               (yyval.intval) = ((yyvsp[-2].intval) < (yyvsp[0].intval));
               printf("Condition: %d < %d evaluates to %d\n", (yyvsp[-2].intval), (yyvsp[0].intval), (yyvsp[-2].intval) < (yyvsp[0].intval));
           }
#line 1594 "y.tab.c"
    break;

  case 39: /* Condition: Expression GT Expression  */
#line 206 "lang.y"
                                     {
               printf("Condition: %d > %d evaluates to %d\n", (yyvsp[-2].intval), (yyvsp[0].intval), (yyvsp[-2].intval) > (yyvsp[0].intval));
               (yyval.intval) = ((yyvsp[-2].intval) > (yyvsp[0].intval));
           }
#line 1603 "y.tab.c"
    break;

  case 40: /* Condition: Expression LEQ Expression  */
#line 210 "lang.y"
                                      {
               (yyval.intval) = ((yyvsp[-2].intval) <= (yyvsp[0].intval));
               printf("Condition: %d <= %d evaluates to %d\n", (yyvsp[-2].intval), (yyvsp[0].intval), (yyvsp[-2].intval) <= (yyvsp[0].intval));
           }
#line 1612 "y.tab.c"
    break;

  case 41: /* Condition: Expression GEQ Expression  */
#line 214 "lang.y"
                                      {
               (yyval.intval) = ((yyvsp[-2].intval) >= (yyvsp[0].intval));
               printf("Condition: %d >= %d evaluates to %d\n", (yyvsp[-2].intval), (yyvsp[0].intval), (yyvsp[-2].intval) >= (yyvsp[0].intval));
           }
#line 1621 "y.tab.c"
    break;

  case 42: /* WhileStmt: WHILE LPAREN Condition RPAREN Block  */
#line 220 "lang.y"
                                               {
        printf("Parsed While Statement.\n");
    }
#line 1629 "y.tab.c"
    break;

  case 43: /* InputStmt: READINT LPAREN Identifier RPAREN  */
#line 225 "lang.y"
                                            {
        printf("Read integer into %s.\n", (yyvsp[-1].strval));
        
    }
#line 1638 "y.tab.c"
    break;

  case 44: /* InputStmt: READCHAR LPAREN Identifier RPAREN  */
#line 229 "lang.y"
                                              {
        printf("Read character into %s.\n", (yyvsp[-1].strval));
    }
#line 1646 "y.tab.c"
    break;

  case 45: /* InputStmt: READBOOL LPAREN Identifier RPAREN  */
#line 232 "lang.y"
                                              {
        printf("Read boolean into %s.\n", (yyvsp[-1].strval));
    }
#line 1654 "y.tab.c"
    break;

  case 46: /* OutputStmt: PRINT LPAREN Expression RPAREN  */
#line 237 "lang.y"
                                           {
        printf("Output: %d\n", (yyvsp[-1].intval));  // Print evaluated expression

    }
#line 1663 "y.tab.c"
    break;


#line 1667 "y.tab.c"

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

#line 243 "lang.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main() {
    printf("Starting the parser...\n");
    return yyparse();
}
