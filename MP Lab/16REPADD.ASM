DATA SEGMENT
A DW 1234H
B DW 0005H
C DD ?
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:  MOV DX,DATA
        MOV DS,DX
        MOV CX,B
        MOV BX,A
        MOV AX,0
        MOV DX,0
    UP: ADD AX,BX
        ADC DX,0
        LOOP UP
        MOV WORD PTR C,AX
        MOV C+2 ,DX
        CODE ENDS
        END START
