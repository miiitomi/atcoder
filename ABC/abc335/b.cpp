#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> V;
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            for (int z = 0; z <= N; z++) {
                if (x + y + z <= N) {
                    V.push_back(vector<int>{x, y, z});
                }
            }
        }
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    for (auto v : V) {
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    }
}
