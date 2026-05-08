#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
string prop;
set<string> cuv;
string c;
int main(){
    getline(cin, prop);
    int l = prop.size();
    for(int i = 0; i <= l; i++){
        if(prop[i] == ' ' || prop[i] == 0){
            if(!c.empty()){
                cuv.insert(c);
                c.clear();
            }
        }else{
            c.push_back(prop[i]);
        }
    }
    int n = cuv.size();
    for(auto it = cuv.begin(); it != cuv.end(); it++){
        cout << *it << '\n';
    }
    return 0;
}
