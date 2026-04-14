#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = 0;
    short data = 0;

    fd = open("/dev/misc_bh1750", O_RDWR);
    if (-1 == fd)
    {
        perror("fail to open");
        return -1;
    }

    while (1)
    {
        read(fd, &data, sizeof(data));
        printf("light = %.2lf\n", data/1.2);
        sleep(1);
    }

    close(fd);

    return 0;
}