#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<string> S;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        if (!S.count(s)) {
            S.insert(s);
            cout << i << endl;
        }
    }
}
