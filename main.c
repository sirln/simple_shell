#include "ash.h"

/**
  *main - start of program execution
  *
  *@argc: number of arguments
  *@argv: array of arguments
  *
  *Return: 0 on success and 1 on failure
  *
  */

int main(int argc, char **argv)
{
	if (argc == 0)
		return (-1);

	ash(argv);

	return (0);
}
