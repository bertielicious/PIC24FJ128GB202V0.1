#include "mcc_generated_files/mcc.h"
void write_command(uint8_t command)
{
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(command);
    CS = HI;
}
