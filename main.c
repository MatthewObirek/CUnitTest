#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include "Question.h"

const char* d_name = "Content";

int main(int argc, char* argv[])
{

    DIR *d;
    //hello
    struct dirent *dir;
    d = opendir(d_name);
    char** d_line = (char**)calloc(10, 50);
    int i = 0;
    int l_size = 0;
    if (d)
    {
        while ((dir = readdir(d)) != NULL) 
        {
            if(!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
                continue;
            d_line[i] = dir->d_name;
            printf("%s\n", dir->d_name);
            i++;
            l_size = i;
        }
        closedir(d);
    }
    else
    {
        perror("Directory not found, Check directory spelling");
        exit(EXIT_FAILURE);
    }

    printf("Which files should be loaded?[1,2,...,%d]\n", l_size);
    //char input[2*l_size];
    //fgets(input, sizeof(input), stdin);
    char* f_name = "Content/Example.txt";
    printf("for now, loading %s...\n", f_name);
    //! Reading more than 1 file needs to be addressed.
    /*     
    char delim[2] = ",";
    char* ptr = strtok(input, delim);
    int array[l_size];
    int n = 0;
	while(ptr != NULL)
	{
        array[n] = ((int)ptr[0]) - 48;
        n++;
		ptr = strtok(NULL, delim);
	}
    for(int index = 0; index<l_size; index++)
    {
        if(array[index] == 0)
            break;
        char* f_name[strlen(d_name)+strlen(d_line[array[index]])+1];
        strcat(f_name, d_line[index]);
        printf("%s\n", f_name);    

    }*/
    FILE* file = fopen(f_name, "r");
    char line[256];
    int cnt = 0; 
    Question q_list[50];
    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
        presence would allow to handle lines longer that sizeof(line) */
        char delim[2] = ":";
        char* ptr = strtok(line, delim);
        char Querry[256];
        char Type[256];
        char ExtraInfo[256];
        char Hint[256];
        char Answer[256];
        ///printf("%s\n", ptr);
        if (strcmp(ptr, "!Question") == 0)
        {
            ptr+=11;
            ///printf("%s\n", ptr);            
            strcpy(Querry, ptr);
        }
        else if(strcmp(ptr, "!QType") == 0)
        {   
            ptr+=8;
            ///printf("%s\n", ptr);
            strcpy(Type, ptr);
        }
        else if(strcmp(ptr, "!ExtraInfo") == 0)
        {
            ptr+=12;
            ///printf("%s\n", ptr);
            strcpy(ExtraInfo, ptr);
        }
        else if(strcmp(ptr, "!Hint") == 0)
        {
            ptr+=7;
            ///printf("%s\n", ptr);
            strcpy(Hint, ptr);
        }
        else if(strcmp(ptr, "!Answer") == 0)
        {
            ptr+=9;
            ///printf("%s\n", ptr);
            strcpy(Answer, ptr);
        }        
        else if(strcmp(line, "!EndQuestion") == 0)
        {

            if(cnt>49)
                break;
            createQuestion(&q_list[cnt], Querry, Type, ExtraInfo, Hint, Answer);
            printf("count: %d\n",cnt);
            cnt++; 
        }
        
    }


    for(int x = 0; x < cnt; x++)
    {
        printf("\n\ncount: %d\n", x);
        printQuestion(&q_list[x]);
    }
    fclose(file);
    return 0;
}


    /*Question *TestArray;
    printf("%d\n", argc);
    if(argc > 1)
    {
        printf("%s\n", argv[1]);
        FILE* file = fopen(argv[1], "r");
        char line[7][250];
        int cnt = 0; 
        while (fgets(line[0], sizeof(line), file)) {
            /* note that fgets don't strip the terminating \n, checking its
            presence would allow to handle lines longer that sizeof(line) 
            cnt++;
         
        }

        fclose(file);
        cnt = cnt/7;
        file = fopen(argv[1], "r");
        TestArray = malloc(cnt*sizeof(Question));
        printf("not here\n");
        int j = 0;
        while (fgets(line[0], sizeof(line), file)) {
            /* note that fgets don't strip the terminating \n, checking its
            presence would allow to handle lines longer that sizeof(line) 
            for(int i = 1; i < 7; i++)
                fgets(line[i], sizeof(line[i]), file);
            int x;
            sscanf(line[6], "%d", &x);
            createQuestion(&TestArray[j], line[0], line[1],line[2], line[3], line[4], line[5], x);
            printf("not here either %d\n", j);
            j++;
         
        }
        /* may check feof here to make a difference between eof and io failure -- network
        timeout for instance *
        fclose(file);
    }
    else
    {
        printf("no file was added, enter a file here that contains the proper formatting for the quiz\n(NOTE): formatting is listed in the README:");
        return EXIT_FAILURE;
    }
    //printf("\n");
    
    //printQuestion(&NewQuestion);

    int isCorrect = answerQuestion(&TestArray[0]);
    if (isCorrect==0)
    {
        printf("Good Job\n");
    }
    else
    {
        printf("Bad Job\n");
    }

    isCorrect = answerQuestion(&TestArray[1]);
    if (isCorrect==0)
    {
        printf("Good Job\n");
    }
    else
    {
        printf("Bad Job\n");
    }*/
