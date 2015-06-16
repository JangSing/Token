#include "addToken.h"
#include "Token.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * This file consist of function add2Tokens which is a pointer to Token type.
 * The task of this function is to pass in the Operator Token and 
 * Integer Tokens to form a tree.
 * 
 * input:
 *		-leftValue
 *		-rightValue
 *		-*operatorSymbol
 * 
 * return:
 * 		-Token
 */
 
Token *add2Tokens(int leftValue, char *operatorSymbol, int rightValue){
	//allocating memory for the pointers
	OperatorToken *opTok =malloc(sizeof(OperatorToken)+sizeof(Token *)*2);
	IntegerToken *LeftInt =malloc(sizeof(IntegerToken));
	IntegerToken *RightInt =malloc(sizeof(IntegerToken));
	
	//creating operator token
	opTok=(OperatorToken *)createOperatorToken(operatorSymbol,INFIX,LEFT_TO_RIGHT);
	
	/*
	//only exist when perform mocking(for OperatorToken)
		opTok->type=TOKEN_OPERATOR_TYPE;
		opTok->symbol=operatorSymbol;
		opTok->arity=INFIX;
	*/
	
	//creating integer token
	LeftInt=(IntegerToken *)createIntegerToken(leftValue);
	RightInt=(IntegerToken *)createIntegerToken(rightValue);
	
	/*
	//only exist when perform mocking(for IntegerToken)
		LeftInt->type=TOKEN_INTEGER_TYPE;
		LeftInt->value=leftValue;
		RightInt->type=TOKEN_INTEGER_TYPE;
		RightInt->value=rightValue;
	*/
	
	//inserting the token into the operator token
	opTok->token[0]=(Token *)LeftInt;	
	opTok->token[1]=(Token *)RightInt;	
	


	return (Token *)opTok;
}