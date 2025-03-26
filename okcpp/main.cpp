#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("okcpp.in");
ofstream fout("okcpp.out");
int c;
int p, k;
long long kmare;
long long a, b;
int nrcif;
int v[12];
void kp(int k){
    if(k == 10){
        int s = 0;
        for(int i = 0; i <= 9; i++){
            s = s+v[i];
        }
        if(s == nrcif+1){
            bool ok = true;
            int m = kmare;
            for(int i = 0; i <= p-2; i++){
                m = m-v[i];
                if(m < 1){
                    break;
                }
            }
            if(m >= 1){
                fout << 1;
                v[1]--;
                for(int i=0;i<=9;i++){
                    for(int j = 1; j <= v[i]; j++){
                        fout << i;
                    }
                }
                exit(0);
            }
        }
    }else{
        for(int i = nrcif; i >= 0; i--){
            v[k] = i;
            bool ok = true;
            if(v[k] > v[k-1] && k > 0){
                ok = false;
            }
            int s = 0;
            for(int j = 1; j <= k; j++){
                s = s+v[j];
                if(s > nrcif+1){
                    ok = false;
                    break;
                }
            }
            if(ok){
                kp(k+1);
            }
        }
    }
}
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
        fin >> kmare >> p >> a;
        long long z = a;
        long long p10 = 1;
        do{
            p10=p10*10;
            nrcif++;
            z = z/10;
        }while(z > 0);
        int f[12] = {0,0,0,0,0,0,0,0,0,0};
        kp(0);
    }
    return 0;
}
