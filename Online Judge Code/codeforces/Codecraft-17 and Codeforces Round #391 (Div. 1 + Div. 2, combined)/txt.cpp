%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "SymbolTable.h"
//#define YYSTYPE SymbolInfo*

    using namespace std;

    extern int yylineno;
    extern char* yytext;
    extern FILE *yyin;
    string lastTypeSpecifier;
    int yyparse(void);
    int yylex(void);

    FILE *tokenout;
    FILE *logout;
    FILE *errorout;
    FILE *fp;
    SymbolTable st;
    int error_count = 0, semantic_error = 0;

    void yyerror(char *s)
    {
        //write your code
    }


%}

%union
{
    SymbolInfo *val;
}

%token <val> NOT IF ELSE FOR WHILE ID LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA CONST_INT INT CONST_FLOAT FLOAT VOID RETURN ASSIGNOP LOGICOP RELOP ADDOP MULOP INCOP DECOP PRINTLN
%type <val> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments

//%left
//%right

//%nonassoc


%%

start :
program
{
    //write your code in this block in all the similar blocks below
}
;

program :
program unit
{
    fprintf(logout, "At line no %d# program : program unit\n\n", yylineno );
}
| unit
{
    fprintf(logout, "At line no %d# program : unit\n\n", yylineno);
}
;

unit :
var_declaration
{
    fprintf(logout, "At line no %d# unit : var_declaration\n\n", yylineno);
}
| func_declaration
{
    fprintf(logout, "At line no %d# unit : func_declaration\n\n", yylineno);
}
| func_definition
{
    fprintf(logout, "At line no %d# unit : func_definition\n\n", yylineno);
}
;

func_declaration :
type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
{
    fprintf(logout, "At line no %d# func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n", yylineno);
}
| type_specifier ID LPAREN RPAREN SEMICOLON
{
    fprintf(logout, "At line no %d# func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n", yylineno);
}
;

func_definition :
type_specifier ID LPAREN parameter_list RPAREN compound_statement
{
    fprintf(logout, "At line no %d# func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", yylineno);
}
| type_specifier ID LPAREN RPAREN compound_statement
{
    fprintf(logout, "At line no %d# func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", yylineno);
}
;


parameter_list  :
parameter_list COMMA type_specifier ID
{
    fprintf(logout, "At line no %d# parameter_list  : parameter_list COMMA type_specifier ID\n\n", yylineno);
}
| parameter_list COMMA type_specifier
{
    fprintf(logout, "At line no %d# parameter_list  : parameter_list COMMA type_specifier\n\n", yylineno);
}
| type_specifier ID
{
    fprintf(logout, "At line no %d# parameter_list  : type_specifier ID\n\n", yylineno);
}
| type_specifier
{
    fprintf(logout, "At line no %d# parameter_list  : type_specifier\n\n", yylineno);
}
;


compound_statement :
LCURL statements RCURL
{
    fprintf(logout, "At line no %d# compound_statement : LCURL statements RCURL\n\n", yylineno);
}
| LCURL RCURL
{
    fprintf(logout, "At line no %d# compound_statement : LCURL RCURL\n\n", yylineno);
}
;

var_declaration :
type_specifier declaration_list SEMICOLON
{
    fprintf(logout, "At line no %d# var_declaration : type_specifier declaration_list SEMICOLON\n\n", yylineno);
    if( $1->getName() == "VOID" )
    {
        fprintf(errorout, "Error at line %d# variable type can't be void\n\n", yylineno);
    }
    $$ = new SymbolInfo( $1->getName() + $2->getName() + $3->getName() );
    fprintf(logout, "%s\n\n", $$->getName());
}
|
type_specifier declaration_list error
{
	fprintf(errorout, "Error at line %d# semicolon(;) is missing\n\n", yylineno);
}
;

