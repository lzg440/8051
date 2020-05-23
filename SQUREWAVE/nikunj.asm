//GENERATE 10KHZ WAVE ON P1.0  AND 50HZ ON P1.1

ORG 00h ; reset vector
JMP main ; jump above interrupt vectors
ORG 000BH ; timer 0 interrupt vector
CPL P1.0 ; invert port 1 pin 0
RETI ; return from interrupt
ORG 001BH ; timer 1 interrupt vector
CLR TR1 ; stop timer 1
MOV TH1, #0DCH
MOV TL1, #00H ; 
SETB TR1 ; start timer 1
CPL P1.1; invent port 1 pin 1
RETI
ORG 0100H ; main program entry point

main:
MOV TMOD, #12H ; timer 0 in 8-bit auto-reload timer mode, timer 1 in 16-bit mode
MOV TH0,#-49; put (256 - 71) 185 decimal into TH0
SETB TR0 ; start timer 0
SETB TF1 ; force timer 1 interrupt
SETB ET0 ; enable timer 0 interrupt
SETB ET1 ; enable timer 1 interrupt
SETB EA ; global interrupt enable
JMP $ ; do nothing but wait for interrupt
end