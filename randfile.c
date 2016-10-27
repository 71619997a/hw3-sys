#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h> 

int randInt() {
    int fd = open("/dev/random", O_RDONLY);
	int ret;
	read(fd, &ret, 4);
	return ret;
}


int main() {
    srand(time(NULL));
    umask(0);


	//GENERATING NUMS
    printf("Generating random numbers:\n");
    int arr[10];
	int i;
    for(i = 0; i < 10; i++) {
        arr[i] = randInt();
		printf("\t\trandom %d: %d\n", i, arr[i]);
    }

	
	//WRITING NUMS
    printf("\nWriting numbers to file...\n");
	int fileDest = open("randNums", O_CREAT | O_RDWR, 0666);
	int success = write(fileDest, &arr, 10 * 4);
	if (success==-1) printf("%s\n", strerror(errno));
	close(fileDest);

	

	//READING NUMS
    printf("\nReading numbers from file...\n");
    int fd = open("randNums", O_RDONLY);
    int readArr[10];
    read(fd, readArr, 10 * 4);

	//VERIFYING NUMS
	printf("\nVerification that written values were the same:\n");
    for(i = 0; i < 10; i++) {
        printf("\t\trandom %d: %d", i, readArr[i]);
		if(readArr[i] == arr[i]) printf("\tSAME\n");
		else printf("\tDIFFERENT\n");
	}


    return 0;
}
