#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("fractii4.in");
ofstream fout("fractii4.out");
int p, n;
int main()
{
    fin >> p >> n;
    if(p == 1){
        for(int i = 1; i <= n; i++){
            int a, b;
            fin >> a >> b;
            int g = __gcd(a, b);
            if(g == 1){
                fout << "-1\n";
            }else{
                int nr = 1;
                for(int j = 2; j*j <= g; j++){
                    if(g % j == 0){
                        nr++;
                        if(j*j < g){
                            nr++;
                        }
                    }
                }
                fout << nr << '\n';
            }
        }
    }else{
        for(int i = 1; i <= n; i++){
            int a, b;
            fin >> a >> b;
            int g = __gcd(a, b);
            fout << a/g << '/' << b/g << '\n';
        }
    }
    return 0;
}
