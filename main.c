#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for (i = 0; i <= 100; i++) {
        printf("progress:[%-50s] %d%%\r", ">", i);
        fflush(stdout);
        usleep(30 * 1000);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}
