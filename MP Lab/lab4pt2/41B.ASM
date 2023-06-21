DATA SEGMENT
   A DB 12
   B DB 02
   PRODUCT DW 0H
DATA ENDS

CODE SEGMENT
   ASSUME CS:CODE, DS:DATA
   START: MOV AX,DATA
          MOV DS,AX

          MOV AL,B
          MOV BL,A
          IMUL BL;
          MOV PRODUCT,AX

          MOV AH,4CH
          INT 21H
CODE ENDS
     END START
