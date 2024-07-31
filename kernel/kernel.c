#include "cdl/tty/tty.h"

void _cdl_kernel_init() {
    // TODO(cdl): [WFT]
}

void _cdl_kernel_main(void* bl_info_table) {
    // TODO(cdl): [WFT] 
    tty_put_string("Hello cdl's Kernel!\nWelcome!!!");
}