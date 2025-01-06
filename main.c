/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-01-06
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include "ovt_def/ovt_type.h"
#include "macros.h"

#include "crc_func.h"
#include "check_sum_func.h"
#include "data_array.h"

int main()
{
#if CRC32
    uint32 crc32_value = _custom_crc32(&data_array[0], sizeof(data_array));
    printf("the crc32 value is 0x%08X\n", crc32_value);
#endif
    return 0;
}