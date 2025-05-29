#include <iostream>
#include <algorithm>
using namespace std;
int n, x;
int nrneg = 0, nrpoz = 0, nrzero = 0;
int neg[10004],poz[10004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x == 0){
            nrzero++;
        }else if(x > 0){
            nrpoz++;
            poz[nrpoz] = x;
        }else{
            nrneg++;
            neg[nrneg] = x;
        }
    }
    sort(poz+1, poz+nrpoz+1);
    sort(neg+1, neg+nrneg+1);
    for(int i = nrneg; i >= 1; i--){
        cout << neg[i] << ' ';
    }
    for(int i = 1; i <= nrzero; i++){
        cout << "0 ";
    }
    for(int i = nrpoz; i >= 1; i--){
        cout << poz[i] << ' ';
    }
    return 0;
}
