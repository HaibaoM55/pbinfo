#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("bucketsort.in");
ofstream fout("bucketsort.out");
int n;
int v[10004];
bool descrescator=false;
int main(){
	fin >> n;
    for(int i = 1; i <= n; i++){
    	fin >> v[i];
    }
    fin >> descrescator;
    sort(v+1, v+n+1);
    if(descrescator){
        for(int i = n; i >= 1; i--){
        	fout << v[i] << ' ';
        }
    }else{
        for(int i = 1; i <= n; i++){
        	fout << v[i] << ' ';
        }
    }
}
