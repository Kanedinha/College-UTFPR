
_main:

;Project_Temp.c,19 :: 		void main()
;Project_Temp.c,21 :: 		config_pin();
	CALL       _config_pin+0
;Project_Temp.c,22 :: 		ADC_Init();
	CALL       _ADC_Init+0
;Project_Temp.c,23 :: 		delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	DECFSZ     R11+0, 1
	GOTO       L_main0
	NOP
;Project_Temp.c,25 :: 		display(0);
	CLRF       FARG_display_temp+0
	CALL       _display+0
;Project_Temp.c,26 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main1:
	DECFSZ     R13+0, 1
	GOTO       L_main1
	DECFSZ     R12+0, 1
	GOTO       L_main1
	DECFSZ     R11+0, 1
	GOTO       L_main1
	NOP
	NOP
;Project_Temp.c,28 :: 		while(1)
L_main2:
;Project_Temp.c,30 :: 		temp_current = ADC_Read(0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	MOVF       R0+0, 0
	MOVWF      _temp_current+0
;Project_Temp.c,31 :: 		temp_current = (temp_current * ((5.0/1024.0) * 100.0));
	CALL       _byte2double+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      122
	MOVWF      R4+2
	MOVLW      125
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	CALL       _double2byte+0
	MOVF       R0+0, 0
	MOVWF      _temp_current+0
;Project_Temp.c,32 :: 		if(temp_current != temp_past)
	MOVF       R0+0, 0
	XORWF      _temp_past+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main4
;Project_Temp.c,34 :: 		temp_past = temp_current;
	MOVF       _temp_current+0, 0
	MOVWF      _temp_past+0
;Project_Temp.c,35 :: 		display(temp_current);
	MOVF       _temp_current+0, 0
	MOVWF      FARG_display_temp+0
	CALL       _display+0
;Project_Temp.c,36 :: 		}
L_main4:
;Project_Temp.c,37 :: 		config_temp();
	CALL       _config_temp+0
;Project_Temp.c,38 :: 		if(temp_current >= temp_cooler)
	MOVF       _temp_cooler+0, 0
	SUBWF      _temp_current+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_main5
;Project_Temp.c,40 :: 		cooler = 1;
	BSF        PORTC+0, 0
;Project_Temp.c,41 :: 		}
	GOTO       L_main6
L_main5:
;Project_Temp.c,44 :: 		cooler = 0;
	BCF        PORTC+0, 0
;Project_Temp.c,45 :: 		}
L_main6:
;Project_Temp.c,46 :: 		}
	GOTO       L_main2
;Project_Temp.c,47 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_config_pin:

;Project_Temp.c,49 :: 		void config_pin()
;Project_Temp.c,52 :: 		trisa.ra0 = 1;
	BSF        TRISA+0, 0
;Project_Temp.c,53 :: 		porta.ra0 = 0;
	BCF        PORTA+0, 0
;Project_Temp.c,56 :: 		trisd = 0;
	CLRF       TRISD+0
;Project_Temp.c,57 :: 		data_display1 = 1;
	MOVLW      1
	MOVWF      PORTD+0
;Project_Temp.c,59 :: 		trisb = 0;
	CLRF       TRISB+0
;Project_Temp.c,60 :: 		data_display2 = 1;
	MOVLW      1
	MOVWF      PORTB+0
;Project_Temp.c,63 :: 		trisc.rc2 = 1;
	BSF        TRISC+0, 2
;Project_Temp.c,64 :: 		button_config = 1;
	BSF        PORTC+0, 2
;Project_Temp.c,66 :: 		trisc.rc1 = 1;
	BSF        TRISC+0, 1
;Project_Temp.c,67 :: 		button_up = 1;
	BSF        PORTC+0, 1
;Project_Temp.c,69 :: 		trisc.rc3 = 1;
	BSF        TRISC+0, 3
;Project_Temp.c,70 :: 		button_down = 1;
	BSF        PORTC+0, 3
;Project_Temp.c,73 :: 		trisc.rc4 = 0;
	BCF        TRISC+0, 4
;Project_Temp.c,74 :: 		led_config = 0;
	BCF        PORTC+0, 4
;Project_Temp.c,77 :: 		trisc.rc0 = 0;
	BCF        TRISC+0, 0
;Project_Temp.c,78 :: 		cooler = 0;
	BCF        PORTC+0, 0
;Project_Temp.c,79 :: 		}
L_end_config_pin:
	RETURN
; end of _config_pin

_display:

;Project_Temp.c,81 :: 		void display(unsigned char temp)
;Project_Temp.c,83 :: 		unsigned char temp_display1 = 0;
;Project_Temp.c,84 :: 		unsigned char temp_display2 = 0;
;Project_Temp.c,86 :: 		temp_display1 = temp / 10;
	MOVLW      10
	MOVWF      R4+0
	MOVF       FARG_display_temp+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_U+0
	MOVF       R0+0, 0
	MOVWF      FLOC__display+0
	MOVLW      10
	MOVWF      R4+0
	MOVF       FARG_display_temp+0, 0
	MOVWF      R0+0
	CALL       _Div_8X8_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
;Project_Temp.c,89 :: 		data_display1 = temp_display1;
	MOVF       FLOC__display+0, 0
	MOVWF      PORTD+0
