#include <fstream>
using namespace std;
ifstream fin("aplusb.in");
ofstream fout("aplusb.out");
long long a, b;
long long s;
int main(){
    fin >> a >> b;
    s = a+b;
    fout << s;
    return 0;
}
