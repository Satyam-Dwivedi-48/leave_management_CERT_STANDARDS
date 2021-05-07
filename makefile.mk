a.out: main_function.o quit_again_final.o login_deduction.o main2_table.o
	gcc main_function.o quit_again_final.o login_deduction.o main2_table.o
quit_again_final.o: quit_again_final.c server.h
	gcc -c quit_again_final.c
login_deduction.o: login_deduction.c server.h
	gcc -c login_deduction.c
main2_table.o: main2_table.c server.h
	gcc -c main2_table.c
main_function.o: main_function.c server.h
	gcc -c main_function.c