;Project_Temp.c,90 :: 		data_display2 = temp_display2;
	MOVF       R0+0, 0
	MOVWF      PORTB+0
;Project_Temp.c,91 :: 		}
L_end_display:
	RETURN
; end of _display

_config_temp:

;Project_Temp.c,93 :: 		void config_temp()
;Project_Temp.c,95 :: 		if(button_config == 0)
	BTFSC      PORTC+0, 2
	GOTO       L_config_temp7
;Project_Temp.c,97 :: 		led_config = 1;
	BSF        PORTC+0, 4
;Project_Temp.c,98 :: 		display(temp_cooler);
	MOVF       _temp_cooler+0, 0
	MOVWF      FARG_display_temp+0
	CALL       _display+0
;Project_Temp.c,99 :: 		delay_ms(300);
	MOVLW      4
	MOVWF      R11+0
	MOVLW      12
	MOVWF      R12+0
	MOVLW      51
	MOVWF      R13+0
L_config_temp8:
	DECFSZ     R13+0, 1
	GOTO       L_config_temp8
	DECFSZ     R12+0, 1
	GOTO       L_config_temp8
	DECFSZ     R11+0, 1
	GOTO       L_config_temp8
	NOP
	NOP
;Project_Temp.c,100 :: 		while(button_config == 1)
L_config_temp9:
	BTFSS      PORTC+0, 2
	GOTO       L_config_temp10
;Project_Temp.c,102 :: 		if(button_up == 0)
	BTFSC      PORTC+0, 1
	GOTO       L_config_temp11
;Project_Temp.c,104 :: 		temp_cooler ++;
	INCF       _temp_cooler+0, 1
;Project_Temp.c,105 :: 		if(temp_cooler > 99)
	MOVF       _temp_cooler+0, 0
	SUBLW      99
	BTFSC      STATUS+0, 0
	GOTO       L_config_temp12
;Project_Temp.c,107 :: 		temp_cooler = 0;
	CLRF       _temp_cooler+0
;Project_Temp.c,108 :: 		}
L_config_temp12:
;Project_Temp.c,109 :: 		display(temp_cooler);
	MOVF       _temp_cooler+0, 0
	MOVWF      FARG_display_temp+0
	CALL       _display+0
;Project_Temp.c,110 :: 		delay_ms(300);
	MOVLW      4
	MOVWF      R11+0
	MOVLW      12
	MOVWF      R12+0
	MOVLW      51
	MOVWF      R13+0
L_config_temp13:
	DECFSZ     R13+0, 1
	GOTO       L_config_temp13
	DECFSZ     R12+0, 1
	GOTO       L_config_temp13
	DECFSZ     R11+0, 1
	GOTO       L_config_temp13
	NOP
	NOP
;Project_Temp.c,111 :: 		}
L_config_temp11:
;Project_Temp.c,112 :: 		if(button_down == 0)
	BTFSC      PORTC+0, 3
	GOTO       L_config_temp14
;Project_Temp.c,114 :: 		temp_cooler --;
	DECF       _temp_cooler+0, 1
;Project_Temp.c,115 :: 		if(temp_cooler < 0)
	MOVLW      0
	SUBWF      _temp_cooler+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_config_temp15
;Project_Temp.c,117 :: 		temp_cooler = 99;
	MOVLW      99
	MOVWF      _temp_cooler+0
;Project_Temp.c,118 :: 		}
L_config_temp15:
;Project_Temp.c,119 :: 		display(temp_cooler);
	MOVF       _temp_cooler+0, 0
	MOVWF      FARG_display_temp+0
	CALL       _display+0
;Project_Temp.c,120 :: 		delay_ms(300);
	MOVLW      4
	MOVWF      R11+0
	MOVLW      12
	MOVWF      R12+0
	MOVLW      51
	MOVWF      R13+0
L_config_temp16:
	DECFSZ     R13+0, 1
	GOTO       L_config_temp16
	DECFSZ     R12+0, 1
	GOTO       L_config_temp16
	DECFSZ     R11+0, 1
	GOTO       L_config_temp16
	NOP
	NOP
;Project_Temp.c,121 :: 		}
L_config_temp14:
;Project_Temp.c,122 :: 		}
	GOTO       L_config_temp9
L_config_temp10:
;Project_Temp.c,123 :: 		display(temp_current);
	MOVF       _temp_current+0, 0
	MOVWF      FARG_display_temp+0
	CALL       _display+0
;Project_Temp.c,124 :: 		led_config = 0;
	BCF        PORTC+0, 4
;Project_Temp.c,125 :: 		delay_ms(300);
	MOVLW      4
	MOVWF      R11+0
	MOVLW      12
	MOVWF      R12+0
	MOVLW      51
	MOVWF      R13+0
L_config_temp17:
	DECFSZ     R13+0, 1
	GOTO       L_config_temp17
	DECFSZ     R12+0, 1
	GOTO       L_config_temp17
	DECFSZ     R11+0, 1
	GOTO       L_config_temp17
	NOP
	NOP
;Project_Temp.c,126 :: 		}
L_config_temp7:
;Project_Temp.c,127 :: 		}
L_end_config_temp:
	RETURN
; end of _config_temp
