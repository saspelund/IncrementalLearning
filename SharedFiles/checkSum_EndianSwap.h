#ifndef CALCCHECKSUM_ENDIANSWAP_H
#define CALCCHECKSUM_ENDIANSWAP_H

// This function calcualtes the 8-bit checksum for a set of bytes starting at <startAddress>
// and for a total of <numberOfElements>
unsigned char calcCheckSum( unsigned char * startAddress, int numberOfElements)
{
	unsigned int checkSum = 0;
	for (int i=0; i<numberOfElements; i++)
	{
		checkSum += (unsigned int)startAddress[i]; //assuming it is being passed less than 2^24-1 elements
	}
	
	return (unsigned char)(checkSum & 0xff);
}

//This function swaps the endianness of a single 32-bit value
void endian_swap_32(unsigned int & x)
{
    x = (x>>24) |
        ((x<<8) & 0x00FF0000) |
        ((x>>8) & 0x0000FF00) |
         (x<<24);
}
#endif //CALCCHECKSUM_ENDIANSWAP_H
