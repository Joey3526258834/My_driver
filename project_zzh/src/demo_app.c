
#include "../include/demo_app.h"
#if 0
int get_data_adxl345(Que_Data_t *pdata)
{
    if (pdata == NULL)
    {
        printf("错误：pdata 是空指针\n");
        return -1;
    }
    int fd = 0;
    int data[3] = {0};
    char buf[100] = {0};

    fd = open("/dev/misc_adxl345", O_RDWR);
    if (-1 == fd)
    {
        perror("fail to open");
        return -1;
    }
    read(fd, data, sizeof(data));
    pdata->x = (float)data[0];
    pdata->y = (float)data[1];
    pdata->z = (float)data[2];

    close(fd);

    return 0;
}
#endif

#if 0
int get_data_lm75(Que_Data_t *pdata)
{
    if (pdata == NULL)
    {
        printf("错误：pdata 是空指针\n");
        return -1;
    }
    int fd = 0;
    unsigned char data[2] = {0};
    char buf[100] = {0};

    fd = open("/dev/misc_lm75", O_RDWR);
    if (-1 == fd)
    {
        perror("fail to open");
        return -1;
    }
    // printf("2open ok\n");
    memset(buf, 0, sizeof(buf));
    read(fd, data, sizeof(data));
    pdata->temp = ((((data[0] << 8) | data[1]) >> 7) * 0.5);

    close(fd);

    return 0;
}
#endif

int get_data_dht11(Que_Data_t *pdata)
{
    if (pdata == NULL)
    {
        printf("错误：pdata 是空指针\n");
        return -1;
    }
    int fd;
    char buf[5] = {0};
    char buff[100] = {0};
    int ret;

    fd = open("/dev/misc_dht11", O_RDWR);
    if (fd < 0)
    {
        perror("open /dev/misc_dht11 failed");
        return -1;
    }

    sleep(2);
    ret = read(fd, buf, sizeof(buf));
    if (ret == 4)
    {
        sprintf(buff, "%d.%d \n", buf[0], buf[1]);
        pdata->hum = atof(buff);
        sprintf(buff, "%d.%d \n", buf[2], buf[3]);
        pdata->temp = atof(buff);
    }

    close(fd);
    return 0;
}

int get_data_bh1750(Que_Data_t *pdata)
{
    if (pdata == NULL)
    {
        printf("错误：pdata 是空指针\n");
        return -1;
    }
    int fd = 0;
    short data = 0;

    fd = open("/dev/misc_bh1750", O_RDWR);
    if (-1 == fd)
    {
        perror("fail to open bh1750");
        return -1;
    }

    read(fd, &data, sizeof(data));
    pdata->light = (data / 1.2);

    close(fd);

    return 0;
}