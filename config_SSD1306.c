//#include "mcc_generated_files/system.h"
//#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/mcc.h"
void config_SSD1306(void)
{
    /*************************SSD1306 configuration*******************/
    CS = LO;
    RES = LO;
    __delay_ms(10);
    RES = HI;
     __delay_ms(10);
     
     
    DC = LO;
    SPI1_Exchange8bit(0xAE);    //Display off 
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xd5);    //0xD5  Set Display Clock Divide Ratio/Oscillator Frequency 
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x80);     // sets SSD1306 internal oscillator to it's value as if RESET
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xa8);     //0xA8  Set Multiplex Ratio
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x3f);     //lines COM0 to COM63 for 128 x 64 display. 63 = 0x3f, 31 = 0x1f
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xd3);     //0xD3  Set Display Offset
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x00);     //affects the line characters are displayed
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x40);     //0x40  Set Display Start Line
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x8d);      //0x8D  Set Charge Pump
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x14);       //0x14  Enable Charge Pump
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xc8);        //0xC8  Set COM Output Scan Direction
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xda);        //0xDA  Set COM Pins Hardware Configuration
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x12);        
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x81);      //0x81   Set Contrast Control  
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xaf);     
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xd9);      //0xD9   Set Pre-Charge Period
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x25);     
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xdb);      //0xDB   Set VCOMH Deselect Level
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0x20);   
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xa4);      //0xA4   Set Entire Display On/Off
    CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xa6);      //0xA6   Set Normal/Inverse Display
    CS = HI;
    
 //   CS = LO;
 //   DC = LO;
  //  SPI1_Exchange8bit(0xa7);     
  //  CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xa1);     // mirror image of normal display selected
    CS = HI;
    
  //  CS = LO;
  //  DC = LO;
  //  SPI1_Exchange8bit(0xa0);    //SSD1306_SET_COM_OUTPUT_SCAN_DIRECTION 0xA0
  //  CS = HI;
    
    CS = LO;
    DC = LO;
    SPI1_Exchange8bit(0xaf);       //0xAF   Set OLED Display On  
    CS = HI;
    
    
    /*************************End of SSD1306 configuration*******************/
    
}
