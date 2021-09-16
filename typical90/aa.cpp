#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<string> S;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        if (!S.count(s)) {
            ans.push_back(i);
            S.insert(s);
        }
    }
    for (int a : ans) {
        cout << a << endl;
    }
}
