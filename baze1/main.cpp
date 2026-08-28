#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("baze1.in");
ofstream fout("baze1.out");
int b1, b2;
char s1[35], s2[35];
int s = 0;
int main(){
    fin >> b1 >> b2;
    fin >> s1 >> s2;
    int l = strlen(s1);
    int p = 1;
    for(int i = l-1; i >= 0; i--){
        s += (s1[i]-'0')*p;
        p = p*b1;
    }
    l = strlen(s2);
    p = 1;
    for(int i = l-1; i >= 0; i--){
        s += (s2[i]-'0')*p;
        p = p*b2;
    }
    fout << s;
    return 0;
}
