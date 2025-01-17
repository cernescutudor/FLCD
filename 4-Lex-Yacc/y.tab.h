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

#line 153 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
