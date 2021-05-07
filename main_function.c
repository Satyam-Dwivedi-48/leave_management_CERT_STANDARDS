#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
#include"server.h"
struct Empdetials emp[5];  // definition of emp
int linematched;
int main(int argc,char *argv[])//command line arguments takes the name of the file to be read
{
    char file_name[30];//to copy the name of the file into a character array
    if(argc != 2)   //Argument Validation
    {
        printf("PLEASE ENTER DATA IN CORRECT FORMAT \n");
        exit(0);
    }
    //if(argv[1]=='\0')
    if (strlen(argv[1])>30)    //To bound the file name size to avoid overflows
    {
        printf("Length of file name exceeds the limit\n");
        exit(0);
    }
    strcpy(file_name,argv[1]);//copying the name here 
    //printf("%s\n\n",file_name);//tersting if the name is taken sucessfully
    table(file_name);//calling the function to initiate the process of filling a structure with all the data from the files
    printf("--------------------------------HELLO-------------------------------\n");
    printf("----------------------WELCOME TO LEAVE MANEGMENT SYSTEM--------------\n");
    main2();//the use of this is explained in the next .c file
    return 0;
}