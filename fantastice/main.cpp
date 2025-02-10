#include <fstream>
using namespace std;
ifstream fin("fantastice.in");
ofstream fout("fantastice.out");
int n, x;
int ciur[1000004];
int nr = 0;
int main()
{
    for(int i = 2; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j+= i){
            ciur[j]++;
        }
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(ciur[ciur[x]+1] == 1){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
