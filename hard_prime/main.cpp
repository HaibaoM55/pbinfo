#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("hard_prime.in");
ofstream fout("hard_prime.out");
int n, v[30004];
bool prim(int x) {
    if (x <= 3)
        return x >= 2;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int d = 5; d * d <= x; d += 6){
        if (x % d == 0 || x % (d + 2) == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; i++){
        if(v[i] != v[i-1] && prim(v[i])){
            fout << v[i] << ' ';
        }
    }
    return 0;
}
