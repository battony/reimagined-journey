.syntax     unified

.global     interrupt_reset

.type       interrupt_reset,                    function

.section    .text

interrupt_reset:
    ldr     r0,     =data_ram_start
    ldr     r1,     =data_rom_start
    ldr     r2,     =data_rom_end

1:
    teq     r1,     r2
    beq     1f
    ldr     r3,     [r1],   0x4
    str     r3,     [r0],   0x4
    b       1b

1:
    ldr     r0,     =bss_ram_start
    ldr     r1,     =bss_ram_end
    eor     r2,     r2

1:
    teq     r0,     r1
    beq     1f
    str     r2,     [r0],   0x4
    b       1b

1:
    b       main
