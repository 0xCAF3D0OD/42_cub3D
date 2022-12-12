NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

INCL	= -I . -I./ft_printf

SRCS	+= $(addprefix char/,	\
		   ft_isalnum.c			\
		   ft_isalpha.c			\
		   ft_isascii.c			\
		   ft_isdigit.c			\
		   ft_isprint.c			\
		   ft_tolower.c			\
		   ft_toupper.c)

SRCS	+= $(addprefix str/,	\
		  ft_strlen.c			\
		  ft_strtrim.c			\
		  ft_strlcat.c			\
		  ft_strchr.c			\
		  ft_strrchr.c			\
		  ft_strnstr.c			\
		  ft_atoi.c				\
		  ft_strncmp.c			\
		  ft_strdup.c			\
		  ft_strlcpy.c			\
		  ft_substr.c			\
		  ft_strjoin.c			\
		  ft_itoa.c				\
		  ft_strmapi.c			\
		  ft_striteri.c			\
		  ft_split.c)

SRCS	+= $(addprefix put/,	\
		   ft_putchar_fd.c		\
		   ft_putstr_fd.c		\
		   ft_putnbr_fd.c		\
		   ft_putendl_fd.c)

SRCS	+= $(addprefix list/,	\
		   ft_lstnew.c			\
		  ft_lstadd_front.c		\
		  ft_lstsize.c			\
		  ft_lstlast.c			\
		  ft_lstadd_back.c		\
		  ft_lstiter.c			\
		  ft_lstdelone.c		\
		  ft_lstclear.c			\
		  ft_lstmap.c)

SRCS	+= $(addprefix mem/,	\
		   ft_bzero.c			\
		   ft_calloc.c			\
		   ft_memchr.c			\
		   ft_memcpy.c			\
		   ft_memmove.c			\
		   ft_memcmp.c			\
		   ft_memset.c)

SRCS	+= $(addprefix get_next_line/,	\
		   get_next_line.c)

SRCS	+= $(addprefix ft_printf/,	\
		   ft_printf.c				\
		   deal_with_nbr.c			\
		   deal_with_strings.c		\
		   itoas.c					\
		   itoas2.c					\
		   ft_uitoa.c				\
		   is_functions.c			\
		   parsing.c				\
		   print.c					\
		   print2.c)

OBJS	= ${SRCS:.c=.o}

CC		= gcc -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	${OBJS}
	@printf "\nLibft Objects done\n"
	@ar -rcs $@ $^
	@printf "Libft done :]\n"

.c.o:
	@${CC} ${INCL} -c $< -o ${<:.c=.o}
	@printf "Libft object : %-33.33s\r" $<

clean:
	@rm -f ${OBJS}
	@printf "libft objects deleted\n"

fclean:	clean
	@rm -f ${NAME}
	@printf "libft.a deleted\n"

re:	fclean all

.PHONY:		all clean fclean re 
