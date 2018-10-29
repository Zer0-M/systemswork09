#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "randgen.h"
int randnum(){
    int fd=open("/dev/random",O_RDONLY);
    int randno[1];
    int bytesread=read(fd,randno,sizeof(int));
    if(bytesread<0){
        printf("%s\n",strerror(errno));
    }

    close(fd);
    return randno[0];
}
int main(){
    int randnums[10];
    for(int i=0;i<10;i++){
        randnums[i]=randnum();
        printf("random number %d = %d\n",i,randnums[i]);
    }
    
    printf("\nWriting numbers to the randnums file...\n\n");
    int wfd=open("./randnums",O_WRONLY|O_CREAT);
    int bytesread=write(wfd,randnums,sizeof(randnums));
    if(bytesread<0){
        printf("%s\n",strerror(errno));
    }
    int readnums[10];
    close(wfd);
    
    printf("Read numbers from randnums file:\n");
    int rfd=open("./randnums",O_RDONLY);
    bytesread=read(rfd,readnums,sizeof(readnums));
    if(bytesread<0){
        printf("%s\n",strerror(errno));
    }
    for(int i=0;i<10;i++){
        printf("random numbers read %d = %d\n",i,readnums[i]);
    }
    close(rfd);
    
    return 0;

}
