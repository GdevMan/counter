CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = counter

SRC = src/main.c src/game.c src/achivements.c src/sls.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)/usr/bin/$(TARGET)

uninstall:
	rm -f $(DESTDIR)/usr/bin/$(TARGET)

.PHONY: all clean install uninstall
