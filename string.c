#include "shell.h"
/**
*str_len - returns the length of a string
*@str: the string whose length to check
*
*Return: integer length of string
*/
int str_len(char *str)
{
int i = 0;
if (!str)
return (0);
while (*str++)
i++;
return (i);
}
/**
*str_cmp - performs lexicogarphic comparison of two strings.
*@str1: the first string
*@str2: the second string
*
*Return: negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
*/
int str_cmp(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}
/**
*starts_with - checks if needle starts with haystack
*@haystack: string to search
*@needle: the substring to find
*
*Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
{
if (*needle++ != *haystack++)
return (NULL);
}
return ((char *)haystack);
}
/**
*str_cat - concatenates two strings
*@dest: the destination buffer
*@src: the source buffer
*
*Return: pointer to destination buffer
*/
char *str_cat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}

