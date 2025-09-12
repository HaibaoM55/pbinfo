#include <iostream>
#include <string>
using namespace std;
#define MOD 666013
string s, t;
int ft[26], fs[26];
long long fact[100001];
long long exp_rap(long long  b, int e){
    if(e==0)
        return 1;
    if(e%2==0)
        return exp_rap(b*b%MOD, e/2);
    return b*exp_rap(b, e-1)%MOD;
}
int main()
{
    cin>>s>>t;
    fact[0]=1;
    for (int i=1; i<=100000; i++)
        fact[i]=fact[i-1]*i%MOD;
    for (int i=0; i<t.size(); i++)
        ft[t[i]-'a']++;
    for (int i=0; i<s.size(); i++)
        fs[s[i]-'a']++;
    long long  sol=1, im=1;
    for(int i=0; i<='z'-'a'; i++){
        if(ft[i]!=0){
            if(ft[i]>fs[i]){
                sol=0;
            }else{
                sol=sol*fact[fs[i]]%MOD;
                im=im*fact[ft[i]]%MOD*fact[fs[i]-ft[i]]%MOD;
            }
        }
    }
    cout<<sol*exp_rap(im, MOD-2)%MOD;

    return 0;
}
