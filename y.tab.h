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
    INT = 261,
    FLOAT = 262,
    ID = 263,
    NOT = 264,
    OR = 265,
    AND = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    FOR = 270,
    STRING = 271,
    TYPE = 272,
    DIFF = 273,
    SUPEQ = 274,
    INFEQ = 275,
    EQUAL = 276,
    SUP = 277,
    INF = 278,
    UMOINS = 283
  };
#endif
/* Tokens.  */
#define PLUSPLUS 258
#define MOINSMOINS 259
#define MAIN 260
#define INT 261
#define FLOAT 262
#define ID 263
#define NOT 264
#define OR 265
#define AND 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define FOR 270
#define STRING 271
#define TYPE 272
#define DIFF 273
#define SUPEQ 274
#define INFEQ 275
#define EQUAL 276
#define SUP 277
#define INF 278
#define UMOINS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "compilateur.y" /* yacc.c:1909  */

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

#line 136 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
