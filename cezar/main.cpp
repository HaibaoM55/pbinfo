#include <iostream>
using namespace std;
string prop;
int n;
int main(){
    getline(cin, prop);
    cin >> n;
    int l = prop.size();
    for(int i = 0; i < l; i++){
        if('a' <= prop[i] && prop[i] <= 'z'){
            prop[i] = (prop[i]-'a'+n)%26+'a';
        }
    }
    cout << prop;
    return 0;
}
