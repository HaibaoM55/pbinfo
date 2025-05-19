#include <fstream>
using namespace std;
ifstream fin("primxxl.in");
ofstream fout("primxxl.out");
int n, k, x;
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x;
    }
    return 0;
}
