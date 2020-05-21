all: matrix_gen matrix_add clean

.PHONY: clean

matrix_gen: matrix_gen.c
	gcc -o matrix_gen matrix_gen.c -lpthread -lrt

matrix_add: matrix_add.c
	gcc -o matrix_add matrix_add.c -lpthread -lrt

clean:
	rm -f *.o