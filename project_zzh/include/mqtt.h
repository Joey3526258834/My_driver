#ifndef HEAD_H
#define HEAD_H


#include </home/linux/nfs/rootfs/mqtt/paho.mqtt.c-master/src/MQTTAsync.h>
#include </home/linux/nfs/rootfs/mqtt/paho.mqtt.c-master/src/MQTTClient.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <string.h>
//#define OLD_ADDRESS     "tcp://218.201.45.7:1883"
#define NEW_ADDRESS     "tcp://183.230.40.96:1883"
#define DEV_NAME  "car_devce"		// "first_device"
#define CLIENTID DEV_NAME
#define PRODUCT_ID "4eW0yA1kF5"//"3XoV8495r6"
#define PASSWD "version=2018-10-31&res=products%2F4eW0yA1kF5%2Fdevices%2Fcar_devce&et=5937255523&method=md5&sign=elgUT%2BR6FkvtimQcQEfqFg%3D%3D"
					 //"version=2018-10-31&res=products%2F3XoV8495r6%2Fdevices%2Ffirst_device&et=1837255523&method=sha1&sign=dtVQufcgwCrn5zmdmWLXFEtJAQY%3D";
#define QOS         0
#define TIMEOUT     10000L
//#define __cplusplus

extern void mqtt_deinit();
extern int mqtt_send(char * key, float value);
extern int mqtt_init();
#endif // HEAD_H
