#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>


int main(int argc,char *argv[]){

    char arr1[10000000],arr2[10000000];
    int size,fd;

    while(1){

	fd = open("mypipe.tmp",O_RDONLY);
	write(1,"READ: ",strlen("READ: "));
	size = read(fd,arr1,10000000);
	arr1[size] = '\0';
	sleep(2);
	write(1,arr1,size);
	close(fd);
	printf("\n");

	fd = open("mypipe.tmp",O_WRONLY);
	write(1,"WRITE: ",strlen("WRITE: "));
	fgets(arr2,10000000,stdin);
	write(fd,arr2,strlen(arr2));
	close(fd);
	printf("\n");
    
    }

    exit(EXIT_SUCCESS);
}
