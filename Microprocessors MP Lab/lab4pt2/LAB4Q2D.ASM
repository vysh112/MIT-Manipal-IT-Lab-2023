DATA SEGMENT
   A DD 00763956H
   B DW 0FEA2H
   Q DW 0H
   R DW 0H
DATA ENDS

CODE SEGMENT
   ASSUME CS:CODE, DS:DATA
   START: MOV AX,DATA
          MOV DS,AX

          MOV AX,WORD PTR A
          MOV DX,WORD PTR [A+2]
          MOV CX,B
          IDIV CX;
          MOV Q,AX
          MOV R,DX

          MOV AH,4CH
          INT 21H
CODE ENDS
     END START
