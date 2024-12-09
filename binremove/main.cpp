#include <fstream>
using namespace std;
ifstream fin("binremove.in");
ofstream fout("binremove.out");
int n, p;
bool b[50004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }
    fin >> p;
    for(int i = 1; i <= p; i++){
        int x;
        fin >> x;
        x = n-x;
        for(int j = x; j <= n-1; j++){
            b[j] = b[j+1];
        }
        n--;
        int km = 0;
        int r = 0;
        for(int j = n; j >= 1; j--){
            if(b[j]){
                r++;
                if(km % 2 != 0){
                    r++;
                }
            }
            km++;
        }
        if(r % 3 == 0){
            fout << "1\n";
        }else{
            fout << "0\n";
        }
    }
    return 0;
}
