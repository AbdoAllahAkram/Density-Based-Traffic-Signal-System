#include <avr/io.h>
#include <util/delay.h>

#define setBit(Port,Pin) (Port)|= (1<<Pin)
#define clearBit(Port,Pin) (Port)&= ~(1<<Pin)
#define toggleBit(Port,Pin) (Port)^= (1<<Pin)
#define checkBit(Port,Pin) (Port)& (1<<Pin)

#define R1 PA0
#define Y1 PA1
#define G1 PA2
#define R2 PA3
#define Y2 PA4
#define G2 PA5

#define R3 PC0
#define Y3 PC1
#define G3 PC2
#define R4 PC3
#define Y4 PC4
#define G4 PC5


int main(void)
{
	DDRA = 0XFF;
	DDRC = 0XFF;
	DDRD = 0X00;
	setBit(DDRB, PB0);
	setBit(DDRB, PB1);
	setBit(DDRB, PB2);
	setBit(DDRB, PB3);
	while (1)
	{
		
		if((checkBit(PIND, PD0)))
		{
			while((checkBit(PIND, PD0)))
			{
				setBit(PORTA, R1);
				setBit(PORTA, R2);
				setBit(PORTC, Y3);
				setBit(PORTC, G4);
			}
		}
		
		else if((checkBit(PIND, PD1)))
		{
			while((checkBit(PIND, PD1)))
			{
				setBit(PORTA, R1);
				setBit(PORTC, R4);
				setBit(PORTA, Y2);
				setBit(PORTC, G3);
			}
		}
		else if((checkBit(PIND, PD2)))
		{
			while((checkBit(PIND, PD2)))
			{
				setBit(PORTC, R3);
				setBit(PORTC, R4);
				setBit(PORTA, Y1);
				setBit(PORTA, G2);
			}
		}
		else if((checkBit(PIND, PD3)))
		{
			while((checkBit(PIND, PD3)))
			{
				setBit(PORTC, R3);
				setBit(PORTA, R2);
				setBit(PORTC, Y4);
				setBit(PORTA, G1);
			}
		}
		else
		{
			
			setBit(PORTA, R1);
			setBit(PORTA, R2);
			setBit(PORTC, Y3);
			setBit(PORTC, G4);
			_delay_ms(2000);
			PORTA = 0x00;
			PORTC = 0x00;
		
			setBit(PORTA, R1);
			setBit(PORTC, R4);
			setBit(PORTA, Y2);
			setBit(PORTC, G3);
		
			_delay_ms(2000);
			PORTA = 0x00;
			PORTC = 0x00;
		
			setBit(PORTC, R3);
			setBit(PORTC, R4);
			setBit(PORTA, Y1);
			setBit(PORTA, G2);

			_delay_ms(2000);
			PORTA = 0x00;
			PORTC = 0x00;
		
			setBit(PORTC, R3);
			setBit(PORTA, R2);
			setBit(PORTC, Y4);
			setBit(PORTA, G1);
		
			_delay_ms(2000);
		
			PORTA = 0x00;
			PORTC = 0x00;

			
		}
		
	}
}

