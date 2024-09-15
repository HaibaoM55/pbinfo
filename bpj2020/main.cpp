#include <iostream>
#include <set>
using namespace std;

bool matrix[9][9];
struct CoordRel { // coordonate relative la un punct
    int x, y;
};
struct Piesa {
    int size;
    CoordRel *el;
};
Piesa piese[18];

void initPiese() {
    piese[1].size = 1;
    piese[1].el = new CoordRel[1];
    piese[1].el[0] = {0, 0};
    piese[2].size = 2;
    piese[2].el = new CoordRel[2];
    piese[2].el[0] = {0, 0};
    piese[2].el[1] = {0, 1};
    piese[3].size = 3;
    piese[3].el = new CoordRel[3];
    piese[3].el[0] = {0, 0};
    piese[3].el[1] = {0, 1};
    piese[3].el[2] = {0, 2};
    piese[4].size = 4;
    piese[4].el = new CoordRel[4];
    piese[4].el[0] = {0, 0};
    piese[4].el[1] = {0, 1};
    piese[4].el[2] = {0, 2};
    piese[4].el[3] = {0, 3};
    piese[5].size = 5;
    piese[5].el = new CoordRel[5];
    piese[5].el[0] = {0, 0};
    piese[5].el[1] = {0, 1};
    piese[5].el[2] = {0, 2};
    piese[5].el[3] = {0, 3};
    piese[5].el[4] = {0, 4};
    piese[6].size = 4;
    piese[6].el = new CoordRel[4];
    piese[6].el[0] = {0, 0};
    piese[6].el[1] = {0, 1};
    piese[6].el[2] = {1, 0};
    piese[6].el[3] = {1, 1};
    piese[7].size = 9;
    piese[7].el = new CoordRel[9];
    piese[7].el[0] = {0, 0};
    piese[7].el[1] = {0, 1};
    piese[7].el[2] = {0, 2};
    piese[7].el[3] = {1, 0};
    piese[7].el[4] = {1, 1};
    piese[7].el[5] = {1, 2};
    piese[7].el[6] = {2, 0};
    piese[7].el[7] = {2, 1};
    piese[7].el[8] = {2, 2};
    piese[8].size = 2;
    piese[8].el = new CoordRel[2];
    piese[8].el[0] = {0, 0};
    piese[8].el[1] = {1, 0};
    piese[9].size = 3;
    piese[9].el = new CoordRel[3];
    piese[9].el[0] = {0, 0};
    piese[9].el[1] = {1, 0};
    piese[9].el[2] = {2, 0};
    piese[10].size = 4;
    piese[10].el = new CoordRel[4];
    piese[10].el[0] = {0, 0};
    piese[10].el[1] = {1, 0};
    piese[10].el[2] = {2, 0};
    piese[10].el[3] = {3, 0};
    piese[11].size = 5;
    piese[11].el = new CoordRel[5];
    piese[11].el[0] = {0, 0};
    piese[11].el[1] = {1, 0};
    piese[11].el[2] = {2, 0};
    piese[11].el[3] = {3, 0};
    piese[11].el[4] = {4, 0};
    piese[12].size = 3;
    piese[12].el = new CoordRel[3];
    piese[12].el[0] = {0, 0};
    piese[12].el[1] = {1, 0};
    piese[12].el[2] = {0, 1};
    piese[13].size = 4;
    piese[13].el = new CoordRel[4];
    piese[13].el[0] = {0, 0};
    piese[13].el[1] = {1, -1};
    piese[13].el[2] = {1, 0};
    piese[13].el[3] = {1, 1};
    piese[14].size = 4;
    piese[14].el = new CoordRel[4];
    piese[14].el[0] = {0, 0};
    piese[14].el[1] = {1, 0};
    piese[14].el[2] = {1, 1};
    piese[14].el[3] = {2, 1};
    piese[15].size = 4;
    piese[15].el = new CoordRel[4];
    piese[15].el[0] = {0, 0};
    piese[15].el[1] = {0, 1};
    piese[15].el[2] = {1, -1};
    piese[15].el[3] = {1, 0};
    piese[16].size = 5;
    piese[16].el = new CoordRel[5];
    piese[16].el[0] = {0, 0};
    piese[16].el[1] = {0, 1};
    piese[16].el[2] = {0, 2};
    piese[16].el[3] = {1, 2};
    piese[16].el[4] = {2, 2};
    piese[17].size = 4;
    piese[17].el = new CoordRel[4];
    piese[17].el[0] = {0, 0};
    piese[17].el[1] = {1, 0};
    piese[17].el[2] = {1, 1};
    piese[17].el[3] = {1, 2};
}

int main(int argc, const char * argv[]) {
    FILE *fin, *fout;
    fin = fopen("bpj2020.in", "r");
    fout = fopen("bpj2020.out", "w");
    int n, scor = 0, a, l, c;
    initPiese();
    fscanf(fin, "%d", &n);
    while(n--) {
        fscanf(fin, "%d %d %d", &a, &l, &c);
        scor += piese[a].size;
        for(int i = 0; i < piese[a].size; i++) {
            int x, y;
            x = l + piese[a].el[i].x;
            y = c + piese[a].el[i].y;
            matrix[x][y] = true;
        }
        set<int> linii;
        set<int> coloane;
        for(int i = 1; i <= 8; i++) {
            bool isFull = true;
            for(int j = 1; j <= 8; j++) {
                if(!matrix[i][j]) {
                    isFull = false;
                    break;
                }
            }
            if(isFull) {
                linii.insert(i);
            }
        }
        for(int i = 1; i <= 8; i++) {
            bool isFull = true;
            for(int j = 1; j <= 8; j++) {
                if(!matrix[j][i]) {
                    isFull = false;
                    break;
                }
            }
            if(isFull) {
                coloane.insert(i);
            }
        }
        // aflam cate linii si coloane sunt complete
        int lFull = linii.size(),
            cFull = coloane.size();
        // actualizare matrice
        // parcurgem toate elementele matricii
        for(int i = 1; i <= 8; i++) {
            for(int j = 1; j <= 8; j++) {
                if(coloane.find(j) != coloane.end() || linii.find(i) != linii.end()) {
                    // daca i e o linie completa, sau j e o coloana completa
                    // atunci eliberam elemntul de pe pozitia ixj
                    matrix[i][j] = false;
                }
            }
        }
        // adaugam scorul corespunzator
        if(lFull + cFull == 1) {
            scor += 10;
        } else if(lFull + cFull == 2) {
            scor += 30;
        } else if(lFull + cFull == 3) {
            scor += 60;
        } else if(lFull + cFull == 4) {
            scor += 100;
        } else if(lFull + cFull == 5) {
            scor += 150;
        } else if(lFull + cFull == 6) {
            scor += 500;
        }
    }
    fprintf(fout, "%d", scor);
}
