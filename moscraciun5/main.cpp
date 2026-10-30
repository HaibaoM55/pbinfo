#include <fstream>
using namespace std;
ifstream fin("moscraciun5.in");
ofstream fout("moscraciun5.out");
int n, m;
int a[104][104];
bool viz[104][104];
int dirx[6] = {1,-1,0,0};
int diry[7] = {0,0,1,-1};
int rasp = 0;
void fill(int i, int j){
    rasp += a[i][j];
    for(int d = 0; d < 4; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(1 <= i1 && i1 <= n){
            if(1 <= j1 && j1 <= m){
                if(!viz[i1][j1] && a[i1][j1] != 0){
                    viz[i1][j1] = true;
                    fill(i1, j1);
                }
            }
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    viz[1][1] = true;
    fill(1, 1);
    fout << rasp;
	return 0;
}
