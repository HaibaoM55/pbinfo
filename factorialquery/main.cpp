#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int n;
int v[1000004];
long long s = 1;
#define DIM 10000
char buff[DIM];
int poz=0;
void citire_rapida(int &nr)
{
    nr = 0;
    while (buff[poz] < '0' || buff[poz] > '9'){
        if(++poz == DIM){
            fread(buff,1,DIM,stdin),poz=0;
        }
    }
    while ('0'<=buff[poz] && buff[poz]<='9'){
        nr = nr*10 + buff[poz] - '0';
        if(++poz == DIM){
            fread(buff,1,DIM,stdin),poz=0;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        citire_rapida(v[i]);
    }
    sort(v+1, v+n+1);
    long long fact_inainte = 1;
    v[0] = 1;
    for(int i = 1; i <= n; i++){
        s = s*fact_inainte;
        s = s%MOD;
        if(v[i] > v[i-1]){
            for(int j = v[i-1]+1; j <= v[i]; j++){
                s = s * j;
                s = s % MOD;
                fact_inainte = fact_inainte * j;
                fact_inainte = fact_inainte % MOD;
            }
        }
    }
    cout << s;
    return 0;
}
