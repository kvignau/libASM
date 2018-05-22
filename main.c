#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ft_bzero(void *s, size_t n);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_isprint(int c);
int ft_puts(const char *s);

void test_bzero()
{
	char *str;
	char *str2;
	int len = 0;

	str = strdup("COUCOUcoucou");
	str2 = strdup("COUCOUcoucou");
	len = strlen(str);
	ft_bzero((void *)str, len);
	bzero((void *)str2, len);
	int i = -1;
	while (++i < len)
		if (str[i] != str2[i])
		{
			printf("\033[31merror on ft_bzero at i -> %d char->  %c\033[0m\n", i, str[i]);
			return ;
		}
	printf("\033[92m ft_bzero is ok \033[0m\n");
}

void test_puts()
{
	char *str;
	char *str1;

	str = strdup("COUCOUcoucou");
	str1 = NULL;
	// ft_puts(str);
	printf("MINE -> %d TRUE -> %d\n", ft_puts(str), puts(str));
	printf("MINE -> %d TRUE -> %d\n", ft_puts(str1), puts(str1));
	// while (++i < len)
	// 	if (str[i] != str2[i])
	// 	{
	// 		printf("\033[31merror on ft_bzero at i -> %d char->  %c\033[0m\n", i, str[i]);
	// 		return ;
	// 	}
	// printf("\033[92m ft_bzero is ok \033[0m\n");
}

void    test_isalpha()
{
    int i = 0;

    while (i++ < 128)
    {
        if (ft_isalpha(i) != isalpha(i))
        {
            printf("\033[31merror on ft_isalpha at char -> %c\033[0m\n", i);
            return ;
        }
    }
    printf("\033[92m ft_isalpha is ok \033[0m\n");
}

void    test_isdigit()
{
    int i = 0;

    while (i++ < 128)
        if (ft_isdigit(i) != isdigit(i))
        {
            printf("\033[31merror on ft_isdigit at char -> %c\033[0m\n", i);
            return ;
        }
    printf("\033[92m ft_isdigit is ok \033[0m\n");
}

void    test_isalnum()
{
    int i = 0;

    while (i++ < 128)
        if (ft_isalnum(i) != isalnum(i))
        {
            printf("\033[31merror on ft_isalnum at char -> %c\033[0m\n", i);
            return ;
        }
    printf("\033[92m ft_isalnum is ok \033[0m\n");
}

void    test_isascii()
{
    int i = -1;

    while (i++ < 1000)
        if (ft_isascii(i) != isascii(i))
        {
            printf("\033[31merror on ft_isascii at char -> %c\033[0m\n", i);
            return ;
        }
    printf("\033[92m ft_isascii is ok \033[0m\n");
}

void    test_tolower()
{
    int i = 0;

    while (i++ < 128)
    {
        if (ft_tolower(i) != tolower(i))
        {
            printf("\033[31merror on ft_tolower at char -> %c\033[0m\n", i);
            return ;
        }
    }
    printf("\033[92m ft_tolower is ok \033[0m\n");
}

void    test_toupper()
{
    int i = 0;

    while (i++ < 128)
    {
        if (ft_toupper(i) != toupper(i))
        {
            printf("\033[31merror on ft_toupper at char -> %c\033[0m\n", i);
            return ;
        }
    }
    printf("\033[92m ft_toupper is ok \033[0m\n");
}

void    test_isprint()
{
    int i = 0;

    while (i++ < 128)
    {
        if (ft_isprint(i) != isprint(i))
        {
            printf("\033[31merror on ft_isprint at char -> %c\033[0m\n", i);
            return ;
        }
    }
    printf("\033[92m ft_isprint is ok \033[0m\n");
}

int			main(void)
{
	test_bzero();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_tolower();
	test_toupper();
	test_isprint();
	test_puts();
}
