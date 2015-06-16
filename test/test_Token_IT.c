#include "unity.h"
#include "Token.h"
#include "addToken.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

// test the function createOperatorToken are functioning correctly
void test_only_function_createOperatorToken()
{
	OperatorToken *opTok ;
	
	opTok=(OperatorToken *) createOperatorToken("+",INFIX,LEFT_TO_RIGHT);
	
	TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,opTok->type);
	TEST_ASSERT_EQUAL("+",opTok->symbol);
	TEST_ASSERT_EQUAL(INFIX,opTok->arity);
	TEST_ASSERT_EQUAL(LEFT_TO_RIGHT,opTok->Assoc);
}

// test the function createIntegerToken are functioning correctly
void test_only_function_createIntegerToken()
{
	IntegerToken *IntTok;
	
	IntTok=(IntegerToken *)createIntegerToken(100000);
	
	TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,IntTok->type);
	TEST_ASSERT_EQUAL(100000,IntTok->value);
}

// test the function add2Token are functioning correctly
void test_addtoken_given_2_plus_3_should_return_token_tree()
{
	
	OperatorToken *opTok;
	
	//calling function add2tokens
		opTok=(OperatorToken *)add2Tokens(2, "+", 3);	
	
	//test whether the symbol,arity and associativity has successfully inserted into the Token 
		TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,opTok->type);
		TEST_ASSERT_EQUAL("+",opTok->symbol);
		TEST_ASSERT_EQUAL(INFIX,opTok->arity);
		TEST_ASSERT_EQUAL(LEFT_TO_RIGHT,opTok->Assoc);	
	
	//test whether the values have been inserted to the tree
		TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,((IntegerToken *)(opTok->token[0]))->type);
		TEST_ASSERT_EQUAL(2,((IntegerToken *)(opTok->token[0]))->value);
		TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,((IntegerToken *)(opTok->token[0]))->type);
		TEST_ASSERT_EQUAL(3,((IntegerToken *)(opTok->token[1]))->value);
}








