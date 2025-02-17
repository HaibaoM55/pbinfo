#include <iostream>
using namespace std;
int n;
int v[1004];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    bool ok = true;
    bool alt;
    if(v[1] > v[2]){
        alt = true;
    }else{
        alt = false;
    }
    for(int i = 2; i < n; i++){
        if(alt){
            if(v[i] >= v[i+1]){
                ok = false;
                break;
            }
        }else{
            if(v[i] <= v[i+1]){
                ok = false;
                break;
            }
        }
        alt = !alt;
    }
    if(ok){
        cout << "DA";
    }else{
        cout <<"NU";
    }
    return 0;
}
