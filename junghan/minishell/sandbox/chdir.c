/**********************************************************************
* ex_chdir.c                                                          *
* exmple source – change current working directory                    *
**********************************************************************/
 
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <path name>\n", argv[0]);
        return 1;
    }
    char name[1024];
    printf("Before Current Directory:%s\n",getcwd(name, 1024));
    if(chdir(argv[1])==-1)
    {
        printf("failed, change directory\n");
    }
    else
    {
        printf("After Current Directory:%s\n",getcwd(name, 1024));
    }
 
    return 0;
}
