DATA SEGMENT
   A DW 1234H
   B DW 0002H
   PRODUCT DD 0H
DATA ENDS

CODE SEGMENT
   ASSUME CS:CODE, DS:DATA
   START: MOV AX,DATA
          MOV DS,AX

          MOV DX,0
          MOV CX,B
          MOV AX,0
          MOV BX,A
   BACK:  ADD AX,BX
          ADC DX,0
   LOOP BACK
          MOV WORD PTR PRODUCT,AX
          MOV WORD PTR [PRODUCT+2],DX

          MOV AH,4CH
          INT 21H
CODE ENDS
     END START
