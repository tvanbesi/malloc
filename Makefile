SRCS		= malloc.c
OBJS		= ${SRCS:.c=.o}
INC			= -Ilibft
LIB			= libft/libft.a
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

ifndef HOSTTYPE
HOSTTYPE = $(shell uname -m)_$(shell uname -s)
endif

NAME_LIB	= libft_malloc.so
NAME		= libft_malloc_${HOSTTYPE}.so

%.o :		%.c
			${CC} ${CFLAGS} ${INC} -c $<
all :
			cd libft && make EXCLUDE=alloc
			make ${NAME}
${NAME} :	${OBJS}
			ar rc ${NAME} ${OBJS} ${LIB}
			ln -s ${NAME} ${NAME_LIB}
clean :
			${RM} ${OBJS}
fclean :	clean
			${RM} ${NAME} ${NAME_LIB}
re :		fclean all
.PHONY :
			all ${NAME} clean fclean re
