#include "main.h"

char *get_path(char *c_path, char *f_path)
{
    char *path = getenv("PATH");
    char *token = strtok(path, ":");
    while (token != NULL)
    {
        snprintf(f_path, SIZE, "%s/%s", token, c_path);
        if (access(f_path, F_OK) == 0)
            return (f_path);
        token = strtok(NULL, ":");
    }
    printf("%s\n", path);   
    return  (c_path);
}
