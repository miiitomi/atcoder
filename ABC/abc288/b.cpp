#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    set<string> S;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (i < K) S.insert(s);
    }
    for (auto iter = S.begin(); iter != S.end(); iter++) {
        cout << *iter << endl;
    }
}
