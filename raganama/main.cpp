#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("raganama.in");
ofstream fout("raganama.out");
int c;
int l;
char x[105];
char v[104];
int f[105];
int f1[104];
int p = 1;
bool ciur[105];
int prime[26] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int nrp = 25;
int nr[1002];
char x1[105];
int exp1[26];
int nc;
int main()
{
    fin >> c;
    if(c == 1){
        int z = 1;
        fin >> x1;
        l = strlen(x1);
        for(int i = 0; i <= l-1; i++){
             f[i] = x1[i]-'a';
        }
        while(fin >> x){
            z++;
            next_permutation(f, f+l);
            bool ok = true;
            for(int i = 0; i <= l-1; i++){
                if(f[i]+'a' != x[i]){
                    ok = false;
                    break;
                }
            }
            if(ok == false){
                for(int i = 0; i <= l-1; i++){
                    fout << (char)(f[i]+'a');
                }
                return 0;
            }
        }
        z--;

    }else{
        int z = 1;
        char x[101];
        while(fin >> x){
            z++;
        }
        z--;
        l = strlen(x);
        for(int i = 0; i <= l-1; i++){
             f[x[i]-'a']++;
        }
        if(l <= 20){
            long long nrm = 1;
            for(int i = 2; i <= l; i++){
                nrm = nrm*i;
            }
            for(int i = 0; i <= 25; i++){
                for(int j = 2; j <= f[i]; j++){
                    nrm = nrm/j;
                }
            }
            fout << nrm-z;
        }else{
            //
            nr[0] = 1;
            nc = 1;
            for(int i = 1; i <= nrp && prime[i] <= l; i++){
                int x1 = l;
                int sm = 0;
                while(x1 >= prime[i]){
                    x1 = x1/prime[i];
                    sm = sm+x1;
                }
                exp1[i] = sm;
            }
            for(int i = 0; i <= 25; i++){
                if(f[i] != 0){
                    for(int j = 1; j <= nrp && prime[j] <= f[i]; j++){
                        int x1 = f[i];
                        int sm = 0;
                        while(x1 >= prime[j]){
                            x1 = x1/prime[j];
                            sm = sm+x1;
                        }
                        exp1[j] -= sm;
                    }
                }
            }
            for(int k = 1; k <= nrp; k++){
                //prime[k] -> nr prim
                //exp1[k] -> exp1onentul nr prim
                for(int e = 1; e <= exp1[k]; e++){
                    int t = 0;
                    for(int i = 0; i <= nc-1; i++){
                        t = t+(nr[i]*prime[k]);
                        nr[i] = t % 10;
                        t = t/10;
                    }
                    while(t > 0){
                        nr[nc] = t % 10;
                        t = t / 10;
                        nc++;
                    }
                }
            }
            int t = 0;
            for(int i = 0; i <= nc-1; i++){
                nr[i] -= t;
                t = 0;
                if(nr[i] < 0){
                    nr[i] = 9;
                    t = 1;
                }
                if(nr[i] < z%10){
                    nr[i] = nr[i]+10-z%10;
                    t = 1;
                }else{
                    nr[i] = nr[i]-z%10;
                }
                z = z/10;
            }
            while(nr[nc-1] == 0 && nc >= 2){
                nc--;
            }
            for(int i = nc-1; i >= 0; i--){
                fout << nr[i];
            }
        }
    }
    return 0;
}
