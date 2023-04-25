#include "shell.h"
/**
***str_split - splits a string into words using a delimiter
*@str: the input string
*@delim: the delimeter string
*Return: a pointer to an array of strings, or NULL on failure
*/
char **str_split(char *str, char *delim)
{
int i, j, k, m, num_words = 0;
char **words;
if (str == NULL || str[0] == '\0')
return (NULL);
if (!delim)
delim = " ";
for (i = 0; str[i] != '\0'; i++)
{
if (!is_delim(str[i], delim) && (is_delim(str[i + 1], delim) || !str[i + 1]))
num_words++;
}
if (num_words == 0)
return (NULL);
words = malloc((1 + num_words) *sizeof(char *));
if (!words)
return (NULL);
for (i = 0, j = 0; j < num_words; j++)
{
while (is_delim(str[i], delim))
i++;
k = 0;
while (!is_delim(str[i + k], delim) && str[i + k])
k++;
words[j] = malloc((k + 1) * sizeof(char));
if (!words[j])
{
for (k = 0; k < j; k++)
free(words[k]);
free(words);
return (NULL);
}
for (m = 0; m < k; m++)
words[j][m] = str[i++];
words[j][m] = '\0';
}
words[j] = NULL;
return (words);
}

