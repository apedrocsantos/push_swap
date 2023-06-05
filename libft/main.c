#include <stdio.h>
#include <string.h>
#include "libft.h"

static int	checkbool(int a, int b)
{
	//printf("a -> %d, b -> %d\ ---->", a, b);
	if ((a > 0 && b > 0) || (a < 0 && b < 0) || (a == 0 && b == 0))
		return (1);
	return (0);
}

static int	check2(int a, int b)
{
	return (a == b);
	return (0);
}

int	main()
{
	int	i = 0;
	char	d;
	char *str = "aeiouea";
	char *big = "Hello there!";
	char *little = "lo";
	char str2[] = "Hello";

////////////////////////////ISALPHA////////////////////////////
	int n = 8;
	int intarray[] = {0, 11, 36, 70, 122, 253, -10, 300};

	printf("ft_isalpha\n");
	while (i < n)
	{
		if(checkbool(ft_isalpha(intarray[i]), isalpha(intarray[i])))
			printf("\tOK  ");
		else
			printf("\t--KO  ");
		i++;
	}

////////////////////////////ISDIGIT////////////////////////////
	printf("\nft_isdigit\n");
	i = 0;
	intarray[1] = 47;
	intarray[2] = 48;
	intarray[3] = 47;
	intarray[4] = 58;

	while (i < n)
	{
		if(checkbool(ft_isdigit(intarray[i]), isdigit(intarray[i])))
			printf("\tOK  ");
		else
			printf("\t--KO  ");
		i++;
	}

////////////////////////////ISALNUM////////////////////////////
	printf("\nft_isalnum\n");
	i = 0;
	intarray[1] = 47;
	intarray[2] = 48;
	intarray[3] = 70;
	intarray[4] = 91;

	while (i < n)
	{
		if(checkbool(ft_isalnum(intarray[i]), isalnum(intarray[i])))
			printf("\tOK  ");
		else
			printf("\t--KO  ");
		i++;
	}

////////////////////////////ISASCII////////////////////////////
	printf("\nft_isascii\n");
	i = 0;
	intarray[1] = -1;
	intarray[2] = 0;
	intarray[3] = 127;
	intarray[4] = 128;

	while (i < n)
	{
		if(checkbool(ft_isascii(intarray[i]), isascii(intarray[i])))
			printf("\tOK  ");
		else
			printf("\t--KO  ");
		i++;
	}
////////////////////////////ISPRINT////////////////////////////
	printf("\nft_isprint\n");
	i = 0;
	intarray[1] = 31;
	intarray[2] = 32;
	intarray[3] = 126;
	intarray[4] = 127;

	while (i < n)
	{
		if(checkbool(ft_isprint(intarray[i]), isprint(intarray[i])))
			printf("\tOK  ");
		else
			printf("\t--KO  ");
		i++;
	}

////////////////////////////ISPRINT////////////////////////////
	printf("\nft_strlen\n");
	char *chararr[] = {"aiai", "yuiyu", "\0", "", "\200", "00x00000", "  ", ""};
	i = 0;
	
	while (i < n)
	{
		if(check2(ft_strlen(chararr[i]), strlen(chararr[i])))
			printf("\tOK  ");
		else
			printf("\t--KO  ");
		i++;
	}
////////////////////////////MEMSET////////////////////////////
	printf("\nft_memset\n");
	char s1[10] = "aaa";
	char s2[10] = "aaa";
	int	i1[] = {1, 2, 3, 4};
	int	i2[] = {1, 2, 3, 4};
	char *s3 = ft_memset(s1, 88, 5*sizeof(char));
	char *s4 = memset(s2, 88, 5*sizeof(char));
	char *s5 = ft_memset(i1, 88, 5*sizeof(char));
	char *s6 = memset(i2, 88, 5*sizeof(char));


	if (!memcmp(s3, s4, 5))
		printf("\tOK  ");
	else
		printf("\t--KO  ");
	if (!memcmp(s5, s5, 5))
		printf("\tOK  ");
	else
		printf("\t--KO  ");

////////////////////////////BZERO////////////////////////////
	printf("\nft_bzero\n");
	ft_bzero(s3, 5*sizeof(char));
	bzero(s4, 5*sizeof(char));
	ft_bzero(s5, 5*sizeof(char));
	bzero(s6, 5*sizeof(char));


	if (!memcmp(s3, s4, 5))
		printf("\tOK  ");
	else
		printf("\t--KO  ");
	if (!memcmp(s5, s5, 5))
		printf("\tOK  ");
	else
		printf("\t--KO  ");

////////////////////////MEMCPY///////////////////////////
	printf("\nmemcpy\n");
	ft_memcpy(s1 + 2, s1, 3);
	memcpy(s2 + 2, s1, 3);

	if (!memcmp(s1, s5, 5))
		printf("\tOK  ");
	else
		printf("\t--KO  ");

/*
	printf("ft_isdigit: %d\t", ft_isdigit(d));
	printf("isdigit: %d\n", isdigit(d));
	
	printf("ft_isalnum: %d\t", ft_isalnum(d));
	printf("isalnum: %d\n", isalnum(d));

	printf("ft_isascii: %d\t", ft_isascii(323));
	printf("isascii: %d\n", isascii(323));

	printf("ft_isprint: %d\t", ft_isprint(39));
	printf("isprint: %d\n", isprint(39));

	printf("ft_strlen %lu\t", ft_strlen(str));
	printf("strlen %lu\n", strlen(str));

	ft_memset(str2, 'a', 5*sizeof(char));
	i = 0;
	while (i < 5)
	{
		printf("%p\t", &str[i]);
		printf("%c\n", str[i++]);
	}

	char *src = "ola";
	char dest[20];
	int	size = 3;

	printf("ft_strlcpy: %d\t", ft_strlcpy(dest, src, size));
	printf("%s\tshould be '3\tol'\n", dest);

	printf("ft_toupper: %c\t", ft_toupper(c));
	printf("toupper: %c\n", toupper(c));
	
	printf("ft_tolower: %c\t", ft_tolower('d'));
	printf("tolower: %c\n", tolower('d'));

	
	printf("ft_strchr %s\t", ft_strchr(str, 'e'));
	printf("strchr %s\n", strchr(str, 'e'));

	printf("ft_strrchr %s\t", ft_strrchr(str, 'e'));
	printf("strrchr %s\n", strrchr(str, 'e'));

	printf("ft_strncmp %d\t", ft_strncmp(big, little, 2));
	printf("strncmp %d\n", ft_strncmp(big, little, 2));
	
	printf("ft_strnstr: %s\t 'lo there!'\n", ft_strnstr(big, little, 9));

	 str = "       -1234arg123";

	printf("ft_atoi: %d\t", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));*/
	}