type_specifier :
INT
{
    fprintf(logout, "At line no %d# type_specifier : INT\n\n", yylineno);
    $$ = $1;
    $$->setDataType("INT");
    lastTypeSpecifier = "INT";
    fprintf( logout, "%s\n\n", $$->getName().c_str() );
}
| FLOAT
{
    fprintf(logout, "At line no %d# type_specifier : FLOAT\n\n", yylineno);
    $$ = $1;
    $$->setDataType("FLOAT");
    lastTypeSpecifier = "FLOAT";
    fprintf( logout, "%s\n\n", $$->getName().c_str() );
}
| VOID
{
    fprintf(logout, "At line no %d# type_specifier : VOID\n\n", yylineno);
    $$ = $1;
    $$->setDataType("VOID");
    lastTypeSpecifier = "VOID";
    fprintf( logout, "%s\n\n", $$->getName().c_str() );

}
;

declaration_list :
declaration_list COMMA ID
{
    fprintf(logout, "At line no %d# declaration_list : declaration_list COMMA ID\n\n", yylineno);
    SymbolInfo *found = st.lookUp( $3->getName() );
    $$ = new SymbolInfo( $1->getName()+$2->getName()+ $3->getName() );
    if( found != 0 )
    {
        fprintf(errorout, "Error at line %d# variable name %s already used\n\n", yylineno, $3->getName().c_str());
        semantic_error++;
    }
    else if( lastTypeSpecifier == "VOID" )
    {

        fprintf(errorout, "Error at line %d# variable %s type can't be void\n\n", yylineno, $3->getName().c_str());
        semantic_error++;
    }
    else
    {
        SymbolInfo* sm = new SymbolInfo( $3->getName(), "ID", lastTypeSpecifier );
        st.insert(*sm);
    }
    fprintf(logout, "%s\n\n", $$->getName().c_str());
}
| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
{
    fprintf(logout, "At line no %d# declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n", yylineno);
    SymbolInfo *found = st.lookUp( $3->getName() );
    $$ = new SymbolInfo( $1->getName()+$2->getName()+ $3->getName() + $4->getName()+$5->getName()+$6->getName() );
    if( found != 0 )
    {
        fprintf(errorout, "Error at line %d# variable name %s already used\n\n", yylineno, $3->getName().c_str());
        semantic_error++;
    }
    else if( lastTypeSpecifier == "VOID" )
    {

        fprintf(errorout, "Error at line %d# variable %s type can't be void\n\n", yylineno, $3->getName().c_str());
        semantic_error++;
    }
    else
    {
        SymbolInfo* sm = new SymbolInfo( $3->getName(), "ARRAY", lastTypeSpecifier );
        st.insert(*sm);
    }
    fprintf(logout, "%s\n\n", $$->getName().c_str());
}
| ID
{
    fprintf(logout, "At line no %d# declaration_list : ID\n\n", yylineno);
    SymbolInfo *found = st.lookUp( $1->getName() );
    $$ = new SymbolInfo( $1->getName() );
    if( found != 0 )
    {
        fprintf(errorout, "Error at line %d# variable name %s already used\n\n", yylineno, $1->getName().c_str());
        semantic_error++;
    }
    else if( lastTypeSpecifier == "VOID" )
    {

        fprintf(errorout, "Error at line %d# variable %s type can't be void\n\n", yylineno, $1->getName().c_str());
        semantic_error++;
    }
    else
    {
        SymbolInfo* sm = new SymbolInfo( $1->getName(), "ID", lastTypeSpecifier );
        st.insert(*sm);
    }
    fprintf(logout, "%s\n\n", $$->getName().c_str());
}
| ID LTHIRD CONST_INT RTHIRD
{
    fprintf(logout, "At line no %d# declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n", yylineno);
    SymbolInfo *found = st.lookUp( $1->getName() );
    $$ = new SymbolInfo( $1->getName()+$2->getName()+ $3->getName() + $4->getName() );
    if( found != 0 )
    {
        fprintf(errorout, "Error at line %d# variable name %s already used\n\n", yylineno, $1->getName().c_str());
        semantic_error++;
    }
    else if( lastTypeSpecifier == "VOID" )
    {

        fprintf(errorout, "Error at line %d# variable %s type can't be void\n\n", yylineno, $1->getName().c_str());
        semantic_error++;
    }
    else
    {
        SymbolInfo* sm = new SymbolInfo( $1->getName(), "ARRAY", lastTypeSpecifier );
        st.insert(*sm);
    }
    fprintf(logout, "%s\n\n", $$->getName().c_str());
}
;

