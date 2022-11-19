#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int arg1, char ** argv)
{
    int fd, ch;
    for(int i=1; i<arg1; i++){
        fd = open(argv[i], O_RDONLY);
        if(fd < 0)
        {
            perror(argv[i]);
            continue;
        }
        while(read(fd, &ch,1)== 1)
        {
            write(STDOUT_FILENO, &ch,1);
        }
        close(fd);
    }
}