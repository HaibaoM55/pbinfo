#include <iostream>
using namespace std;
int n, m;
int s[200004], t[200004];
bool urc[200004], cob[200004];
int rasp = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> t[i];
	}
	for(int i = 1; i <= m; i++){
        if(s[i] < t[i]){
            if(!urc[s[i]]){
                urc[s[i]] = true;
                rasp++;
            }
            if(!urc[t[i]]){
                urc[t[i]] = true;
                rasp++;
            }
        }else{
            if(!cob[s[i]]){
                cob[s[i]] = true;
                rasp++;
            }
            if(!cob[t[i]]){
                cob[t[i]] = true;
                rasp++;
            }
        }
    }
    if(urc[n-1] && cob[n-1]){
        rasp--;
	}
	cout << rasp;
	return 0;
}
