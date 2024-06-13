LIB = libft.a

CC = clang

SRC_DIR   = ./src
INC_DIR   = ./include
BUILD_DIR = ./build

LIB_H = $(INC_DIR)/libft.h

C_FILES  = src/libc/ctype/ft_isdigit.c
C_FILES += src/libc/ctype/ft_isascii.c
C_FILES += src/libc/ctype/ft_isprint.c
C_FILES += src/libc/ctype/ft_toupper.c
C_FILES += src/libc/ctype/ft_isalpha.c
C_FILES += src/libc/ctype/ft_isalnum.c
C_FILES += src/libc/ctype/ft_tolower.c
C_FILES += src/libc/strings/ft_bzero.c
C_FILES += src/libc/stdlib/ft_calloc.c
C_FILES += src/libc/stdlib/ft_atoi.c
C_FILES += src/libc/string/ft_strnstr.c
C_FILES += src/libc/string/ft_strlcpy.c
C_FILES += src/libc/string/ft_strlen.c
C_FILES += src/libc/string/ft_memcmp.c
C_FILES += src/libc/string/ft_strchr.c
C_FILES += src/libc/string/ft_memcpy.c
C_FILES += src/libc/string/ft_strrchr.c
C_FILES += src/libc/string/ft_memchr.c
C_FILES += src/libc/string/ft_memset.c
C_FILES += src/libc/string/ft_strncmp.c
C_FILES += src/libc/string/ft_memmove.c
C_FILES += src/libc/string/ft_strlcat.c
C_FILES += src/libc/string/ft_strdup.c
C_FILES += src/extension/io/ft_putstr_fd.c
C_FILES += src/extension/io/ft_putnbr_fd.c
C_FILES += src/extension/io/ft_putendl_fd.c
C_FILES += src/extension/io/ft_putchar.c
C_FILES += src/extension/io/ft_putchar_fd.c
C_FILES += src/extension/string/ft_striteri.c
C_FILES += src/extension/string/ft_strjoin.c
C_FILES += src/extension/string/ft_split.c
C_FILES += src/extension/string/ft_substr.c
C_FILES += src/extension/string/ft_strmapi.c
C_FILES += src/extension/string/ft_strtrim.c
C_FILES += src/extension/string/ft_itoa.c
C_FILES += src/list/ft_lstadd_back.c
C_FILES += src/list/ft_lstnew.c
C_FILES += src/list/ft_lstlast.c
C_FILES += src/list/ft_lstclear.c
C_FILES += src/list/ft_lstiter.c
C_FILES += src/list/ft_lstmap.c
C_FILES += src/list/ft_lstsize.c
C_FILES += src/list/ft_lstadd_front.c
C_FILES += src/list/ft_lstdelone.c

OBJS := $(C_FILES:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)


CFLAGS  = -Wall -Wextra
#CFLAGS += -Werror
CPPFLAGS  = -I$(INC_DIR) -MMD -MP

.PHONY: all
all: build

.PHONY: build
build: $(LIB)

$(LIB): $(OBJS)
	@echo Building libft
	@ar rcs $@ $^
	@printf "$(GREEN)===============BUILD COMPLETED===============$(NC)\n"

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo Cleaning up object files
	@rm -rf $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	@echo Cleaning up lib
	@rm -rf $(LIB)
	@make -C test clean

.PHONY: re
re: fclean update

.PHONY: test
test: $(LIB)
	@make -C test

.PHONY: fmt
fmt:
	@echo Formatting
	@bash aux/norme.sh

.PHONY: check
check: re
	@python3 -c 'print("-" * 80)'
	@echo SAINTE NORMINETTE SOIS CLEMENTE
	@python3 -c 'print("-" * 80)'
	@echo
	@norminette $(C_FILES) $(BONUS_C_FILES)
	@echo
	@norminette $(LIB_H)
	@printf "$(GREEN)===============NORME OK===============$(NC)\n"
	@echo
	@cppcheck --language=c $(C_FILES) $(BONUS_C_FILES)

	@cppcheck --language=c $(LIB_H)
	@printf "$(GREEN)===============CPPCHECK OK===============$(NC)\n"

# LSP stuff, don't worry about it
.PHONY: update
update:
	make clean
	mkdir -p $(BUILD_DIR)
	bear --output $(BUILD_DIR)/compile_commands.json -- make build

# aliases
.PHONY: b f c u t
b: build
f: fmt
c: clean
u: update
t: test

GREEN = \033[0;32m
NC = \033[0m

-include $(DEPS)
