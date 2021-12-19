#include "Question.h"

void createQuestion(Question* Q, char* Querry, char* a, char* b, char* c, char* d, char* Hint, int answer)
{
    strcpy(Q->Querry, Querry);
    strcpy(Q->A, a);
    strcpy(Q->B, b);
    strcpy(Q->C, c);
    strcpy(Q->D, d);
    strcpy(Q->Hint, Hint);
    Q->answer = answer;
    return;
}

void printQuestion(Question *Q)
{
    printf("%s", Q->Querry);
    printf("%s", Q->A);
    printf("%s", Q->B);
    printf("%s", Q->C);
    printf("%s", Q->D);
}