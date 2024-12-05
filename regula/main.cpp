#include <iostream>
using namespace std;
int c, v, i;
int main()
{
    cin >> c;
    cin >> v;
    if(c == 1){
        int x = v;
        int nri = 0;
        for(i = 1; x > 0; i++){
            if(i % 2 != 0){
                nri++;
            }
            int s = i+nri;
            if(x > s){
                x = x - s;
            }else{
                break;
            }
        }
        if(x <= i){
            cout << x;
        }else{
            cout << 2*(x-i)-1;
        }
    }else{
        int x = 0;
        int nri = 0;
        for(int i = 1; i <= v-1; i++){
            if(i % 2 != 0){
                nri++;
            }
            x = x+i+nri;
        }
        cout << x+v;
    }
    return 0;
}
