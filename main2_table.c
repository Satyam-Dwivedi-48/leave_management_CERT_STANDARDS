#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<ctype.h>
#include"server.h"
/*main function has a call to table() and invoking main() for re-login used to reset the structure and the deductions were lost,so we copied 
everything from the main function into another function called main2() which is basically the main function without the table() invoking so the
structure is not resetted after every call from again() and quit() during Re-login and structure keeps a track of the deductions that happened and 
in this way we also removed the Welcome sentence to the same user,but the main reason is to avoid rewriting of the structure on every call 
and losing the deduction data*/
void main2()
{
    int casualm=10;//defining the maximum possible leaves here
    int medicalm=15;
    int earnedm=7;
    int leave_days=0;//handles the number of leaves that a user will enter
    int choice=0;//type of leave is handled by this variable 1 is casual,2 is emergency,3 is earned
    int log=0;//CHECKS IF LOGIN WAS SUCCESFULL OR NOT
    int res=0;//CHECKS IF DEDUCTION WAS SUCCESFULL OR NOT
    //-------------------------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------------------------
    log=login();//login is invoked and log stores the value which determines whether the login was succesful or not
    if(log==1)//if log=1,implies that the login was succesful and the user was found
    {
        printf("PLEASE SELECT HE TYPE OF LEAVE YOU WANT TO TAKE\n");
        printf("1.CASUAL LEAVE\n");
        printf("2.MEDICAL LEAVE\n");
        printf("3.EARNED LEAVE\n");
        (void)scanf("%d",&choice);
        printf("PLEASE ENTER THE NUMBER OF LEAVES YOU WANT TO APPLY FOR\n");
        (void)scanf("%d",&leave_days);
    }
    else 
    {
        printf("SORRY THE LOGIN CREDENTIALS DON'T MATCH WITH ANY USER\n\n\n");//when the login fails this message is displayed
        again();//gives user another chance to take give the input
    }
    //first validation of the input values,this compares the input with the largest value of holidays available
    int flag=1;//this controls wheter the variable entered is within the maximum limit and that deduction() function can be called
     if(choice==1)
    {
        if(leave_days>casualm)
        {
            printf("THE ENTERED NUMBER OF DAYS CROSSES THE MAXIMUM LIMIT \n");
            again();
            flag=0;
        }
    }
    if(choice==2)
    {
        if(leave_days>medicalm)
        {
            printf("THE ENTERED NUMBER OF DAYS CROSSES THE MAXIMUM LIMIT \n");
            again();
            flag=0;
        }
    }
    if(choice==3)
    {
        if(leave_days>earnedm)
        {
            printf("THE ENTERED NUMBER OF DAYS CROSSES THE MAXIMUM LIMIT \n");
            again();
            flag=0;
        }
    }
    if(choice>3||choice<0)
    {
        printf("sorry!! wrong input\n");
        again();
        flag=0;
    }

            

    if(flag==1)//if the validation is succcesful the value of the variable remains 1 and this loop is entered
    {
        res=0;
        res=deduction(linematched,leave_days,choice);//if res==1 then thern the validation was succesful and then the deduction is called and parameter is passed
        if(res==1)//if deduction was succesful then the 
        {
            printf("DEDUCTION  WAS SUCCESFUL\n\n");
            again();       
        }
        // else{
        //     printf("failed\n");
        //     again();
        // }
    }
}
//Here, we convert the file to a structure and then use the structure to access the data and also using files to store the information 
extern void table(char file_n[])//this function is responsible for populating the structure by reading the file
{
   FILE *fp=NULL;//defining a file pointer
   //char ch;
   char  line[256];//definig 256 here,any arbitrary number can be used
   char *token;//token pointer that points to the elements of a line
   int tokenposition=0;//token here means the particular text separated by comma
   int lineposition=0;//line here is the entire line which has entire details of the an emmployee 
   fp=fopen(file_n,"r");//opening the file in read mode as we are only accessing information and not rewriting it
   //-------------------------------------------------------------------------------------------------------------------------------------------------

if (fp==NULL)
{
    printf("File access error!!\n");
    exit(0);
}

    while(fgets(line,256,fp) !=NULL) //accessing the lines one by one and trying to recognize the end of a line
    {
        tokenposition=0;//when we tokenize the line we need the count to keep a track of where we are int he string
        //printf("%s \n",line);//used to check which line is not being read by the compiler
        token = strtok(line,",");
            //this seperates a line into token(entity) based on a delimiter,here the delimiter is a comma
        //strtok-tring tokenization method
        while(token != NULL)
        {
            switch(tokenposition)//acessing the required element through the tokenposition counter
            {
                case 0://NAME
                    strcpy(emp[lineposition].name,token);
                    break;
                case 1://ID
                    strcpy(emp[lineposition].id,token);
                    break;
                case 2://PASSWORD
                    strcpy(emp[lineposition].password,token);
                    break;
                case 3://CASUAL LEAVE
                    emp[lineposition].casual=atoi(token);
                    break;
                case 4://MEDICAL LEAVE
                    emp[lineposition].medical=atoi(token);
                    break;
                case 5://EARNED LEAVE
                    emp[lineposition].earned=atoi(token);
                    break;
            }
            token =strtok(NULL,",");
        tokenposition++;//to access the next token in the same line 
        }
        lineposition++;//after all the tokens are put in a structure,we move to the next line and redo the entire process of reading a line
    }
        int success=fclose(fp); //Don't forget to close the file when finished
    if(success==0)
    {
        printf("file closed successfully\n");
    }
    else{
        printf("ERROR WHILE CLOSING THE FILE\n");
    }
}