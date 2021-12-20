#pragma once
#include <stdio.h>
#include <string.h>

struct
{
    char Querry[250];
    char Choice[4][250];
    char Hint[250];
    int answer;
} typedef Question;

void createQuestion(Question* Q, char* Querry, char* a, char* b, char* c, char* d, char* Hint, int answer);

void printQuestion(Question* Q);

int answerQuestion(Question* Q);

struct 
{
    Question* Start;
    Question* End;
} typedef TestList;

void fillTest(char* filename, TestList testlist);

void startTest(TestList testlist);

