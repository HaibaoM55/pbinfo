#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string prop;
char vocale[] = "aeiouAEIOU";
int main(){
    getline(cin, prop);
    int l = prop.size();
    int nr = 0;
    for(int i = 0; i < l; i++){
        if(strchr(vocale, prop[i]) != 0){
            nr++;
        }
    }
    cout << nr;
    return 0;
}
