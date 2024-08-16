#include <fstream>
using namespace std;
ifstream fin("cb1.in");
ofstream fout("cb1.out");
int n, q;
int v[50004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    fin >> q;
    for(int j = 1; j <= q; j++){
        int x, y;
        fin >> x >> y;
        int z = 0;
        // nr mai mici sau egale cu y
        int p1 = 1, p2 = n;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v[mij] > y){
                p2 = mij-1;
            }else{
                p1 = mij+1;
            }
        }
        if(x == 1){
            fout << p2 << '\n';
        }else if(x == 2){
            fout << n-p1+1 << '\n';
        }else{
            int nr = 0;
            for(int i = p2; i >= 1; i--){
                if(v[i] == y){
                    nr++;
                }else{
                    break;
                }
            }
            fout << nr << '\n';
        }
    }
    return 0;
}
