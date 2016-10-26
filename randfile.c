#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>


void populateArray(int *array) {
    int fd = open("/dev/random", O_RDWR);
    read(fd, array, 40);
    write(fd, array, 40);
}

int main() {
    srand(time(NULL));
    umask(0);
    printf("Generating random numbers:\n");
    int arr[10];
    populateArray(arr);
    int i;
    for(i = 0; i < 10; i++) {
        printf("\t\trandom %d: %d\n", i, arr[i]);
    }
    printf("\nWriting numbers to file...\n");
    int fd = open("randfile", O_CREAT | O_RDWR, 0644);
    write(fd, arr, 10 * 4);
    printf("\nReading numbers from file...\n");
    int readArr[10];
    read(fd, readArr, 10 * 4);
    printf("\nVerification that written values were the same:\n");
    for(i = 0; i < 10; i++) {
        printf("\t\trandom %d: %d\n", i, arr[i]);
    }
}
