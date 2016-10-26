#include <stdio.h>
#include <stdlib.h>
#include <fnctl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

int random(int fd) {
    int random;
    read(fd, &random, 4);
    return random;
}

void populateArray(int *array) {
    int fd = open("/dev/random", O_RDONLY);
    int i;
    for(i = 0; i < 10; i++) {
        array[i] = random(fd);
    }
    close(fd);
}
