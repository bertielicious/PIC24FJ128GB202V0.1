#include "mcc_generated_files/mcc.h"
void write_data(uint8_t data)
{
    CS = LO;
    DC = HI;
    SPI1_Exchange8bit(data);
    CS = HI;
}
