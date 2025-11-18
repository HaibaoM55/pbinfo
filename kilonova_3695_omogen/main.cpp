#include <iostream>
using namespace std;
int n;
int v[1000004], f[10000004];
bool ciur[10000004];
int nrp=0, prm[1000004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ciur[1]=true;
    for(int i = 2; i <= 10000000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 10000000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int i = 1;
    bool ok = true;
    long long nr = n;
    for(int j = 1; j <= n; j++){
        int x = v[j];
        if(v[j] == 1){
            nr += j-i;
            continue;
        }
        for(int d = 1; prm[d]*prm[d] <= x; d++){
            if(x % prm[d] == 0){
                f[prm[d]]++;
                if(f[prm[d]] == 2){
                    while(f[prm[d]] == 2){
                        int x1 = v[i];
                        for(int d1 = 1; prm[d1]*prm[d1] <= x1; d1++){
                            if(x1 % prm[d1] == 0){
                                f[prm[d1]]--;
                                while(x1 % prm[d1] == 0){
                                    x1 = x1 / prm[d1];
                                }
                            }
                        }
                        if(x1 > 1){
                            f[x1]--;
                        }
                        i++;
                    }
                }
                while(x % prm[d] == 0){
                    x = x/prm[d];
                }
            }
        }
        if(x > 1){
            f[x]++;
            if(f[x] == 2){
                while(f[x] == 2){
                    int x1 = v[i];
                    for(int d1 = 1; prm[d1]*prm[d1] <= x1; d1++){
                        if(x1 % prm[d1] == 0){
                            f[prm[d1]]--;
                            while(x1 % prm[d1] == 0){
                                x1 = x1 / prm[d1];
                            }
                        }
                    }
                    if(x1 > 1){
                        f[x1]--;
                    }
                    i++;
                }
            }
        }
        nr += j-i;
    }
    cout << nr;
    return 0;
}
