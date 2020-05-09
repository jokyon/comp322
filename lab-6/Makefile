all: spiritd moles clean

.PHONY: clean

spiritd: spiritd.c
	gcc -o spiritd spiritd.c

moles: moles.c
	gcc -o moles moles.c

clean:
	rm -f *.o