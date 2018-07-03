/*

 Write a C program for recursive descent parser for the following grammar:
 E -> TX
 T -> FY
 X -> +TX
 X -> null
 Y -> *FY
 Y -> null
 F -> id

 Terminals = +, *, id
 Non-terminals = E, T, X, Y, F
 Start symbol = E 
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
enum validTokens {PLUS, MULTIPLY, ID, $};
enum validTokens inputTokens[] = {ID,PLUS, ID, MULTIPLY, ID, PLUS, ID, MULTIPLY, ID, $};
enum validTokens currentToken;
int i = -1;
enum validTokens getCurrentToken()
{
	return inputTokens[i];
}
void forward()
{
	++i;
	currentToken = getCurrentToken();
	printf("i - %d -> current token no - %d\n", i, currentToken);
}
void error()
{
	printf("error - Wrong syntax");
	exit(1);
}
void match(enum validTokens t)
{
	if(currentToken == t)
	{
		printf("matched token no - %d\n", t);
		forward();
	}
	else
	{
		error();
	}
}
void E();
void X();
void T();
void Y();
void F();
void E()
{
	T();
	X();
}
void X()
{
	switch(currentToken)
	{
		case PLUS:
			match(PLUS);
			T();
			X();
			break;
		default:
			break;
	}
}
void T()
{
	F();
	Y();
}
void Y()
{
	switch(currentToken)
	{
		case MULTIPLY:
			match(MULTIPLY);
			F();
			Y();
			break;
		default:
			break;
	}
}
void F()
{
	match(ID);
}
int main()
{
	forward();
	E();
	if(currentToken == $)
	{
		printf("Parsing successfull\n");
	}
	else
	{
		error();
	}
	return 0;
}