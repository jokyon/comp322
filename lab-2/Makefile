all: launch tube clean
	gcc -o launch launch.c 
	gcc -o tube tube.c 

.PHONY: all

launch: 
	gcc -o launch launch.c

tube:
	gcc -o tube tube.c 
clean:
	rm -f all launch tube