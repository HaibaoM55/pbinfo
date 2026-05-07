#include <string.h>
void SplitText(const char s[], char cuv[100][30], int &n){
	n = 0;
    int l = strlen(s);
    int z = 0;
    for(int i = 0; i <= l; i++){
        if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')){
        	cuv[n][z] = s[i];
            z++;
        }else{
            if(z > 0){
                cuv[n][z] = 0;
            	n++;
                z = 0;
            }
        }
    }
}
