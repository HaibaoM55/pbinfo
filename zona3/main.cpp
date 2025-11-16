#include <fstream>
using namespace std;
ifstream fin("zona3.in");
ofstream fout("zona3.out");
int n, m;
int a[104][104];
bool vizitat[104][104];
bool vizitatf[104][104];
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,-1,1};
int lee(int x, int y){
    vizitat[x][y] = true;
    int z = 1;
    for(int i = 0; i < 4; i++){
    	int x1 = x+dirx[i];
        int y1 = y+diry[i];
        if(1 <= x1 && x1 <= n){
            if(1 <= y1 && y1 <= m){
                if(!vizitat[x1][y1] && a[x1][y1] == 1){
                	vizitat[x1][y1] = true;
					z += lee(x1, y1);
                }
            }
        }
    }
	return z;
}
void fill(int x, int y, int val){
	vizitatf[x][y] = true;
    a[x][y] = val;
    for(int i = 0; i < 4; i++){
    	int x1 = x+dirx[i];
        int y1 = y+diry[i];
        if(1 <= x1 && x1 <= n){
            if(1 <= y1 && y1 <= m){
                if(!vizitatf[x1][y1] && a[x1][y1] == 1){
                	vizitatf[x1][y1] = true;
                	fill(x1, y1, val);
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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vizitat[i][j] && a[i][j] == 1){
                int x = lee(i, j);
                fill(i, j, x);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
        	fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
//linia 67 HAHfhafjanasfjahffjsaf s
