#include <iostream>
using namespace std;
long long NextNumber(long long n){
   long long i = 1;
   for(;;){
      if((n & i) && !(n & (i<<1))){
         n &= ~i;
         n |= (i<<1);
         break;
      }
      i <<= 1;
   }
   long long j=1, k=1;
   while(j < i){
      if(n & j){
         n &= ~j;
         n |= k;
         k <<= 1;
      }
      j <<= 1;
   }
   return n;
}/*
int main(){
    cout << NextNumber(30);
    return 0;
}
*/
