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
    NUMBER = 260,
    ID = 261,
    NOT = 262,
    OR = 263,
    AND = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    FOR = 268,
    STRING = 269,
    TYPE = 270,
    DIFF = 271,
    SUPEQ = 272,
    INFEQ = 273,
    EQUAL = 274,
    SUP = 275,
    INF = 276,
    UMOINS = 281
  };
#endif
/* Tokens.  */
#define PLUSPLUS 258
#define MOINSMOINS 259
#define NUMBER 260
#define ID 261
#define NOT 262
#define OR 263
#define AND 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define STRING 269
#define TYPE 270
#define DIFF 271
#define SUPEQ 272
#define INFEQ 273
#define EQUAL 274
#define SUP 275
#define INF 276
#define UMOINS 281

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

#line 127 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
