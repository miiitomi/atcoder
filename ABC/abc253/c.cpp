#include <bits/stdc++.h>
#include<map>
using namespace std;

int main() {
    map<int, int> M;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            M[x]++;
        } else if (a == 2) {
            int x, c;
            cin >> x >> c;
            if (M.count(x)) {
                M[x] -= min(M[x], c);
            }
            if (M[x] == 0) {
                M.erase(x);
            }
        } else {
            auto iter = M.end();
            iter--;
            cout << iter->first - M.begin()->first << endl;
        }
    }    
}
