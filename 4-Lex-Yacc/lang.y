%{
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
%}

%union {
    int intval;
    char *strval;
    char charval;
}

%token <intval> TRUE FALSE INTCONST
%token <strval> IDENTIFIER CHARCONST
%token PROG_BEGIN END IF ELSE WHILE READINT READCHAR READBOOL PRINT
%token <strval> INT BOOL CHAR 
%token EQ NEQ LEQ GEQ LT GT ASSIGN PLUS MINUS MULT DIV MOD LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA ERROR

%type <intval> Expression Term Factor Condition
%type <strval> Identifier Type Constant

%start S

%%

S: PROG_BEGIN Block END {
        printf("Parsed Program Successfully.\n");
    }
    ;

Block: LBRACE StatementList RBRACE {
        printf("Parsed Block.\n");
    }
    ;

StatementList: Statement SEMICOLON StatementList {

    }
             | /* empty */ {

    }
    ;

Statement: DeclStmt
         | AssignStmt
         | InputStmt
         | OutputStmt
         | IfStmt
         | WhileStmt
    ;

DeclStmt: Type Identifier {
        printf("Declared variable: %s\n", $2);
        setVariable($2, 0);
        
    }
        | Type Identifier LBRACKET Expression RBRACKET {
        printf("Declared array: %s of size %d\n", $2, $4);
    }
    ;

Type: INT       { $$ = strdup("int"); }
    | BOOL      { $$ = strdup("bool"); }
    | CHAR      { $$ = strdup("char"); }
    ;

Identifier: IDENTIFIER {
        $$ = $1;
    }
    ;

AssignStmt: Identifier ASSIGN Expression {
        printf("Assigned value to %s.\n", $1);
        setVariable($1, $3);
    }
           | Identifier LBRACKET Expression RBRACKET ASSIGN Expression {
        printf("Assigned value to array %s at index %d.\n", $1, $3);
    }
    ;

Expression: Term
           | Expression PLUS Term {
                 $$ = $1 + $3;
             }
           | Expression MINUS Term {
                 $$ = $1 - $3;
             }
    ;

Term: Factor
    | Term MULT Factor {
          $$ = $1 * $3;
      }
    | Term DIV Factor {
          $$ = $1 / $3;
      }
    | Term MOD Factor {
          $$ = $1 % $3;
      }
    ;

Factor: Identifier {
          $$ = getVariable($1); /* Assume Identifier resolves to an integer */
      }
      | Constant {
          $$ = $1;
      }
      | LPAREN Expression RPAREN {
          $$ = $2;
      }
    ;

Constant: INTCONST {
        $$ = $1; // $1 is an integer, and $$ is also <intval>
    }
    | TRUE {
        $$ = 1; // TRUE is treated as an integer literal
    }
    | FALSE {
        $$ = 0; // FALSE is treated as an integer literal
    }
    | CHARCONST {
        $$ = (int) $1[1]; // Assuming CHARCONST is a string like "'A'", take the character value
    }
    ;


IfStmt: IF LPAREN Condition RPAREN Block {
    if ($3) {
        printf("Condition true: Executing If block.\n");
    }
} 
| IF LPAREN Condition RPAREN Block ELSE Block {
    if ($3) {
        printf("Condition true: Executing If block.\n");
        /* Execute the if block */
    } else {
        printf("Condition false: Executing Else block.\n");
        /* Execute the else block */
    }
};

Condition: Expression EQ Expression {
               $$ = ($1 == $3);
               printf("Condition: %d == %d evaluates to %d\n", $1, $3, $1 == $3);
           }
          | Expression NEQ Expression {
               $$ = ($1 != $3);
               printf("Condition: %d != %d evaluates to %d\n", $1, $3, $1 != $3);
           }
          | Expression LT Expression {
               $$ = ($1 < $3);
               printf("Condition: %d < %d evaluates to %d\n", $1, $3, $1 < $3);
           }
          | Expression GT Expression {
               printf("Condition: %d > %d evaluates to %d\n", $1, $3, $1 > $3);
               $$ = ($1 > $3);
           }
          | Expression LEQ Expression {
               $$ = ($1 <= $3);
               printf("Condition: %d <= %d evaluates to %d\n", $1, $3, $1 <= $3);
           }
          | Expression GEQ Expression {
               $$ = ($1 >= $3);
               printf("Condition: %d >= %d evaluates to %d\n", $1, $3, $1 >= $3);
           }
    ;

WhileStmt: WHILE LPAREN Condition RPAREN Block {
        printf("Parsed While Statement.\n");
    }
    ;

InputStmt: READINT LPAREN Identifier RPAREN {
        printf("Read integer into %s.\n", $3);
        
    }
          | READCHAR LPAREN Identifier RPAREN {
        printf("Read character into %s.\n", $3);
    }
          | READBOOL LPAREN Identifier RPAREN {
        printf("Read boolean into %s.\n", $3);
    }
    ;

OutputStmt: PRINT LPAREN Expression RPAREN {
        printf("Output: %d\n", $3);  // Print evaluated expression

    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main() {
    printf("Starting the parser...\n");
    return yyparse();
}
