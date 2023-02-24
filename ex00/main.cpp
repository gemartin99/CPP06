#include "Cast.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Invalid arguments" << std::endl;
		return (-1);
	}
	try
	{
		parsing(argv[1]);
	}
}