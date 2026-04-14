#目标文件
OBJ=bh1750_app

#依赖的文件
OBJS+=main.c

#工具链
CC=arm-linux-gnueabihf-gcc 

$(OBJ):$(OBJS)
	$(CC) $^ -o $@
	cp $(OBJ) ~/nfs/rootfs 
.PHONY:
distclean:
	rm $(OBJ)