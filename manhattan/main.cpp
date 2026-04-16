#include <fstream>
using namespace std;
#define MOD 666013
ifstream fin("manhattan.in");
ofstream fout("manhattan.out");
struct zona{
    int x1, y1, x2, y2;
}a, b;
long long fact[200004], inv_fact[200004];
int invers(int x){
    long long rasp = 1;
    int e = MOD - 2;
    while(e){
        if(e & 1){
          rasp = rasp * x % MOD;
        }
        x = (1LL*x*x)% MOD;
        e >>= 1;
    }
    return rasp;
}
int comb(int n, int k){
  return (1LL*fact[n]*inv_fact[k]*inv_fact[n-k])%MOD;
}
int numara(int w, zona z){
    long long rasp = (comb(z.x1 + z.y1 + 1, z.y1 + 1) - comb(z.x1 + z.y1 - w, z.y1 + 1))-(comb(z.x2 + z.y1 + 2, z.y1 + 1) - comb(z.x2 + z.y1 + 1 - w, z.y1 + 1))+ (comb(z.x2 + z.y2 + 3, z.y2 + 2) - comb(z.x2 + z.y2 + 2 - w, z.y2 + 2))- (comb(z.x1 + z.y2 + 2, z.y2 + 2) - comb(z.x1 + z.y2 + 1 - w, z.y2 + 2));
    return (rasp + 8 * MOD) % MOD;
}
int main(){
    fin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    fin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    if((a.y1 > b.y2) || (b.y1 > a.y2)){
        swap(a.x1, a.y1);
        swap(a.x2, a.y2);
        swap(b.x1, b.y1);
        swap(b.x2, b.y2);
    }
    if(a.x1 > b.x1){
        a.x1 = -a.x1;
        a.x2 = -a.x2;
        swap(a.x1, a.x2);
        b.x1 = -b.x1;
        b.x2 = -b.x2;
        swap(b.x1, b.x2);
    }
    b.x1 -= a.x1;
    b.x2 -= a.x1;
    b.y1 -= a.y1;
    b.y2 -= a.y1;
    a.x2 -= a.x1;
    a.y2 -= a.y1;
    a.x1 = 0;
    a.y1 = 0;
    fact[0] = 1;
    for(int i = 1; i <= 200000; i++){
        fact[i] = (1LL*i*fact[i-1])%MOD;
    }
    inv_fact[200000] = invers(fact[200000]);
    for(int i = 199999; i >= 0; i--){
        inv_fact[i] = (1LL*(i+1)*inv_fact[i+1])%MOD;
    }
    long long rasp = 0;
    for(int h = 0; h <= a.y2; h++){
        if(h < b.y1){
            zona m = b;
            m.y1 -= h;
            m.y2 -= h;
            rasp += numara(a.x2, m);
        }else if(h > b.y2){
            zona m = b;
            m.y1 = h-b.y2;
            m.y2 = h-b.y1;
            rasp += numara(a.x2, m);
        }else{
            zona m = b;
            m.y1 = 0;
            m.y2 -= h;
            rasp += numara(a.x2, m);
            m.y1 = 1;
            m.y2 = h-b.y1;
            rasp += numara(a.x2, m);
        }
    }
    rasp = rasp % MOD;
    fout << rasp;
    return 0;
}
