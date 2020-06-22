#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
  if(x == 0) return y;
  return Euclidean_gcd_rec(y%x, x);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
  while(x != 0){
    unsigned int z = x;
    x = y % x;
    y = z;
  }
  return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
  if(x == 0) return y;
  else if(y == 0) return x;
  else if((x & 1) == 0 && (y & 1) == 0) return binary_gcd_rec(x>>1,y>>1)<<1;
  else if((x & 1) == 0) return binary_gcd_rec(x>>1,y);
  else if((y & 1) == 0) return binary_gcd_rec(x,y>>1);
  else if(y >= x) binary_gcd_rec(x, (y-x)>>1);
  else binary_gcd_rec((x-y)>>1, y);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
  unsigned int c=0;
  while(x != 0 && y != 0){
    if((x & 1) == 0 && (y & 1) == 0) x>>=1,y>>=1,c++;
    else if((x & 1) == 0) x>>=1;
    else if((y & 1) == 0) y>>=1;
    else if(y >= x) y=(y-x)>>1;
    else x=(x-y)>>1;
  }
  return (x ? x : y)<<c;
}


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
