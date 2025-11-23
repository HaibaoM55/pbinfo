#include <iostream>
#include <string.h>
using namespace std;
char s[267];
int f[67];
int l;
int main(){
	cin.get(s, 267);
    l = strlen(s);
    for(int i = 0; i <= l; i++){
        if('a' <= s[i] && s[i] <= 'z'){
        	f[s[i]-'a']++;
        }else{
            bool ok = false;
            for(int i1 = 0; i1 <= 25; i1++){
                for(int j = 1; j <= f[i1]; j++){
                	cout << (char) (i1+'a');
                    ok=true;
                }
                f[i1] = 0;
            }
            if(ok){
            	cout << '\n';
            }
        }
    }
}
