DATA SEGMENT
   A DW 0322H
   B DB 82H
   Q DB 0H
   R DB 0H
DATA ENDS

CODE SEGMENT
   ASSUME CS:CODE, DS:DATA
   START: MOV AX,DATA
          MOV DS,AX

          MOV AX,A
          MOV BL,B
          IDIV BL
          MOV Q,AL
          MOV R,AH

          MOV AH,4CH
          INT 21H
CODE ENDS
     END START
