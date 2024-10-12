#include <fstream>
using namespace std;
ifstream fin("memory009.in");
ofstream fout("memory009.out");
int n, m;
int x;
bool f1[34], f2[34];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f1[x]++;
    }
    for(int i = 1; i <= m; i++){
        fin >> x;
        f2[x]++;
    }
    for(int i = 0; i <= 30; i++){
        if(f1[i] && f2[i]){
            fout << i << ' ';
        }
    }
    return 0;
}
