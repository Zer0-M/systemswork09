#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(){
    int fd=open("/dev/random",O_RDONLY);
    int * randnum;
    int bytesRead=read(fd,randnum,4);
    printf("%s\n",strerror(errno));
}