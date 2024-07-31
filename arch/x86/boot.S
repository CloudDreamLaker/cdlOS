#include "multiboot.h"

.section .multiboot
    .long MB_MAGIC
    .long MB_FLAG
    .long MB_CHECK_SUM(MB_FLAG)

.section .bss
    .align 16
    stack_bottom:
        .skip 16 * 1024
    stack_top:

.section .text
    start_:
        movl $stack_top, %esp
        /*
            TODO(cdl): kernel init
                1. Load GDT
                2. Load IDT
                3. Enable Paging
        */
        call _cdl_kernel_init

        pushl %ebx
        call _cdl_kernel_main

        cli

    j_:
        hlt
        jmp j_