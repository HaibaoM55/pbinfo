#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("secventa.in");
ofstream fout("secventa.out");
unsigned long long k, p = 1;
unsigned long long putere(unsigned long long a, unsigned long long n, unsigned long long mod){
    unsigned long long p1 = 1;
    while(n > 0){
        if(n % 2 == 1){
            p1 = p1*a;
            p1 = p1%mod;
        }
        a = a%mod;
        a = a*a;
        a = a%mod;
        n = n/2;
    }
    return p1;
}
int main()
{
    fin >> k;
    while(k % p== 0 && k != p){
        p = p*2;
    }
    if(p != k){
        p = p/2;
    }
    unsigned long long ptr = putere(2, p, 1000000007);
    ptr--;
    fout << ptr;
    return 0;
}
