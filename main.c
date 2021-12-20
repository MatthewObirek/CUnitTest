#include <stdio.h>
#include <stdlib.h>

#include "Question.h"

int main(int argc, char* argv[])
{

    Question NewQuestion;
    printf("%d\n", argc);
    if(argc > 1)
    {
        printf("%s\n", argv[1]);
        FILE* file = fopen(argv[1], "r");
        char line[7][250];
        while (fgets(line[0], sizeof(line), file)) {
            /* note that fgets don't strip the terminating \n, checking its
            presence would allow to handle lines longer that sizeof(line) */
            for(int i = 1; i < 7; i++)
                fgets(line[i], sizeof(line[i]), file);
            int x;
            sscanf(line[6], "%d", &x);
            createQuestion(&NewQuestion, line[0], line[1],line[2], line[3], line[4], line[5], x);
         
        }
        /* may check feof here to make a difference between eof and io failure -- network
        timeout for instance */

        fclose(file);
    }
    else
    {
        printf("no file was added, enter a file here that contains the proper formatting for the quiz\n(NOTE): formatting is listed in the README:");
    }
    //printf("\n");
    
    //printQuestion(&NewQuestion);

    int isCorrect = answerQuestion(&NewQuestion);
    if (isCorrect==0)
    {
        printf("Good Job\n");
    }
    else
    {
        printf("Bad Job\n");
    }
}