#include <stdio.h>

const int n = 1000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
	if(y==0) return x;
	return Euclidean_gcd_rec(y,x%y);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
	while(y) {
		x%=y;
		unsigned int o=y;
		y=x; x=o;
	}
	return x;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
	if(x==0) return y;
	if(y==0) return x;
	if(x&y&1) {
		if(x>=y) return binary_gcd_rec((x-y)>>1,y);
		else return binary_gcd_rec(x,(y-x)>>1);
	}
	if(x&1) return binary_gcd_rec(x,y>>1);
	if(y&1) return binary_gcd_rec(x>>1,y);
	return binary_gcd_rec(x>>1,y>>1)<<1;
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
	unsigned int g=0;
	while(x&&y) {
		if(x&y&1) {
			if(x>=y) x=(x-y)>>1;
			else y=(y-x)>>1;
		}
		else if(x&1) y>>=1;
		else if(y&1) x>>=1;
		else g++,x>>=1,y>>=1;
	}
	if(x) return x<<g;
	else return y<<g;
}


int main(){
  unsigned int i, j, c;


  c = 0;
  for(i = 1; i <= n; i++){
    for(j = i + 1; j <= n; j++){
      if(binary_gcd_itr(i, j) == 1){
      //if(binary_gcd_rec(i, j) == 1){
      //if(Euclidean_gcd_itr(i, j) == 1){
      //if(Euclidean_gcd_rec(i, j) == 1){
        c++;
      }
    }
  }
  c = 2 * c + 1;

  printf("%f\n", (double) c / (n * n));
  return 0;
}
