#include "main.h"
#include "additional.h"
#include "my_ls.h"

int main(int ac, char **av) //main function takes the arguments and parses them to either search term or arg struct
{
    char *searchTerm = ".";
    arg_t* args = (arg_t *)malloc(sizeof(arg_t));
    args->a = false;
    args->b = false;
    for(int j = 0; j < ac; j++)
    {
        if(my_strcmp(av[j], "-a") == 0)
            args->a = true;
        if(my_strcmp(av[j], "-t") == 0)
            args->b = true;
        if((my_strcmp(av[j], "-t") != 0) && (my_strcmp(av[j], "-a") != 0) && (my_strcmp(av[j], "./my_ls") != 0))
            searchTerm = av[j];
    }
    //printf("searchterm = %s, ac = %i \n", searchTerm, ac);
    dirFunction(searchTerm, args);
    return 0;
}