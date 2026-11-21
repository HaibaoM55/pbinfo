#include <fstream>
#include <set>
using namespace std;
ifstream fin("dominew.in");
ofstream fout("dominew.out");
int n, m, x;
int v[1000004], a[8004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> x;
        a[i] = x;
        int p1 = 1, p2 = n, p = 0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v[mij] < x){
                p = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                p++;
            }
        }
        fout << p+1 << ' ';
    }
}
