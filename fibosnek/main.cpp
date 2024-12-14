#include <fstream>
using namespace std;
ifstream fin("fibosnek.in");
ofstream fout("fibosnek.out");
long long fib[51];
char a[1504][1504];
char k[2500000];
int n, m, c;
int main()
{
    fin >> c >> n >> m;
    fib[0]=0;
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= 50; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    if(c == 1){
        int l = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int x;
                fin >> x;
                for(int z = 2; z <= 50; z++){
                    if(fib[z] == x){
                        l++;
                        break;
                    }
                    if(fib[z] > x){
                        break;
                    }
                }
            }
        }
        fout << l;
    }else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int x;
                fin >> x;
                int p1 = 1, p2 = 50;
                while(p1 <= p2){
                    int mij = (p1+p2)/2;
                    if(fib[mij] < x){
                        p1 = mij+1;
                    }else{
                        p2 = mij-1;
                    }
                }
                if(x == fib[p1]){
                    a[i][j] = p1;
                }else{
                    if(fib[p1]-x < x-fib[p1-1]){
                        a[i][j] = -p1;
                    }else{
                        a[i][j] = -(p1-1);
                    }
                }
            }
        }
        long long smax = 0;
        int z = 0;
        k[z] = 0;
        k[m*n+1] = 0;
        for(int j = 1; j <= m; j++){
            for(int i = 1; i <= n; i++){
                z++;
                k[z] = a[i][j];
            }
        }
        int kk = 0;
        long long s1 = 0;
        long long s2 = 0;
        for(int j = 1; j <= z; j++){
            long long s = 0;
            bool ok = true;
            for(int i = j; i <= z; i++){
                if(k[i] > 0){
                    s = s+fib[(int)k[i]];
                }else{
                    j = i;
                    break;
                }
            }
            for(int i = j; i <= z; i++){
                if(k[i] < 0){
                    if(ok){
                        s = s + fib[(int)(-k[i])];
                    }else{
                        s = 0;
                        break;
                    }
                }else{
                    ok = false;
                    s = s+fib[(int)k[i]];
                }
                smax = max(smax, s);
            }
        }
        fout << smax;
    }
    return 0;
}
