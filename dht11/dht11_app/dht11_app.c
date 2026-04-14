#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = 0;
    ssize_t nret = 0;
    unsigned char data[4] = {0};
    char hum[8] = {0};
    char temp[8] = {0};

    fd = open("/dev/misc_dht11", O_RDWR);
    if (-1 == fd) {
        perror("fail to open");
        return -1;
    }

    while (1)
    {
        nret = read(fd, data, sizeof(data)); 
        if (4 == nret) 
        {
            sprintf(hum, "%d.%d", data[0], data[1]);
            sprintf(temp, "%d.%d", data[2], data[3]);
            printf("temp = %s, hum = %s\n", temp, hum);
        }
        
        sleep(2);
    }
    
    close(fd);

    return 0;
}