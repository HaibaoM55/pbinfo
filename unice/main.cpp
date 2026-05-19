#include <fstream>
using namespace std;
ifstream fin("unice.in");
ofstream fout("unice.out");
int n, x;
int f[167];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
     	fin >> x;
        f[x]++;
    }
    for(int i = 0; i <= 99; i++){
        if(f[i] == 1){
            fout << i << ' ';
        }
    }
	return 0;
}
