#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<string> c(M);
    for (int i = 0; i < M; i++) cin >> c[i];

    vector<map<char,int>> row(M), column(N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            char ch = c[i][j];
            row[i][ch] += 1;
            column[j][ch] += 1;
        }
    }

    set<int> remain_rows, remain_cols;
    for (int i = 0; i < M; i++) remain_rows.insert(i);
    for (int j = 0; j < N; j++) remain_cols.insert(j);

    bool update = true;

    while (update) {
        update = false;
        set<int> delete_rows, delete_cols;

        for (int i : remain_rows) {
            if ((int)row[i].size() == 1) {
                auto iter = row[i].begin();
                if (iter->second >= 2) delete_rows.insert(i);
            }
        }
        for (int j : remain_cols) {
            if ((int)column[j].size() == 1) {
                auto iter = column[j].begin();
                if (iter->second >= 2) delete_cols.insert(j);
            }
        }

        if ((int)delete_rows.size() >= 1) {
            update = true;
            for (int i : delete_rows) {
                remain_rows.erase(i);
                for (int j : remain_cols) {
                    column[j][c[i][j]]--;
                    if (column[j][c[i][j]] == 0) column[j].erase(c[i][j]);
                }
            }
        }

        if ((int)delete_cols.size() >= 1) {
            update = true;
            for (int j : delete_cols) {
                remain_cols.erase(j);
                for (int i : remain_rows) {
                    row[i][c[i][j]]--;
                    if (row[i][c[i][j]] == 0) row[i].erase(c[i][j]);
                }
            }
        }
    }

    cout << (int)remain_cols.size() * (int)remain_rows.size() << endl;

}
