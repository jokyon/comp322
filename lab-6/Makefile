all: spiritd moles clean

.PHONY: all

spiritd: spiritd.c
	gcc -o spiritd spiritd.c

moles: moles.c
	gcc -o moles moles.c

clean:
	rm -f all spiritd moles

