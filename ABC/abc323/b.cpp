#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<pair<int,int>> V(N, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        V[i].second = i;
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') V[i].first--;
        }
    }
    sort(V.begin(), V.end());

    for (auto v : V) cout << v.second + 1 << " ";
    cout << endl;
}
