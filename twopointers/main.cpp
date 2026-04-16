#include <iostream>
#include <map>
using namespace std;
int n;
char l1, l2;
char v[1000004];
int f[30][30];
int** dp = new int*[1000004];
char x, xu;
int pasif(char p, char pmm){
    char pn = p;
    int pasi1 = 0;
    while(pn != pmm){
        if(pn == 'z'){
            pn = 'a';
        }else{
            pn = (pn-'a'+1)+'a';
        }
        pasi1++;
    }
    int pasi2 = 0;
    pn = p;
    while(pn != pmm){
        if(pn == 'a'){
            pn = 'z';
        }else{
            pn = (pn-'a'-1)+'a';
        }
        pasi2++;
    }
    return min(pasi1, pasi2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l1 >> l2;
    for(int i = 0; i <= 25; i++){
        for(int j = 0; j <= 25; j++){
            f[i][j] = pasif(i+'a', j+'a');
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    dp[1] = new int[27];
    for(int j = 0; j < 26; j++){
        dp[1][j] = 2e9;
    }
    dp[1][l2-'a'] = f[l1-'a'][v[1]-'a']+1;
    if(f[l2-'a'][v[1]-'a']+1 < dp[1][l1-'a']){
        dp[1][l1-'a'] = f[l2-'a'][v[1]-'a']+1;
    }
    for(int i = 2; i <= n; i++){
        dp[i] = new int[27];
        for(int j = 0; j < 26; j++){
            dp[i][j] = 2e9;
        }
        char st = v[i-1];
        char cur = v[i];
        int ds = f[st-'a'][cur-'a']+1;
        for(int j = 0; j < 26; j++){
            if(dp[i-1][j] == 2e9){
                continue;
            }
            int ca = dp[i-1][j]+ds;
            if(ca < dp[i][j]){
                dp[i][j] = ca;
            }
            int cb = dp[i-1][j]+f[j][cur-'a']+1;
            if(cb < dp[i][st-'a']){
                dp[i][st-'a'] = cb;
            }
        }
        if(i >= 3){
            delete[] dp[i-2];
        }
    }
    int vmin = 2e9;
    for(int j = 0; j < 26; j++){
        if(dp[n][j] < vmin){
            vmin = dp[n][j];
        }
    }
    cout << vmin;
    return 0;
}
