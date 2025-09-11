#include <fstream>
using namespace std;
ifstream fin("pozitiiconsecutive.in");
ofstream fout("pozitiiconsecutive.out");
int a, b;
int f[100004];
int main(){
    fin >> a >>b;
    f[0] = 0;
    f[1] = 3;
    for(int i = 0; i <= 100000; i++){
        if(i >= 2){
            f[i] = 2*f[i-1]-f[i-2]+2;
        }
        if(f[i] == b){
            for(int j = i; j >= 0; j--){
                fout << f[j] << ' ';
            }
        }
    }
    return 0;
}
