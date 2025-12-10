#include <fstream>
using namespace std;
#define BLOC_SIZE 450
ifstream fin("spiridusi.in");
ofstream fout("spiridusi.out");
int n, q;
char x;
bool b[250004];
struct bloc{
    int vmax;
    int in, sf;
}rasp[BLOC_SIZE];
int tip;
int y, z;
void construieste_bloc(int nrb){
    int nrf = nrb*BLOC_SIZE;
    if(nrf > n){
        nrf = n;
    }
    int vmax = 0, nr = 0;
    for(int i = (nrb-1)*BLOC_SIZE+1; i <= nrf; i++){
        if(b[i]){
            nr++;
        }else{
            nr = 0;
        }
        vmax = max(vmax, nr);
    }
    rasp[nrb].vmax = vmax;
    rasp[nrb].in = 0;
    for(int i = (nrb-1)*BLOC_SIZE+1; i <= nrf; i++){
        if(b[i]){
            rasp[nrb].in++;
        }else{
            break;
        }
    }
    rasp[nrb].sf = 0;
    for(int i = nrf; i >= (nrb-1)*BLOC_SIZE+1; i--){
        if(b[i]){
            rasp[nrb].sf++;
        }else{
            break;
        }
    }
}
void initializare(){
    int nr_blocuri = (n+BLOC_SIZE-1)/BLOC_SIZE;
    for(int i = 1; i <= nr_blocuri; i++){
        construieste_bloc(i);
    }
}
int raspuns(int i, int j){
    int vmax = 0;
    int bloc1 = (i-1)/BLOC_SIZE+1;
    int bloc2 = (j-1)/BLOC_SIZE+1;
    int nr = 0;
    int sf1 = bloc1*BLOC_SIZE;
    if(bloc1 == bloc2){
        for(int z = i; z <= j; z++){
            if(b[z]){
                nr++;
            }else{
                nr = 0;
            }
            vmax = max(nr, vmax);
        }
        return vmax;
    }
    for(int z = i; z <= sf1; z++){
        if(b[z]){
            nr++;
        }else{
            nr = 0;
        }
        vmax = max(nr, vmax);
    }
    for(int z = bloc1+1; z <= bloc2-1; z++){
        if(rasp[z].in == BLOC_SIZE){
            nr += BLOC_SIZE;
            vmax = max(vmax, nr);
        }else{
            nr += rasp[z].in;
            vmax = max(vmax, nr);
            vmax = max(vmax, rasp[z].vmax);
            nr = rasp[z].sf;
        }
    }
    for(int z = (bloc2-1)*BLOC_SIZE+1; z <= j; z++){
        if(b[z]){
            nr++;
        }else{
            nr = 0;
        }
        vmax = max(nr, vmax);
    }
    return vmax;
}
int main(){
    fin >> n >> q;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(x == '1'){
            b[i] = true;
        }else{
            b[i] = false;
        }
    }
    initializare();
    for(int i = 1; i <= q; i++){
        fin >> tip >> y;
        if(tip == 1){
            b[y] = !b[y];
            int bloc = (y-1)/BLOC_SIZE+1;
            construieste_bloc(bloc);
        }else{
            fin >> z;
            fout << raspuns(y, z) << '\n';
        }
    }
    return 0;
}
