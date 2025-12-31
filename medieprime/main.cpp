#include <iostream>
#include <iomanip>
using namespace std;
bool ciur[10004];
int n, x;
int s=0,nr=0;
int main(){
    ciur[0] = true;
    ciur[1] = true;
    for(int i = 2; i <= 10000; i++){
        if(!ciur[i]){
            for(int j = i; j <= 10000/i; j++){
            	ciur[j*i] = true;
            }
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        if(ciur[x] == false){
        	s += x;
            nr++;
        }
    }
    double rasp = s;
    rasp = rasp/nr;
    long long r = rasp*100;
    cout << r/100 << '.' << r/10%10 << r%10;
}
