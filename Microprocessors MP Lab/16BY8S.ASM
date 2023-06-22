DATA SEGMENT
A DW -7
B DB -1
Q DW ?
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:   MOV DX,DATA
         MOV DS,DX
         MOV AX,A
         MOV BL,B
         IDIV BL
         MOV Q,AX
         MOV AH,4CH
         INT 21H
         CODE ENDS
         END START


