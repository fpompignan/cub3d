NAME	= cub3D

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Werror -Wextra
INC	= -I minilibx/include -I minilibx -I includes -I libft
LIBRARY = -lm libft/libft.a -lm minilibx/libmlx_Linux.a -L/usr/lib -lXext -lX11

# Directory
SRCDIR		= src
PARSINGDIR	= src/parsing
OBJDIR		= obj
UTILSDIR	= src/utils
GRAPHICSDIR	= src/graphique

SRCS	= $(wildcard $(SRCDIR)/*.c)
PARSING = $(wildcard $(PARSINGDIR)/*.c)
UTILS	= $(wildcard $(UTILSDIR)/*.c)
GRAPHICS= $(wildcard $(GRAPHICSDIR)/*.c)

OBJS	= $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o))) $(addprefix $(OBJDIR)/,$(notdir $(PARSING:.c=.o))) $(addprefix $(OBJDIR)/,$(notdir $(UTILS:.c=.o))) $(addprefix $(OBJDIR)/,$(notdir $(GRAPHICS:.c=.o)))

$(OBJDIR)/%.o:		$(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	${CC} ${CFLAGS} $(INC) -c $< -o $@

$(OBJDIR)/%.o:		$(UTILSDIR)/%.c
	@mkdir -p $(OBJDIR)
	${CC} ${CFLAGS} $(INC) -c $< -o $@

$(OBJDIR)/%.o:		$(PARSINGDIR)/%.c
	@mkdir -p $(OBJDIR)
	${CC} ${CFLAGS} $(INC) -c $< -o $@

$(OBJDIR)/%.o:		$(GRAPHICSDIR)/%.c
	@mkdir -p $(OBJDIR)
	${CC} ${CFLAGS} $(INC) -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
	@make --silent -C libft
#	@make --silent -C minilibx
	${CC} ${CFLAGS} $^ $(LIBRARY) -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean
	make all

bonus:	all

.PHONY:	all clean fclean re
