# source code files without external functions
SRCS_NOEXT	=	ft_strchr.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isspace.c \
				ft_isprint.c \
				ft_memcmp.c \
				ft_strncmp.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_bzero.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstiter.c
# source code files using the write external functions
SRCS_WRITE	=	ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putnstr.c
# source code files using malloc and/or free external functions
SRCS_ALLOC	=	ft_itoa.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_split.c \
				ft_calloc.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstclear.c \
				ft_lstdelone.c

OBJS_NOEXT	=	${SRCS_NOEXT:.c=.o}
OBJS_WRITE	=	${SRCS_WRITE:.c=.o}
OBJS_ALLOC	=	${SRCS_ALLOC:.c=.o}

OBJS		=	${OBJS_NOEXT}
EXCLUDE		=

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
RM			= rm -f

ifndef EXCLUDE
OBJS += ${OBJS_WRITE} ${OBJS_ALLOC}
else ifeq (${EXCLUDE},write)
OBJS += ${OBJS_ALLOC}
else ifeq (${EXCLUDE},alloc)
OBJS += ${OBJS_WRITE}
else ifneq (${EXCLUDE},all)
$(error Wrong value for EXCLUDE. Allowed values are 'write', 'alloc' and 'all'.)
endif

%.o :		%.c
			${CC} ${CFLAGS} -c $<
all :		${NAME}
${NAME} :	${OBJS}
			ar rc ${NAME} ${OBJS}
clean :
			${RM} ${OBJS}
fclean :	clean
			${RM} ${NAME}
re :		fclean all
.PHONY :
			all ${NAME} clean fclean re
