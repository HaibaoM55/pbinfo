#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("unudoi.in");
ofstream fout("unudoi.out");
int n, m;
int a[50004], b[50004];
int nr = 0;
int ult[50004];
bool ok[50004];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int j = 1; j <= m; j++){
        fin >> b[j];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    int op1 = 0;
    bool ok = true;
    nr = n;
    for(int i = 1; i <= n; i++){
        int p1 = 1, p2 = m;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(b[mij] < a[i]){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        if(op1 == p1){
            nr--;
        }else{
            ok = true;
        }
        op1 =p1;
    }
    fout << nr;
    return 0;
}
