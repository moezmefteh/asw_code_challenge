#include "i2c.h"
#include <stdint.h>

#include "lis3mdl_driver.h"

// Function to get full-scale configuration
uint8_t lis3mdl_get_full_scale(uint8_t bus_address) {
    uint8_t *scale;
    status_t status = i2c_read(bus_address, LIS3MDLTR_CTRL_REG2, 1, scale);
    if (status == STATUS_OK) {
        *scale &= 0x60; // Mask other bits except for the full-scale bits
        return scale;
    }
    return -1; 
}

// Function to get output data rate
OutputDataRate lis3mdl_get_output_data_rate(uint8_t bus_address) {
    uint8_t rate;
    status_t status = i2c_read(bus_address, LIS3MDLTR_CTRL_REG1, 1, &rate);
    if (status == STATUS_OK) {
        rate &= 0x1C;
        switch (rate) {
            case 0x0:
                return ODR_0_625_Hz;
            case 0x4:
                return ODR_1_25_Hz;
            case 0x08:
                return ODR_2_5_Hz;
            case 0x0C:
                return ODR_5_Hz;
            case 0x10:
                return ODR_10_Hz;
            case 0x14:
                return ODR_20_Hz;
            case 0x18:
                return ODR_40_Hz;
            case 0x1C:
                return ODR_80_Hz;
            default:
                // Invalid rate value
                return -1;
        }
    }
    return -1;
}

// Function to set output data rate
status_t lis3mdl_set_output_data_rate(uint8_t bus_address, OutputDataRate rate) {
    uint8_t ctrl_reg1;
    status_t status = i2c_read(bus_address, LIS3MDLTR_CTRL_REG1, 1, &ctrl_reg1);
    if (status == STATUS_OK) {
        // Mask out existing DO[2:0] bits
        ctrl_reg1 &= 0xE3; // Mask out DO[2:0]
        // Set new DO[2:0] bits according to the desired rate
        switch (rate) {
            case 0:
                ctrl_reg1 |= 0x00; // 0.625 Hz
                break;
            case 1:
                ctrl_reg1 |= 0x04; // 1.25 Hz
                break;
            case 2:
                ctrl_reg1 |= 0x08; // 2.5 Hz
                break;
            case 3:
                ctrl_reg1 |= 0x0C; // 5 Hz
                break;
            case 4:
                ctrl_reg1 |= 0x10; // 10 Hz
                break;
            case 5:
                ctrl_reg1 |= 0x14; // 20 Hz
                break;
            case 6:
                ctrl_reg1 |= 0x18; // 40 Hz
                break;
            case 7:
                ctrl_reg1 |= 0x1C; // 80 Hz
                break;
            default:
                // Invalid rate value
                return STATUS_ERROR;
        }
        // Write the modified value back to CTRL_REG1
        status = i2c_write(bus_address, LIS3MDLTR_CTRL_REG1, 1, &ctrl_reg1);
    }
    return status;
}


// Function to enable/disable interrupt pin
status_t lis3mdl_set_interrupt_pin(uint8_t bus_address, uint8_t enable) {
    uint8_t INT_CFG;
    status_t status = i2c_read(bus_address, LIS3MDLTR_INT_CFG, 1, &INT_CFG);
    if (status == STATUS_OK) {
        if (enable)
            INT_CFG |= 0x01;  // Set the enable interrupt pin
        else
            INT_CFG &= ~0x01; // Clear the disable interrupt pin
        status = i2c_write(bus_address, LIS3MDLTR_INT_CFG, 1, &INT_CFG);
    }
    return status;
}

// Function to read output data of a specified axis
uint8_t* lis3mdl_read_axis_data(uint8_t bus_address, Axis axis) {
    uint8_t *OutputData;
    status_t status;
    switch (axis)
    {
    case X:
        status = i2c_read(bus_address, LIS3MDLTR_OUT_X_L, 2, OutputData);
        if (status == STATUS_OK) {
            return OutputData;
        }
        break;
    case Y:
        status = i2c_read(bus_address, LIS3MDLTR_OUT_Y_L, 2, OutputData);
        if (status == STATUS_OK) {
            return OutputData;
        }
        break;
    case Z:
        status = i2c_read(bus_address, LIS3MDLTR_OUT_Z_L, 2, OutputData);
        if (status == STATUS_OK) {
            return OutputData;
        }
        break;
    default:
        return -1;
        break;
    }
    
}
