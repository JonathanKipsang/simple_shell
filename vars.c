#include "shell.h"
/**
* is_chain - tests if current character in buffer is a chaining delimiter
* @info: the parameter struct
* @buf: the character buffer
* @p: address of current position in buf
*
* Return: 1 if chaining delimiter, 0 otherwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;
if (buf[j] == '|' && buf[j + 1] == '|')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[j] == ';')
{
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
}
else
{
return (0);
}
*p = j;
return (1);
}
/**
* check_chain - checks if we should continue chaining based on last status
* @info: the parameter struct
* @buf: the character buffer
* @p: address of current position in buf
* @i: starting position in buf
* @len: length of buf
*
* Return: void
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;
if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
j = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
j = len;
}
}
*p = j;
}
/**
* replace_alias - replaces an alias in the tokenized string
* @info: the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;
for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
{
return (0);
}
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
{
return (0);
}
p = _strdup(p + 1);
if (!p)
{
return (0);
}
info->argv[0] = p;
}
return (1);
}
/**
* replace_vars - replaces variables in the tokenized string
* @info: the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_vars(info_t *info)
{int i = 0;
list_t *node;
for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
{
continue;
}
if (!_strcmp(info->argv[i], "$?"))
{
free(info->argv[i]);
info->argv[i] = _itoa(info->status);
if (!info->argv[i])
{
return (0);
}
}
}
return (1);
}
