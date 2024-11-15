#include <fstream>
using namespace std;
ifstream fin("eliminarex.in");
ofstream fout("eliminarex.out");
int n, q;
int t[100004];
int x;
int main()
{
    fin >> n >> q;
    for(int i = 1; i <= n; i++){
        fin >> t[i];
    }
    for(int i = 1; i <= q; i++){
        fin >> x;
        int p1 = 1;
        int p2 = n;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(t[mij] < x){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        if(t[p1] == x){
            fout << "0\n";
        }else{
            fout << x-p2 << '\n';
        }
    }
    return 0;
}
