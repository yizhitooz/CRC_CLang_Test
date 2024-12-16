#include "crc_func.h"

uint16 _chipone_crc(const uint8 *data, uint16 data_len)
{
    uint16 crc = 0;
    uint16 i, j;
    for (i = 0; i < data_len; i++)
    {
        crc ^= data[i] << 8;
        for (j = 8; j; j--)
        {
            if (crc & 0x8000)
            {
                crc <<= 1;
                crc ^= 0x8005;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

uint32 _custom_crc32(const uint8 *data, uint16 data_len)
{
    uint32 crc = 0x00000000;
    uint16 i, j;

    for (i = 0; i < data_len; i++)
    {
        crc ^= (uint32)data[i] << 24;
        for (j = 0; j < 8; j++)
        {
            if (crc & 0x80000000)
            {
                crc = (crc << 1) ^ 0x04C11DB7;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}