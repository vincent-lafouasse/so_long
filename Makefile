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
# CFLAGS   += -Werror
CPPFLAGS  = -I$(INCLUDE_DIR) -I$(INTERNAL_INCLUDE_DIR)
CPPFLAGS += -MMD -MP
LDLIBS = 
LDFLAGS =

LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_MAKE_PATH = $(LIBFT_PATH)
LIBFT_INCLUDE_PATH = $(LIBFT_PATH)
LIBFT_LIB_PATH = $(LIBFT_PATH)

CPPFLAGS += -I$(LIBFT_PATH)/include
LDFLAGS += -L$(LIBFT_LIB_PATH)
LDLIBS += -lft

MLX_PATH = ./lib/minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_MAKE_PATH = $(MLX_PATH)
MLX_INCLUDE_PATH = $(MLX_PATH)
MLX_LIB_PATH = $(MLX_PATH)

CPPFLAGS += -I$(MLX_INCLUDE_PATH)
LDFLAGS += -L$(MLX_LIB_PATH)
LDLIBS += -lmlx -lXext -lX11

.PHONY: all
all: build

.PHONY: run
run: $(NAME)
	./$^ ./assets/maps/valid/tiny.ber

.PHONY: build
build: $(NAME)

# Linking
$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

# Compilation
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_MAKE_PATH)

$(MLX):
	-./$(MLX_PATH)/configure
	make -C $(MLX_MAKE_PATH)

.PHONY: re
re: fclean build

CPPCHECK_FLAGS  = --language=c --enable=all
CPPCHECK_FLAGS += --check-level=exhaustive
CPPCHECK_FLAGS += --suppress=missingIncludeSystem
CPPCHECK_FLAGS += --suppress=variableScope
CPPCHECK_FLAGS += -isrc/log -ilib
CPPCHECK_FLAGS += --cppcheck-build-dir=build
CPPCHECK_FLAGS += --project=build/compile_commands.json
.PHONY: check
check:
	cppcheck $(CPPCHECK_FLAGS)
	# norminette src # to be reenabled later


.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	make clean -C $(MLX_MAKE_PATH)
	make clean -C $(LIBFT_MAKE_PATH)
	$(RM) Makefile.gen

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX)
	make fclean -C $(LIBFT_MAKE_PATH)

# VERBOSITY = --verbose

# LSP stuff, don't worry about it
.PHONY: update
update: fclean
	mkdir -p $(BUILD_DIR)
	bear $(VERBOSITY) --output $(BUILD_DIR)/compile_commands.json -- make build

# aliases
.PHONY: b c u r
b: build
c: clean
u: update
r: run
