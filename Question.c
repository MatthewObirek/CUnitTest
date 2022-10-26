#include "Question.h"

void createQuestion(Question* Q, char* Querry, char* Type, char* ExtraInfo, char* Answer, char* Hint)
{
    strcpy(Q->Querry, Querry);
    strcpy(Q->Type, Type);
    strcpy(Q->ExtraInfo, ExtraInfo);
    strcpy(Q->Answer, Answer);
    strcpy(Q->Hint, Hint);
    return;
}

void printQuestion(Question *Q)
{
    printf("%s", Q->Querry);
    printf("%s", Q->Type);
    if (strcmp(Q->Type, "MC") == 0)
    {
        char delim[2] = "!";
        char* ptr = strtok(Q->ExtraInfo, delim);
        char Choice[4][128];
        int n = 0;
        while(ptr != NULL)
        {
            strcpy(Choice[n], ptr);
            n++;
            ptr = strtok(NULL, delim);
        }
        printf("\t%s", Choice[0]);
        printf("\t%s", Choice[1]);
        printf("\t%s", Choice[2]);
        printf("\t%s", Choice[3]);
    }
    else if (strcmp(Q->Type, "TF") == 0)
    {
        printf("\tTrue, or False\n");
    }
}

int answerQuestion(Question* Q)
{
    int input;
    int correctness = 0;
    printQuestion(Q);
    do {
        printf("Answer(A=1/B=2/C=3/D=4): ");
        scanf("%d", &input);
        if (input == Q->Answer) 
        {

            return correctness;//return correct
        }
        else if (correctness>0)
        {
           // printf("Incorrect, The correct answer is \n\n%s\nTry again\n", Q->Choice[(Q->answer-1)]);

        }
        else 
        {
            printf("%s", Q->Hint);
        }
        correctness++;
    } while ( input != Q->Answer);
    return correctness;
}