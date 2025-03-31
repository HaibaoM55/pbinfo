#include <fstream>
using namespace std;
ifstream fin("leduri.in");
ofstream fout("leduri.out");
int n,nr = 0, nrmax=0,nrmin=2e9;
bool a1[100004],a[100004], b[100004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a1[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }
    //cazul 1
    nr = 1;
    for(int i = 1; i <= n; i++){
        a[i] = a1[i];
    }
    a[1] = !a[1];
    a[2] = !a[2];
    for(int i = 1; i <= n-2; i++){
        if(a[i] != b[i]){
            a[i] = !a[i];
            a[i+1] = !a[i+1];
            a[i+2] = !a[i+2];
            nr++;
        }
    }
    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        nrmin = min(nrmin, nr);
    }
    //cazul 2
    nr = 0;
    for(int i = 1; i <= n; i++){
        a[i] = a1[i];
    }
    for(int i = 1; i <= n-2; i++){
        if(a[i] != b[i]){
            a[i] = !a[i];
            a[i+1] = !a[i+1];
            a[i+2] = !a[i+2];
            nr++;
        }
    }
    ok = true;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        nrmin = min(nrmin, nr);
    }
    //cazul 3
    nr = 1;
    for(int i = 1; i <= n; i++){
        a[i] = a1[i];
    }
    a[n] = !a[n];
    a[n-1] = !a[n-1];
    for(int i = 1; i <= n-2; i++){
        if(a[i] != b[i]){
            a[i] = !a[i];
            a[i+1] = !a[i+1];
            a[i+2] = !a[i+2];
            nr++;
        }
    }
    ok = true;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        nrmin = min(nrmin, nr);
    }
    //cazul 4
    nr = 2;
    for(int i = 1; i <= n; i++){
        a[i] = a1[i];
    }
    a[1] = !a[1];
    a[2] = !a[2];
    a[n] = !a[n];
    a[n-1] = !a[n-1];
    for(int i = 1; i <= n-2; i++){
        if(a[i] != b[i]){
            a[i] = !a[i];
            a[i+1] = !a[i+1];
            a[i+2] = !a[i+2];
            nr++;
        }
    }
    ok = true;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        nrmin = min(nrmin, nr);
    }
    fout << nrmin;
    return 0;
}
