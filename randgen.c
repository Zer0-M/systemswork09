#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(){
    int fd=open("/dev/random",O_RDONLY);
    int randnums[10];
    int bytesread=read(fd,randnums,sizeof(randnums));
    if(bytesread<0){
        printf("%s\n",strerror(errno));
    }
    for(int i=0;i<10;i++){
        printf("random number %d = %d\n",i,randnums[i]);
    }
    close(fd);

    printf("\nWriting numbers to the randnums file...\n\n");
    int wfd=open("./randnums",O_WRONLY|O_CREAT);
    bytesread=write(wfd,randnums,sizeof(randnums));
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