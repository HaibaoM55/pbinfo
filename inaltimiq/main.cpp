#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct copil{
	int numar, inaltime;
}v[1004];
bool compara(copil a, copil b){
	return a.inaltime < b.inaltime;
}
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
        v[i].numar = i;
     	cin >> v[i].inaltime;
    }
    sort(v+1, v+n+1, compara);
    for(int i = 1; i <= n; i++){
    	cout << v[i].numar << ' ' ;
	}
}
