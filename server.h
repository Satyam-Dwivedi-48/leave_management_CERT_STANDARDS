#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<ctype.h>
extern int linematched;//global variable which stores the variable 
extern struct Empdetials
{
    char name[25];
    char id[9];//onr extra character to store /n
    char password[5];
    int casual;//casual,medical,earned leave as per the question 
    int medical;
    int earned;
}emp[5];//declaring array of structures which will later be populated using table() function
//extern struct Empdetials emp[5]; // declaration of emp
extern void main2();//this containsthe main part of the code workings,its pupose is explained below just before the function
extern void final_print();//prints the details of the user on quitting the wizard
extern void quit();//this is one function which handles the termination of code prompting the user to take another trail
extern void again();//this function handles the login if user wishes to take another leave
extern void table(char file_n[]);//populating the structure from data elements from the file by using specific delimiter 
extern int login();//this function verifies the password with the one present in the file database
extern int deduction(int linematched,int days,int type_of_leave);//this performs another validation and deducts the days user desires for taking the leave