ENTRY(start_)
SECTIONS {
    . = 0x100000;

    .text BLOCK(4K) : {
        * (.multiboot)
        * (.text)
    }

    .bss BLOCK(4k) : {
        * (COMMON)
        * (.bss)
    }

    .data BLOCK(4K) : {
        * (.data)
    }

    .rodata BLOCK(4K) : {
        * (.rodata)
    }
}