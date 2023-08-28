CFLAGS := -w 
LIBS := -lpulse -lpulse-simple
FILES := server.c audio_interface.c socket_interface.c log.c

clean:
	rm -rf server

build:
	clang $(CFLAGS) $(FILES) -o server $(LIBS)

test:
	./server

	
