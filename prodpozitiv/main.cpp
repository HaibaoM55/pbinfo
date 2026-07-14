#include <fstream>
using namespace std;
ifstream cin("prodpozitiv.in");
ofstream cout("prodpozitiv.out");
int n, x, nrm = 2e9, nr0=0;
int nrn = 0;
int nr = 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x == 0){
            nr0++;
        }else if(x < 0){
            nrm = min(nrm, 1-x);
            nrn++;
        }
    }
    nr = nr0;
    if(nrn % 2 != 0){
        nr += nrm;
    }
    cout << nr;
    return 0;
}
