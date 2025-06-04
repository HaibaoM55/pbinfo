#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("magazin.in");
ofstream fout("magazin.out");
int n, m;
char t[200004];
int f[200004][27];
int f1[27];
char x[50004];
bool exista(int f1[27], int f2[27]){
    for(int i = 0; i < 26; i++){
        if(f1[i] > f2[i]){
            return false;
        }
    }
    return true;
}
int main(){
    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> t[i];
        for(int j = 0; j < 26; j++){
            f[i][j] = f[i-1][j];
        }
        f[i][t[i]-'a']++;
    }
    t[n] = 0;
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> x;
        int l = strlen(x);
        for(int j = 0; j < 26; j++){
            f1[j] = 0;
        }
        for(int j = 0; j < l; j++){
            f1[x[j]-'a']++;
        }
        int p1 = 0, p2 = n-1,p=-1;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(exista(f1, f[mij])){
                p2 = mij-1;
                p = mij;
            }else{
                p1 = mij+1;
            }
        }
        fout << p+1 << '\n';
    }
    return 0;
}
