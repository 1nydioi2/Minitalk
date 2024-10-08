SERVER_NAME = server

CLIENT_NAME = client

SERVER_SOURCES = server_main.c \
				 server_utils.c

CLIENT_SOURCES = client_main.c

SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

COMPILER = cc

COMPILATION_FLAGS = -Wall -Wextra -Werror

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJECTS)
	$(COMPILER) $(COMPILATION_FLAGS) -o $(SERVER_NAME) $(SERVER_OBJECTS)

$(CLIENT_NAME): $(CLIENT_OBJECTS)
	$(COMPILER) $(COMPILATION_FLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJECTS)

%.o: %.c
	$(COMPILER) $(COMPILATION_FLAGS) -o $@ -c $<

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

clean:
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS)

re: fclean all

.PHONY: fclean all clean re
