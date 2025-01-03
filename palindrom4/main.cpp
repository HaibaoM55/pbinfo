#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("palindrom.in");
ofstream fout("palindrom.out");
int n, c;
int v[50004];
char x[104];
long long r = 0;
int s;
bool estepalindrom(char p[104], int l){
    int z = l-1;
    for(int i = 0; i <= (l-1)/2; i++){
        if(p[i] != p[z]){
            return false;
        }
        z--;
    }
    return true;
}
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        int l = strlen(x);
        for(int j = 0; j <= l; j++){
            int z1 = 0;
            for(int z = j; z >= 1; z--){
                x[l+z-1] = x[z1];
                z1++;
            }
            if(estepalindrom(x, l+j)){
                v[i] = j;
                r = r + v[i];
                break;
            }
        }
    }
    if(c == 1){
        fout << r;
    }else{
        fin >> s;
        int zmax = 0;
        v[0] = 0;
        for(int i = 1; i <= n; i++){
            v[i] = v[i-1]+v[i];
        }
        for(int i = 1; i <= n; i++){
            int p1 = i, p2 = n;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(v[mij]-v[i-1] <= s){
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
            zmax = max(zmax, p2-i+1);
        }
        fout << zmax;
    }
    return 0;
}
