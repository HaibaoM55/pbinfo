#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[1000004];
int v1[1000004];
int f[1000004];
int f1[1000004];
int s[1000004];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v1[i] = v[i];
    }
    sort(v1+1, v1+n+1);
    int z = 0;
    v1[0] = v1[1]-1;
    for(int i = 1; i <= n; i++){
        if(v1[i] != v1[i-1]){
            z++;
            f[z] = v1[i];
        }
    }
    for(int i = 1; i <= n; i++){
        int p1 = 1;
        int p2 = z;
        int p=0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(f[mij] < v[i]){
                p1 = mij+1;
            }else{
                p=mij;
                p2 = mij-1;
            }
        }
        v[i] = p;
    }
    int s = 0;
    int vmax = 0;
    int p=1;
    for(int i = 1; i <= n; i++){
        if(f1[v[i]] == 0){
            f1[v[i]]=i;
            s++;
        }else{
            s=s-(f1[v[i]]-p);
            p=f1[v[i]]+1;
            f1[v[i]]=i;
        }
        vmax = max(vmax, s);
    }
    cout << vmax;
    return 0;
}
