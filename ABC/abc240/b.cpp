#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }
    cout << (int)S.size() << endl;
}
