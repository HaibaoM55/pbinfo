#include <fstream>
using namespace std;
ifstream in("n_suma.in");
ofstream out("n_suma.out");
int main(){
    long long n,i,j,s;
    in >> n;
    s =0;
    for(i = 1; i <= n; i++){
        in >> j;
        s = s+j;
    }
    out << s;
    return 0;
}
