ENTRY(interrupt_reset)

MEMORY {
    ROM (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rw) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS {
    
    .text : {
        . = ALIGN(4);
        *(.int)
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > ROM

    .data : {
        . = ALIGN(4);
        *(.data*)
        . = ALIGN(4);
    } > RAM AT > ROM

    .bss  : {
        . = ALIGN(4);
        *(.bss*)
        . = ALIGN(4);
    } > RAM

}

stack_pointer  = ORIGIN(RAM) + LENGTH(RAM);

data_ram_start = ADDR(.data);
data_ram_end   = ADDR(.data) + SIZEOF(.data);

data_rom_start = LOADADDR(.data);
data_rom_end   = LOADADDR(.data) + SIZEOF(.data);

bss_ram_start  = ADDR(.bss);
bss_ram_end    = ADDR(.bss) + SIZEOF(.bss);
