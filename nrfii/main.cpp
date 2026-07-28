#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("nrfii.in");
ofstream fout("nrfii.out");
int n, k, x;
int f[104];
int vmax = 0;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
    	f[x]++;
        vmax = max(vmax, f[x]);
    }
    for(int i = 1; i <= n; i++){
        if(f[i] == vmax){
        	fout << i << ' ';
        }
    }
    return 0;
}
