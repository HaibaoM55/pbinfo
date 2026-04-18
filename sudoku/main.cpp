#include <fstream>
using namespace std;
ifstream fin("sudoku.in");
ofstream fout("sudoku.out");
int a[14][14];
bool lin[14][14], col[14][14], box[14][14][14];
void build(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            lin[i][a[i][j]] = true;
        }
    }
    for(int j = 1; j <= 9; j++){
        for(int i = 1; i <= 9; i++){
            col[j][a[i][j]] = true;
        }
    }
    for(int i = 1; i <= 9; i += 3){
        for(int j = 1; j <= 9; j += 3){
            box[i][j][a[i][j]] = true;box[i][j][a[i][j+1]] = true;box[i][j][a[i][j+2]] = true;
            box[i][j][a[i+1][j]] = true;box[i][j][a[i+1][j+1]] = true;box[i][j][a[i+1][j+2]] = true;
            box[i][j][a[i+2][j]] = true;box[i][j][a[i+2][j+1]] = true;box[i][j][a[i+2][j+2]] = true;
        }
    }
}
void rezolva(){
    bool folos = false;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(a[i][j] == 0){
                int nrf = 0;
                int nrff = 0;
                for(int k = 1; k <= 9; k++){
                    bool ok = true;
                    if(lin[i][k] || col[j][k] || box[i][j][k]){
                        ok = false;
                    }
                    if(ok){
                        nrff = k;
                        nrf++;
                    }
                }
                if(nrf == 1){
                    folos = true;
                    a[i][j] = nrff;
                }
            }
        }
    }
    bool ok = true;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(a[i][j] == 0){
                ok = false;
                break;
            }
        }
    }
    if(!folos){
        return;
    }
    if(!ok){
        build();
        rezolva();
    }
}
int z = 0;
int pi[85], pj[85];
void backtrackstart(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(a[i][j] == 0){
                z++;
                pi[z] = i;
                pj[z] = j;
            }
        }
    }
}
bool verif(){
    for(int i = 1; i <= 9; i++){
        bool seen[10] = {false};
        for(int j = 1; j <= 9; j++){
            if(a[i][j] != 0){
                if(seen[a[i][j]]) return false;
                seen[a[i][j]] = true;
            }
        }
        fill(seen, seen + 10, false);
        for(int j = 1; j <= 9; j++){
            if(a[j][i] != 0){
                if(seen[a[j][i]]) return false;
                seen[a[j][i]] = true;
            }
        }
    }
    bool seen[10] = {false};
    for(int startRow = 1; startRow < 9; startRow += 3){
        for(int startCol = 1; startCol < 9; startCol += 3){
            fill(seen, seen + 10, false);
            for(int r = startRow; r <= startRow + 2; r++){
                for(int c = startCol; c <= startCol + 2; c++){
                    if(a[r][c] != 0){
                        if(seen[a[r][c]]) return false;
                        seen[a[r][c]] = true;
                    }
                }
            }
        }
    }
    return true;
}
bool continua = true;
void backtrack(int k){
    if(!continua) return;
    if(k == z+1){
        continua = false;
        return;
    }
    for(int i = 1; i <= 9; i++){
        a[pi[k]][pj[k]] = i;
        if(verif()){
            backtrack(k+1);
            if(continua) return;
        }
        a[pi[k]][pj[k]] = 0;
    }
}
int main(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            fin >> a[i][j];
        }
    }
    build();
    rezolva();
    backtrackstart();
    backtrack(1);
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
