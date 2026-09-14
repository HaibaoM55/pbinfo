#include <fstream>
using namespace std;
ifstream fin("urat.in");
ofstream fout("urat.out");
int n;
long long rasp = 0;
int main(){
    fin >> n;
    int z = n;
    for(int i = 1; i < n; i++){
        rasp += i;
    }
    fout << rasp << '\n';
    fout << -1;
    return 0;
}
