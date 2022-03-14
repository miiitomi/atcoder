#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int> c;
    set<int> S;
    for (int x : a) {
        if (!S.count(x)) {
            S.insert(x);
            c.push_back(x);
        }
    }

    sort(c.begin(), c.end());

    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(c.begin(), c.end(), a[i]);
        cout << distance(c.begin(), iter) << endl;
    }
}
