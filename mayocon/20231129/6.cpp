// https://atcoder.jp/contests/abc161/tasks/abc161_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<int> v, w;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            if (v.empty() || abs(v.back()-i) > C) {
                v.push_back(i);
            }
        }
        if (S[N-1-i] == 'o') {
            if (w.empty() || abs(w.back() - (N-1-i)) > C) {
                w.push_back(N-1-i);
            }
        }
    }

    reverse(w.begin(), w.end());

    for (int i = 0; i < N; i++) {
        if (S[i] != 'o') continue;
        int tmp1=0, tmp2=0;

        int id1 = distance(v.begin(), lower_bound(v.begin(), v.end(), i)), d1;
        id1--;
        if (id1 >= 0) d1 = v[id1];
        else d1 = -C-1;
        int l1 = distance(lower_bound(w.begin(), w.end(), max(i+1, d1+C+1)), w.end());
        tmp1 = id1 + 1 + l1;

        
        int id2 = distance(w.begin(), lower_bound(w.begin(), w.end(), i+1)), d2;
        if (id2 < (int)w.size()) d2 = w[id2];
        else d2 = w.back() + C + 1;
        int l2 = distance(v.begin(), lower_bound(v.begin(), v.end(), min(i, d2 - C)));
        tmp2 = ((int)w.size() - id2) + l2;

        if (max(tmp1, tmp2) < K) cout << i+1 << endl; 
    }
}
