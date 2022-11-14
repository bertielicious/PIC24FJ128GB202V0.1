#include "mcc_generated_files/mcc.h"
#include "setPageAddress.h"
void clearDisplay(void)
{
    uint8_t col, row;
    for(row = 0; row < 8; row++)
    {
        setPageAddress(row);
        for(col = 0; col <128; col++)
        {
            CS = LO;
            DC = HI;
            SPI1_Exchange8bit(0x00);       // clear 8 pixels of display at a time
            CS = HI;
        }
    }
}
