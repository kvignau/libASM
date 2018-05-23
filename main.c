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
char *ft_strcat(char *restrict s1, const char *restrict s2);
size_t ft_strlen(const char *s);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char *ft_strdup(const char *s1);

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
    char *str2;
    char *str3;
	char *str4;

    str = strdup("COUCOUcoucouYOLLOOOOO");
	str1 = NULL;
    str2 = strdup("");

	printf("MINE -> %d TRUE -> %d\n", ft_puts(str), puts(str));
    printf("MINE -> %d TRUE -> %d\n", ft_puts(str1), puts(str1));
    printf("MINE -> %d TRUE -> %d\n", ft_puts(str2), puts(str2));
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

void    test_strcat()
{
    char *str;
    char *str1;

    // str = NULL;
    // str1 = strdup("");
    str = (char *)malloc(sizeof(char) * 100);
    str = strcpy(str, "test");
    str1 = strdup("coucou");

    str = ft_strcat(str, str1);
    printf("STR -> %p, %s\n", str, str);
    // int i = 0;

    // while (i++ < 128)
    // {
    //     if (ft_isprint(i) != isprint(i))
    //     {
    //         printf("\033[31merror on ft_isprint at char -> %c\033[0m\n", i);
    //         return ;
    //     }
    // }
    // printf("\033[92m ft_isprint is ok \033[0m\n");
}

void    test_strlen()
{
    int a = strlen("YoooOOOoooOO coucou");
    int b = ft_strlen("YoooOOOoooOO coucou");
    if (a != b)
        printf("\033[31merror on ft_strlen TRUE-> %d MINE -> %d\n", a, b);
    else
        printf("\033[92m ft_strlen is ok \033[0m\n");
}

void    test_ft_memset()
{
    char *str = strdup("totowefewefwe");
    char *str2 = strdup("totowefewefwe");
    int len = strlen("totowefewefwe");
    memset(str, 'x', 4);
    ft_memset(str2, 'x', 4);
    if (str && str2 && strcmp(str, str2) != 0)
        printf("\033[31merror on ft_memset at str -> %s str2->  %s\033[0m\n", str, str2);
    else if (!str2)
        printf("\033[92m ft_memset for NULL string is ok \033[0m\n");
    else
        printf("\033[92m ft_memset is ok str -> %s str2->  %s\033[0m\n", str, str2);
}

void test_memcpy ()
{
    // char    memc1[10]   = "123456789";
    // char    memc2[5]    = "abcd";
    // ft_memcpy(memc1, memc2, 3);
    // if (memc1[0] == memc2[0] && memc1[1] == memc2[1] && memc1[2] == memc2[2])
    //     printf("\033[92m ft_memcpy is ok \033[0m\n");
    // else
    //     printf("\033[31merror on ft_memcpy\033[0m\n");

    char *str = strdup("totowefewefwe");
    char *str2 = strdup("coucou");

    char *str3 = strdup("totowefewefwe");
    char *str4 = strdup("coucou");

    memcpy(str, str2, 4);
    ft_memcpy(str3, str4, 4);
    if (str && str3 && strcmp(str, str3) != 0)
        printf("\033[31merror on ft_memset at str -> %s str3->  %s\033[0m\n", str, str3);
    else if (!str3)
        printf("\033[92m ft_memset for NULL string is ok \033[0m\n");
    else
        printf("\033[92m ft_memset is ok str -> %s str3->  %s\033[0m\n", str, str3);
}

void    test_strdup()
{
    char *str = strdup("42");
    char *str2;

    str2 = ft_strdup("42");
    if (str && str2 && strcmp(str, str2) != 0)
        printf("\033[31merror on ft_strdup at str -> %s str2->  %s\033[0m\n",str, str2);
    else if (!str2)
        printf("\033[92m ft_strdup is ok for NULL string\033[0m\n");
    else
        printf("\033[92m ft_strdup is ok str2->  %s\033[0m\n", str2);
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
    test_strcat();
    test_strlen();
    test_ft_memset();
    test_memcpy();
    test_strdup();
}
