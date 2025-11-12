#include <iostream>
#include <string.h>
using namespace std;
char x[260];
bool b[67];
int l;
int main(){
	cin.get(x, 260);
    l = strlen(x);
    for(int i = 0; i < l; i++){
        if('a' <= x[i] && x[i] <= 'z'){
            if(b[x[i]-'a'] == false){
            	cout << x[i] << ' ';
                b[x[i]-'a'] = true;
            }
        }
    }
}
