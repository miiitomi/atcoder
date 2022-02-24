#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second < b.second) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        int x, l;
        cin >> x >> l;
        V[i].first = x - l;
        V[i].second = x + l;
    }
    sort(V.begin(), V.end(), cmp);
    int ans = 1;
    int now = V[0].second;
    for (int i = 1; i < N; i++) {
        if (now <= V[i].first) {
            ans++;
            now = V[i].second;
        }
    }
    cout << ans << endl;
}
