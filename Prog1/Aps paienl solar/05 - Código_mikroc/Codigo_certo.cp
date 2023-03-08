#line 1 "C:/Users/Emers/Desktop/UTFPR/1ºPeríodo/Prog1/Aps paienl solar/05 - Código_mikroc/Codigo_certo.c"
#line 23 "C:/Users/Emers/Desktop/UTFPR/1ºPeríodo/Prog1/Aps paienl solar/05 - Código_mikroc/Codigo_certo.c"
unsigned int LDR_1;
unsigned int LDR_2;
unsigned int LDR_3;
unsigned int LDR_4;
unsigned int posicao_x = 2;
unsigned int posicao_y = 2;

void analogico(){
 LDR_1 = ADC_read(0);
 LDR_1 = (LDR_1 * (5.0/1024.0));
 LDR_2 = ADC_read(1);
 LDR_2 = (LDR_2 * (5.0/1024.0));
 LDR_3 = ADC_read(2);
 LDR_3 = (LDR_3 * (5.0/1024.0));
 LDR_4 = ADC_read(3);
 LDR_4 = (LDR_4 * (5.0/1024.0));
}

void pin_config(){




 trisa.ra0 = 1;
 porta.ra0 = 0;


 trisa.ra1 = 1;
 porta.ra1 = 0;


 trisa.ra2 = 1;
 porta.ra2 = 0;


 trisa.ra3 = 1;
 porta.ra3 = 0;




 trisb.rb0 = 0;
  portb.rb0  = 0;


 trisb.rb1 = 0;
  portb.rb1  = 0;


 trisb.rb2 = 0;
  portb.rb2  = 0;


 trisb.rb3 = 0;
  portb.rb3  = 0;




 trisb.rb4 = 0;
  portb.rb4  = 0;


 trisb.rb5 = 0;
  portb.rb5  = 0;


 trisb.rb6 = 0;
  portb.rb6  = 0;


 trisb.rb7 = 0;
  portb.rb7  = 0;

 anselb = 0;
}

void sensor(){



 if(LDR_1 < LDR_2 && LDR_3 < LDR_4){
 if(LDR_1 <=  1.5  && LDR_3 <=  1.5 ){
 if(posicao_x >= 0 && posicao_x < 4){
 posicao_x++;
 }
 }
 }
 if(LDR_1 > LDR_2 && LDR_3 > LDR_4){
 if(LDR_2 <=  1.5  && LDR_4 <=  1.5 ){
 if(posicao_x > 0 && posicao_x <= 4){
 posicao_x--;
 }
 }
 }



 if(LDR_3 < LDR_1 && LDR_4 < LDR_2){
 if(LDR_3 <=  1.5  && LDR_4 <=  1.5 ){
 if(posicao_y > 0 && posicao_y <= 4){
 posicao_y--;
 }
 }
 }
 if(LDR_3 > LDR_1 && LDR_4 > LDR_2){
 if(LDR_1 <=  1.5  && LDR_2 <=  1.5 ){
 if(posicao_y >= 0 && posicao_y < 4){
 posicao_y++;
 }
 }
 }
}

void motor(posicao_x){



 if(posicao_x == 0){
  portb.rb4  = 0;
  portb.rb5  = 0;
  portb.rb6  = 0;
  portb.rb7  = 0;
  portb.rb4  = 1;
  portb.rb6  = 1;
 delay_ms( 200 );
 }
 if(posicao_x == 1){
  portb.rb4  = 0;
  portb.rb5  = 0;
  portb.rb6  = 0;
  portb.rb7  = 0;
  portb.rb4  = 1;
 delay_ms( 200 );
 }
 if(posicao_x == 2){
  portb.rb4  = 0;
  portb.rb5  = 0;
  portb.rb6  = 0;
  portb.rb7  = 0;
  portb.rb4  = 1;
  portb.rb5  = 1;
 delay_ms( 200 );
 }
 if(posicao_x == 3){
  portb.rb4  = 0;
  portb.rb5  = 0;
  portb.rb6  = 0;
  portb.rb7  = 0;
  portb.rb5  = 1;
 delay_ms( 200 );
 }
 if(posicao_x == 4){
  portb.rb4  = 0;
  portb.rb5  = 0;
  portb.rb6  = 0;
  portb.rb7  = 0;
  portb.rb5  = 1;
  portb.rb7  = 1;
 delay_ms( 200 );
 }



 if(posicao_y == 0){
  portb.rb0  = 0;
  portb.rb1  = 0;
  portb.rb2  = 0;
  portb.rb3  = 0;
  portb.rb0  = 1;
  portb.rb2  = 1;
 delay_ms( 200 );
 }
 if(posicao_y == 1){
  portb.rb0  = 0;
  portb.rb1  = 0;
  portb.rb2  = 0;
  portb.rb3  = 0;
  portb.rb0  = 1;
 delay_ms( 200 );
 }
 if(posicao_y == 2){
  portb.rb0  = 0;
  portb.rb1  = 0;
  portb.rb2  = 0;
  portb.rb3  = 0;
  portb.rb0  = 1;
  portb.rb1  = 1;
 delay_ms( 200 );
 }
 if(posicao_y == 3){
  portb.rb0  = 0;
  portb.rb1  = 0;
  portb.rb2  = 0;
  portb.rb3  = 0;
  portb.rb1  = 1;
 delay_ms( 200 );
 }
 if(posicao_y == 4){
  portb.rb0  = 0;
  portb.rb1  = 0;
  portb.rb2  = 0;
  portb.rb3  = 0;
  portb.rb1  = 1;
  portb.rb3  = 1;
 delay_ms( 200 );
 }
}

void main() {
 ADC_init();
 pin_config();
 while (1){
 analogico();
 sensor();
 motor();
 }
}
