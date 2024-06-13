NAME = libftprintf.a

BUILD_DIR            = ./build
SRC_DIR              = ./src
INCLUDE_DIR          = ./include
INTERNAL_INCLUDE_DIR = ./src

SRCS  = src/ft_printf.c
SRCS += src/tokenize/tokenize.c
SRCS += src/print/print.c
SRCS += src/print/print_numbers.c
SRCS += src/print/print_pointer.c
SRCS += src/print/print_text.c

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -g3
CFLAGS   += -Werror
CPPFLAGS  = -I$(INCLUDE_DIR) -I$(INTERNAL_INCLUDE_DIR)
CPPFLAGS += -MMD -MP

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a
CPPFLAGS += -I$(LIBFT_PATH)/include

ARFLAGS = rcs

.PHONY: all
all: build

.PHONY: build
build: $(NAME)

.PHONY: example
example: $(BUILD_DIR)/example $(NAME)
	cat example/main.c
	./build/example

$(BUILD_DIR)/example: example/main.c
	$(CC) $(CFLAGS) -I./include $^ -L. -lftprintf -o $@

# Linking
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar $(ARFLAGS) $@ $(OBJS)

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

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

VERBOSITY = 

# LSP stuff, don't worry about it
.PHONY: update
update:
	make clean
	mkdir -p $(BUILD_DIR)
	bear $(VERBOSITY) --output $(BUILD_DIR)/compile_commands.json -- make build

# aliases
.PHONY: b c u e
b: build
c: clean
u: update
e: example
