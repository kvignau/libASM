#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <unistd.h>

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

int ft_isupper(int c);
int ft_islower(int c);
void ft_putchar(int c);
void ft_putchar_fd(int c, int fd);
void ft_putstr(char *str);
void ft_putstr_fd(char *str, int fd);
char *ft_strtoupper(char *str);
char *ft_strtolower(char *str);

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

    str = strdup("COUCOUcoucouYOLLOOOOO");
	str1 = NULL;
    str2 = strdup("");

    printf("\n\033[92m ft_puts is ok \033[0m\n");
	printf("MINE -> %d TRUE -> %d\n", ft_puts(str), puts(str));
    printf("MINE -> %d TRUE -> %d\n", ft_puts(str1), puts(str1));
    printf("MINE -> %d TRUE -> %d\n", ft_puts(str2), puts(str2));
    printf("\n");
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
    char *str2;
    char *str3;

    str = (char *)malloc(sizeof(char) * 100);
    str = strcpy(str, "test");
    str1 = strdup("coucou");

    str2 = (char *)malloc(sizeof(char) * 100);
    str2 = strcpy(str2, "test");
    str3 = strdup("coucou");

    str = ft_strcat(str, str1);
    str2 = strcat(str2, str3);
    if (strcmp(str, str2) != 0)
        printf("\033[31merror on ft_strcat \nMINE -> %s\nTRUE -> %s \033[0m\n", str, str2);
    else
        printf("\033[92m ft_strcat is ok \033[0m\n");
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

void    test_isupper()
{
    int i = 0;

    while (i++ < 128)
    {
        if (i >= 65 && i <= 90 && ft_isupper(i) != 1)
        {
            printf("\033[31merror on ft_isupper at char -> %c\033[0m\n", i);
            return ;
        }
    }
    printf("\033[92m ft_isupper is ok \033[0m\n");
}

void    test_islower()
{
    int i = 0;

    while (i++ < 128)
    {
        if (i >= 97 && i <= 122 && ft_islower(i) != 1)
        {
            printf("\033[31merror on ft_islower at char -> %c\033[0m\n", i);
            return ;
        }
    }
    printf("\033[92m ft_islower is ok \033[0m\n");
}

void    test_putchar()
{
    int i = 0;

    printf("\n\033[92m ft_putchar is ok \033[0m\n");
    write(1, "REAL -> ", 8);
    while (i++ < 128)
    {
        write(1, &i, 1);
    }
    i = 0;
    write(1, "\n\n MINE -> ", 11);
    while (i++ < 128)
    {
        ft_putchar(i);
    }
    write(1, "\n", 1);
}

void    test_putchar_fd()
{
    int i = 0;

    printf("\n\033[92m ft_putchar_fd is ok \033[0m\n");
    write(2, "REAL -> ", 8);
    while (i++ < 128)
    {
        write(2, &i, 1);
    }
    i = 0;
    write(2, "\n\n MINE -> ", 11);
    while (i++ < 128)
    {
        ft_putchar_fd(i, 2);
    }
    write(2, "\n", 1);
}

void test_putstr()
{
    char *str;
    char *str1;
    char *str2;
    char *str3;
    char *str4;

    str = strdup("COUCOUcoucouYOLLOOOOO\n");
    str1 = NULL;
    str2 = strdup("");

    printf("\n\033[92m ft_putstr is ok \033[0m\n");
    ft_putstr(str);
    ft_putstr(str1);
    ft_putstr(str2);
    printf("\n");
}

void test_putstr_fd()
{
    char *str;
    char *str1;
    char *str2;

    str = strdup("COUCOUcoucouYOLLOOOOO\n");
    str1 = NULL;
    str2 = strdup("");

    printf("\n\033[92m ft_putstr_fd is ok \033[0m\n");
    ft_putstr_fd(str, 2);
    ft_putstr_fd(str1, 2);
    ft_putstr_fd(str2, 2);
    printf("\n");
}

void    test_strtoupper()
{
    char *str = strdup("acdcjnsj./.?>>AAAdcnsdocnsodcnjs>/;d?1!");
    char *str1 = strdup("acdcjnsj./.?>>AAAdcnsdocnsodcnjs>/;d?1!");
    printf("\033[92m ft_strtoupper is ok \n%s\n%s\033[0m\n", str1, ft_strtoupper(str));
}

void    test_strtolower()
{
    char *str = strdup("acdcjnsj./.?>>AAAdcnsdoSJDJBCDHBCnjs>/;d?1!");
    char *str1 = strdup("acdcjnsj./.?>>AAAdcnsdoSJDJBCDHBCnjs>/;d?1!");
    printf("\033[92m ft_strtolower is ok \n%s\n%s\033[0m\n", str1, ft_strtolower(str));
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
    test_isupper();
    test_islower();
    test_putchar();
    test_putchar_fd();
    test_putstr();
    test_putstr_fd();
    test_strtoupper();
    test_strtolower();
}
