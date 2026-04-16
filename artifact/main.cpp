#include <fstream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
ifstream fin("artifact.in");
ofstream fout("artifact.out");
int n, m;
char x[17];
long long f[37];
long long v[37];
int a[14];
int nr = 0, z=0;
vector<int> sir;
bool folosit[10];
bool numerge0[37];
void genereaza() {
    if(sir.size() == z){
        int zz = 0;
        long long fs = 0, vs = 0;
        bool mergeb = true;
        for(int x : sir){
            zz++;
            if(x == 0 && numerge0[a[zz]]){
                mergeb = false;
                break;
            }
            fs += f[a[zz]]*x;
            vs += v[a[zz]]*x;
        }
        if(mergeb && fs == vs){
            nr++;
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (!folosit[i]) {
            folosit[i] = true;
            sir.push_back(i);
            genereaza();
            sir.pop_back();
            folosit[i] = false;
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> x;
        int l = strlen(x);
        long long p = 1;
        if(l > 1) numerge0[x[0]-'A'] = true;
        for(int i = l-1; i >= 0; i--){
            f[x[i]-'A'] += p;
            p = p*10;
        }
    }
    for(int i = 1; i <= m; i++){
        fin >> x;
        int l = strlen(x);
        long long p = 1;
        if(l > 1) numerge0[x[0]-'A'] = true;
        for(int i = l-1; i >= 0; i--){
            v[x[i]-'A'] += p;
            p = p*10;
        }
    }
    for(int i = 0; i < 26; i++){
        if(f[i] > 0 || v[i] > 0){
            z++;
            a[z] = i;
        }
    }
    genereaza();
    fout << nr;
    return 0;
}
