CC=gcc
CFLAGS=-g -Wall 
GST_PKG=`pkg-config --cflags --libs gstreamer-1.0`
OBJS=main.o
TARGET=main

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(GST_FLAGS)

all: $(TARGET)

clean:
	rm main.o
