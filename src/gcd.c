#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
  if(y == 0) return x;
  return Euclidean_gcd_rec(y, x % y);
}

/*
unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
  while(x != 0){
    unsigned int z = x;
    x = x % y;
    y = z;
  }

  return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
}
*/


int main(){
  unsigned int i, j, c;


  c = 0;
  for(i = 1; i <= n; i++){
    for(j = i + 1; j <= n; j++){
      if(Euclidean_gcd_rec(i, j) == 1){
        c++;
      }
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double) c / (n * n));
  return 0;
}
