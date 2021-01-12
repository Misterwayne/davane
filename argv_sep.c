#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(char *str, int n)
{
	char	*str_new;
	int		i;

	i = ft_strlen(str);
	if (i > n)
		i = n; 
	if (!(str_new = malloc((sizeof(char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (str[i] && i < n)
		{
			str_new[i] = str[i];
			i++;
		}
	str_new[i] = '\0';
	return (str_new);
}

// char **increase_size(char **pointers, char *str)
// {
// 	char **new_pointers;
// 	int i;

// 	i = 0;
// 	if (pointers)
// 	{
// 		while (pointers[i])
// 			i++;
// 		printf("%d, ", i);
// 		new_pointers = malloc((sizeof(char *)) * (i + 1));
// 		i = 0;
// 		while (pointers[i])
// 		{
// 			new_pointers[i] = pointers[i];
// 			//printf("%s, ", pointers[i]);
// 			i++;
// 		}
// 		new_pointers[i] = str;
// 		new_pointers[i + 1] = NULL;
// 		free(pointers);
// 		return (new_pointers);
// 		//return (NULL);
// 	}
// 	else 
// 		{
// 			new_pointers = malloc((sizeof(char *)) * 2);
// 			new_pointers[0] = str;
// 			new_pointers[1] = NULL;
// 		}
// 	// i = 0;
// 	// while (new_pointers[i])
// 	// 	printf("%s\n", new_pointers[i++]);
// 	return (new_pointers);
// }

char	*copy_line(char *line)
{
	int		i;
	char 	*copy;

	i = 0;
	copy = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			break;
		// if (line[i] == '\"' || line[i] == '\'')
		// 	printf("symbol!!!\n");
		i++;
	}
	copy = strndup(line, i);
	return (copy); 
}

int 	find_size(char *line)
{
	int i;
	int n;
	char *data;

	i = 0;
	n = 0;
	while (line[i] != '\0') // line is existing?
	{
		if (line[i] != ' ')
		{
			data = copy_line(line + i);
			i = i + ft_strlen(data);
			free(data);
			n++;
		}
		else
			i++;
	}
	return (n);
}

char	 **split_argv(char *line, int n)
{
	int i;
	char **pointers;
	char *data;

	pointers = NULL;
	pointers = malloc(sizeof(char *) * (n + 1));
	i = 0;
	n = 0;
	while (line[i] != '\0') // line is existing?
	{
		if (line[i] != ' ')
		{
			data = copy_line(line + i);
			i = i + ft_strlen(data);
			pointers[n++] = data;
			// printf("%s(%lu)\n", data, strlen(data));
			// pointers = increase_size(pointers, data);
		}
		else
			i++;
	}
	pointers[n] = NULL;
	return (pointers);
}

int main(int argc, char **argv)
{
	char *line = "privsdsdsafsdfsadfdsfsdet  s d akak de la";
	char **pointers;
	int i = 0;
	int n;

	n = find_size(line);
	pointers = split_argv(line, n);
	while (pointers[i])
		printf("%s\n", pointers[i++]);
	return (0);
}
