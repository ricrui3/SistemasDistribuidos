        .include "p30f3013.inc"
  
        .global COMANDO_LCD
        .global DATO_LCD
        .global BUSY_FLAG
        .global INI_LCD4

        .equ RS_LCD, RF2
        .equ RW_LCD, RF3
        .equ E_LCD,  RF4
        .equ BF_LCD, RB7

        .equ PORT_CTRL_LCD,     PORTF
        .equ PORT_DATA_LCD,     PORTB

;******************************************************************************
;DESCRICION:	ESTA RUTINA MANDA UN COMANDO AL LCD EN MODO DE 4 BITS
;PARAMETROS: 	W0, COMANDO A ENVIAR
;RETORNO: 		NINGUNO
;******************************************************************************
COMANDO_LCD:
        PUSH.D      W0

        BCLR        PORT_CTRL_LCD,  #RS_LCD     ;RS = 0
        NOP
ESCRITURA_LCD:
        BCLR        PORT_CTRL_LCD,  #RW_LCD     ;RW = 0
        NOP
        BSET        PORT_CTRL_LCD,  #E_LCD      ;E = 1
        NOP
        MOV         W0,             W1          ;W1 = W0
        MOV         #0XFF0F,        W0          ;W0 = 0XFF0F
        AND         PORT_DATA_LCD               ;PORTB = PORTB & W0
        NOP
        ;CONTINUARA...
        POP.D       W0
        RETURN
;******************************************************************************
;DESCRICION:	ESTA RUTINA MANDA UN DATO AL LCD EN MODO DE 4 BITS
;PARAMETROS: 	W0, DATO A ENVIAR
;RETORNO: 		NINGUNO
;******************************************************************************
DATO_LCD:
        PUSH.D      W0

        BSET        PORT_CTRL_LCD,  #RS_LCD     ;RS = 1
        NOP
        GOTO        ESCRITURA_LCD

;******************************************************************************
;DESCRICION:	ESTA RUTINA VERIFICA LA BANDERA DE BF DEL LCD
;PARAMETROS: 	NINGUNO
;RETORNO: 		NINGUNO
;******************************************************************************
BUSY_FLAG:

        ;CONTINUARA...
        RETURN
;******************************************************************************
;DESCRICION:	ESTA RUTINA INICIALIZA EL LCD EN MODO DE 4 BITS
;PARAMETROS: 	NINGUNO
;RETORNO: 		NINGUNO
;******************************************************************************
INI_LCD4:
        CALL        RETARDO_15ms
        MOV         #0X33,              W0
        CALL        COMANDO_LCD
        CALL        RETARDO_15ms
        MOV         #0X33,              W0
        CALL        COMANDO_LCD
        CALL        RETARDO_15ms
        MOV         #0X33,              W0
        CALL        COMANDO_LCD

        CALL        BUSY_FLAG
        MOV         #0X22,              W0
        CALL        COMANDO_LCD

        CALL        BUSY_FLAG
        MOV         #0X28,              W0
        CALL        COMANDO_LCD

        CALL        BUSY_FLAG
        MOV         #0X08,              W0
        CALL        COMANDO_LCD
        ;CONTINUARA...


        RETURN

