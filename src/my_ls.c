#include "main.h"
#include "additional.h"
#include "my_ls.h"

void freeList(node* head)
{
    node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        //free(temp->name);
        free(temp);
    }
}

int dirFunction(char* searchTerm, arg_t* args) //directory function, opens and reads directory, stats the information required.
{
    DIR *folder;
    struct dirent *entry;
    struct stat filestat;
    node *head = (node *)malloc(sizeof(node));
    head->name = NULL;
    //head->time = NULL;
    head->next = NULL;
    folder = opendir(searchTerm);
    if(folder == NULL)
    {
        printf("Unable to read directory\n");
        return(1);
    }
    while( (entry=readdir(folder)) )
    {   
        char test[50];
        strcpy(test, searchTerm);
        strcat(test, "/");
        lstat(strcat(test, entry->d_name), &filestat);
        append(head, entry->d_name, filestat.st_mtime);
    }  
    printerFunction(head, args);
    closedir(folder);
    freeList(head);
    return 0;
}

