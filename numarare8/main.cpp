#include <fstream>
using namespace std;
ifstream cin("numarare8.in");
ofstream cout("numarare8.out");
int n;
int v[10004];
int f[10004];
int nrp = 143;
bool esteprim(int k){
    if(k < 2) return false;
    for(int i = 2; i*i <= k; i++){
    	if(k % i == 0) return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
        f[v[i]]++;
        if(f[v[i]]==1 && esteprim(v[i]) && v[i] >= 100 && v[i] <= 999){
        	nrp--;
        }
    }
    cout << nrp;
    return 0;
}
