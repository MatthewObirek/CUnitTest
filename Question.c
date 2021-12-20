#include "Question.h"

void createQuestion(Question* Q, char* Querry, char* a, char* b, char* c, char* d, char* Hint, int answer)
{
    strcpy(Q->Querry, Querry);
    strcpy(Q->Choice[0], a);
    strcpy(Q->Choice[1], b);
    strcpy(Q->Choice[2], c);
    strcpy(Q->Choice[3], d);
    strcpy(Q->Hint, Hint);
    Q->answer = answer;
    return;
}

void printQuestion(Question *Q)
{
    printf("%s", Q->Querry);
    printf("\t%s", Q->Choice[0]);
    printf("\t%s", Q->Choice[1]);
    printf("\t%s", Q->Choice[2]);
    printf("\t%s", Q->Choice[3]);
}

int answerQuestion(Question* Q)
{
    int input;
    int correctness = 0;
    printQuestion(Q);
    do {
        printf("Answer(A=1/B=2/C=3/D=4): ");
        scanf("%d", &input);
        if (input == Q->answer) 
        {

            return correctness;//return correct
        }
        else if (correctness>0)
        {
            printf("Incorrect, The correct answer is \n\n%s\nTry again\n", Q->Choice[(Q->answer-1)]);

        }
        else 
        {
            printf("%s", Q->Hint);
        }
        correctness++;
    } while ( input != Q->answer);
    return correctness;
}