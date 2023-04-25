#include "shell.h"
/**
* _strncpy - copies a string
* @dest: the destination string to be copied to
* @src: the source string
* @n: the amount of characters to be copied
*
* Return: the pointer to the destination string
*/
char *_strncpy(char *dest, const char *src, size_t n)
{
char *ret = dest;
while (*src && n--)
*dest++ = *src++;
if (n)
memset(dest, 0, n);
return (ret);
}
/**
* _strncat - concatenates two strings
* @dest: the first string
* @src: the second string
* @n: the amount of bytes to be maximally used
*
* Return: the pointer to the concatenated string
*/
char *_strncat(char *dest, const char *src, size_t n)
{
char *ret = dest;
while (*dest)
dest++;
while (n-- && (*dest++ = *src++))
;
if (n == (size_t)-1)
*dest = '\0';
return (ret);
}
/**
* _strchr - locates a character in a string
* @s: the string to be parsed
* @c: the character to look for
*
* Return: a pointer to the first occurrence of the character c in the string s,
*         or NULL if the character is not found
*/
char *_strchr(const char *s, int c)
{
while (*s && *s != (char)c)
s++;
return (*s == (char)c ? (char *)s : NULL);
}

