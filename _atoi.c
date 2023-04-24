#include "shell.h"
/**
* interactive_mode - checks if the shell is in interactive mode
* @info: pointer to an info_t struct
* Return: 1 if interactive, otherwise return 0
*/
int interactive_mode(info_t *info)
{
int stdin_is_tty = isatty(STDIN_FILENO);
int read_fd_is_std = info->readfd <= 2;
return (stdin_is_tty && read_fd_is_std);
}
/**
* is_delimiter - determines whether a character is a delimiter
* @c: the character that needs to be checked
* @delim: delimiter string
* Return: 1 if true, if false 0
*/
int is_delimiter(char c, char *delim)
{
while (*delim != '\0')
{
if (*delim == c)
{
return (1);
}
delim++;
}
return (0);
}
/**
* is_alpha - determines whether a given character is an alphabetic character
* @c: the character that needs to be check
* Return: 1 if true, if false 0
*/
int is_alpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
return (1);
}
else
{
return (0);
}
}
/**
* string_to_int - converts a string to integer
* @s: string that needs to be converted
* Return: 0 if no numbers in string, converted number otherwise
*/
int string_to_int(char *s)
{
int i = 0;
int sign = 1;
int flag = 0;
unsigned int result = 0;
int output;
while (s[i] != '\0' && flag != 2)
{
if (s[i] == '-')
{
sign *= -1;
}
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
{
flag = 2;
}
i++;
}
if (sign == -1)
{
output = -result;
}
else
{
output = result;
}
return (output);
}

