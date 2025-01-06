#include "ovt_def/ovt_type.h"

/**
 * @brief 集创北方 CRC 校验
 *
 * @param data
 * @param data_len
 * @return uint16
 */
uint16 _chipone_crc(const uint8 *data, uint16 data_len);

/**
 * @brief CRC 32 位校验
 *
 * @param data
 * @param data_len
 * @return uint32
 */
uint32 _custom_crc32(const uint8 *data, uint16 data_len);

/**
 * @brief 敦泰 CRC 校验
 *
 * @param data
 * @param data_len
 * @return uint16
 */
uint16 _focal_crc(const uint8 *data, uint16 data_len);