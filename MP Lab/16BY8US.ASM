DATA SEGMENT
A DW 2000H
B DB 20H
Q DW ?
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:   MOV DX,DATA
         MOV DS,DX
         MOV AX,A
         MOV BL,B
         DIV BL
         MOV Q,AX
         MOV AH,4CH
         INT 21H
         CODE ENDS
         END START


