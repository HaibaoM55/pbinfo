#include <iostream>
#include <algorithm>
using namespace std;
int x, y;
unsigned int bst = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;
    if(x > y){
        int aux = x;
        x = y;
		y = aux;
    }
    long long minim = y-x;
    if (y-x < x){
        int d = y-x;
        int s = (x/d)+1;
        s = s*d;
        s = s-x;
        cout<<s;
    }else{
        for(int i=2; i*i <= y-x; i++){
            if((y-x) % i == 0){
                int z = i;
                if(z >= x && z < minim){
                    minim=z;
                }
                z = (y-x)/i;
                if(z >= x && z < minim){
                    minim = z;
                }
            }
        }
        cout << minim-x;
    }
    return 0;
}
