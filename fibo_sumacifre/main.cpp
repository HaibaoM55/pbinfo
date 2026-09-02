#include <iostream>
using namespace std;
unsigned long long n;
int f[104] = {1,1,2,3,5,8,4,3,7,1,8,9,8,8,7,6,4,1,5,6,2,8,1,9};
int main(){
    cin >> n;
    int rasp = n%24;
    if(rasp == 0){
        rasp = 24;
    }
    cout << f[rasp-1];
    return 0;
}
