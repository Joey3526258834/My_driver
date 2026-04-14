#模块名
module_name=bh1750_drv

#将文件加入内核模块中
obj-m+=$(module_name).o

#内核路径
kerdir=/home/linux/IMX6ULL/kernel/linux-imx-rel_imx_4.1.15_2.1.0_ga_alientek

#驱动模块代码路径
curdir=$(shell pwd)

all:
	make -C $(kerdir) modules M=$(curdir)
	cp $(module_name).ko ~/nfs/rootfs

.PHONY:
clean:
	rm $(module_name).ko 
distclean:
	rm -rf *.o *.cmd *.mod.* *.ko .tmp_versions *.order *.symvers .*.cmd