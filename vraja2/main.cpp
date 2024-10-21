#include <iostream>
using namespace std;
int n;
int v[1003];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    bool ok = true;
    int nr = 0;
    while(ok){
        ok = false;
        int maxim = 0, maximi;
        int z = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] == 0){
                z = 0;
            }else{
                z++;
                if(z > maxim){
                    maxim = z;
                    maximi = i;
                }
                ok = true;
            }
        }
        if(ok){
            int minim = 1000000;
            for(int i = maximi-maxim+1; i <= maximi; i++){
                minim = min(v[i], minim);
            }
            for(int i = maximi-maxim+1; i <= maximi; i++){
                v[i] = v[i]-minim;
            }
            nr++;
        }
    }
    cout << nr;
    return 0;
}
