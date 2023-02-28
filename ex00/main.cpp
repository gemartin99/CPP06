#include <string>
#include <iostream>
#include <cstring>

//int i = 10;
//float f = static_cast<float>(i);

	//if (i == 10 && (strncmp("2147483647", t, 11) < 0) || (strlen(t) == 11 && strncmp("-2147483648", t, 12) < 0) || strlen(t) > 11))

int check_point(char *s)
{
	int i = -1;
	while (s[++i])
	{
		if (s[i] == '.')
		{
			if (i > 11 || (i == 10 && (strncmp("2147483647", s, i) < 0)) || (i == 11 && (strncmp("-2147483648", s, i) < 0)))
				return (-1);
			else
				return (0);
		}
	}
	return (1);
}

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
	int x = 0;

	while (s[++i])
		if (s[i] == '.')
			x = 1;
	i = -1;
	if (s[i + 1] == '-' || s[i + 1] == '+')
		i++;
	while (s[++i])
	{
		if (s[i] == 'f' && i > 2 && x == 1 && isdigit(s[i - 1]) && !s[i + 1])
			;
		else if (!isdigit(s[i]) && s[i] != '.')
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
		cout_error("Invalid input");
}

int check_decimal(char *s)
{
	int j = 0;
	int i = 0;
	int c = 0;

	while (s[j] != '.')
		j++;
	while(s[++i + j])
	{
		if (s[i] != '0' && s[i] != 'f')
			c = 1;
	}
	i--;
	if (s[i] == 'f')
		i--;
	if (i > 7 && i <= 15 && c == 1)
		return (-1);
	if (i > 15 && c == 1)
		return (-2);
	return (0);
}

int check_zero(char *s)
{
	int i = 0;

	while (s[i] != '.')
		i++;
	while(s[++i])
	{
		if (s[i] != '0' && s[i] != 'f')
			return (1);
	}
	return (0);
}

void cast_values(char *s)
{
	int i;
	float f;
	char c = '\0';
	double d;

	if (check_point(s) && ((strlen(s) == 10
		&& (strncmp("2147483647", s, 11) < 0)) || (strlen(s) == 11 && 
		strncmp("-2147483648", s, 12) < 0) || strlen(s) > 11))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit (0);
	}
	if (check_point(s) == -1)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit (0);
	}
	else if (!check_point(s))
	{
		f = atof(s);
		//double d = std::stod(s);
		c = static_cast<int>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		
		//(void)c;
		//std::cout << test << "aaaa\n";
		if (f < 32 || f > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		if (!check_zero(s))
		{
			std::cout << "float: " << f << ".0f" <<std::endl;
			std::cout << "double: " << d << ".0" <<std::endl;
		}
		else
		{
			int x = check_decimal(s);
			if (x == -1)
			{
				std::cout << "float: Non displayable" << std::endl;
				std::cout << "double: " << d << std::endl;
			}
			else if (x == -2)
			{
				std::cout << "float: Non displayable" << std::endl;
				std::cout << "double: Non displayable" << std::endl;
			}
			else
			{
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << d << std::endl;
			}
		}
		exit (0); 
	}
	else
	{
		i = atoi(s);
		c = static_cast<int>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		if (i > 31 && i < 127)
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" <<std::endl;
		std::cout << "double: " << d << ".0" <<std::endl;
		exit (0);
	}
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
	cast_values(argv[1]);
}