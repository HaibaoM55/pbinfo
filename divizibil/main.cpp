#include <iostream>
using namespace std;
int main(){
    int t, n, c1, c2, c3;
    cin >> t >> n >> c1 >> c2;
    if(t == 1){
        int g = n-(n/c1+n/c2);
        g = g+n/(c1*c2);
        cout << g;
    }else{
        cin >> c3;
        int g = n-(n/c1+n/c2+n/c3);
        g = g+n/(c1*c2)+n/(c2*c3)+n/(c1*c3)-n/(c1*c2*c3);
        cout << g;
    }
    return 0;
}
