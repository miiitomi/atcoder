#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> t(N), x(N);
    vector<vector<int>> c(N);

    for (int i = 0; i < N; i++) {
        cin >> t[i] >> x[i];
        x[i]--;
        if (t[i] == 1) {
            c[x[i]].push_back(i);
        }
    }

    vector<int> S(N+1, 0), v(N, 0);
    for (int i = N-1; i >= 0; i--) {
        if (t[i] == 2) {
            while (!c[x[i]].empty() && c[x[i]].back() > i) c[x[i]].pop_back();
            if (!c[x[i]].empty()) {
                v[c[x[i]].back()] = 1;
                S[c[x[i]].back()]++;
                S[i + 1]--;
                c[x[i]].pop_back();
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int x = 0; x < N; x++) S[x+1] += S[x];
    cout << *max_element(S.begin(), S.end()) << endl;
    for (int i = 0; i < N; i++) {
        if (t[i] == 1) cout << v[i] << " ";
    }
    cout << endl;
}
