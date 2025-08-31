#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string MinLexSwap(string s){
    string dih = s;
    sort(dih.begin(), dih.end());

        int l = s.length();
    if(dih.compare(s) == 0){
        int i;
        for (i=l-2; s[i]==s[i+1]; i--)
            ;

        swap(s[i],s[i+1]);
        return s;
    }else{
        int f[27];
        for(int i = 1; i <= 26; i++){
            f[i] = -1;
        }
        for(int i = 0; i < l; i++){
            f[s[i]-'a'+1]=i;
        }
        for(int i = 0; i < l; i++){
            for(int j = 1; j <= s[i]-'a'; j++){
                if(f[j] == -1 || f[j] <= i){
                    continue;
                }
                swap(s[i], s[f[j]]);
                return s;
            }
        }
        return s;
    }
}/*
int main(){
    cout << MinLexSwap("abcdef");
    return 0;
}*/
