#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("sumpow2.in");
ofstream fout("sumpow2.out");
char s1[24], s2[24];
int b[20];
int main(){
    fin >> s1 >> s2;
    int l = strlen(s1);
    for(int i = 0; i < l; i++){
        b[s1[i]-'a']++;
    }
    l = strlen(s2);
    for(int i = 0; i < l; i++){
        int x = s2[i]-'a';
        b[x]++;
        while(b[x] == 2){
            b[x] = 0;
            b[x+1]++;
            x++;
        }
    }
    for(int i = 0; i < 17; i++){
        if(b[i]){
            fout << (char) (i+'a');
        }
    }
    return 0;
}
