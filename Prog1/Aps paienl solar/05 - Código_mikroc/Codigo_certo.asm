
_analogico:

;Codigo_certo.c,30 :: 		void analogico(){
;Codigo_certo.c,31 :: 		LDR_1 = ADC_read(0);
	CLRF        FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_1+0 
	MOVF        R1, 0 
	MOVWF       _LDR_1+1 
;Codigo_certo.c,32 :: 		LDR_1 = (LDR_1 * (5.0/1024.0));
	CALL        _word2double+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       32
	MOVWF       R6 
	MOVLW       119
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_1+0 
	MOVF        R1, 0 
	MOVWF       _LDR_1+1 
;Codigo_certo.c,33 :: 		LDR_2 = ADC_read(1);
	MOVLW       1
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_2+0 
	MOVF        R1, 0 
	MOVWF       _LDR_2+1 
;Codigo_certo.c,34 :: 		LDR_2 = (LDR_2 * (5.0/1024.0));
	CALL        _word2double+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       32
	MOVWF       R6 
	MOVLW       119
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_2+0 
	MOVF        R1, 0 
	MOVWF       _LDR_2+1 
;Codigo_certo.c,35 :: 		LDR_3 = ADC_read(2);
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_3+0 
	MOVF        R1, 0 
	MOVWF       _LDR_3+1 
;Codigo_certo.c,36 :: 		LDR_3 = (LDR_3 * (5.0/1024.0));
	CALL        _word2double+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       32
	MOVWF       R6 
	MOVLW       119
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_3+0 
	MOVF        R1, 0 
	MOVWF       _LDR_3+1 
;Codigo_certo.c,37 :: 		LDR_4 = ADC_read(3);
	MOVLW       3
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_4+0 
	MOVF        R1, 0 
	MOVWF       _LDR_4+1 
;Codigo_certo.c,38 :: 		LDR_4 = (LDR_4 * (5.0/1024.0));
	CALL        _word2double+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       32
	MOVWF       R6 
	MOVLW       119
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _LDR_4+0 
	MOVF        R1, 0 
	MOVWF       _LDR_4+1 
;Codigo_certo.c,39 :: 		}
L_end_analogico:
	RETURN      0
; end of _analogico

_pin_config:

;Codigo_certo.c,41 :: 		void pin_config(){
;Codigo_certo.c,46 :: 		trisa.ra0 = 1;   //define como entrada(1) ou saída(0)
	BSF         TRISA+0, 0 
;Codigo_certo.c,47 :: 		porta.ra0 = 0;   //situação atual, desligado(0) ou ligado(1)
	BCF         PORTA+0, 0 
;Codigo_certo.c,50 :: 		trisa.ra1 = 1;
	BSF         TRISA+0, 1 
;Codigo_certo.c,51 :: 		porta.ra1 = 0;
	BCF         PORTA+0, 1 
;Codigo_certo.c,54 :: 		trisa.ra2 = 1;
	BSF         TRISA+0, 2 
;Codigo_certo.c,55 :: 		porta.ra2 = 0;
	BCF         PORTA+0, 2 
;Codigo_certo.c,58 :: 		trisa.ra3 = 1;
	BSF         TRISA+0, 3 
;Codigo_certo.c,59 :: 		porta.ra3 = 0;
	BCF         PORTA+0, 3 
;Codigo_certo.c,64 :: 		trisb.rb0 = 0;
	BCF         TRISB+0, 0 
;Codigo_certo.c,65 :: 		motor_y1 = 0;
	BCF         PORTB+0, 0 
;Codigo_certo.c,68 :: 		trisb.rb1 = 0;
	BCF         TRISB+0, 1 
;Codigo_certo.c,69 :: 		motor_y2 = 0;
	BCF         PORTB+0, 1 
;Codigo_certo.c,72 :: 		trisb.rb2 = 0;
	BCF         TRISB+0, 2 
;Codigo_certo.c,73 :: 		motor_y3 = 0;
	BCF         PORTB+0, 2 
;Codigo_certo.c,76 :: 		trisb.rb3 = 0;
	BCF         TRISB+0, 3 
;Codigo_certo.c,77 :: 		motor_y4 = 0;
	BCF         PORTB+0, 3 
;Codigo_certo.c,82 :: 		trisb.rb4 = 0;
	BCF         TRISB+0, 4 
;Codigo_certo.c,83 :: 		motor_x1 = 0;
	BCF         PORTB+0, 4 
;Codigo_certo.c,86 :: 		trisb.rb5 = 0;
	BCF         TRISB+0, 5 
;Codigo_certo.c,87 :: 		motor_x2 = 0;
	BCF         PORTB+0, 5 
;Codigo_certo.c,90 :: 		trisb.rb6 = 0;
	BCF         TRISB+0, 6 
;Codigo_certo.c,91 :: 		motor_x3 = 0;
	BCF         PORTB+0, 6 
;Codigo_certo.c,94 :: 		trisb.rb7 = 0;
	BCF         TRISB+0, 7 
;Codigo_certo.c,95 :: 		motor_x4 = 0;
	BCF         PORTB+0, 7 
;Codigo_certo.c,97 :: 		anselb = 0;
	CLRF        ANSELB+0 
;Codigo_certo.c,98 :: 		}
L_end_pin_config:
	RETURN      0
