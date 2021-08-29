PROJECT = $(shell basename $(CURDIR))

HEADERS = headers
SOURCES = sources
ANOTHER = another
MCULIBS = mculibs

C_FILES = $(wildcard $(SOURCES)/*/*/*.c $(SOURCES)/*/*.c)
S_FILES = $(wildcard $(SOURCES)/*/*/*.s $(SOURCES)/*/*.s $(ANOTHER)/*.s)

OBJECTS = $(S_FILES:.s=.o) $(C_FILES:.c=.o)

ARMCOMP = arm-none-eabi-gcc
ARMSIZE = arm-none-eabi-size
ARMDUMP = arm-none-eabi-objdump
ARMCOPY = arm-none-eabi-objcopy
FLASHER = st-flash

LDFILES = $(ANOTHER)/stm32f103xb.ld

FLGCOMP = -I $(HEADERS) -I $(MCULIBS) -mcpu=cortex-m3 -mthumb \
		  -Ofast -flto -nostdlib -fno-builtin -T $(LDFILES) \
		  -Wall -Wextra -Wpedantic -Wno-main
FLGSIZE = -Gd
FLGDUMP = -d
FLGCOPY = -O binary
FLGFLSH = --reset write

.PHONY:  clean flash dump size
.SILENT: clean

%.o: %.s
	$(ARMCOMP) $(FLGCOMP) -c -o $@ $<

%.o: %.c
	$(ARMCOMP) $(FLGCOMP) -c -o $@ $<

$(PROJECT).elf: $(OBJECTS)
	$(ARMCOMP) $(FLGCOMP) -o $(PROJECT).elf $(OBJECTS)

$(PROJECT).bin: $(PROJECT).elf
	$(ARMCOPY) $(FLGCOPY) $(PROJECT).elf $(PROJECT).bin

size: $(PROJECT).elf
	$(ARMSIZE) $(FLGSIZE) $(PROJECT).elf

dump: $(PROJECT).elf
	$(ARMDUMP) $(FLGDUMP) $(PROJECT).elf

flash: $(PROJECT).bin
	$(FLASHER) $(FLGFLSH) $(PROJECT).bin 0x08000000

clean:
	rm -rf $(PROJECT).elf $(PROJECT).bin $(OBJECTS)
