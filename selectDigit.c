#include "mcc_generated_files/mcc.h"
uint8_t* selectDigit(uint8_t digit)
{
    const uint8_t zero[8] = {0x00,0x7e,0xe1,0x91,0x89,0x85,0x7e,0x00};
    const uint8_t one[8] = {0x00,0x84,0x82,0xff,0x80,0x80,0x00,0x00};
    const uint8_t two[8] = {0x00,0xe2,0x91,0x91,0x89,0x89,0xc6,0x00};
    const uint8_t three[8] = {0x00,0x42,0x81,0x89,0x89,0x89,0x76,0x00};
    const uint8_t four[8] = {0x10,0x18,0x14,0x92,0xff,0x90,0x10,0x00};
    const uint8_t five[8] = {0x00,0x47,0x89,0x89,0x89,0x89,0x71,0x00};
    const uint8_t six[8] = {0x00,0x7c,0x8a,0x89,0x89,0x89,0x70,0x00};
    const uint8_t seven[8] = {0x00,0x03,0x01,0xf1,0x09,0x05,0x03,0x00};
    const uint8_t eight[8] = {0x00,0x76,0x89,0x89,0x89,0x89,0x76,0x00};
    const uint8_t nine[8] = {0x00,0x06,0x89,0x89,0x89,0x49,0x3e,0x00};
    
    switch(digit)
    {
            case 0:
                return zero;
                break;
                
            case 1:
                return one;
                break;
                
            case 2:
                return two;
                break;
                
            case 3:
                return three;
                break;
                
            case 4:
                return four;
                break;
                
            case 5:
                return five;
                break;
                
            case 6:
                return six;
                break;
                
            case 7:
                return seven;
                break;
                
            case 8:
                return eight;
                break;
                
            case 9:
                return nine;
                break;
                
            default:
                break;
    }          
            
}
