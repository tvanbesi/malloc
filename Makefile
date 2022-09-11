SRCS			= malloc.c init.c
OBJS			= ${SRCS:.c=.o}
INC				= -Ilibft
LIB				= libft/libft.a
CC				= clang
CFLAGS_DEBUG	= -g -ggdb
CFLAGS			= -Wall -Wextra -Werror -fpic ${CFLAGS_DEBUG}
RM				= rm -f

ifndef HOSTTYPE
HOSTTYPE = $(shell uname -m)_$(shell uname -s)
endif

NAME_LIB	= libft_malloc.so
NAME		= libft_malloc_${HOSTTYPE}.so

LIBC_TOGGLE	=
ifdef USE_LIBC_MALLOC
LIBC_TOGGLE	+= -D USE_LIBC_MALLOC
SRCS = malloc.c
OBJS = ${SRCS:.c=.o}
endif

%.o :		%.c
			${CC} ${CFLAGS} ${INC} -c $< ${LIBC_TOGGLE}
all :
			cd libft && make EXCLUDE=alloc
			make ${NAME}
${NAME} :	${OBJS}
			${CC} -shared -o ${NAME} ${OBJS}
			${RM} ${NAME_LIB}
			ln -s ${NAME} ${NAME_LIB}
clean :
			${RM} ${OBJS}
fclean :	clean
			${RM} ${NAME} ${NAME_LIB}
re :		fclean all
.PHONY :
			all ${NAME} clean fclean re
