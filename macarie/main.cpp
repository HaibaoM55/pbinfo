#include <fstream>
using namespace std;
ifstream fin("macarie.in");
ofstream fout("macarie.out");
int n, q;
int b[1000004];
int f[1000004];
int x;
int main()
{
    fin >> n >> q;
    for(int i = 1; i <= n; i++){
        fin >> x;
        b[x]++;
    }
    for(int i = 1; i <= 1000000; i++){
        for(int j = 1; j*i <=1000000; j++){
            for(int p = 1; p <= b[j*i]; p++){
                f[i]++;
            }
        }
    }
    for(int i = 1; i <= 1000000; i++){
        f[i] = f[i-1]+f[i];
    }
    for(int i = 1; i <= q; i++){
        fin >> x;
        int p1 = 1;
        int p2 = 1000000;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(f[mij] < x){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        fout << p1 << ' ';
    }
    return 0;
}
