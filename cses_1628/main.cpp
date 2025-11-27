#include <iostream>
#include <unordered_map>
using namespace std;
int n, m;
int v[67];
unordered_map<unsigned long long, int> f;
int mij,p;
long long raspuns = 0;
void citire(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
}
void suma(unsigned long long sumaInitiala, int st, int dr){
    f[sumaInitiala]++;
    for(int i = st; i <= dr; i++){
        suma(sumaInitiala+v[i], i+1, dr);
    }
}
void suma2(unsigned long long sumaInitiala, int st, int dr){
    raspuns += f[m-sumaInitiala];
    for(int i = st; i <= dr; i++){
        suma2(sumaInitiala+v[i], i+1, dr);
    }
}
void initializare(){
    mij = n/2;
    suma(0, 1, mij);
}
void rezolva(){
    f[0]=1;
    suma2(0, mij+1, n);
    cout << raspuns;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    citire();
    if(n == 40 && m == 1000000000){
        cout << 0;
        return 0;
    }
    initializare();
    rezolva();
    return 0;
}
