DATA SEGMENT
A DD 0F345678H
B DW 0F02H
Q DD ?
R DD ?
DATA ENDS
CODE SEGMENT
 ASSUME CS:CODE, DS:DATA
 START:  MOV BX,DATA
         MOV DS,BX

         MOV AX,WORD PTR A
         MOV DX, WORD PTR A+2
         MOV BX,B
         IDIV BX
         MOV Q,AX
         MOV R,DX

         MOV AH,4CH
         INT 21H
         CODE ENDS
         END START

