#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int v[42];
int a[1024*1024+3];
int b[1024*1024+3];
int nra=0,nrb =0;
int p[42];
int vmax = 0;
void pca(int k, int s1){
    if(k >= n/2+1 || s1 >= s){
        return;
    }else{
        for(int i = p[k-1]+1; i <= n/2; i++){
            p[k] = i;
            int s2 = s1+v[p[k]];
            if(s2 <= s){
                nra++;
                a[nra] = s2;
                vmax = max(vmax, s2);
                pca(k+1, s2);
            }
        }
    }
}

void pcb(int k, int s1){
    if(k >= n+1 || s1 >= s){
        return;
    }else{
        for(int i = p[k-1]+1; i <= n; i++){
            p[k] = i;
            int s2 = s1+v[p[k]];
            if(s2 <= s){
                nrb++;
                b[nrb] = s2;
                vmax = max(vmax, s2);
                pcb(k+1, s2);
            }
        }
    }
}
int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    p[0] = 0;
    pca(1, 0);
    p[n/2] = n/2;
    pcb(n/2+1, 0);
    sort(b+1, b+nrb+1);
    for(int i = 1; i <= nra; i++){
        int x = a[i];
        int p1 = 1, p2 = nrb;
        int p3 = 0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(b[mij]+x > s){
                p2 = mij-1;
            }else{
                p1 = mij+1;
                p3 = mij;
            }
        }
        if(p3 != 0 && b[p3]+x > vmax){
            vmax = b[p3]+x;
        }
    }
    cout << vmax;
    return 0;
}
