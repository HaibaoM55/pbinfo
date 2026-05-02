
#include <string.h>
void Trim(char s[]){
	int lm1 = 0;
    int l = strlen(s);
    for(int i = 0; i < l; i++){
        if(s[i] == ' '){
        	lm1++;
        }else{
         	break;
        }
    }
    int lm = l;
    for(int i = l-1; i > 0; i--){
        if(s[i] == ' '){
            lm--;
        }else{
            break;
        }
    }
    for(int i = lm1; i < lm; i++){
        s[i-lm1] = s[i];
        s[i-lm1+1]=0;
    }
}
