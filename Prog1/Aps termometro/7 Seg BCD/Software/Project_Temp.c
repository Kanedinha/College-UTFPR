
#define cooler                  portc.rc0
#define button_up               portc.rc1
#define button_config           portc.rc2
#define button_down             portc.rc3
#define led_config              portc.rc4
#define data_display1           portd
#define data_display2           portb

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
                          cooler = 1;
                  }
                  else
                  {
                          cooler = 0;
                  }
          }
}

void config_pin()
{
          //configura sensor de temperatura
          trisa.ra0 = 1;
          porta.ra0 = 0;

          //configura display
          trisd = 0;
          data_display1 = 1;

          trisb = 0;
          data_display2 = 1;

          //configura botoes
          trisc.rc2 = 1;
          button_config = 1;

          trisc.rc1 = 1;
          button_up = 1;

          trisc.rc3 = 1;
          button_down = 1;

          //configura led
          trisc.rc4 = 0;
          led_config = 0;

          //configura cooler
          trisc.rc0 = 0;
          cooler = 0;
}

void display(unsigned char temp)
{
        unsigned char temp_display1 = 0;
          unsigned char temp_display2 = 0;

          temp_display1 = temp / 10;
          temp_display2 = temp % 10;

          data_display1 = temp_display1;
          data_display2 = temp_display2;
}

void config_temp()
{
        if(button_config == 0)
        {
                led_config = 1;
                display(temp_cooler);
                  delay_ms(300);
                  while(button_config == 1)
                  {
                          if(button_up == 0)
                          {
                                  temp_cooler ++;
                                  if(temp_cooler > 99)
                                  {
                                          temp_cooler = 0;
                                  }
                                  display(temp_cooler);
                                  delay_ms(300);
                          }
                          if(button_down == 0)
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
                  led_config = 0;
                  delay_ms(300);
          }
}