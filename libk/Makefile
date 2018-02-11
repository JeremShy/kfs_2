C++_SRC_NAME = putstr.c++ \
				strlen.c++ \
				putstr_color.c++ \
				getKeyComb_down.c++ \
				putchar.c++ \
				putnbr.c++ \
				printk.c++ \
				KeyComb.c++ \
				memcpy.c++ \
				volatile_memcpy.c++ \
				moveCursor.c++

ASM_SRC_NAME =

ASM_OBJ_NAME = $(ASM_SRC_NAME:.s=.o)
C++_OBJ_NAME = $(C++_SRC_NAME:.c++=.o)

C++ = i686-elf-g++
ASM = i686-elf-as
LD = i686-elf-gcc -T linker.ld

C++_SRC_PATH = ./c++/
ASM_SRC_PATH = ./asm/

C++_OBJ_PATH = ./objc++/
ASM_OBJ_PATH = ./objasm/

NAME = ../libk.a

C++_FLAGS= -fno-builtin -fno-exceptions -fno-stack-protector -fno-rtti -nostdlib -nodefaultlibs -g -Wall -Wextra

C++_SRC = $(addprefix $(C++_PATH),$(C++_SRC_NAME))
ASM_SRC = $(addprefix $(ASM_PATH),$(ASM_SRC_NAME))

C++_OBJ = $(addprefix $(C++_OBJ_PATH),$(C++_OBJ_NAME))
ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))

INCLUDES = ./includes/ ../includes
INCLUDE_FLAGS = $(addprefix -I ,$(INCLUDES))

OBJ = $(C++_OBJ) $(ASM_OBJ)

ccred = \033[0;31m
cccyan = \033[0;36m
ccgreen = \033[0;32m
ccend = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar r $(NAME) $^ >&- 2>&-
	@/bin/echo -e '$(ccred)'libk'$(ccend)': Compiled.'\n'

$(C++_OBJ_PATH)%.o: $(C++_SRC_PATH)%.c++
	@/bin/mkdir -p $(C++_OBJ_PATH) >&- 2>&-
	@$(C++) $(C++_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@/bin/echo -e '$(ccred)'libk'$(ccend)':'\t''$(ccgreen)'[C]'$(ccend)' : $<

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.s
	@/bin/mkdir -p $(ASM_OBJ_PATH) >&- 2>&-
	@$(ASM) $< -o $@ --fatal-warnings
	@/bin/echo -e '$(ccred)'libk'$(ccend)':'\t''$(cccyan)'[ASM]'$(ccend)' : $<

clean:
	@rm -fv $(OBJ)
	@rm -rfv $(C++_OBJ_PATH)
	@rm -rfv $(ASM_OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all
