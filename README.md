# LIS3MDL Driver

This repository contains a C driver for the LIS3MDL magnetometer sensor. The driver enables communication with the sensor over the I2C interface, allowing users to configure the sensor, read data from it, and control its settings.

## Usage

1. Clone or download this repository.
2. Add the `lis3mdl_driver.c` and `lis3mdl_driver.h` files to your project.
3. Ensure that you have an I2C driver integrated into your project.

## Functions

- `lis3mdl_get_full_scale(bus_address)`: Get full-scale configuration of the sensor.
- `lis3mdl_get_output_data_rate(bus_address)`: Get output data rate of the sensor.
- `lis3mdl_set_output_data_rate(bus_address, rate)`: Set output data rate of the sensor.
- `lis3mdl_set_interrupt_pin(bus_address, enable)`: Enable/disable interrupt pin.
- `lis3mdl_read_axis_data(bus_address, axis)`: Read output data of a specified axis.

## Example

```c
#include <stdio.h>
#include "lis3mdl_driver.h"

int main() {
    // Initialize sensor and configure settings

    // Read sensor data

    return 0;
}
