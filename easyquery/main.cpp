#include <fstream>
using namespace std;
ifstream fin("easyquery.in");
ofstream fout("easyquery.out");
int n, t;
int v[100003];
long long mars[100003];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    fin >> t;
    for(int i = 1; i <= t; i++){
        int a, x, y, p;
        fin >> a >> x >> y >> p;
        if(a == 1){
            mars[x] += p;
            mars[y+1] -= p;
        }else{
            mars[x] -= p;
            mars[y+1] += p;
        }
    }
    mars[0] = 0;
    for(int i = 1; i <= n; i++){
        mars[i] += mars[i-1];
        fout << v[i]+mars[i] << ' ';
    }
    return 0;
}
