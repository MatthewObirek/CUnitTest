#pragma once
#include <stdio.h>
#include <string.h>

struct
{
    char Querry[256];
    char Type[256];
    char ExtraInfo[256];
    char Answer[256];
    char Hint[256];
} typedef Question;

void createQuestion(Question* Q, char* Querry, char* Type, char* ExtraInfo, char* Answer, char* Hint);

void printQuestion(Question* Q);

int answerQuestion(Question* Q);

struct 
{
    Question* Start;
    Question* End;
} typedef TestList;

void fillTest(char* filename, TestList testlist);

void startTest(TestList testlist);

