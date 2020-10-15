#include <stdlib.h>
#include <stdio.h>

int		ft_strlen_split2(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c && s[i] != ' ')
		i++;
	return (i + 1);
}

int		ft_strcount2(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0' || s[i + 1] == ' ') && s[i] != ' ')
			n = n + 1;
		i++;
	}
	return (n);
}

char	*ft_full2(char const *s, int len, char c, int i)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(tmp = malloc(len + 1)))
		return (0);
	while (j < len)
		tmp[j++] = s[k++];
	tmp[j] = '\0';
	return (tmp);
}

char	**ft_split_custom(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;
	int		len;
	int		len_arr;

	i = 0;
	k = 0;
	len_arr = ft_strcount2((char *)s, c);
	if (!(arr = malloc(sizeof(char *) * (len_arr + 1))))
		return (0);
	while (i < len_arr)
	{
        while (((char *)s)[k] == c || (((char *)s)[k]) == ' ')
			k++;
		len = ft_strlen_split2(&(((char *)s)[k]), c);
		if (!(arr[i] = malloc(len + 1)))
			return (0);
        if (k != 0)
		    arr[i] = ft_full2(&(((char *)s)[k - 1]), len, c, i);
        else
            arr[i] = ft_full2(&(((char *)s)[k]), len, c, i); 
		while ((((char *)s)[k]) != c && (((char *)s)[k]) != '\0' && (((char *)s)[k]) != ' ')
			k++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}

// int main(void)
// {
//     char *test = "echo gh$e";
//     char **res;

//     res = ft_split_custom(test, '$');
//     for (int i = 0; res[i]; i++)
//         printf("%s\n",res[i]);
//     return 0;
// }