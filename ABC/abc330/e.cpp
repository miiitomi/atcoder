#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    unordered_map<int, int> mp;
    set<int> out_set;

    for (int a : A) mp[a]++;
    for (int x = 0; x < max(N, Q)+10; x++) if (!mp.count(x)) out_set.insert(x);

    for (int q = 0; q < Q; q++) {
        int i, x;
        cin >> i >> x;
        i--;
    
        int a = A[i];
        mp[a]--;
        if (mp[a] == 0) out_set.insert(a);

        A[i] = x;
        if (out_set.count(x)) out_set.erase(x);
        mp[x]++;

        cout << *out_set.begin() << "\n";
    }

    cout << flush;
}
