DATA SEGMENT
   A DW 11FAH
   B DW 6532H
   PRODUCT DD 0H
DATA ENDS

CODE SEGMENT
   ASSUME CS:CODE, DS:DATA
   START: MOV AX,DATA
          MOV DS,AX

          MOV AX,B
          MOV BX,A
          IMUL BX
          MOV WORD PTR PRODUCT,AX
          MOV WORD PTR [PRODUCT+2],DX

          MOV AH,4CH
          INT 21H
CODE ENDS
     END START
