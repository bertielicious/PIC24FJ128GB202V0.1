#include "mcc_generated_files/mcc.h"
void set_Columns(uint8_t columnMode, uint8_t startCol, uint8_t endCol)
{
     CS = LO;
        DC = LO;
        SPI1_Exchange8bit(columnMode);       //set column address
        CS = HI;
        
        CS = LO;
        DC = LO;
        SPI1_Exchange8bit(startCol);       //set start column address
        CS = HI;
        
        CS = LO;
        DC = LO;
        SPI1_Exchange8bit(endCol);       //set end column address
        CS = HI;
}
