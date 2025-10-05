#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, rK, cK, rD, cD;
    cin >> n >> rK >> cK >> rD >> cD;

    long long row_closure_time = 0;
    // Determine the time Doran needs to close the row-wise escape route
    if (rK < rD) {
        // Krug has an escape route towards r=0.
        // Doran needs rD turns to "guard" the r=0 edge.
        row_closure_time = rD;
    } else if (rK > rD) {
        // Krug has an escape route towards r=n.
        // Doran needs n-rD turns to guard the r=n edge.
        row_closure_time = n - rD;
    }
    // If rK == rD, Krug has no row-wise escape advantage. The time is 0.

    long long col_closure_time = 0;
    // Determine the time Doran needs to close the column-wise escape route
    if (cK < cD) {
        // Krug has an escape route towards c=0.
        // Doran needs cD turns to guard this edge.
        col_closure_time = cD;
    } else if (cK > cD) {
        // Krug has an escape route towards c=n.
        // Doran needs n-cD turns to guard this edge.
        col_closure_time = n - cD;
    }
    // If cK == cD, Krug has no column-wise escape advantage. The time is 0.

    // The Krug is caught when all her escape routes are closed. This happens
    // at the time the last route is closed. So, we take the maximum of the closure times.
    long long survival_time = std::max(row_closure_time, col_closure_time);
    
    cout << survival_time << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}