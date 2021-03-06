#include "../../headers/minishell.h"

int 	line_size(char *line)
{
	int		i;
	char 	symbol;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			break;
		if ((line[i] == '\"' || line[i] == '\'') && (i == 0 || line[i - 1] != '\\'))
			{
				symbol = line[i];
				i++;
				while (line[i + 1] != '\0')
				{
					if (line[i] == symbol && line[i - 1] != '\\')
						break;
					i++;
				}
			}
		i++;
	}
	return (i);
}

int 	arrays_size(char *line)
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
			i = i + line_size(line + i);
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
	int size;
	char **pointers;
	char *data;

	pointers = NULL;
	if (!(pointers = malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	i = 0;
	n = 0;
	while (line[i] != '\0') // line is existing?
	{
		if (line[i] != ' ')
		{
			size = line_size(line + i);
			data = strndup(line + i, size);
			i = i + size;
			pointers[n++] = data;
		}
		else
			i++;
	}
	pointers[n] = NULL;
	return (pointers);
}

char 	**ft_split_argv(char *line, t_shell *shell)
{
	char **argv;
	int n;

	n = arrays_size(line);
	argv = split_argv(line, n);
	return (argv);
}
