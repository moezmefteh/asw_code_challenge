#ifndef __LIS3MDL_DRIVER_H__
#define __LIS3MDL_DRIVER_H__
#include <stdint.h>
#include "i2c.h"
// LIS3MDLTR Magnetometer Register Addresses
#define LIS3MDLTR_CTRL_REG1     0x20
#define LIS3MDLTR_CTRL_REG2     0x21
#define LIS3MDLTR_INT_CFG       0x30
#define LIS3MDLTR_OUT_X_L       0x28
#define LIS3MDLTR_OUT_Y_L       0x2A
#define LIS3MDLTR_OUT_Z_L       0x2C


// Constants for configuration
#define LIS3MDLTR_FULL_SCALE_4  0x00  // +/- 4 Gauss
#define LIS3MDLTR_FULL_SCALE_8  0x20  // +/- 8 Gauss
#define LIS3MDLTR_OUTPUT_RATE_10HZ 0x20 // Output data rate: 10Hz


typedef enum {
    ODR_0_625_Hz,
    ODR_1_25_Hz,
    ODR_2_5_Hz,
    ODR_5_Hz,
    ODR_10_Hz,
    ODR_20_Hz,
    ODR_40_Hz,
    ODR_80_Hz
} OutputDataRate;

typedef enum{
    X,
    Y,
    Z
} Axis;

uint8_t lis3mdl_get_full_scale(uint8_t bus_address);
OutputDataRate lis3mdl_get_output_data_rate(uint8_t bus_address);
status_t lis3mdl_set_output_data_rate(uint8_t bus_address, OutputDataRate rate);
status_t lis3mdl_set_interrupt_pin(uint8_t bus_address, uint8_t enable);
uint8_t* lis3mdl_read_axis_data(uint8_t bus_address, Axis axis);

#endif