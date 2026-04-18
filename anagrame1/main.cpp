#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");
char x[12];
int main(){
    fin >> x;
    int l = strlen(x);
    sort(x, x+l);
    do{
        fout << x << '\n';
    }while(next_permutation(x, x+l));
    return 0;
}
