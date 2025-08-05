#include <fstream>
using namespace std;
ifstream fin("low_memory.in");
ofstream fout("low_memory.out");
int n;
int main(){
    fin >> n;
    long long v[n];
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = n; i >= 1; i--){
        fout << v[i] << ' ';
    }
    return 0;
}
