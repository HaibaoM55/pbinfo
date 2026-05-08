#include <fstream>
#include <string>
#include <map>
using namespace std;
ifstream fin("polybius.in");
ofstream fout("polybius.out");
int cer;
string t, cuv;
char x[6][7];
pair<int, int> f[41];
char a, b;
int main(){
    fin >> cer;
    fin >> t;
    int z = 0;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            x[i][j] = t[z];
            f[t[z]-'A'] = {i, j};
            z++;
        }
    }
    if(cer == 1){
        fin >> cuv;
        int l = cuv.size();
        for(int k = 0; k < l; k++){
            fout << f[cuv[k]-'A'].first << f[cuv[k]-'A'].second;
        }
    }else{
        while(fin >> a){
            fin >> b;
            fout << x[a-'0'][b-'0'];
        }
    }
    return 0;
}
