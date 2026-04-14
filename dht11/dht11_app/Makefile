modulename:=dht11_app

CC:=arm-linux-gnueabihf-gcc

$(modulename):$(modulename).c 
	$(CC) $^ -o $@
	cp $(modulename) ~/nfs/rootfs 

.PHONY:
clean:
	rm $(modulename)
distclean:
	rm $(modulename)
	rm ~/nfs/rootfs/$(modulename)