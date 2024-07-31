#ifndef __CDL_multiboot
#define __CDL_multiboot


#define MB_MAGIC 0x1BADB002
#define MB_FLAG_4K_ALIGNED 0x01
#define MB_FLAG_MEM_MAP 0x02
#define MB_FLAG 0x03
#define MB_CHECK_SUM(flags) -(MB_MAGIC+flags)


#endif