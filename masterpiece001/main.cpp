#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("masterpiece001.in");
ofstream fout("masterpiece001.out");
int n;
int x;
short divz[400004];
int v[100004];
int divmax = 0, z = 0;
int main()
{
    divz[1] = 1;
    for(int i = 2; i <= 400000; i++){
        divz[i]++;
        for(int j = i; j <= 400000; j += i){
            divz[j]++;
        }
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(divz[x] > divmax){
            divmax = divz[x];
            z = 0;
        }
        if(divz[x] == divmax){
            z++;
            v[z] = x;
        }
    }
    sort(v+1, v+z+1);
    v[0] = 0;
    for(int i = 1; i <= z; i++){
        if(v[i-1] != v[i]){
            fout << v[i] << ' ';
        }
    }
    return 0;
}
