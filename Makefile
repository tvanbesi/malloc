SDIR			= src
ODIR			= obj
_SRCS			=	malloc.c show_alloc_mem.c \
					memory_bucket.c memory_pointer.c \
					get_available_pointer.c \
					init.c utils.c
_OBJS			= ${_SRCS:.c=.o}
SRCS			= ${_SRCS:%=${SDIR}/%}
OBJS			= ${_OBJS:%=${ODIR}/%}
INC				= -Ilibft -Iinc
LIB				= libft/libft.a
CC				= clang
CFLAGS			= -Wall -Wextra -Werror -fpic -g -ggdb
RM				= rm -f

ifndef HOSTTYPE
HOSTTYPE = $(shell uname -m)_$(shell uname -s)
endif

NAME_LIB	= libft_malloc.so
NAME_BLANK	= libblank.so
NAME		= libft_malloc_${HOSTTYPE}.so

${ODIR}/%.o :	${SDIR}/%.c
				${CC} ${CFLAGS} ${INC} -c $< -o $@
all :
				cd libft && make EXCLUDE=alloc
				make ${NAME}
${NAME} :		${NAME_BLANK} ${OBJS}
				${CC} -shared -o ${NAME} ${OBJS}
				${RM} ${NAME_LIB}
				ln -s ${NAME} ${NAME_LIB}
${NAME_BLANK} :	${ODIR}/blank.o
				${CC} -shared -o ${NAME_BLANK} ${ODIR}/blank.o
clean :
				${RM} ${OBJS} ${ODIR}/blank.o
fclean :		clean
				${RM} ${NAME} ${NAME_LIB} ${NAME_BLANK}
re :			fclean all
.PHONY :
				all ${NAME} clean fclean re
