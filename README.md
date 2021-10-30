# leave_management_CERT_STANDARDS
_This is the modified version of employee leave management system following the CERT  standards prescribed by Carnegie mellon university and the details of this is listed in the vast and detailed project report and synopsis._
 

### List of .c files implemented in the project

1) __main_function.c__  
This function acts like min function in any modular code, it reads and validates the input given by the command argument and passes on the name of the file to table function in the main2_table function to continue with the execution of the program.

2) __main2_table.c__  
This acts as main handler and calls the table() function  to populate the array of structures and this is the core function called every time the user wants to login and also handles level 1 of input validation and the other level being handled In login deduction which takes care of negative inputs.

3) __login_deduction.c__  
This function has the code for authentication of user credentials allow access for the deduction of leaves from appropriate quota and of the right person and deliver the message of deduction in case of success and an appropriate error in case of a failure of deduction and it updates the structure values of the logged-in user, all input points are safeguarded from buffer overflow and stack smashing cases by flushing the stdin buffer.

4) __quit_again_final.c__  
This function gives our project the ability to let user dictate the terms of termination of the program, here we make the user at  centre of the program by giving him/her the power to re-login without termination of the code without user permission.
If the user decides to finally quit after the prompts the quit function is called to ask for one last time to confirm that unintentional inputs are not taken straightaway and user is given a chance to correct his mistake if it was committed and calls print() function.
Final_print() is a multipurpose function which does the job of creating a file name using the reference of the system time and manages the format and creates the file and handles the appropriate errors and writes the output to the file and to the terminal at the same time and ends the execution of the program.
  
  __Windows Subsystem for Linux(WSL) was used to execute the program.__
### Steps to run the code:

 1) Run the make utility using this command which compiles all the .c files using gcc and creates an executable a.out.  
   ``` 
    make -f makefile.mk 
   ```
 2) Now run the executable and pass the file name as the command line argument.
   ```C 
    ./a.out employeeinfo.txt
   ```
