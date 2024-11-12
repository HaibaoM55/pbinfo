#include <fstream>
using namespace std;
ifstream fin("mcub.in");
ofstream fout("mcub.out");
int n;
long long nr = 0;
int v[100004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] >= v[i-1]){
            nr = nr + (v[i]-v[i-1]);
        }
    }
    fout << nr;
    return 0;
}
