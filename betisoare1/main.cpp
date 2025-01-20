#include <fstream>
using namespace std;
ifstream fin("betisoare1.in");
ofstream fout("betisoare1.out");
int n;
bool b[1004],tip;
char x;
int nrap=0, nrsmax = 0, nrs = 1;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(x == '1'){
            b[i] = true;
        }else{
            b[i] = false;
        }
        if(i > 1){
            if(b[i] == b[i-1]){
                nrs++;
                if(nrs > nrsmax){
                    nrsmax = nrs;
                    nrap = 1;
                    tip = b[i];
                }else if(nrs == nrsmax){
                    if(tip == false &&  b[i] == true){
                        tip = true;
                        nrap = 1;
                    }else if(b[i] == tip){
                        nrap++;
                    }
                }
            }else{
                nrs = 1;
            }
        }
    }
    fout << tip << ' ' << nrsmax<<'\n';
    fout << nrap;
    return 0;
}
