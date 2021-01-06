#################
##  VARIABLES  ##
#################

#	Sources

SRCS = $(SRCSDIR)/main.c $(SRCSDIR)/init.c $(SRCSDIR)/exit.c $(SRCSDIR)/free.c $(SRCSDIR)/display.c $(SRCSDIR)/utils.c \
		$(SRCSDIR)/pwd.c $(SRCSDIR)/env.c $(SRCSDIR)/comma.c $(SRCSDIR)/quotes.c $(SRCSDIR)/parsing.c
SRCSDIR = ./srcs

#	Objects

OBJS = $(SRCS:.c=.o)

#	Headers

HEADER = minishell.h
HEADERDIR = ./srcs

#	Libraries

LIBFTDIR = ./libs/libft
LIBFT = libft.a
GNLDIR = ./libs/GNL
GNL = gnl.a

#	Name

NAME = minishell

#	Compiler

CC = gcc

#	Flags

CFLAGS = -Wall -Werror -Wextra 


###############
##  TARGETS  ##
###############

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	@$(CC) -fsanitize=address -I$(HEADERDIR)/ $(OBJS) $(LIBFTDIR)/$(LIBFT) $(GNLDIR)/$(GNL) -o $(NAME)
	@echo "minishell compiled succesfully"
	
$(SRCSDIR)/%.o: %.c $(SRCSDIR)/$(HEADER)
	@$(CC) $(CFLAGS) -c -o $@ $< 

clean: 
	/bin/rm -f $(OBJS) $(LIBFTDIR)/*.o $(GNLDIR)/*.o 

fclean: clean
	/bin/rm -f $(NAME) $(LIBFTDIR)/$(LIBFT) $(GNLDIR)/$(GNL)

re: fclean all

$(LIBFT):	
			@cd ${LIBFTDIR} && make
			@echo "libft compiled succesfully"

$(GNL):	
			@cd ${GNLDIR} && make
			@echo "get_next_line compiled succesfully"

.PHONY: all clean fclean re