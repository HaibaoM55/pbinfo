#include <fstream>
using namespace std;
ifstream cin("partitiimultime2.in");
ofstream cout("partitiimultime2.out");
int n, p;
int x[16];
void bk(int k, int vm, int p){
    if(k == n+1){
        for(int i = 1; i <= p; i++){
            for(int j = 1; j <= n; j++){
                if(x[j] == i){
                    cout << j;
                }
            }
            cout << '*';
        }
        cout << '\n';
    }else{
        int vmax = vm+1;
        for(int i = 1; i <= vmax ; i++){
            x[k] = i;
            int z = max(vm, i);
            if(i == vmax){
                bk(k+1, z, p+1);
            }else{
                bk(k+1, z, p);
            }
        }
    }
}
int main()
{
    cin >> n;
    x[1] = 1;
    bk(2, 1, 1);
    return 0;
}
