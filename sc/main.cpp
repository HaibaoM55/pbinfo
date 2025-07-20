#include <string.h>
using namespace std;
int SC(char s[]){
	int l = strlen(s);
    int suma = 0;
    for(int i = 0; i < l; i++){
        if('0' <= s[i] && s[i] <= '9'){
        	suma = suma + (s[i]-'0');
        }
    }
    return suma;
}
