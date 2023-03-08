
#define sensor_1        porta.ra0
#define sendor_2        porta.ra1
#define sendor_3        porta.ra2
#define sendor_4        porta.ra3
#define motor_y         portb.rb0
#define motor_y         portb.rb1
#define motor_y         portb.rb2
#define motor_y         portb.rb3
#define motor_x         portb.rb4
#define motor_x         portb.rb5
#define motor_x         portb.rb6
#define motor_x         portb.rb7

void pinagem();

void main() {

}

void pinagem(){
     // sensores LDR
     // sensor 1
     porta.ra0 = 1;
     porta.ra0 = 0;
     // sensor 2
     porta.ra1 = 1;
     porta.ra1 = 0;
     // sensor 3
     porta.ra2 = 1;
     porta.ra2 = 0;
     // sensor 4
     porta.ra3 = 1;
     porta.ra3 = 0;
     //
}
