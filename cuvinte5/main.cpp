#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char vocale[] = "aeiouAEIOU";
string prop, cuv[34];
int nrmax = 0;
int main(){
    getline(cin, prop);
    int l = prop.size();
    int nr = 1;
    for(int i = 0; i <= l; i++){
        if(('a' <= prop[i] && prop[i] <= 'z') || ('A' <= prop[i] && prop[i] <= 'Z')){
            cuv[nr].push_back(prop[i]);
        }else{
            if(cuv[nr].size() > 0){
                nr++;
            }
        }
    }
    nr--;
    int p = 0;
    for(int i = 1; i <= nr; i++){
        if(strchr(vocale, cuv[i][0]) != 0 && strchr(vocale, cuv[i][cuv[i].size()-1]) != 0){
            p++;
        }
    }
    cout << p << '\n';
    int lmax = 0;
    for(int i = 1; i <= nr; i++){
        if(strchr(vocale, cuv[i][0]) != 0 && strchr(vocale, cuv[i][cuv[i].size()-1]) != 0){
            cout << cuv[i] << '\n';
            int l1 = cuv[i].size();
            lmax = max(lmax, l1);
        }
    }
    cout << lmax;
    return 0;
}
