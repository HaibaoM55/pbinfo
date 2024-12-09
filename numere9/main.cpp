#include <fstream>
using namespace std;
ifstream fin("numere9.in");
ofstream fout("numere9.out");
int n;
bool f[250004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            fin >> x;
            f[x] = true;
        }
    }
    for(int i = 1; i <= n*n; i++){
        if(f[i] == false){
            fout << i << ' ';
            break;
        }
    }
    for(int i = n*n; i >= 1; i--){
        if(f[i] == false){
            fout << i;
            break;
        }
    }
    return 0;
}
