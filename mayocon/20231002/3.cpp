#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    unordered_set<int> r, s, p;
    for (int i = 0; i < N; i++) {
        if (T[i] == 'r' && !r.count(i-K)) r.insert(i);
        if (T[i] == 's' && !s.count(i-K)) s.insert(i);
        if (T[i] == 'p' && !p.count(i-K)) p.insert(i);
    }

    cout << R*(int)s.size() + S*(int)p.size() + P*(int)r.size() << endl;
}
