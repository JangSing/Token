#include "unity.h"
#include "mock_Token.h"
#include "addToken.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

// test the function add2Token are functioning correctly with mock
void test_addtoken_given_2_plus_3_should_return_token_tree_with_mock()
{
  //allocating memory for the pointers
    OperatorToken *opTok=malloc(sizeof(OperatorToken)+sizeof(Token *)*2);
    IntegerToken *LeftInt=malloc(sizeof(IntegerToken));
    IntegerToken *RightInt=malloc(sizeof(IntegerToken));	
	
  //mocking the function inside Token.h
    createOperatorToken_ExpectAndReturn("+",INFIX,LEFT_TO_RIGHT,(Token *)opTok);
    createIntegerToken_ExpectAndReturn(2,(Token *)LeftInt);
    createIntegerToken_ExpectAndReturn(3,(Token *)RightInt);
		
  // faking the value for OperatorToken
    opTok->type=TOKEN_OPERATOR_TYPE;
    opTok->symbol="+";
    opTok->arity=INFIX;
    opTok->Assoc=LEFT_TO_RIGHT;	
		
  // faking the value for IntegerToken
    LeftInt->type=TOKEN_INTEGER_TYPE;
    LeftInt->value=2;
    RightInt->type=TOKEN_INTEGER_TYPE;
    RightInt->value=3;
		
  //calling function add2Tokens
    opTok=(OperatorToken *)add2Tokens(2, "+", 3);	

  //test whether the symbol, arity and associativity  has successfully inserted into the Token 
    TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,opTok->type);
    TEST_ASSERT_EQUAL("+",opTok->symbol);
    TEST_ASSERT_EQUAL(INFIX,opTok->arity);
    TEST_ASSERT_EQUAL(LEFT_TO_RIGHT,opTok->Assoc);
	
  //test whether the IntegerToken has been successfully inserted into opTok 
  //(this test is for mocking only)
    TEST_ASSERT_EQUAL_PTR(LeftInt,opTok->token[0]);
    TEST_ASSERT_EQUAL_PTR(RightInt,opTok->token[1]);
	
	
  //test whether the values have been inserted to the tree
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,((IntegerToken *)(opTok->token[0]))->type);
    TEST_ASSERT_EQUAL(2,((IntegerToken *)(opTok->token[0]))->value);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,((IntegerToken *)(opTok->token[0]))->type);
    TEST_ASSERT_EQUAL(3,((IntegerToken *)(opTok->token[1]))->value);
}








