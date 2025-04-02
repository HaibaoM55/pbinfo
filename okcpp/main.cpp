#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("okcpp.in");
ofstream fout("okcpp.out");
int c;
int p, k;
long long a, b;
int nrcif;
int v[12];
int main()
{
    fin >> c;
    if(c == 1){
        fin >> k >> p >> a >> b;
        int nr = 0;
        for(long long j = a; j <= b; j++){
            long long x = j;
            int m = k;
            int f[12] = {0,0,0,0,0,0,0,0,0,0};
            do{
                f[x%10]++;
                x = x/10;
            }while(x > 0);
            sort(f+0, f+10);
            bool ok = true;
            for(int i = 9; i >= 9-p+2; i--){
                m = m-f[i];
                if(m < 1){
                    break;
                }
            }
            if(m >= 1){
                nr++;
            }
        }
        fout << nr;
    }else{
        fin >> k >> p >> a;
        long long z = a;
        int nrcif = 0;
        int f[12] = {0,0,0,0,0,0,0,0,0,0};
        do{
            nrcif++;
            v[nrcif] = z%10;
            f[z%10]++;
            z = z/10;
        }while(z > 0);
        z = nrcif;
        for(int i = 1; i <= nrcif/2; i++){
            swap(v[i], v[z]);
            z--;
        }
        for(int i = nrcif; i >= 1; i--){
            f[v[i]]--;
            int fv[12];
            for(int j = 0; j < 10; j++){
                fv[j] =f[j];
            }
            for(int j = v[i]+1; j <= 9; j++){
                for(int zz = 0; zz < 10; zz++){
                    fv[zz] =f[zz];
                }
                v[i] = j;
                fv[j]++;
                sort(fv, fv+10);
                z = 0;
                for(int pl = 9; pl >= 9-p+2; pl--){
                    z = z + fv[pl];
                }
                if(z < k){
                    bool ok = true;
                    int vect[20];
                    for(int pl = 1; pl < i; pl++){
                        vect[pl] = v[pl];
                    }
                    vect[i] = j;
                    int fc[12];
                    for(int pl = 0; pl <= 9; pl++){
                        fc[pl] = f[pl];
                    }
                    for(int pl = i+1; pl <= nrcif; pl++){
                        int fvm[12];
                        bool ok1 = false;
                        for(int kk = 0; kk <= 9; kk++){
                            for(int xk = 0; xk <= 9; xk++){
                                fvm[xk] = fc[xk];
                            }
                            fvm[j]++;
                            fvm[kk]++;
                            sort(fvm, fvm+10);
                            int z1 = 0;
                            for(int pl1 = 9; pl1 >= 9-p+2; pl1--){
                                z1 = z1 + fvm[pl1];
                            }
                            if(z1 < k){
                                vect[pl] = kk;
                                fc[kk]++;
                                ok1 = true;
                                break;
                            }
                        }
                        if(ok1 == false){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        for(int pl = 1; pl <= nrcif; pl++){
                            fout << vect[pl];
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
