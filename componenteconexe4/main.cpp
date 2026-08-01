#include <iostream>
using namespace std;
int n, m;
int Radacina(int k){
    if(T[k] == 0)
        return k;
    else
    {
        int x = Radacina(T[k]);
        T[k] = x;
        return x;
    }
}
void Unire(int k, int p)
{
    int rk = Radacina(k), rp = Radacina(p);
    if(rk != rp)
    {
        if(Rang[rk] > Rang[rp])
            T[rp] = rk;
        else
        {
            T[rk] = rp;
            if(Rang[rk] == Rang[rp])
                Rang[rp] ++;
        }
    }
}
int main(){
    //TODO
    return 0;
}
