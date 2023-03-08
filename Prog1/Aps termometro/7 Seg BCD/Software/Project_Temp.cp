#line 1 "C:/Users/Emers/Desktop/UTFPR/Prog1/APS/7 Seg BCD/Software/Project_Temp.c"









void config_pin();
void display(unsigned char temp);
void config_temp();

unsigned char temp_current = 0;
unsigned char temp_past = 0;
unsigned char temp_cooler = 30;


void main()
{
 config_pin();
 ADC_Init();
 delay_ms(100);

 display(0);
 delay_ms(500);

 while(1)
 {
 temp_current = ADC_Read(0);
 temp_current = (temp_current * ((5.0/1024.0) * 100.0));
 if(temp_current != temp_past)
 {
 temp_past = temp_current;
 display(temp_current);
 }
 config_temp();
 if(temp_current >= temp_cooler)
 {
  portc.rc0  = 1;
 }
 else
 {
  portc.rc0  = 0;
 }
 }
}

void config_pin()
{

 trisa.ra0 = 1;
 porta.ra0 = 0;


 trisd = 0;
  portd  = 1;

 trisb = 0;
  portb  = 1;


 trisc.rc2 = 1;
  portc.rc2  = 1;

 trisc.rc1 = 1;
  portc.rc1  = 1;

 trisc.rc3 = 1;
  portc.rc3  = 1;


 trisc.rc4 = 0;
  portc.rc4  = 0;


 trisc.rc0 = 0;
  portc.rc0  = 0;
}

void display(unsigned char temp)
{
 unsigned char temp_display1 = 0;
 unsigned char temp_display2 = 0;

 temp_display1 = temp / 10;
 temp_display2 = temp % 10;

  portd  = temp_display1;
  portb  = temp_display2;
}

void config_temp()
{
 if( portc.rc2  == 0)
 {
  portc.rc4  = 1;
 display(temp_cooler);
 delay_ms(300);
 while( portc.rc2  == 1)
 {
 if( portc.rc1  == 0)
 {
 temp_cooler ++;
 if(temp_cooler > 99)
 {
 temp_cooler = 0;
 }
 display(temp_cooler);
 delay_ms(300);
 }
 if( portc.rc3  == 0)
 {
 temp_cooler --;
 if(temp_cooler < 0)
 {
 temp_cooler = 99;
 }
 display(temp_cooler);
 delay_ms(300);
 }
 }
 display(temp_current);
  portc.rc4  = 0;
 delay_ms(300);
 }
}
