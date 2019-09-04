/*De manera predeteriminada esta ajustado el codigo para usarlo con un
PIC18f4550,pero es posible adaptarlo a otros pic, definiendo los pines
de DAC_CS, DAC_CLK y DAC_DATA desde el codigo principal.

Las funciones disponibles son las siguientes:

DAC_init(); inicializa el DAC
DAC_a(valor); manda datos de salida al OUTA
DAC_b(valor); manda datos de salida al OUTB


*/



#ifndef  DAC_CS
   #define DAC_CS  PIN_A1
#endif

#ifndef  DAC_CLK
   #define DAC_CLK  PIN_B1
#endif

#ifndef  DAC_DATA
   #define DAC_DATA  PIN_C7
#endif

void DAC_init(void)
{
output_low(DAC_DATA);
output_low(DAC_CLK);
output_high(DAC_CS);
}

void DAC_a(int16 voltaje_a)
{
char valora;
valora= (voltaje_a >> 8) & 0x0F;
valora=valora |0x70;
output_low(DAC_CS);
spi_write(valora);
valora=voltaje_a;
spi_write(valora);
output_high(DAC_CS);

}

void DAC_b(int16 voltaje_b)
{

char valorb;
valorb= (voltaje_b >> 8) & 0x0F;
valorb=valorb |0xF0;
output_low(DAC_CS);
spi_write(valorb);
valorb=voltaje_b;
spi_write(valorb);
output_high(DAC_CS);

}



