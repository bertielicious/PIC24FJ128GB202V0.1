#include "mcc_generated_files/mcc.h"
void setPageAddress(uint8_t pageNumber)
{
   uint8_t result;
   result = (pageNumber | 0xB0);
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(result);
    CS = HI;
}
