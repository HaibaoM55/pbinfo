#include <fstream>
using namespace std;
ifstream fin("summit.in");
ofstream fout("summit.out");
int n, x;
long long s[1000004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        s[i] = s[i-1]+x;
    }
    for(int i = 1; i <= n; i++){
        int p1 = 1, p2 = i, p = 0;
        x = s[i]-s[i-1];
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(s[mij] == x){
                p = mij;
                break;
            }
            if(s[mij] < x){
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        fout << p << '\n';
    }
    return 0;
}
