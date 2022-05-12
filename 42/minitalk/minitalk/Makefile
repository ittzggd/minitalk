$(NAME1) : client

$(NAME2) : server

all : client server

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

client : client.c
	$(CC) $(CFLAGS) -o $@ $<

server : server.c
	$(CC) $(CFLAGS) -o $@ $<
