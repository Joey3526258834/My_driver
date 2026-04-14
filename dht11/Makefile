modulename:=dht11

all:
	make -C $(modulename)_app
	make -C $(modulename)_drv

.PHONY:
clean:
	make -C $(modulename)_app clean
	make -C $(modulename)_drv clean
distclean:
	make -C $(modulename)_app distclean
	make -C $(modulename)_drv distclean