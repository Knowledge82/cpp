#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
	}
	std::cout << "\n";
	return (0);
}
