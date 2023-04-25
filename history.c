#include "shell.h"
/**
* get_history_file - gets the history file
* @info: parameter struct
*
* Return: allocated string containg history file
*/
char *get_history_file(info_t *info)
{
char *buf = NULL;
char *dir = _getenv(info, "HOME=");
if (!dir)
{
return (NULL);
}
buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
{
free(dir);
return (NULL);
}
buf[0] = 0;
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
free(dir);
return (buf);
}
/**
* write_history - creates a file, or appends to an existing file
* @info: the parameter struct
*
* Return: 1 on success, else -1
*/
int write_history(info_t *info)
{
int result = -1;
char *filename = NULL;
list_t *node = NULL;
ssize_t fd;
filename = get_history_file(info);
if (!filename)
{
return (-1);
}
fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
{
return (-1);
}
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(BUF_FLUSH, fd);
if (close(fd) != -1)
{
result = 1;
}
return (result);
}
/**
* read_history - reads history from file
* @info: the parameter struct
*
* Return: histcount on success, 0 otherwise
*/
int read_history(info_t *info)
{
int i = 0, last = 0, linecount = 0, histcount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = NULL;
list_t *node = NULL;
filename = get_history_file(info);
if (!filename)
{
return (0);
}
fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
{
return (0);
}
if (!fstat(fd, &st))
{
fsize = st.st_size;
}
if (fsize < 2)
{
close(fd);
return (0);
}
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
{
close(fd);
return (0);
}
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
{
free(buf);
close(fd);
return (0);
}
close(fd);
for (i = 0; i < fsize; i++)
{
if (buf[i] == '\n')
{
buf[i] = 0;
build_history_list(info, buf + last, linecount++);
last = i + 1;
}
}
if (last != i)
{
build_history_list(info, buf + last, linecount++);
}
free(buf);
histcount = linecount;
while (histcount-- >= HIST

