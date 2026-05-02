#include <iostream>
using namespace std;
int n, m;
int victorii[101] = {0}, egaluri[101] = {0}, infrangeri[101] = {0};
int puncte[101] = {0};
int golMarcate[101] = {0}, golPrimite[101] = {0};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int e1, g1, e2, g2;
        cin >> e1 >> g1 >> e2 >> g2;

        golMarcate[e1] += g1;
        golMarcate[e2] += g2;
        golPrimite[e1] += g2;
        golPrimite[e2] += g1;

        if (g1 > g2)
        {
            victorii[e1]++;
            infrangeri[e2]++;
            puncte[e1] += 3;
        }
        else if (g1 == g2)
        {
            cout << "CAZ2Z" << e1 << ' '<< e2 << '\n';
            egaluri[e1]++;
            egaluri[e2]++;
            puncte[e1] += 1;
            puncte[e2] += 1;
        }
        else
        {
            victorii[e2]++;
            infrangeri[e1]++;
            puncte[e2] += 3;
        }
    }

    for (int i = 1; i <= n; i++){
        cout << "Echipa " << i << ": "
             << victorii[i] << " " << egaluri[i] << " " << infrangeri[i] << "\n";
    }
    for (int i = 1; i <= n; i++)
        cout << "Echipa " << i << ": " << puncte[i] << " puncte\n";

    int maxGoluri = golMarcate[1], idxGolgheter = 1;
    for (int i = 2; i <= n; i++)
    {
        if (golMarcate[i] > maxGoluri)
        {
            maxGoluri = golMarcate[i];
            idxGolgheter = i;
        }
    }
    cout << "Golgheter: echipa " << idxGolgheter << " cu " << maxGoluri << " goluri\n";

    for (int i = 1; i <= n; i++)
        cout << "Echipa " << i << ": diferenta "
             << golMarcate[i] - golPrimite[i] << "\n";

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int p;
        cin >> p;
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (puncte[j] >= p)
                cnt++;
        }
        if (cnt == 0)
            cout << "niciuna\n";
        else
            cout << cnt << "\n";
    }

    return 0;
}
