#include <fstream>
using namespace std;
ifstream fin("sume1.in");
ofstream fout("sume1.out");
long long n;
long long exponentiereRapida(long long a, long long b) {
    long long rasp = 1;
    a = a % 1000000007;
    while (b > 0) {
        if (b % 2 == 1) {
            rasp = (rasp * a) % 1000000007;
        }
        a = (a * a) % 1000000007;
        b /= 2;
    }
    return rasp;
}
int main(){
    fin >> n;
    long long rasp = exponentiereRapida(2, n+1)-1;
    if(rasp == -1){
        rasp = 1000000006;
    }
    fout << rasp;
    return 0;
}
