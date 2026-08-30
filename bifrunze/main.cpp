#include <fstream>
using namespace std;
ifstream fin("bifrunze.in");
ofstream fout("bifrunze.out");
int n, x, y, z;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x >> y >> z;
        if(y == 0 && z == 0){
            fout << i << ' ';
        }
    }
    return 0;
}
