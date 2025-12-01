#include <fstream>
using namespace std;
ifstream fin("mygo.in");
ofstream fout("mygo.out");
int v[14];
int main(){
    for(int i = 0; i <= 9; i++){
        fin >> v[i];
    }
    return 0;
}
