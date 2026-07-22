# Nom de l'exécutable final
TARGET = annuaire_federation_sportive

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

# Liste des fichiers
SRCS = main.c club.c joueur.c util.c competition.c
OBJS = $(SRCS:.c=.o)
HEADERS = club.h joueur.h util.h competition.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re