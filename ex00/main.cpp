#include <string>
#include <iostream>

//int i = 10;
//float f = static_cast<float>(i);

void char_case(char c)
{
	int i = static_cast<int>(c);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" <<std::endl;
	std::cout << "double: " << d << ".0" <<std::endl;
	exit (0); 
}

void cout_error(std::string s)
{
	std::cout << s << std::endl;
	exit (-1);
}

int only_nums(char *s)
{
	int i = -1;

	if (s[i + 1] == '-' || s[i + 1] == '+')
		i++;
	while (s[++i])
	{
		if (!isdigit(s[i]) && s[i] != '.')
			return (0);
	}
	return (1);
}

int check_invalid_point(char *s)
{
	int i = -1;

	if (s[i + 1] == '.')
		return (0);
	while (s[++i])
	{
		if (s[i] == '.' && i > 0 && (!isdigit(s[i - 1]) || !isdigit(s[i + 1])))
			return (0);
	}
	return (1);
}

int check_over_one(char *s, char c) //funcion para comprobar que cualquier letra que le pase solo pueda estar una vez dentro de la string
{
	int i = -1;
	int res = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (((c == '-' || c == '+') && i != 0) || (c == '.' && i == 0))
				return (0);
			res++;
		}
	}
	if (res > 1)
		return (0);
	return (1);
}

void parsing(char *s)
{
	if (!strcmp(s, "nanf") || !strcmp(s, "nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit (0);
	}
	else if (!strcmp(s, "+inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		exit (0);
	}
	else if (!strcmp(s, "-inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		exit (0);
	}
	if (strlen(s) == 3 && s[0] == 39 && s[2] == 39 && s[1] > 32 && s[1] < 127)
		char_case(s[1]);
	if (!check_over_one(s, '.') || !check_over_one(s, '-') || !check_over_one(s, '+') || !check_invalid_point(s) || !only_nums(s))
		cout_error("Inalid input");
}

int main(int argc, char **argv)
{
	// char res_c;
	// int res_i;
	// float res_f;
	// double res_d;

	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Invalid arguments" << std::endl;
		return (-1);
	}
	parsing(argv[1]);
}