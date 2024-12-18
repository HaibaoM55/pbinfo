#include <fstream>
using namespace std;
ifstream fin("logic.in");
ofstream fout("logic.out");
int c, n;
char v[10][260];
int k;
char x[260];
long long t[10][260][3];
int nrsi=0, nrsau=0;
int main()
{
    fin >> c;
    fin >> n;
    int nrk = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= nrk; j++){
            fin >> v[i][j];
            if(v[i][j] == '|'){
                nrsau++;
            }else{
                nrsi++;
            }
        }
        nrk = nrk*2;
    }
    fin >> k;
    if(c == 1){
        for(int i = 1; i <= k; i++){
            int l = nrk;
            fin >> x;
            int j = n;
            while(l > 1){
                bool a1, a2;
                for(int i = 0; i < l; i++){
                    if(i % 2 == 0){
                        if(x[i] == '0'){
                            a1 = false;
                        }else{
                            a1 = true;
                        }
                    }else{
                        if(x[i] == '0'){
                            a2 = false;
                        }else{
                            a2 = true;
                        }
                        if(v[j][(i+1)/2] == '|'){
                            if(a1 || a2){
                                x[i/2] = '1';
                            }else{
                                x[i/2] = '0';
                            }
                        }else{
                            if(a1 && a2){
                                x[i/2] = '1';
                            }else{
                                x[i/2] = '0';
                            }
                        }
                    }
                }
                l = l/2;
                x[l] = 0;
                j--;
            }
            fout << x << '\n';
        }
    }else{
        nrk = nrk/2;
        for(int i = 1; i <= nrk; i++){
            if(v[n][i] == '&'){
                t[n][i][1] = 1;
                t[n][i][0] = 3;
            }else{
                t[n][i][1] = 3;
                t[n][i][0] = 1;
            }
        }
        for(int i = n-1; i >= 1; i--){
            nrk = nrk/2;
            for(int j = 1; j <= nrk; j++){
                if(v[i][j] == '&'){
                    t[i][j][1] = t[i+1][2*j-1][1]*t[i+1][2*j][1];
                    t[i][j][0] = t[i+1][2*j-1][0]*t[i+1][2*j][0]+t[i+1][2*j-1][0]*t[i+1][2*j][1]+t[i+1][2*j-1][1]*t[i+1][2*j][0];
                }else{
                    t[i][j][1] = t[i+1][2*j-1][1]*t[i+1][2*j][1]+t[i+1][2*j-1][0]*t[i+1][2*j][1]+t[i+1][2*j-1][1]*t[i+1][2*j][0];
                    t[i][j][0] = t[i+1][2*j-1][0]*t[i+1][2*j][0];
                }
                t[i][j][1] = t[i][j][1]%666013;
                t[i][j][0] = t[i][j][0]%666013;
            }
        }
        fout << t[1][1][k];
    }
    return 0;
}
