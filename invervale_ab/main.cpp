#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("intervale.in");
ofstream fout("intervale.out");
int n,a,b;
struct interval{
    int n;
    char tip;
}v[200004];
int s[200004];
bool compara(interval a, interval b){
    if(a.n < b.n){
        return true;
    }else if(a.n > b.n){
        return false;
    }else if(a.tip == 's' && b.tip == 'd'){
        return true;
    }
    return false;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a >> b;
        v[(i-1)*2+1].n = a;
        v[(i-1)*2+1].tip = 's';
        v[i*2].n = b;
        v[i*2].tip = 'd';
    }
    sort(v+1, v+2*n+1, compara);
    int nrmax = 0;
    for(int i = 1; i <= 2*n; i++){
        if(v[i].tip == 's'){
            s[i]++;
        }else{
            s[i+1]--;
        }
    }
    s[0] = 0;
    for(int i = 1; i <= 2*n; i++){
        s[i] = s[i-1]+s[i];
        nrmax = max(nrmax, s[i]);
    }
    fout << nrmax;
    return 0;
}
