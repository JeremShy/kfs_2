C++_SRC_NAME = kernel.c++ \
				Terminal.c++ \
				Cursor.c++ \
				TerminalManager.c++
C++_OBJ_NAME = $(C++_SRC_NAME:.c++=.o)

ASM_SRC_NAME = boot.s
ASM_OBJ_NAME = $(ASM_SRC_NAME:.s=.o)

C++ = i686-elf-g++
ASM = i686-elf-as
LD = i686-elf-gcc -T linker.ld

C++_SRC_PATH = ./c++/
ASM_SRC_PATH = ./asm/

C++_OBJ_PATH = ./objc++/
ASM_OBJ_PATH = ./objasm/

PRENAME = jcamhi_kernel
ISO_NAME = $(PRENAME).iso
BIN_NAME = $(PRENAME).bin
NAME = $(ISO_NAME)

C++_FLAGS = -fno-builtin -fno-exceptions -fno-stack-protector -fno-rtti -nostdlib -nodefaultlibs -g -Wall -Wextra
C++_SRC = $(addprefix $(C++_PATH),$(C++_SRC_NAME))
ASM_SRC = $(addprefix $(ASM_PATH),$(ASM_SRC_NAME))

C++_OBJ = $(addprefix $(C++_OBJ_PATH),$(C++_OBJ_NAME))
ASM_OBJ = $(addprefix $(ASM_OBJ_PATH),$(ASM_OBJ_NAME))
OBJ = $(C++_OBJ) $(ASM_OBJ)

INCLUDES = ./libk/includes/ ./includes
INCLUDE_FLAGS = $(addprefix -I ,$(INCLUDES))

ccred = \033[0;31m
cccyan = \033[0;36m
ccgreen = \033[0;32m
ccend = \033[0m

CRTI_OBJ=$(ASM_OBJ_PATH)crti.o
CRTBEGIN_OBJ:=$(shell $(C++) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(C++) $(CFLAGS) -print-file-name=crtend.o)
CRTN_OBJ=$(ASM_OBJ_PATH)crtn.o

OBJ_LINK_LIST:=$(CRTI_OBJ) $(CRTBEGIN_OBJ) $(OBJ) $(CRTEND_OBJ) $(CRTN_OBJ)
INTERNAL_OBJS:=$(CRTI_OBJ) $(OBJ) $(CRTN_OBJ)

all: lib $(NAME)

$(NAME) : $(INTERNAL_OBJS) libk.a
	@$(LD) -o $(BIN_NAME) $(OBJ_LINK_LIST) $(C++_FLAGS) -L. -lk
	@/bin/echo -e '$(ccred)'kernel'$(ccend)': Compiled and linked.'\n'
	@mkdir -p isodir/boot/grub
	@cp $(BIN_NAME) isodir/boot/$(BIN_NAME)
	@/bin/echo -e '$(cccyan)'Making a bootable cd...'$(ccend)'
	grub-mkrescue -o $(ISO_NAME) isodir
	@/bin/echo -e '$(ccgreen)'Everything ok '$(ccend)'

lib:
	@$(MAKE) --no-print-directory -C libk

$(C++_OBJ_PATH)%.o: $(C++_SRC_PATH)%.c++
	@/bin/echo -e '$(ccred)'kernel'$(ccend)':	'$(ccgreen)'[C]'$(ccend)': $<
	@/bin/mkdir -p $(C++_OBJ_PATH) >&- 2>&-
	@$(C++) $(C++_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(ASM_OBJ_PATH)%.o: $(ASM_SRC_PATH)%.s
	@/bin/echo -e '$(ccred)'kernel'$(ccend)':	'$(cccyan)'[ASM]'$(ccend)': $<
	@/bin/mkdir -p $(ASM_OBJ_PATH) >&- 2>&-
	@$(ASM) $< -o $@

clean:
	@$(MAKE) -C libk clean
	@rm -fv $(INTERNAL_OBJS)

fclean: clean
	@$(MAKE) -C libk fclean
	@rm -fv $(BIN_NAME)
	@rm -fv $(ISO_NAME)
	@rm -rfv $(C++_OBJ_PATH)
	@rm -rfv $(ASM_OBJ_PATH)
	@rm -fv isodir/boot/$(BIN_NAME)

test: all
	kvm -m 256 -cdrom $(ISO_NAME) -curses

debug: all
	kvm -m 256 -cdrom $(ISO_NAME) -curses -s -S
re: fclean all
