#ifndef Token_H
#define Token_H

/**
 *Global structure and function for all the file
 */

typedef enum{
  TOKEN_INTEGER_TYPE,
  TOKEN_OPERATOR_TYPE,
}Tokentype;

typedef enum{
  PREFIX,
  INFIX,
  POSTFIX,
}Arity;

typedef enum{
  NONE,
  LEFT_TO_RIGHT,
  RIGHT_TO_LEFT,
}Associativity;

typedef struct{
  Tokentype type;
}Token;

typedef struct{
  Tokentype type;
  int value;
}IntegerToken;

typedef struct{
  Tokentype type;
  char *symbol;
  Arity arity;
  Associativity Assoc;
  Token *token[0];
}OperatorToken;


Token *createOperatorToken(char *symbol, Arity arity,Associativity Assoc) ;

Token *createIntegerToken(int value) ;

#endif // Token_H
