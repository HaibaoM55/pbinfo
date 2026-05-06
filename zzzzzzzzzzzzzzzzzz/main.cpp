#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Bloc {
    int id;
    int start;
    int dimensiune;

    int sfarsit() const {
        return start + dimensiune - 1;
    }
};

class HeapManager {
    vector<Bloc> alocari;
    const int MAX_MEM = 1000;

public:
    void alloc(int id, int dim) {
        int adresaCurenta = 0;
        bool alocat = false;

        // Sortăm după adresa de start pentru a parcurge memoria liniar
        sort(alocari.begin(), alocari.end(), [](const Bloc& a, const Bloc& b) {
            return a.start < b.start;
        });

        for (const auto& b : alocari) {
            if (b.start - adresaCurenta >= dim) {
                alocari.push_back({id, adresaCurenta, dim});
                alocat = true;
                break;
            }
            adresaCurenta = b.sfarsit() + 1;
        }

        if (!alocat && MAX_MEM - adresaCurenta >= dim) {
            alocari.push_back({id, adresaCurenta, dim});
        }
    }

    void free(int id) {
        for (auto it = alocari.begin(); it != alocari.end(); ) {
            if (it->id == id) {
                it = alocari.erase(it);
            } else {
                ++it;
            }
        }
    }

    void defrag() {
        int adresaLibera = 0;
        // Sortăm pentru a păstra ordinea originală a adreselor
        sort(alocari.begin(), alocari.end(), [](const Bloc& a, const Bloc& b) {
            return a.start < b.start;
        });

        for (int i = 0; i < alocari.size(); i++) {
            alocari[i].start = adresaLibera;
            adresaLibera = alocari[i].sfarsit() + 1;
        }
    }

    void print() {
        sort(alocari.begin(), alocari.end(), [](const Bloc& a, const Bloc& b) {
            return a.start < b.start;
        });

        if(alocari.empty()) {
            cout << "Empty" << endl;
            return;
        }

        for (int i = 0; i < alocari.size(); i++) {
            cout << "[" << alocari[i].id << ": " << alocari[i].start
                 << "-" << alocari[i].sfarsit() << "] ";
        }
        cout << endl;
    }
};

int main() {
    HeapManager manager;
    int M;
    cin >> M;

    while (M--) {
        string comanda;
        cin >> comanda;
        if (comanda == "ALLOC") {
            int id, dim;
            cin >> id >> dim;
            manager.alloc(id, dim);
        } else if (comanda == "FREE") {
            int id;
            cin >> id;
            manager.free(id);
        } else if (comanda == "DEFRAG") {
            manager.defrag();
        }
    }

    manager.print();
    return 0;
}
