#include <iostream>
using namespace std;
int a, b;
int nr = 0;
int main()
{
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        int x = i;
        bool ok =true;
        do{
            int cif = x%10;
            if(cif != 0){
                if(i % cif != 0){
                    ok = false;
                    break;
                }
            }
            x = x/10;
        }while(x > 0);
        if(ok){
            nr++;
        }
    }
    cout << nr;
    return 0;
}
