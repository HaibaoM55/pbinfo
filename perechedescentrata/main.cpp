#include <iostream>
#include <string>
#include <map>
using namespace std;
string prop, cuv;
map<string, bool> f1, f2;
int main(){
    getline(cin, prop);
    int l = prop.size();
    for(int i = 0; i <= l; i++){
        if('a' <= prop[i] && prop[i] <= 'z'){
            cuv.push_back(prop[i]);
        }else{
            int lc = cuv.size();
            if(lc % 2 == 0){
                f2[cuv] = true;
                cuv.erase(lc/2, 1);
                if(f1[cuv]){
                    cout << "DA";
                    return 0;
                }
            }else{
                f1[cuv] = true;
                string cuvnou = cuv.substr(0, (lc+1)/2);
                cuvnou = cuvnou.append(cuv.substr(lc/2, (lc+1)/2));
                if(f2[cuvnou]){
                    cout << "DA";
                    return 0;
                }
            }
            cuv.clear();
        }
    }
    cout << "NU";
    return 0;
}
