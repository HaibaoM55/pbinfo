#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("smartphone1.in");
ofstream fout("smartphone1.out");
int n;
char x[12];
char c[10][9];
int nr = 0;
int main()
{
    fin >> n;
    strcpy(c[1],  "245");
    strcpy(c[2], "13456");
    strcpy(c[3], "256");
    strcpy(c[4], "12578");
    strcpy(c[5], "12346789");
    strcpy(c[6], "23589");
    strcpy(c[7], "458");
    strcpy(c[8], "45679");
    strcpy(c[9], "568");
    for(int i = 1; i <= n; i++){
        fin >> x;
        int l = strlen(x);
        bool ok = true;
        for(int j = 1; j <= l-1; j++){
            if(strchr(c[x[j-1]-'0'], x[j]) == 0){
                ok = false;
                break;
            }
        }
        if(ok){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
