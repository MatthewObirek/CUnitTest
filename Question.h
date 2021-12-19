#pragma once
#include <stdio.h>
#include <string.h>

struct {
    char Querry[250];
    char A[250];
    char B[250];
    char C[250];
    char D[250];
    char Hint[250];
    int answer;
} typedef Question;

void createQuestion(Question* Q, char* Querry, char* a, char* b, char* c, char* d, char* Hint, int answer);

void printQuestion(Question *Q);