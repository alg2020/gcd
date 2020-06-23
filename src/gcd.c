#include <stdio.h>
#include <assert.h>
const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
    return x?Euclidean_gcd_rec(y%x, x):y;
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
    while(x){
        unsigned int temp = x;
        x = y % x;
        y = temp;
    }
    return y;
}
unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
    if(x * y == 0)return x + y;
    if(x&1){
        if(y&1){
            if(x > y)return binary_gcd_rec((x-y)/2, y);
            return binary_gcd_rec(x,(y-x)/2);
        }
        return binary_gcd_rec(x, y/2);
    }
    if(y&1)return binary_gcd_rec(x/2, y);
    return 2*binary_gcd_rec(x/2,y/2);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
    if(x * y == 0)return x + y;
    unsigned int l_shift = 0;
    while(~(x|y) & 1)l_shift ++, x >>= 1, y >>= 1;
    unsigned int diff, mi;
    while(x*y){
        diff = x > y ? x - y : y - x;
        mi = x > y ? y : x;
        x = diff, y = mi;
        if(~x&1)x >>= 1;
        if(~y&1)y >>= 1;
    }
    return (x+y)<<l_shift;
}


int main(){
  unsigned int i, j, c;


  c = 0;
  for(i = 1; i <= n; i++){
    for(j = i + 1; j <= n; j++){
      if(Euclidean_gcd_rec(i, j) == 1){
        c++;
      }
      assert(Euclidean_gcd_rec(i,j) == Euclidean_gcd_itr(i,j));
      assert(Euclidean_gcd_rec(i,j) == binary_gcd_itr(i,j));
      assert(Euclidean_gcd_rec(i,j) == binary_gcd_rec(i,j));
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double) c / (n * n));
  return 0;
}
