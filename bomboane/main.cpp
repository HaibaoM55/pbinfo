#include <iostream>
#include <set>
#include <vector>

using namespace std;

void read_vector(vector<int> &v)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

multiset<int> get_unpaired_elements(vector<int> v, int target)
{
    multiset<int> result;

    for (int &val : v) {
        //cout << val << ' ';
        if (result.find(target - val) != result.end()) {
            result.erase(result.find(target-val));
        } else {
            result.insert(val);
        }
    }

    return result;
}

int main(void)
{
    vector<int> v;

    read_vector(v);

    int target;
    cin >> target;

    multiset<int> result = get_unpaired_elements(v, target);

    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
