
#include<avr/io.h>
#include<util/delay.h>
void send(char send);
void ini();
char rec(void);


void main()
{
ini();
while(1)
{
usstrsend("AT");
_delay_ms(1000);
send(0x0d);
_delay_ms(1000);
usstrsend("ATD #enter your number;");
_delay_ms(1000);
send(0x0d);
_delay_ms(500000);
usstrsend("ATH");
_delay_ms(1000);
send(0x0d);
_delay_ms(1000);
_delay_ms(10000);




}

}

void usstrsend(char *str)
{
int i=0;
while(str[i]!='\0')
{
send(str[i]);
i++;
}
}

void ini()
{
  UBRRL=51;
 UBRRH=0;
 UCSRB=0x18;
 UCSRC=0x8e;
}
  void send(char send)
  {
    while((UCSRA & 0x20)==0);
	UDR=send;
	}

	char rec(void)
	{
	 while ((UCSRA & 0x80)==0);
	 return UDR;
	 }
