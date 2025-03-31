#include <fstream>
#include <map>
using namespace std;
ifstream fin("patru.in");
ofstream fout("patru.out");
int n;
int v[10004];
int f[1000004];
map<int, int> f1;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(n <= 2000){
        long long nr = 0;
        for(int i1 = 3; i1 < n; i1++){
            for(int i2 = 1; i2 < i1-1; i2++){
                if(v[i1-1] <= 2147483647/v[i2]){
                    f1[v[i1-1]*v[i2]]++;
                }
            }
            for(int i2 = i1+1; i2 <= n; i2++){
                if(v[i2] % v[i1] == 0){
                    nr += f1[v[i2]/v[i1]];
                }
            }
        }
        fout << nr;
    }else{
        long long nr = 0;
        for(int i1 = 3; i1 < n; i1++){
            for(int i2 = 1; i2 < i1-1; i2++){
                if(v[i1-1] <= 1000000/v[i2]){
                    f[v[i1-1]*v[i2]]++;
                }
            }
            for(int i2 = i1+1; i2 <= n; i2++){
                if(v[i2] % v[i1] == 0){
                    nr += f[v[i2]/v[i1]];
                }
            }
        }
        fout << nr;
    }
    return 0;
}
