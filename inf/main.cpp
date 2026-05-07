#include <fstream>
using namespace std;
ifstream fin("inf.in");
ofstream fout("inf.out");
int n, k;
char x[1500004];
char nextC(char p){
    if(p == 'I') return 'N';
    if(p == 'N') return 'F';
    if(p == 'F') return 'I';
}
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x[i];
    }
    int nrmin = k;
    for(int i = 1; i <= n-k+1; i++){
        char curC;
        int nr;
        nr = 0;
        curC = 'I';
        for(int j = i; j <= i+k-1; j++){
            if(x[j] != curC){
                nr++;
            }
            curC = nextC(curC);
        }
        nrmin = min(nrmin, nr);
        nr = 0;
        curC = 'N';
        for(int j = i; j <= i+k-1; j++){
            if(x[j] != curC){
                nr++;
            }
            curC = nextC(curC);
        }
        nrmin = min(nrmin, nr);
        nr = 0;
        curC = 'F';
        for(int j = i; j <= i+k-1; j++){
            if(x[j] != curC){
                nr++;
            }
            curC = nextC(curC);
        }
        nrmin = min(nrmin, nr);
    }
    fout << nrmin;
    return 0;
}
