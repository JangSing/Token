#include "Token.h"
#include <stdlib.h>

/**
 * This file consist of function createOperatorToken and createIntegerToken.
 * Both of the function is a pointer to Token.
 * 
 * The createOperatorToken will assign the value of the element of the
 * Operator Token.
 * 	inputs:
 * 		-symbol
 *		-arity
 *		-Associativity
 *	return:
 * 		-Token
 *
 * The createIntegerToken will assign the value of the element of the 
 * Integer Token.
 * 	inputs:
 * 		-value
 * 	return:
 *		-Token
 *
 */

Token *createOperatorToken(char *symbol, Arity arity,Associativity Assoc) {
	//allocating memory for the pointers opTok
		OperatorToken *opTok =malloc(sizeof(OperatorToken)+sizeof(Token *)*2);
	
	//assigning the value for OperatorToken
		opTok->type=TOKEN_OPERATOR_TYPE;
		opTok->symbol=symbol;
		opTok->arity=arity;
		opTok->Assoc=Assoc;
	
	return (Token *)opTok;
}

Token *createIntegerToken(int value){
	//allocating memory for the pointers IntTok
		IntegerToken *IntTok =malloc(sizeof(IntegerToken));
	
	//assigning the value for IntegerToken
		IntTok->type=TOKEN_INTEGER_TYPE;
		IntTok->value=value;
	
	return (Token *)IntTok;
}


