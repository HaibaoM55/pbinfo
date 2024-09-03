#include <iostream>
using namespace std;
int n;
int v[100004];
int aux[100004];
long long s = 0;
void interclasare(int p, int q, int r){
    int i=p;
    int j=q+1;
    int k=p-1;
    while(i <= q && j <= r){
        if(v[i] <= v[j]){
            k++;
            aux[k] = v[i];
            i++;
        }else{
            k++;
            aux[k] = v[j];
            s += q-i+1;
            j++;
        }
    }
    while(i <= q){
        k++;
        aux[k] = v[i];
        i++;
    }
    while(j <= r){
        k++;
        aux[k] = v[j];
        j++;
    }
    for(int i = p; i <= r; i++){
        v[i] = aux[i];
    }
}
void mergesort(int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergesort(p, q);
        mergesort(q+1, r);
        interclasare(p, q, r);
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    s=0;
    mergesort(1, n);
    cout << s;
    return 0;
}
