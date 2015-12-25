#include <stdlib.h>
#include <stdio.h>

#include "main.h"

int do_problem(int num)
{
	switch (num) {
	case 1:
		return problem1();
	case 2:
		return problem2();
	case 3:
		return problem3();
	case 4:
		return problem4();
	case 5:
		return problem5();
	case 6:
		return problem6();
	case 7:
		return problem7();
	case 8:
		return problem8();
	case 9:
		return problem9();
	case 10:
		return problem10();
	case 11:
		return problem11();
	case 12:
		return problem12();
	case 13:
		return problem13();
	case 14:
		return problem14();
	}
	return -1;
}

int main(int argc, char **argv)
{
	long num;
	char *endptr = NULL;
	if (argc < 2 || (num = strtol(argv[1], &endptr, 10)) <= 0 || *endptr || do_problem((int)num) < 0) {
		printf("Usage: %s [problem number]\n", *argv);
		return 0;
	}
	return 0;
}
