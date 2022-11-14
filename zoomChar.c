#include "mcc_generated_files/mcc.h"
/* Overview: function can zoom any 8 x 8 bitmap by 1, 2,3 or 4 times.
 * This function reads a byte of hex data (character representation within an 8 element array), 
 * and replicates each pixel which is set to four pixels, and then stored in one of for arrays as follows:
 *  original pixel      zoomed pixel
 *      *                   *   *
 *                          *   *
 * Input: hex byte from character array
 * 
 *   col 0-7
    --------
   |    |lsb|
   |    |   |
   | 1  | 2 |       r   v
   |    |   |       o   a   i   h
   |--------|       w   l   n   e
   |    |   |           u       x
   |  3 | 4 |           e
   |    |   |
   |    |msb|
    --------
 * 
 * each 4 x 4 matrix is mapped to a larger 8 x 8 matrix, to allow for the increased size of the character
 * 
 * 
 * Output: 2 x pixel replication (vertically and horizontally)contained within four arrays of eight elements each
 * mapped each to 1,2,3,4 for the input array
 * 
 * 
 ******************************************************************************************************************
 pseudocode
 * repeat for 8 bytes of array1
 * read first hex byte from  character array1 to be displayed
 * check byte to see if there is a '1' contained within that byte
 * if a '1' is found
 * {
 * calculate the column and value of pixel A - pixel A = col + 1, pixel value <<1
 * calculate the column and value of pixel B - pixel B = col + 2, pixel value <<1
 * calculate the column and value of pixel C - pixel A = col + 1, pixel value <<1
 * calculate the column and value of pixel D - pixel A = col + 1, pixel value <<1
 */


void zoomChar(uint8_t  num)
{
    uint8_t byteBit7, byteBit6, byteBit5, byteBit4, byteBit3, byteBit2, byteBit1, byteBit0, unzoomedByte, zoomedByte0,zoomedByte1, i, offset; 
    uint8_t zero[8] = {0x00,0x7e,0xe1,0x91,0x89,0x85,0x7e,0x00};   // static definition as address of array passed back to caller
    uint8_t one[8] = {0x00,0x84,0x82,0xff,0x80,0x80,0x00,0x00};   // after the function has been left. static effectively keeps the 
    uint8_t two[8] = {0x00,0xe2,0x91,0x91,0x89,0x89,0xc6,0x00};    // the array address alive even when we have left the function
    uint8_t three[8] = {0x00,0x42,0x81,0x89,0x89,0x89,0x76,0x00};
    uint8_t four[8] = {0x00,0x10, 0x18,0x14,0x92,0xff,0x90,0x00};
    uint8_t five[8] = {0x00,0x47,0x89,0x89,0x89,0x89,0x71,0x00};
    uint8_t six[8] =  {0x00,0x7c,0x8a,0x89,0x89,0x89,0x70,0x00};
    uint8_t seven[8] = {0x00,0x03,0x01,0xf1,0x09,0x05,0x03,0x00};
    uint8_t eight[8] = {0x00,0x76,0x89,0x89,0x89,0x89,0x76,0x00};
    uint8_t nine[8] = {0x00,0x06,0x89,0x89,0x89,0x49,0x3e,0x00};
    uint8_t *ptr;
    
    switch(num)
    {
        case 0:
            ptr = &zero[0];
            break;
            
        case 1:
            ptr = &one[0];
            break;
            
        case 2:
            ptr = &two[0];
            break;  
            
        case 3:
            ptr = &three[0];
            break;
            
        case 4:
            ptr = &four[0];
            break;
            
        case 5:
            ptr = &five[0];
            break;
            
        case 6:
            ptr = &six[0];
            break;
            
        case 7:
            ptr = &seven[0];
            break;
            
        case 8:
            ptr = &eight[0];
            break;
            
        case 9:
            ptr = &nine[0];
            break;
    }
    
    offset = 0;
    for(i = 0; i< 8; i++)
    {
        unzoomedByte = *ptr;
        byteBit0 = (unzoomedByte & 0b00000001); // calculates page 0 zoomed byte, a byte at a time with every function call
        byteBit1 = byteBit0;
        byteBit2 = (unzoomedByte & 0b00000010);
        byteBit3 = byteBit2;
        byteBit4 = (unzoomedByte & 0b00000100);
        byteBit5 = byteBit4;
        byteBit6 = (unzoomedByte & 0b00001000);
        byteBit7 = byteBit6;
        zoomedByte0 = (byteBit7<<4) | (byteBit6<<3) | (byteBit5<<3) |  (byteBit4<<2) | (byteBit3<<2) |  (byteBit2<<1) | (byteBit1<<1) | byteBit0;

        byteBit0 = (unzoomedByte & 0b00010000)>>4;    // calculates page 1 zoomed byte, a byte at a time with every function call
        byteBit1 = byteBit0;
        byteBit2 = (unzoomedByte & 0b00100000)>>4;
        byteBit3 = byteBit2;
        byteBit4 = (unzoomedByte & 0b01000000)>>4;
        byteBit5 = byteBit4;
        byteBit6 = (unzoomedByte & 0b10000000)>>4;
        byteBit7 = byteBit6;
 
        zoomedByte1 = (byteBit7<<4) | (byteBit6<<3) | (byteBit5<<3) |  (byteBit4<<2) | (byteBit3<<2) |  (byteBit2<<1) | (byteBit1<<1) | byteBit0;
   
        
        
        write_command(0x22);// set page address
        write_command(0x00);// set page start address 0
        write_command(0x15);// set page end address

        write_command(0xb3);// set page 3

        write_command(0x21);// set column address
        write_command(0x00);// col starts from 0
        write_command(127); // col ends at 127
        write_command(0x21);// set column address
        write_command(1+offset);// set column address
        write_data(zoomedByte0);

        write_command(0x22);// set page address
        write_command(0x00);// set page start address 0
        write_command(0x15);// set page end address

        write_command(0xb4);// set page 4

        write_command(0x21);// set column address
        write_command(0x00);// col starts from 0
        write_command(127); // col ends at 127
        write_command(0x21);// set column address
        write_command(1+offset);// set column address
        write_data(zoomedByte1);

        ptr++;
        offset= offset + 2; // SETC COLUMN ADDRESS OFFSET
	}
}
