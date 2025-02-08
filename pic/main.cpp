#include <fstream>
using namespace std;
ifstream fin("pic.in");
ofstream fout("pic.out");
int c, n;
unsigned long long a[54][54];
unsigned long long v[54][54];
int afara = 0;
unsigned long long smax =0, suma = 0;
unsigned long long smaxi = 1;
int main()
{
    fin >> c;
    fin >> n;
    suma= 0;
    for(int i = 1; i <= n; i++){
        int s = 0;
        for(int j = 1; j <= i; j++){
            fin >> a[i][j];
            suma = suma+a[i][j];
            s = s + a[i][j];
        }
        if(s > smax){
            smax = s;
            smaxi = i;
        }
    }
    if(c == 1){
        fout << smaxi;
    }else{
        unsigned long long p1 = suma, p2 = 18037451331708310LL;
        unsigned long long crct=1;
        while(p1 <= p2){
            unsigned long long mij = (p1+p2)/2;
            unsigned long long x = mij;
            v[1][1] = x;
            bool corect = true;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                    if(v[i][j] >= a[i][j]){
                        unsigned long long dif = v[i][j]-a[i][j];
                        if(i != n){
                            v[i+1][j] += dif/2;
                            v[i+1][j+1] += dif/2;
                            if(dif % 2 == 1){
                                v[i+1][j]++;
                            }
                        }
                    }else{
                        corect = false;
                    }
                    v[i][j] = 0;
                }
            }
            if(corect){
                p2 = mij-1;
                crct = mij;
            }else{
                p1 = mij+1;
            }
        }
        fout << crct << ' ' << (unsigned long long)crct-suma;
    }
    return 0;
}
