#include <SPI.h>   
#define SPI_SS 10

void slaveSPI_Setup() 
{
   SPI.setDataMode(SPI_MODE0); 
   SPI.setBitOrder(MSBFIRST);
   SPI.setClockDivider(SPI_CLOCK_DIV4); 
   
   SPCR |= _BV(SPE);       
}   

unsigned char SPI_read() 
{
   while(!(SPSR & (1<<SPIF)));
   return SPDR; 
}

void setup() 
{
   Serial.begin(112500);
   slaveSPI_Setup(); 
}   

void loop() 
{
   unsigned char ch = SPI_read();
   Serial.println(ch);
} 
