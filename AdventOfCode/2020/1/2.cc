#include "../template.cc"

const int N = 200;

void solve() {
    vi a(N);
    cin >> a;

    F0R(i, N) 
        FOR(j, i + 1, N) 
            FOR(k, j + 1, N)
                if(a[i] + a[j] + a[k] == 2020)
                    cout << a[i]*a[j]*a[k] << endl;
}
