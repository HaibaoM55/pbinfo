#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int v[20004];
int pc1[20004], pc2[20004];
int nrp1=0, nrp2=0, nrp0=0;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        char tip[30];
        cin >> tip;
        if(tip[2] == '0'){
            pc1[0]++;
            pc1[pc1[0]] = v[i];
        }else{
            pc2[0]++;
            pc2[pc2[0]] = v[i];
        }
    }
    for(int i = 1; i <= m; i++){
        char tip[30];
        cin >> tip;
        if(tip[2] == '0'){
            nrp1++;
        }else if(tip[2] == '6'){
            nrp2++;
        }else{
            nrp0++;
        }
    }
    sort(pc1+1, pc1+pc1[0]+1);
    sort(pc2+1, pc2+pc2[0]+1);
    int rasp = 0;
    while(nrp1 && pc1[0]){
        rasp += pc1[pc1[0]];
        pc1[0]--;
        nrp1--;
    }
    while(nrp2 && pc2[0]){
        rasp += pc2[pc2[0]];
        pc2[0]--;
        nrp2--;
    }
    while(nrp0){
        if(pc1[0] == 0){
            rasp += pc2[pc2[0]];
            pc2[0]--;
        }else if(pc2[0] == 0){
            rasp += pc1[pc1[0]];
            pc1[0]--;
        }else if(pc1[pc1[0]] > pc2[pc2[0]]){
            rasp += pc1[pc1[0]];
            pc1[0]--;
        }else{
            rasp += pc2[pc2[0]];
            pc2[0]--;
        }
        nrp0--;
    }
    cout << rasp;
	return 0;
}
