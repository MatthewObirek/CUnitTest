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

int answerQuestion(Question* Q)
{
    int input;
    int correctness = 0;
    printQuestion(Q);
    do {
        printf("Answer(A=1/B=2/C=3/D=4/Hint=5): ");
        scanf("%d", &input);
        if (input == Q->answer) 
        {

            return correctness;//return correct
        }
        else if (input == 5)
        {
            printf("%s", Q->Hint);
            printf("Answer(A=1/B=2/C=3/D=4/Hint=5): ");
            scanf("%d", &input);
        }
        else
        {
            printf("Incorrect, The correct answer is \"%i\" Try again", Q->answer);

        }
        correctness++;
    } while ( input != Q->answer);
    return correctness;
}