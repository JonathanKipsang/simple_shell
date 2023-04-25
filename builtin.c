#include "shell.h"
/*
* exit_function - exits the program with a given exit status
* @info: pointer to a struct containing potential arguments
*
* Return: returns -2 if info.argv[0] == "exit"
*/
int exit_function(info_t *info)
{
int exit_status;
if (info->argv[1])
{
exit_status = _erratoi(info->argv[1]);
if (exit_status == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
/*
* cd_function - changes the current directory of the process
* @info: pointer to a struct containing potential arguments
*
* Return: Always returns 0
*/
int cd_function(info_t *info)
{
char *current_dir, *new_dir, buffer[1024];
int chdir_return;
current_dir = getcwd(buffer, 1024);
if (!current_dir)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
new_dir = _getenv(info, "HOME=");
if (!new_dir)
chdir_return = /* TODO: what should this be? */
chdir((new_dir = _getenv(info, "PWD=")) ? new_dir : "/");
else
chdir_return = chdir(new_dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(current_dir);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_return = /* TODO: what should this be? */
chdir((new_dir = _getenv(info, "OLDPWD=")) ? new_dir : "/");
}
else
chdir_return = chdir(info->argv[1]);
if (chdir_return == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/*
* help_function - prints help information
* @info: pointer to a struct containing potential arguments
*
* Return: Always returns 0
*/
int help_function(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
