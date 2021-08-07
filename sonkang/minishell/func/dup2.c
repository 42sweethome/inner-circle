#include <unistd.h> //dup, STDOUT_FILENO, close
#include <stdio.h> //fprint, stderr, stdout, perror
#include <fcntl.h> //open, O_WDONLY

int main(int argc,char **argv)
{
    int fd = 0;
    if(argc != 2)
    {
        fprintf(stderr,"usage: %s [file name]\n",argv[0]);        
		return 1;
    }
    fd= open(argv[1],O_WRONLY);
    if(fd == -1)
    {
      perror("failed open ");      
	  return 1;
    }
    if(dup2(fd,STDOUT_FILENO) == -1)
    {
      perror("failed dup2");      
	  return 1;
    }
    printf("hello world\n");
    close(fd);
    return 0;
}

