#include <stdio.h>
#include "lis3mdl_driver.h"

int main() {
    // If the SDO/SA1 pin is connected to the voltage supply, the address is 0x1E, otherwise, if the SDO/SA1 pin is connected to ground, the address is 0x1C .
    uint8_t bus_address = 0x1E;

    uint8_t * axis_data;

    
    // Test setting output data rate
    OutputDataRate rate_to_set = ODR_2_5_Hz; // Choose desired output data rate
    status_t set_rate_status = lis3mdl_set_output_data_rate(bus_address, rate_to_set);
    if (set_rate_status == STATUS_OK) {
        printf("Output data rate set successfully.\n");
    } else {
        printf("Failed to set output data rate.\n");
    }
    
    // Test getting full-scale configuration
    uint8_t get_scale_status = lis3mdl_get_full_scale(bus_address);
    printf("Full-scale configuration: %d\n", get_scale_status);

    axis_data = lis3mdl_read_axis_data(bus_address,X);
    printf("x axis data : %d\n", get_scale_status);



    return 0;
}
