// https://atcoder.jp/contests/abc075/tasks/abc075_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> S;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        if (S.count(a)) S.erase(a);
        else S.insert(a);
    }

    cout << *S.begin() << endl;
}
