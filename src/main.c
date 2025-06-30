
// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     int i;
//     for (i = 0; i <= 100; i++) {
//         printf("progress:[%-50s] %d%%\r", ">", i);
//         fflush(stdout);
//         usleep(30 * 1000);
//     }
//     printf("\n");
//     fflush(stdout);
//     return 0;
// }

#define _GNU_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHARED_SIZE 1024

int main() {
    char *shared_memory = mmap(NULL, SHARED_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // child process
        printf("Child process ID: %d\n", getpid());
        strcpy(shared_memory, "Hello from child process!");
        printf("Child process write: %s\n", shared_memory);
    } else {       // parent process
        sleep(1);  // make sure child process has finished
        printf("Parent process ID: %d\n", getpid());
        printf("Parent process read: %s\n", shared_memory);
    }

    munmap(shared_memory, SHARED_SIZE);
    return 0;
}

// #include <stdint.h>
// #include <stdio.h>
// #include <string.h>

// typedef struct {
//     int a;
//     char b[10];
// } A;

// int main(int argc, char *argv[]) {
//     uint8_t buf[4096];
//     memset(buf, 0, sizeof(buf));

//     A *aobj = (A *)buf;

//     aobj->a = 100;
//     strncpy(aobj->b, "test", sizeof(aobj->b));

//     int *data = (int *)(buf + sizeof(A));
//     *data = 12345;

//     A *obj = (A *)(buf + sizeof(A));
//     printf("%d\n", obj->a);
//     A *aobja = (A *)buf;
//     printf("%d\n", aobja->a);

//     return 0;
// }

// 一条记录一个record
// 一个page 16kb，用来存放record，多个page之间进行对齐，一个record可能在一个page中放不下，那么需要存放在两个相邻的page中
