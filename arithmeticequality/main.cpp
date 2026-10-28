#include <iostream>
using namespace std;
int n;
bool esteperfect(int x){
    int s = 0;
    int pr = 1;
    do{
        s += x%10;
        pr = pr*(x%10);
        x = x/10;
    }while(x);
    return s == pr;
}

int main(){
    cin >> n;
    int p = 1;
    for(int i = 1; i < n; i++){
        p = p*10;
    }
    int finl = p*10-1;
    int nr = 0;
    for(int i = p; i <= finl; i++){
        if(esteperfect(i)){
            nr++;
        }
    }
    cout << nr << ' ';
	return 0;
}
