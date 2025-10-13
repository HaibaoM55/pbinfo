#include <iostream>
using namespace std;
int c, n, m;
int v[100004];
int pst[100004];
int pdr[100004];
int main(){
    cin >> c;
    if(c == 1){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        for(int i = 1; i <= m; i++){
            int x;
            cin >> x;
            int nr=0;
            for(int i = 1; i < x; i++){
                if(v[i] < v[x]){
                    nr++;
                }
            }
            cout << nr<< '\n';
        }
    }else{
        cin >> n;
        int vmax = 0;
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            vmax = max(vmax, v[i]);
        }
        for(int i = 1; i <= n; i++){
            v[i] = vmax-v[i];
        }
        pst[1] = 1;
        for(int i = 2; i <= n; i++){
            int j = i-1;
            pst[i] = i;
            while(j >= 2 && v[j] >= v[i]){
                pst[i] = pst[j];
                j = pst[j]-1;
            }
            if(pst[i] <= 2 && v[i] <= v[1]){
                pst[i] = 1;
            }
        }
        pdr[n] = n;
        for(int i = n-1; i >= 1; i--){
            int j = i+1;
            pdr[i] = i;
            while(j <= n-1 && v[j] >= v[i]){
                pdr[i] = pdr[j];
                j = pdr[j]+1;
            }
            if(j >= n-1 && v[i] <= v[n]){
                pdr[i] = n;
            }
        }
        int ariemaxima = 0;
        for(int i = 1; i <= n; i++){
            ariemaxima = max(ariemaxima, (pdr[i]-pst[i]+1)*v[i]);
        }
        cout << ariemaxima;
    }
    return 0;
}
