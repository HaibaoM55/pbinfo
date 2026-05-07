#include <fstream>
using namespace std;
ifstream cin("rotund.in");
ofstream cout("rotund.out");
int n, nr=0;
long long x, v[67];
bool rotund(long long y){
    int cif[15];
    cif[0] = 0;
    long long r = 0;
    do{
        r = r*10+y%10;
        cif[0]++;
        cif[cif[0]] = y%10;
        y = y/10;
    }while(y);
    for(int i = 2; i <= cif[0]; i++){
        long long r1 = 0;
        for(int j = i; j <= cif[0]; j++){
            r1 = r1*10+cif[j];
        }
        for(int j = 1; j < i; j++){
            r1 = r1*10+cif[j];
        }
        if(r1 == r){
            return true;
        }
    }
    return false;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(rotund(x)){
            nr++;
            v[nr] = x;
        }
    }
    cout << nr << '\n';
    for(int i = 1; i <= nr; i++){
        cout << v[i] << ' ';
    }
    return 0;
}
