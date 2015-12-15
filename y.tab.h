/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 22 "compilateur.y" /* yacc.c:1909  */

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

#line 144 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