statements :
statement
{
    fprintf(logout, "At line no %d# statements : statement\n\n", yylineno);
}
| statements statement
{
    fprintf(logout, "At line no %d# statements : statements statement\n\n", yylineno);
}
;

statement :
var_declaration
{
    fprintf(logout, "At line no %d# statement : var_declaration\n\n", yylineno);
}
| expression_statement
{
    fprintf(logout, "At line no %d# statement : expression_statement\n\n", yylineno);
}
| compound_statement
{
    fprintf(logout, "At line no %d# statement : compound_statement\n\n", yylineno);
}
| FOR LPAREN expression_statement expression_statement expression RPAREN statement
{
    fprintf(logout, "At line no %d# statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n", yylineno);
}
| IF LPAREN expression RPAREN statement
{
    fprintf(logout, "At line no %d# statement : IF LPAREN expression RPAREN statement\n\n", yylineno);
}
| IF LPAREN expression RPAREN statement ELSE statement
{
    fprintf(logout, "At line no %d# statement : IF LPAREN expression RPAREN statement ELSE statement\n\n", yylineno);
}
| WHILE LPAREN expression RPAREN statement
{
    fprintf(logout, "At line no %d# statement : WHILE LPAREN expression RPAREN statement\n\n", yylineno);
}
| PRINTLN LPAREN ID RPAREN SEMICOLON
{
    fprintf(logout, "At line no %d# statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n", yylineno);
}
| RETURN expression SEMICOLON
{
    fprintf(logout, "At line no %d# statement : RETURN expression SEMICOLON\n\n", yylineno);
}
;

expression_statement :
SEMICOLON
{
    fprintf(logout, "At line no %d# expression_statement : SEMICOLON\n\n", yylineno);
}
| expression SEMICOLON
{
    fprintf(logout, "At line no %d# expression_statement : expression SEMICOLON\n\n", yylineno);
}
;

variable :
ID
{
    fprintf(logout, "At line no %d# variable : ID\n\n", yylineno);
    SymbolInfo *found = st.lookUp( $1->getName() );
    $$ = new SymbolInfo( $1->getName(), "?" );
    if( found == 0 )
    {
        fprintf(errorout, "Error at line no %d# Undeclared variable %s\n\n", yylineno, $1->getName().c_str() );
        semantic_error++;
    }
    else
    {
        $$->setType( found->getType() );
        $$->setDataType( found->getDataType() );
    }
    fprintf(logout, "%s\n\n",$$->getName().c_str());
}
| ID LTHIRD expression RTHIRD
{
    fprintf(logout, "At line no %d# variable : ID LTHIRD expression RTHIRD\n\n", yylineno);
    SymbolInfo *found = st.lookUp( $1->getName() );
    $$ = new SymbolInfo( $1->getName()+$2->getName()+$3->getName()+$4->getName(), "?" );
    if( found == 0 || found->getType() != "ARRAY" )
    {
        fprintf(errorout, "Error at line no %d# Undeclared array %s\n\n", yylineno, $1->getName().c_str() );
        semantic_error++;
    }
    else
    {
        if( $3->getDataType() != "INT" )
        {
            fprintf(errorout, "Error at line no %d# array %s index non-integer\n\n", yylineno, $1->getName().c_str() );
            semantic_error++;
        }
        $$->setType( found->getType() );
        $$->setDataType( found->getDataType() );
    }
    fprintf(logout, "%s\n\n",$$->getName().c_str());

}
;

