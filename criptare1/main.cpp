#include <fstream>
using namespace std;
ifstream fin("criptare1.in");
ofstream fout("criptare1.out");
string s, cheie;
int c[26];
char x[1004][1004];
int main(){
    fin >> s;
    fin >> cheie;
    int lc = cheie.size();
    int z = 0;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < lc; j++){
            if(cheie[j] == (i+'a')){
                z++;
                c[j+1] = z;
            }
        }
    }
    int l = s.size();
    int n = l/lc;
    z = 0;
    for(int k = 1; k <= lc; k++){
        for(int j = 1; j <= lc; j++){
            if(c[j] == k){
                for(int i = 1; i <= n; i++){
                    x[i][j] = s[z];
                    z++;
                }
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= lc; j++){
            if(x[i][j] == '*'){
                x[i][j] = ' ';
            }
            fout << x[i][j];
        }
    }
    return 0;
}
