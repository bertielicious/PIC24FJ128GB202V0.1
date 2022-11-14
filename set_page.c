#include "mcc_generated_files/mcc.h"
void set_page(uint8_t memory_mode, uint8_t page_mode, uint8_t page_addr)
{
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(memory_mode);    //
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(page_mode);    //
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xb0|page_addr);    //
    CS = HI;
}
