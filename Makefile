SRCS =  push_swap.c \
		args_cheker.c \
		is_int.c \
		push_swap_utils.c \
		stack_sort_short.c \
		stack_sort.c \
		push_swap_utils2.c \
		push_swap_utils3.c \
		stack_sort_utils.c \
		srcs/libft/ft_isalpha.c srcs/libft/ft_isdigit.c srcs/libft/ft_isalnum.c srcs/libft/ft_isascii.c srcs/libft/ft_isprint.c srcs/libft/ft_strlen.c \
		srcs/libft/ft_toupper.c srcs/libft/ft_tolower.c srcs/libft/ft_strchr.c srcs/libft/ft_strrchr.c srcs/libft/ft_strncmp.c \
		srcs/libft/ft_memcpy.c srcs/libft/ft_memmove.c srcs/libft/ft_memset.c srcs/libft/ft_memcmp.c srcs/libft/ft_memchr.c srcs/libft/ft_bzero.c \
		srcs/libft/ft_strnstr.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strlcat.c srcs/libft/ft_atoi.c srcs/libft/ft_strdup.c srcs/libft/ft_calloc.c \
		srcs/libft/ft_substr.c srcs/libft/ft_strjoin.c srcs/libft/ft_split.c srcs/libft/ft_itoa.c srcs/libft/ft_strmapi.c \
		srcs/libft/ft_putchar_fd.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putendl_fd.c \
		srcs/libft/ft_putnbr_fd.c srcs/libft/ft_strtrim.c  srcs/libft/ft_striteri.c \
		srcs/libft/ft_lstnew.c srcs/libft/ft_lstlast.c srcs/libft/ft_lstadd_front.c srcs/libft/ft_lstsize.c srcs/libft/ft_lstadd_back.c srcs/libft/ft_lstclear.c\
		srcs/libft/ft_lstdelone.c srcs/libft/ft_lstiter.c srcs/libft/ft_lstmap.c
SRCS_BONUS = bonus/args_cheker_bonus.c \
			 bonus/checker_bonus.c \
			 bonus/checker_utils_bonus.c \
			 bonus/functions_bonus.c \
			 bonus/get_next_line_bonus.c \
			 bonus/functions2_bonus.c \
			 bonus/functions3_bonus.c \
			 bonus/get_next_line_utils_bonus.c \
			 srcs/libft/ft_isalpha.c srcs/libft/ft_isdigit.c srcs/libft/ft_isalnum.c srcs/libft/ft_isascii.c srcs/libft/ft_isprint.c srcs/libft/ft_strlen.c \
			 srcs/libft/ft_toupper.c srcs/libft/ft_tolower.c srcs/libft/ft_strchr.c srcs/libft/ft_strrchr.c srcs/libft/ft_strncmp.c \
			 srcs/libft/ft_memcpy.c srcs/libft/ft_memmove.c srcs/libft/ft_memset.c srcs/libft/ft_memcmp.c srcs/libft/ft_memchr.c srcs/libft/ft_bzero.c \
			 srcs/libft/ft_strnstr.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strlcat.c srcs/libft/ft_atoi.c srcs/libft/ft_strdup.c srcs/libft/ft_calloc.c \
			 srcs/libft/ft_substr.c srcs/libft/ft_strjoin.c srcs/libft/ft_split.c srcs/libft/ft_itoa.c srcs/libft/ft_strmapi.c \
			 srcs/libft/ft_putchar_fd.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putendl_fd.c \
			 srcs/libft/ft_putnbr_fd.c srcs/libft/ft_strtrim.c  srcs/libft/ft_striteri.c \
			 srcs/libft/ft_lstnew.c srcs/libft/ft_lstlast.c srcs/libft/ft_lstadd_front.c srcs/libft/ft_lstsize.c srcs/libft/ft_lstadd_back.c srcs/libft/ft_lstclear.c\
			 srcs/libft/ft_lstdelone.c srcs/libft/ft_lstiter.c srcs/libft/ft_lstmap.c
NAME = push_swap
NAME_BONUS = checker
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=leak
RM = rm -f

all: ${NAME}

.SECONDARY: ${OBJS} ${OBJS_BONUS}

${NAME}: ${OBJS}
	${CC} $(CFLAGS) ${OBJS} -o ${NAME}

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} $(CFLAGS) ${OBJS_BONUS} -o ${NAME_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all