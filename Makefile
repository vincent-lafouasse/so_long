NAME = so_long

BUILD_DIR            = ./build
SRC_DIR              = ./src
INCLUDE_DIR          = ./include
INTERNAL_INCLUDE_DIR = ./src

SRCS = $(shell find $(SRC_DIR) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -g3
CFLAGS   += -Werror
CPPFLAGS  = -I$(INCLUDE_DIR) -I$(INTERNAL_INCLUDE_DIR)
CPPFLAGS += -MMD -MP

# LIBFT_PATH = ./lib/libft
# LIBFT = $(LIBFT_PATH)/libft.a
# CPPFLAGS += -I$(LIBFT_PATH)/include

MLX_PATH = ./lib/minilibx-linux/
MLX = $(MLX_PATH)
MLX_INCLUDE_PATH = $(MLX_PATH)
MLX_LIB_PATH = $(MLX_PATH)

CPPFLAGS += -I$(MLX_INCLUDE_PATH)
LDFLAGS += -L$(MLX_LIB_PATH)
LDLIBS += -lmlx

LDFLAGS = 

.PHONY: all
all: build

.PHONY: build
build: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# Compilation
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: re
re: fclean build

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(LIBFT_PATH)/$(BUILD_DIR)
	$(RM) Makefile.gen

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

# VERBOSITY = --verbose

# LSP stuff, don't worry about it
.PHONY: update
update:
	make clean
	mkdir -p $(BUILD_DIR)
	bear $(VERBOSITY) --output $(BUILD_DIR)/compile_commands.json -- make build

# aliases
.PHONY: b c u
b: build
c: clean
u: update
