#include <iostream>
using namespace std;
void citire(int v[], int n, int nr){
    if(nr == n+1){
        return;
    }
    cin >> v[nr];
    citire(v,n,nr+1);
}
void afisare(int v[], int p, int n){
    if(p == n+1){
        return;
    }
    cout << v[p] << ' ';
    afisare(v, p+1, n);
}
int prima_cifra(int n){
    int pc = 0;
    do{
        pc = n%10;
        n=n/10;
    }while(n > 0);
    return pc;
}
int nr_ap(int n){
    int pc = prima_cifra(n), cnt = 0;
    do{
        if(n%10 == pc){
            cnt++;
        }
        n/=10;
    }while(n > 0);
    return cnt;
}
void inloc(int v[], int n){
    if(n==0)
        return;
    else{
        v[n] = nr_ap(v[n]);
        inloc(v,n-1);
    }
}
int main(){
    int n;
    int v[1001];
    cin >> n;
    citire(v,n,1);
    inloc(v,n);
    afisare(v,1,n);
    return 0;

}