expression :
logic_expression
{
    fprintf(logout, "At line no %d# expression : logic_expression\n\n", yylineno);
}
| variable ASSIGNOP logic_expression
{
    fprintf(logout, "At line no %d# expression : variable ASSIGNOP logic_expression\n\n", yylineno);
}
;

logic_expression :
rel_expression
{
    fprintf(logout, "At line no %d# logic_expression : rel_expression\n\n", yylineno);
}
| rel_expression LOGICOP rel_expression
{
    fprintf(logout, "At line no %d# logic_expression : rel_expression LOGICOP rel_expression\n\n", yylineno);
}
;

rel_expression	:
simple_expression
{
    fprintf(logout, "At line no %d# rel_expression : simple_expression\n\n", yylineno);
}
| simple_expression RELOP simple_expression
{
    fprintf(logout, "At line no %d# rel_expression : simple_expression RELOP simple_expression\n\n", yylineno);
}
;

simple_expression :
term
{
    fprintf(logout, "At line no %d# simple_expression : simple_expression\n\n", yylineno);
}
| simple_expression ADDOP term
{
    fprintf(logout, "At line no %d# simple_expression : simple_expression ADDOP term\n\n", yylineno);
}
;

term :
unary_expression
{
    fprintf(logout, "At line no %d# term : unary_expression\n\n", yylineno);
}
|  term MULOP unary_expression
{
    fprintf(logout, "At line no %d# term : term MULOP unary_expression\n\n", yylineno);
}
;

unary_expression :
ADDOP unary_expression
{
    fprintf(logout, "At line no %d# unary_expression : ADDOP unary_expression\n\n", yylineno);
}
| NOT unary_expression
{
    fprintf(logout, "At line no %d# unary_expression : NOT unary_expression\n\n", yylineno);
}
| factor
{
    fprintf(logout, "At line no %d# unary_expression : factor\n\n", yylineno);
}
;

factor :
variable
{
    fprintf(logout, "At line no %d# factor : variable\n\n", yylineno);
}
| ID LPAREN argument_list RPAREN
{
    fprintf(logout, "At line no %d# factor : ID LPAREN argument_list RPAREN\n\n", yylineno);
}
| LPAREN expression RPAREN
{
    fprintf(logout, "At line no %d# factor : LPAREN expression RPAREN\n\n", yylineno);
}
| CONST_INT
{
    fprintf(logout, "At line no %d# factor : CONST_INT\n\n", yylineno);
}
| CONST_FLOAT
{
    fprintf(logout, "At line no %d# factor : CONST_FLOAT\n\n", yylineno);
}
| variable INCOP
{
    fprintf(logout, "At line no %d# factor : variable INCOP\n\n", yylineno);
}
| variable DECOP
{
    fprintf(logout, "At line no %d# factor : variable DECOP\n\n", yylineno);
}
;

argument_list :
arguments
{
    fprintf(logout, "At line no %d# argument_list : arguments\n\n", yylineno);
}
|
{
    fprintf(logout, "At line no %d# argument_list : \n\n", yylineno);
}
;

arguments :
arguments COMMA logic_expression
{
    fprintf(logout, "At line no %d# arguments : arguments COMMA logic_expression\n\n", yylineno);
}
| logic_expression
{
    fprintf(logout, "At line no %d# arguments : logic_expression\n\n", yylineno);
}
;


%%
int main(int argc,char *argv[])
{

    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Cannot Open Input File.\n\n");
        exit(1);
    }

    st.enterScope();

    yyin=fp;
    errorout = fopen("1505002_error.txt", "w");
    tokenout  = fopen("1505002_token.txt","w");
    logout = fopen("1505002_log.txt","w");
    yyparse();
    fclose(logout);
    fclose(tokenout);
    fclose(yyin);
    return 0;
}
