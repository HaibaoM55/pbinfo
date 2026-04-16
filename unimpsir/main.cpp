#include <fstream>
using namespace std;
ifstream fin("sir.in");
ofstream fout("sir.out");
int n;
long long a[100004], s[100004];
int main(){
    fin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    for(int i = 2; i <= n; i++){
        bool ok = false;
        int p1 = 1, p2 = n, p=1;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(s[mij] <= a[i]){
                p1 = mij+1;
                p = mij;
            }else{
                p2 = mij-1;
            }
        }
        if(s[p] == a[i]){
            fout << p;
        }else{
            fout << -1;
        }
        fout << '\n';
    }
    return 0;
}
