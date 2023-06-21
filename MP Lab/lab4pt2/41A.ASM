DATA SEGMENT
   A DW 1111H
   B DW 1934H
   PRODUCT DD 0H
DATA ENDS

CODE SEGMENT
   ASSUME CS:CODE, DS:DATA
   START: MOV AX,DATA
          MOV DS,AX

          MOV AX,B
          MOV BX,A
          MUL BX

          MOV WORD PTR PRODUCT,AX
          MOV WORD PTR [PRODUCT+2],DX

          MOV AH,4CH
          INT 21H
CODE ENDS
     END START

