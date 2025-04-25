#include <fstream>
using namespace std;
ifstream cin("puteri6.in");
ofstream cout("puteri6.out");
int n, x;
int f[11];
int main(){
    cin >> n;
    while(cin >> x){
        int p = 0;
        while(x > 1){
            p++;
            x = x/10;
        }
        f[p]++;
    }
    int p = 0;
    long long nr = 1;
    for(int i = 0; i <= 9; i++){
        if(p+f[i] < n){
            p += f[i];
        }else{
            cout << nr; 
            return 0;
        }
        nr = nr*10;
    }
    cout << "Nu exista";
    return 0;
}
