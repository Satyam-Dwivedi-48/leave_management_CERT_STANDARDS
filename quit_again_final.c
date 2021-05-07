#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
#include"server.h"
void quit()
{
    char ans[5];
    int c;
    printf("ARE YOU SURE YOU WANT TO QUIT THE WIZARD? Y OR N\n");
    (void)scanf("%4s", ans);
    while ((c = fgetc(stdin)) != (int)'\n' && c != EOF); /* Flush stdin */
    if (tolower(ans[0]) == (int)'y')
    {
        final_print();
        printf("\n\n");
        printf("---THANK YOU FOR USING OUR PORTAL--\n");
    }
    else
    {
        main2();
    }
}
void again()
{
    char ans1[5];
    int c;
    //char tt='y';
    printf("SEARCH AGAIN USING ID AND PASSWORD? Y OR N\n");
    (void)scanf("%4s", ans1);
    while ((c = fgetc(stdin)) != (int)'\n' && c != EOF); /* Flush stdin */
    if (tolower(ans1[0]) == (int)'y')
    {
        main2();//FOR RE-LOGIN PROCESS
    }
    else
    {
        quit();
    }
    printf("\n\n\n");
}
//PRINTS TO FILE AND THE TERMINAL THE FINAL RESULTS AND STATEMENT OF LEAVES OF EVERY EMPLOYEE
void final_print()
{

    FILE *fp=NULL;
    //------------------------------------------------------------------------------------------
    char text[150];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    //strftime(text, sizeof(text)-1, "%dd %mm %YYYY %HH:%MM", t);
    (void)strftime(text, sizeof(text)-1,"%d_%B_%Y_%H-%M-%S", t);//string from time
    text[150] = '\0';
    // concat the date to file name
    char *filename;
    //C:\\Users\\Satyam Dwivedi\\Desktop\\Employee_leave_manegment_system-master
    if((filename = malloc(strlen("C:\\Users\\Satyam Dwivedi\\Desktop\\Employee_leave_manegment_system-master")+strlen(text)+1)) != NULL){
        filename[0] = '\0';   // ensures the memory is an empty string
        strcat(filename,"statement_");
        strcat(filename,text);
        strcat(filename,".txt");
    }

    //printf("filename: %s \n\n",filename);
   // use the file
    //------------------------------------------------------------------------------------------
    if(filename!=NULL)
    {
        printf("filename: %s \n\n",filename);
        fp = fopen(filename, "w");// "w" means that we are going to write on this file
    }
    if (fp==NULL)
    {
        printf("File access error!!\n");
        exit(0);
    }
    printf("----------------FINAL STATEMENT OF LEAVE OF EACH EMPLOYEE------------------------\n\n");
    fprintf(fp,"----------------FINAL STATEMENT OF LEAVE OF EACH EMPLOYEE------------------------\n\n");
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("NAME : %s\n",emp[i].name);
        fprintf(fp,"NAME : %s\n",emp[i].name);
        printf("USER ID : %s\n",emp[i].id);
        fprintf(fp,"USER ID : %s\n",emp[i].id);
        printf("CASUAL LEAVE LEFT : %d\n",emp[i].casual);
        fprintf(fp,"CASUAL LEAVE LEFT : %d\n",emp[i].casual);
        printf("MEDICAL LEAVE LEFT : %d\n",emp[i].medical);
        fprintf(fp,"MEDICAL LEAVE LEFT : %d\n",emp[i].medical);
        printf("EARNED LEAVE LEFT : %d\n\n",emp[i].earned);
        fprintf(fp,"EARNED LEAVE LEFT : %d\n\n",emp[i].earned);
    }
    printf("---------THANK YOU FOR USING LEAVE MANEGMENT PORTAL-----\n");
    fprintf(fp,"---------THANK YOU FOR USING LEAVE MANEGMENT PORTAL-----\n");
    // printf("STATMENT GENERATED ON %s \n \n", time_string);
    // fprintf("STATEMENT GENERATED ON %s\n \n", time_string);
    int success=fclose(fp); //Don't forget to close the file when finished
    if(success==0)
    {
        printf("file closed successfully\n");
    }
    else{
        printf("ERROR WHILE CLOSING THE FILE\n");
    }
    free(filename);
}