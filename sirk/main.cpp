#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    int elmsir = 0;
    for(int k = 1; k <= 50000; k++){
        if(k*k+k > n-1){
            elmsir=k;
            break;
        }
    }
    int pozcorecta = elmsir*elmsir+elmsir-n+1;
    int p = 1;
    for(int i = 1; i <= 2*elmsir; i++){
         if(i <= elmsir){
            p++;
         }else{
            p--;
         }
         if(i == pozcorecta){
            cout << p;
            return 0;
         }
    }
    return 0;
}
