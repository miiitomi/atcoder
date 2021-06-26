#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> t(N), l(N), r(N);
    for (int i = 0; i < N; i++) cin >> t.at(i) >> l.at(i) >> r.at(i);

    int ans = 0;

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (max(l.at(i), l.at(j)) < min(r.at(i), r.at(j))) {
                ans++;
                continue;
            }
            if ((max(l.at(i), l.at(j)) > min(r.at(i), r.at(j)))) continue;

            if (max(l.at(i), l.at(j)) == l.at(i)) {
                if ((t.at(i) == 1 || t.at(i) == 2) && (t.at(j) == 1 || t.at(j) == 3)) ans++;
            } else {
                if ((t.at(j) == 1 || t.at(j) == 2) && (t.at(i) == 1 || t.at(i) == 3)) ans++;
            }
        }
    }

    cout << ans << endl;
}
