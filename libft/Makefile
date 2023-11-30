# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = libft.h

# List of source files, objects and includes
SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)
SRC_DIR = srcs/
OBJECTS = $(addprefix $(SRC_DIR), $(OBJS))

# Executable name
NAME = libft.a

# Default rule
all: $(NAME)

$(OBJECTS): $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADER)
	rm -rf $(SRC_DIR)
	rm -f $(NAME)
	mkdir -p $(SRC_DIR)
	mv $(OBJS) $(SRC_DIR)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

# Clean up and re-create
re: fclean all	

# Clean up
clean:
	rm -rf $(SRC_DIR)

# Full clean up
fclean: clean
	rm -rf $(NAME)

# Add bonus
BONUS_SRCS = ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_OBJECTS = $(addprefix $(SRC_DIR), $(BONUS_OBJS))

bonus: $(BONUS_OBJECTS)

$(BONUS_OBJECTS):
	$(CC) $(CFLAGS) -c $(BONUS_SRCS) -I $(HEADER)
	rm -rf $(SRC_DIR)
	mkdir -p $(SRC_DIR)
	mv $(BONUS_OBJS) $(SRC_DIR)
	ar -rc $(NAME) $(BONUS_OBJECTS)
	ranlib $(NAME)

# phony are not associated with files
.PHONY: clean all re fclean bonus