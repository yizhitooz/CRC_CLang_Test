#include "ovt_def/ovt_type.h"
#include "check_sum_func.h"

uint8 _get_checksum(const uint8 *data, uint16 data_len)
{
    uint8 i;
    uint8 sum = 0;
    for (i = 0; i < data_len; i++)
    {
        sum += data[i];
    }
    sum = -sum;
    return sum;
}