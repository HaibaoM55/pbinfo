#include <fstream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
ifstream fin("poseidon.in");
ofstream fout("poseidon.out");
int c;
int n, m;
int a[1004][1004];
struct pos{
    int i, j;
}coada[1000004];
bool viz[1004][1004];
long long fact[1000004] = {0,1,2,9,44,265,1854,14833};
int x1, y1;
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,1,-1};
int test[14];
int main(){
    fin >> c;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            viz[i][j] = false;
        }
    }
    if(c == 1){
        fin >> x1 >> y1;
        int st = 1, dr = 1;
        coada[st].i = x1;
        coada[st].j = y1;
        int comori = 0;
        while(st <= dr){
            for(int d = 0; d < 4; d++){
                int i1 = coada[st].i+dirx[d];
                int j1 = coada[st].j+diry[d];
                if(1 <= i1 && i1 <= n){
                    if(1 <= j1 && j1 <= m){
                        if(!viz[i1][j1] && a[i1][j1] >= 0){
                            viz[i1][j1] = true;
                            dr++;
                            coada[dr].i = i1;
                            coada[dr].j = j1;
                            if(a[i1][j1] > 0){
                                comori++;
                            }
                        }
                    }
                }
            }
            st++;
        }
        fout << comori;
    }else{
//        for(int i = 1; i <= 11; i++){
//            for(int j = 1; j <= i; j++){
//                test[j] = j;
//            }
//            int nr = 0;
//            do{
//                bool ok = true;
//                for(int j = 1; j <= i; j++){
//                    if(test[j] == j){
//                        ok = false;
//                        break;
//                    }
//                }
//                if(ok){
//                    nr++;
//                }
//            }while(next_permutation(test+1, test+i+1));
//            fout << nr << '\n';
//        }
//        return 0;
        long long r = 1;
        long long oricat = 9;
        for(int i = 8; i <= n*m; i++){
            fact[i] = fact[i-1]*oricat;
            if(oricat % 2 == 0){
                fact[i]++;
            }else{
                fact[i] = MOD+fact[i]-1;
            }
            fact[i] = fact[i]%MOD;
            oricat++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!viz[i][j] && a[i][j] >= 0){
                    int comori = 0;
                    int st = 1, dr = 1;
                    coada[st].i = i;
                    coada[st].j = j;
                    while(st <= dr){
                        for(int d = 0; d < 4; d++){
                            int i1 = coada[st].i+dirx[d];
                            int j1 = coada[st].j+diry[d];
                            if(1 <= i1 && i1 <= n){
                                if(1 <= j1 && j1 <= m){
                                    if(!viz[i1][j1] && a[i1][j1] >= 0){
                                        viz[i1][j1] = true;
                                        dr++;
                                        coada[dr].i = i1;
                                        coada[dr].j = j1;
                                        if(a[i1][j1] > 0){
                                            comori++;
                                        }
                                    }
                                }
                            }
                        }
                        st++;
                    }
                    r = r*fact[comori-1];
                    r = r % MOD;
                }
            }
        }
        fout << r;
    }
    return 0;
}
