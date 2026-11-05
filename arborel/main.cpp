#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("arborel.in");
ofstream fout("arborel.out");
int n;
int a[1003], ind[1003];
bool compara(int s, int d){
    return a[s] > a[d];
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        ind[i] = i;
    }
    sort(ind+1,ind+n+1,compara);
    if(n <= 10){
        for(int i = 2; i <= n; i++){
            fout << ind[1] << " " << ind[i] << "\n";
        }
    }else{
        int t = n/3 + n%3;
        int x = n/3 + (n%3 == 2);
        for(int i = 1; i < t; i++){
            fout << ind[i] << ' ' << ind[i+1] << '\n';
        }
        for(int i = t+1; i <= t+x; i++){
            fout << ind[i] << ' ' << ind[1] << '\n';
        }
        for(int i = t+x+1; i <= n; i++){
            fout << ind[i] << ' ' << ind[t] << '\n';
        }
    }
    return 0;
}
