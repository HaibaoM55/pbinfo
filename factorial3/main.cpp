#include <fstream>
using namespace std;
ifstream fin("factorial3.in");
ofstream fout("factorial3.out");
int n;
bool ciur[404];
int prm[104], nrp=0;
long long s = 0;
int main()
{
    fin >> n;
    for(int i = 2; i <= 400; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 400/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int x = i;
        for(int j = 1; j <= nrp && prm[j]*prm[j] <= x; j++){
            while(x % prm[j] == 0){
                x = x / prm[j];
                s++;
            }
        }
        if(x > 1){
            s++;
        }
    }
    /*for(int i = 1; i <= nrp; i++){

        x = n;
        e = 0;
        do{
            x = x/ prm[i];
            e += x;
        }while(x > 0);
        s = s + e;

    }*/
    fout << s;
    return 0;
}
