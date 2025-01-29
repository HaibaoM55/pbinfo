#include <fstream>
using namespace std;
ifstream fin("mere.in");
ofstream fout("mere.out");
int n, t, k;
int x, y;
int v[2000004];
int main()
{
    fin >> n >> t >> k;
    for(int i = 1; i <= t; i++){
        fin >> x >> y;
        int ig = x;
        for(int j = 0; j <= y-1; j++){
            v[ig]++;
            ig++;
            if(ig == n+1){
                ig = 1;
            }
        }
    }
    for(int i = 1; i <= k; i++){
        int q;
        fin >> q;
        fout << v[q] << ' ';
    }
    return 0;
}
