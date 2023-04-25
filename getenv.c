#include "shell.h"
/**
*get_environ_copy - returns a copy of the environment variables
*@info: pointer to info_t structure containing environment variables
*Return: copy of environment variables
*/
char **get_environ_copy(info_t *info)
{
if (!info->env_copy || info->env_changed)
{
info->env_copy = list_to_strings(info->env_list);
info->env_changed = 0;
}
return (info->env_copy);
}
/**
* _unset_env - remove an environment variable
* @info: pointer to info_t structure containing environment variables
* @var: the string environment variable to remove
* Return: 1 on success, 0 on failure
*/
int _unset_env(info_t *info, char *var)
{
list_t *node = info->env_list;
size_t i = 0;
char *p;
if (!node || !var)
return (0);
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env_list), i);
i = 0;
node = info->env_list;
continue;
}
node = node->next;
i++;
}
return (info->env_changed);
}
/**
* _set_env - set a new environment variable or modify an existing one
* @info: pointer to info_t structure containing environment variables
* @var: the string environment variable to set/modify
* @value: the string value for the environment variable
* Return: 1 on success, 0 on failure
*/
int _set_env(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;
if (!var || !value)
return (0);
buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env_list;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env_list), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}

