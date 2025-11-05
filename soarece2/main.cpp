#include <fstream>
#include <queue>
using namespace std;

ifstream fin("soarece2.in");
ofstream fout("soarece2.out");

int n, m;
char x[1004][1004];
bool viz[1004][1004];

struct poz {
    int i, j;
    int ptr;
    char tipdir;
};

poz c[1000004];
int st = 0, dr = 0;

int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, 1, -1};
char tipdir[4] = {'N', 'S', 'E', 'V'};

int start_i, start_j;
int end_i, end_j;

int main() {
    fin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            fin >> x[i][j];
            if(x[i][j] == 'S') {
                start_i = i;
                start_j = j;
            }
            if(x[i][j] == 'B') {
                end_i = i;
                end_j = j;
            }
        }
    }

    // Inițializare BFS
    c[0].i = start_i;
    c[0].j = start_j;
    c[0].ptr = -1;
    viz[start_i][start_j] = true;

    int gasit = -1;

    while(st <= dr) {
        int ci = c[st].i;
        int cj = c[st].j;

        // Verificăm dacă am ajuns la destinație
        if(ci == end_i && cj == end_j) {
            gasit = st;
            break;
        }

        // Explorăm vecinii
        for(int k = 0; k < 4; k++) {
            int ni = ci + dirx[k];
            int nj = cj + diry[k];

            // Verificăm limitele
            if(ni < 1 || ni > n || nj < 1 || nj > m) continue;

            // Verificăm obstacole și zone vizitate
            if(x[ni][nj] == '#' || viz[ni][nj]) continue;

            // Adăugăm în coadă
            dr++;
            c[dr].i = ni;
            c[dr].j = nj;
            c[dr].ptr = st;
            c[dr].tipdir = tipdir[k];
            viz[ni][nj] = true;

            // Verificăm dacă am ajuns la brânză
            if(ni == end_i && nj == end_j) {
                gasit = dr;
                st = dr + 1; // Forțăm oprirea
                break;
            }
        }

        st++;
    }

    // Afișăm rezultatul
    if(gasit == -1) {
        fout << "0\n";
    } else {
        // Reconstruim drumul
        char rasp[1000004];
        int z = 0;
        int curr = gasit;

        while(c[curr].ptr != -1) {
            rasp[z++] = c[curr].tipdir;
            curr = c[curr].ptr;
        }

        fout << z << '\n';
        for(int i = z - 1; i >= 0; i--) {
            fout << rasp[i];
        }
        fout << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}