; end of _pin_config

_sensor:

;Codigo_certo.c,100 :: 		void sensor(){
;Codigo_certo.c,104 :: 		if(LDR_1 < LDR_2 && LDR_3 < LDR_4){
	MOVF        _LDR_2+1, 0 
	SUBWF       _LDR_1+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor73
	MOVF        _LDR_2+0, 0 
	SUBWF       _LDR_1+0, 0 
L__sensor73:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor2
	MOVF        _LDR_4+1, 0 
	SUBWF       _LDR_3+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor74
	MOVF        _LDR_4+0, 0 
	SUBWF       _LDR_3+0, 0 
L__sensor74:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor2
L__sensor69:
;Codigo_certo.c,105 :: 		if(LDR_1 <= sol && LDR_3 <= sol){
	MOVF        _LDR_1+0, 0 
	MOVWF       R0 
	MOVF        _LDR_1+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor5
	MOVF        _LDR_3+0, 0 
	MOVWF       R0 
	MOVF        _LDR_3+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor5
L__sensor68:
;Codigo_certo.c,106 :: 		if(posicao_x >= 0 && posicao_x < 4){
	MOVLW       0
	SUBWF       _posicao_x+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor75
	MOVLW       0
	SUBWF       _posicao_x+0, 0 
L__sensor75:
	BTFSS       STATUS+0, 0 
	GOTO        L_sensor8
	MOVLW       0
	SUBWF       _posicao_x+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor76
	MOVLW       4
	SUBWF       _posicao_x+0, 0 
L__sensor76:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor8
L__sensor67:
;Codigo_certo.c,107 :: 		posicao_x++;
	INFSNZ      _posicao_x+0, 1 
	INCF        _posicao_x+1, 1 
;Codigo_certo.c,108 :: 		}
L_sensor8:
;Codigo_certo.c,109 :: 		}
L_sensor5:
;Codigo_certo.c,110 :: 		}
L_sensor2:
;Codigo_certo.c,111 :: 		if(LDR_1 > LDR_2 && LDR_3 > LDR_4){
	MOVF        _LDR_1+1, 0 
	SUBWF       _LDR_2+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor77
	MOVF        _LDR_1+0, 0 
	SUBWF       _LDR_2+0, 0 
L__sensor77:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor11
	MOVF        _LDR_3+1, 0 
	SUBWF       _LDR_4+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor78
	MOVF        _LDR_3+0, 0 
	SUBWF       _LDR_4+0, 0 
L__sensor78:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor11
L__sensor66:
;Codigo_certo.c,112 :: 		if(LDR_2 <= sol && LDR_4 <= sol){
	MOVF        _LDR_2+0, 0 
	MOVWF       R0 
	MOVF        _LDR_2+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor14
	MOVF        _LDR_4+0, 0 
	MOVWF       R0 
	MOVF        _LDR_4+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor14
L__sensor65:
;Codigo_certo.c,113 :: 		if(posicao_x > 0 && posicao_x <= 4){
	MOVLW       0
	MOVWF       R0 
	MOVF        _posicao_x+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor79
	MOVF        _posicao_x+0, 0 
	SUBLW       0
L__sensor79:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor17
	MOVLW       0
	MOVWF       R0 
	MOVF        _posicao_x+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor80
	MOVF        _posicao_x+0, 0 
	SUBLW       4
L__sensor80:
	BTFSS       STATUS+0, 0 
	GOTO        L_sensor17
L__sensor64:
;Codigo_certo.c,114 :: 		posicao_x--;
	MOVLW       1
	SUBWF       _posicao_x+0, 1 
	MOVLW       0
	SUBWFB      _posicao_x+1, 1 
;Codigo_certo.c,115 :: 		}
L_sensor17:
;Codigo_certo.c,116 :: 		}
L_sensor14:
;Codigo_certo.c,117 :: 		}
L_sensor11:
;Codigo_certo.c,121 :: 		if(LDR_3 < LDR_1 && LDR_4 < LDR_2){
	MOVF        _LDR_1+1, 0 
	SUBWF       _LDR_3+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor81
	MOVF        _LDR_1+0, 0 
	SUBWF       _LDR_3+0, 0 
L__sensor81:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor20
	MOVF        _LDR_2+1, 0 
	SUBWF       _LDR_4+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor82
	MOVF        _LDR_2+0, 0 
	SUBWF       _LDR_4+0, 0 
L__sensor82:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor20
L__sensor63:
;Codigo_certo.c,122 :: 		if(LDR_3 <= sol && LDR_4 <= sol){
	MOVF        _LDR_3+0, 0 
	MOVWF       R0 
	MOVF        _LDR_3+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor23
	MOVF        _LDR_4+0, 0 
	MOVWF       R0 
	MOVF        _LDR_4+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor23
L__sensor62:
;Codigo_certo.c,123 :: 		if(posicao_y > 0 && posicao_y <= 4){
	MOVLW       0
	MOVWF       R0 
	MOVF        _posicao_y+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor83
	MOVF        _posicao_y+0, 0 
	SUBLW       0
L__sensor83:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor26
	MOVLW       0
	MOVWF       R0 
	MOVF        _posicao_y+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor84
	MOVF        _posicao_y+0, 0 
	SUBLW       4
L__sensor84:
	BTFSS       STATUS+0, 0 
	GOTO        L_sensor26
L__sensor61:
;Codigo_certo.c,124 :: 		posicao_y--;
	MOVLW       1
	SUBWF       _posicao_y+0, 1 
	MOVLW       0
	SUBWFB      _posicao_y+1, 1 
;Codigo_certo.c,125 :: 		}
L_sensor26:
;Codigo_certo.c,126 :: 		}
L_sensor23:
;Codigo_certo.c,127 :: 		}
L_sensor20:
;Codigo_certo.c,128 :: 		if(LDR_3 > LDR_1 && LDR_4 > LDR_2){
	MOVF        _LDR_3+1, 0 
	SUBWF       _LDR_1+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor85
	MOVF        _LDR_3+0, 0 
	SUBWF       _LDR_1+0, 0 
L__sensor85:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor29
	MOVF        _LDR_4+1, 0 
	SUBWF       _LDR_2+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor86
	MOVF        _LDR_4+0, 0 
	SUBWF       _LDR_2+0, 0 
L__sensor86:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor29
L__sensor60:
;Codigo_certo.c,129 :: 		if(LDR_1 <= sol && LDR_2 <= sol){
	MOVF        _LDR_1+0, 0 
	MOVWF       R0 
	MOVF        _LDR_1+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor32
	MOVF        _LDR_2+0, 0 
	MOVWF       R0 
	MOVF        _LDR_2+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       64
	MOVWF       R2 
	MOVLW       127
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       0
	BTFSC       STATUS+0, 0 
	MOVLW       1
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_sensor32
L__sensor59:
;Codigo_certo.c,130 :: 		if(posicao_y >= 0 && posicao_y < 4){
	MOVLW       0
	SUBWF       _posicao_y+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor87
	MOVLW       0
	SUBWF       _posicao_y+0, 0 
L__sensor87:
	BTFSS       STATUS+0, 0 
	GOTO        L_sensor35
	MOVLW       0
	SUBWF       _posicao_y+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__sensor88
	MOVLW       4
	SUBWF       _posicao_y+0, 0 
L__sensor88:
	BTFSC       STATUS+0, 0 
	GOTO        L_sensor35
L__sensor58:
;Codigo_certo.c,131 :: 		posicao_y++;
	INFSNZ      _posicao_y+0, 1 
	INCF        _posicao_y+1, 1 
;Codigo_certo.c,132 :: 		}
L_sensor35:
;Codigo_certo.c,133 :: 		}
L_sensor32:
;Codigo_certo.c,134 :: 		}
L_sensor29:
;Codigo_certo.c,135 :: 		}
L_end_sensor:
	RETURN      0
