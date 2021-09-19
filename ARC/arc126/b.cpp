#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first < b.first) return true;
    else if (a.first > b.first) return false;
    else if (a.second >= b.second) return true;
    else return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> V(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        V[i] = make_pair(a, b);
    }
    sort(V.begin(), V.end(), cmp);

    vector<int> L;
    L.push_back(V[0].second);
    for (int i = 1; i < M; i++) {
        auto iter = lower_bound(L.begin(), L.end(), V[i].second);
        if (iter == L.end()) L.push_back(V[i].second);
        else *iter = V[i].second;
    }

    cout << (int)L.size() << endl;
}
