#include <fstream>
#include <string>
using namespace std;
ifstream cin("atbash.in");
ofstream cout("atbash.out");
char c;
int f[30];
int main(){
    int z = 25;
    for(int i = 0; i < 26; i++){
        f[i] = z;
        z--;
    }
    while(cin >> c){
        c = f[c-'A']+'A';
        cout << c;
    }
    return 0;
}
