### VARIABLES

NAME	= exe

### CONTENT

SRC	= $(wildcard src/main.c *.c)
OBJ	= $(SRC:.c =.o)

### COMPILATION COMMANDS

CC	= gcc
CFLAGS	= -W -Wall -Wpedantic -pedantic -Wextra -Iincludes
LDLIBS	= 

### OTHER COMMANDS

RM	= rm -f
ECHO	= echo -e

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDLIBS)
	@$(ECHO) Compiled

clean : 
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*#
	@$(ECHO) Directory cleaned

fclean : clean
	@$(RM)
	@$(ECHO) Remove executable

