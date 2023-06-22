#include <iostream>
#define N 3
using namespace std;
bool isMagicSquare(int mat[][N]) {
   int sum_diag = 0,sum_diag_second=0;
   for (int i = 0; i < N; i++)
      sum_diag = sum_diag + mat[i][i];
   for (int i = 0; i < N; i++)
      sum_diag_second = sum_diag_second + mat[i][N-1-i];
   if(sum_diag!=sum_diag_second)
      return false;
   for (int i = 0; i < N; i++) {
      int rowSum = 0;
      for (int j = 0; j < N; j++)
         rowSum += mat[i][j];
      if (rowSum != sum_diag)
         return false;
   }
   for (int i = 0; i < N; i++) {
      int colSum = 0;
      for (int j = 0; j < N; j++)
         colSum += mat[j][i];
      if (sum_diag != colSum)
      return false;
   }
   return true;
}
int main() {
   int mat[][N] = {{ 6, 1, 8 },
   { 7, 5, 3 },
   { 2, 9, 4 }};
   if (isMagicSquare(mat))
      cout << "It is Magic Square";
   else
   cout << "It is Not a magic Square";
}