; end of _sensor

_motor:

;Codigo_certo.c,137 :: 		void motor(posicao_x){
;Codigo_certo.c,141 :: 		if(posicao_x == 0){
	MOVLW       0
	XORWF       _posicao_x+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor90
	MOVLW       0
	XORWF       _posicao_x+0, 0 
L__motor90:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor36
;Codigo_certo.c,142 :: 		motor_x1 = 0;
	BCF         PORTB+0, 4 
;Codigo_certo.c,143 :: 		motor_x2 = 0;
	BCF         PORTB+0, 5 
;Codigo_certo.c,144 :: 		motor_x3 = 0;
	BCF         PORTB+0, 6 
;Codigo_certo.c,145 :: 		motor_x4 = 0;
	BCF         PORTB+0, 7 
;Codigo_certo.c,146 :: 		motor_x1 = 1;
	BSF         PORTB+0, 4 
;Codigo_certo.c,147 :: 		motor_x3 = 1;
	BSF         PORTB+0, 6 
;Codigo_certo.c,148 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor37:
	DECFSZ      R13, 1, 1
	BRA         L_motor37
	DECFSZ      R12, 1, 1
	BRA         L_motor37
	DECFSZ      R11, 1, 1
	BRA         L_motor37
;Codigo_certo.c,149 :: 		}
L_motor36:
;Codigo_certo.c,150 :: 		if(posicao_x == 1){
	MOVLW       0
	XORWF       _posicao_x+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor91
	MOVLW       1
	XORWF       _posicao_x+0, 0 
L__motor91:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor38
;Codigo_certo.c,151 :: 		motor_x1 = 0;
	BCF         PORTB+0, 4 
;Codigo_certo.c,152 :: 		motor_x2 = 0;
	BCF         PORTB+0, 5 
;Codigo_certo.c,153 :: 		motor_x3 = 0;
	BCF         PORTB+0, 6 
;Codigo_certo.c,154 :: 		motor_x4 = 0;
	BCF         PORTB+0, 7 
;Codigo_certo.c,155 :: 		motor_x1 = 1;
	BSF         PORTB+0, 4 
;Codigo_certo.c,156 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor39:
	DECFSZ      R13, 1, 1
	BRA         L_motor39
	DECFSZ      R12, 1, 1
	BRA         L_motor39
	DECFSZ      R11, 1, 1
	BRA         L_motor39
;Codigo_certo.c,157 :: 		}
L_motor38:
;Codigo_certo.c,158 :: 		if(posicao_x == 2){
	MOVLW       0
	XORWF       _posicao_x+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor92
	MOVLW       2
	XORWF       _posicao_x+0, 0 
L__motor92:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor40
;Codigo_certo.c,159 :: 		motor_x1 = 0;
	BCF         PORTB+0, 4 
;Codigo_certo.c,160 :: 		motor_x2 = 0;
	BCF         PORTB+0, 5 
;Codigo_certo.c,161 :: 		motor_x3 = 0;
	BCF         PORTB+0, 6 
;Codigo_certo.c,162 :: 		motor_x4 = 0;
	BCF         PORTB+0, 7 
;Codigo_certo.c,163 :: 		motor_x1 = 1;
	BSF         PORTB+0, 4 
;Codigo_certo.c,164 :: 		motor_x2 = 1;
	BSF         PORTB+0, 5 
;Codigo_certo.c,165 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor41:
	DECFSZ      R13, 1, 1
	BRA         L_motor41
	DECFSZ      R12, 1, 1
	BRA         L_motor41
	DECFSZ      R11, 1, 1
	BRA         L_motor41
;Codigo_certo.c,166 :: 		}
L_motor40:
;Codigo_certo.c,167 :: 		if(posicao_x == 3){
	MOVLW       0
	XORWF       _posicao_x+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor93
	MOVLW       3
	XORWF       _posicao_x+0, 0 
L__motor93:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor42
;Codigo_certo.c,168 :: 		motor_x1 = 0;
	BCF         PORTB+0, 4 
;Codigo_certo.c,169 :: 		motor_x2 = 0;
	BCF         PORTB+0, 5 
;Codigo_certo.c,170 :: 		motor_x3 = 0;
	BCF         PORTB+0, 6 
;Codigo_certo.c,171 :: 		motor_x4 = 0;
	BCF         PORTB+0, 7 
;Codigo_certo.c,172 :: 		motor_x2 = 1;
	BSF         PORTB+0, 5 
;Codigo_certo.c,173 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor43:
	DECFSZ      R13, 1, 1
	BRA         L_motor43
	DECFSZ      R12, 1, 1
	BRA         L_motor43
	DECFSZ      R11, 1, 1
	BRA         L_motor43
;Codigo_certo.c,174 :: 		}
L_motor42:
;Codigo_certo.c,175 :: 		if(posicao_x == 4){
	MOVLW       0
	XORWF       _posicao_x+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor94
	MOVLW       4
	XORWF       _posicao_x+0, 0 
L__motor94:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor44
;Codigo_certo.c,176 :: 		motor_x1 = 0;
	BCF         PORTB+0, 4 
;Codigo_certo.c,177 :: 		motor_x2 = 0;
	BCF         PORTB+0, 5 
;Codigo_certo.c,178 :: 		motor_x3 = 0;
	BCF         PORTB+0, 6 
;Codigo_certo.c,179 :: 		motor_x4 = 0;
	BCF         PORTB+0, 7 
;Codigo_certo.c,180 :: 		motor_x2 = 1;
	BSF         PORTB+0, 5 
;Codigo_certo.c,181 :: 		motor_x4 = 1;
	BSF         PORTB+0, 7 
;Codigo_certo.c,182 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor45:
	DECFSZ      R13, 1, 1
	BRA         L_motor45
	DECFSZ      R12, 1, 1
	BRA         L_motor45
	DECFSZ      R11, 1, 1
	BRA         L_motor45
;Codigo_certo.c,183 :: 		}
L_motor44:
;Codigo_certo.c,187 :: 		if(posicao_y == 0){
	MOVLW       0
	XORWF       _posicao_y+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor95
	MOVLW       0
	XORWF       _posicao_y+0, 0 
L__motor95:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor46
;Codigo_certo.c,188 :: 		motor_y1 = 0;
	BCF         PORTB+0, 0 
;Codigo_certo.c,189 :: 		motor_y2 = 0;
	BCF         PORTB+0, 1 
;Codigo_certo.c,190 :: 		motor_y3 = 0;
	BCF         PORTB+0, 2 
;Codigo_certo.c,191 :: 		motor_y4 = 0;
	BCF         PORTB+0, 3 
;Codigo_certo.c,192 :: 		motor_y1 = 1;
	BSF         PORTB+0, 0 
;Codigo_certo.c,193 :: 		motor_y3 = 1;
	BSF         PORTB+0, 2 
;Codigo_certo.c,194 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor47:
	DECFSZ      R13, 1, 1
	BRA         L_motor47
	DECFSZ      R12, 1, 1
	BRA         L_motor47
	DECFSZ      R11, 1, 1
	BRA         L_motor47
;Codigo_certo.c,195 :: 		}
L_motor46:
;Codigo_certo.c,196 :: 		if(posicao_y == 1){
	MOVLW       0
	XORWF       _posicao_y+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor96
	MOVLW       1
	XORWF       _posicao_y+0, 0 
L__motor96:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor48
;Codigo_certo.c,197 :: 		motor_y1 = 0;
	BCF         PORTB+0, 0 
;Codigo_certo.c,198 :: 		motor_y2 = 0;
	BCF         PORTB+0, 1 
;Codigo_certo.c,199 :: 		motor_y3 = 0;
	BCF         PORTB+0, 2 
;Codigo_certo.c,200 :: 		motor_y4 = 0;
	BCF         PORTB+0, 3 
;Codigo_certo.c,201 :: 		motor_y1 = 1;
	BSF         PORTB+0, 0 
;Codigo_certo.c,202 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor49:
	DECFSZ      R13, 1, 1
	BRA         L_motor49
	DECFSZ      R12, 1, 1
	BRA         L_motor49
	DECFSZ      R11, 1, 1
	BRA         L_motor49
;Codigo_certo.c,203 :: 		}
L_motor48:
;Codigo_certo.c,204 :: 		if(posicao_y == 2){
	MOVLW       0
	XORWF       _posicao_y+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor97
	MOVLW       2
	XORWF       _posicao_y+0, 0 
L__motor97:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor50
;Codigo_certo.c,205 :: 		motor_y1 = 0;
	BCF         PORTB+0, 0 
;Codigo_certo.c,206 :: 		motor_y2 = 0;
	BCF         PORTB+0, 1 
;Codigo_certo.c,207 :: 		motor_y3 = 0;
	BCF         PORTB+0, 2 
;Codigo_certo.c,208 :: 		motor_y4 = 0;
	BCF         PORTB+0, 3 
;Codigo_certo.c,209 :: 		motor_y1 = 1;
	BSF         PORTB+0, 0 
;Codigo_certo.c,210 :: 		motor_y2 = 1;
	BSF         PORTB+0, 1 
;Codigo_certo.c,211 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor51:
	DECFSZ      R13, 1, 1
	BRA         L_motor51
	DECFSZ      R12, 1, 1
	BRA         L_motor51
	DECFSZ      R11, 1, 1
	BRA         L_motor51
;Codigo_certo.c,212 :: 		}
L_motor50:
;Codigo_certo.c,213 :: 		if(posicao_y == 3){
	MOVLW       0
	XORWF       _posicao_y+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor98
	MOVLW       3
	XORWF       _posicao_y+0, 0 
L__motor98:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor52
;Codigo_certo.c,214 :: 		motor_y1 = 0;
	BCF         PORTB+0, 0 
;Codigo_certo.c,215 :: 		motor_y2 = 0;
	BCF         PORTB+0, 1 
;Codigo_certo.c,216 :: 		motor_y3 = 0;
	BCF         PORTB+0, 2 
;Codigo_certo.c,217 :: 		motor_y4 = 0;
	BCF         PORTB+0, 3 
;Codigo_certo.c,218 :: 		motor_y2 = 1;
	BSF         PORTB+0, 1 
;Codigo_certo.c,219 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor53:
	DECFSZ      R13, 1, 1
	BRA         L_motor53
	DECFSZ      R12, 1, 1
	BRA         L_motor53
	DECFSZ      R11, 1, 1
	BRA         L_motor53
;Codigo_certo.c,220 :: 		}
L_motor52:
;Codigo_certo.c,221 :: 		if(posicao_y == 4){
	MOVLW       0
	XORWF       _posicao_y+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__motor99
	MOVLW       4
	XORWF       _posicao_y+0, 0 
L__motor99:
	BTFSS       STATUS+0, 2 
	GOTO        L_motor54
;Codigo_certo.c,222 :: 		motor_y1 = 0;
	BCF         PORTB+0, 0 
;Codigo_certo.c,223 :: 		motor_y2 = 0;
	BCF         PORTB+0, 1 
;Codigo_certo.c,224 :: 		motor_y3 = 0;
	BCF         PORTB+0, 2 
;Codigo_certo.c,225 :: 		motor_y4 = 0;
	BCF         PORTB+0, 3 
;Codigo_certo.c,226 :: 		motor_y2 = 1;
	BSF         PORTB+0, 1 
;Codigo_certo.c,227 :: 		motor_y4 = 1;
	BSF         PORTB+0, 3 
;Codigo_certo.c,228 :: 		delay_ms(temp);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       8
	MOVWF       R12, 0
	MOVLW       119
	MOVWF       R13, 0
L_motor55:
	DECFSZ      R13, 1, 1
	BRA         L_motor55
	DECFSZ      R12, 1, 1
	BRA         L_motor55
	DECFSZ      R11, 1, 1
	BRA         L_motor55
;Codigo_certo.c,229 :: 		}
L_motor54:
;Codigo_certo.c,230 :: 		}
L_end_motor:
	RETURN      0
; end of _motor

_main:

;Codigo_certo.c,232 :: 		void main() {
;Codigo_certo.c,233 :: 		ADC_init();
	CALL        _ADC_Init+0, 0
;Codigo_certo.c,234 :: 		pin_config();
	CALL        _pin_config+0, 0
;Codigo_certo.c,235 :: 		while (1){
L_main56:
;Codigo_certo.c,236 :: 		analogico();
	CALL        _analogico+0, 0
;Codigo_certo.c,237 :: 		sensor();
	CALL        _sensor+0, 0
;Codigo_certo.c,238 :: 		motor();
	CALL        _motor+0, 0
;Codigo_certo.c,239 :: 		}
	GOTO        L_main56
;Codigo_certo.c,240 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
