#include <fstream>
using namespace std;
ifstream fin("inno.in");
ofstream fout("inno.out");
int n, k;
int a[200004];
int st[200004], dr[200004];
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    st[0] = 2147483647;
    st[1] = a[1];
    for(int i = 2; i <= n; i++){
        st[i] = st[i-1]&a[i];
    }
    dr[n+1] = 2147483647;
    dr[n] = a[n];
    for(int i = n-1; i >= 1; i--){
        dr[i] = dr[i+1] & a[i];
    }
    long long nr = 0;
    for(int i = n-1; i >= 0; i--){
        int p1 = i, p2 = n + 1, p = n + 2;
        while(p1 <= p2){
            int mij = (p1 + p2) / 2;
            int x = st[i] & dr[mij];
            if(__builtin_popcount(x) >= k){
                p2 = mij - 1;
                p = mij;
            }else{
                p1 = mij + 1;
            }
        }
        nr += n-p+2;
        if(i == 0){
            nr--;
        }
    }
    fout << nr;
    return 0;
}
