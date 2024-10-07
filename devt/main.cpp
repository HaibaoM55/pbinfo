#include <fstream>
using namespace std;
ifstream fin("devt.in");
ofstream fout("devt.out");
int n, k;
int s[100004];
int main()
{
    fin >> n >> k;
    for(int i = 2; i <= 100000; i++){
        if(s[i] == 0){
            for(int j = i; j <= 100000/i; j++){
                s[j*i] = 1;
            }
        }
    }
    s[0] = 0;
    s[1] = 1;
    for(int i = 2; i <= n; i++){
        s[i] = s[i-1]+s[i];
    }
    for(int i = 1; i <= k; i++){
        int a, b;
        fin >> a >> b;
        if(a == 0){
            fout << s[b] << '\n';
        }else{
            fout << s[b]-s[a-1] << '\n';
        }
    }
    return 0;
}
