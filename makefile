CFLAGS := -w 
LIBS := -lpulse -lpulse-simple
FILES := server.c audio_interface.c socket_interface.c log.c

clean:
	rm ./server

build:
	gcc $(CFLAGS) $(FILES) -o server $(LIBS)

test:
	./server

	
