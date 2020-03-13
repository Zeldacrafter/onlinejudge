#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (x).size()
#define FOR(a, b, c) for (auto(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (auto(a) = (b); (a) > (c); --(a))
#define F0R(a, b) for (auto(a) = 0; (a) < (b); ++(a))
#define R0F(a, b) for (auto(a) = (b); (a) >= 0; --(a))
#define FORI(a, b) for (auto(a) = (b).begin(); (a) != (b).end(); ++(a))
#define ROFI(a, b) for (auto(a) = (b).rbegin(); (a) != (b).rend(); ++(a))
#define TRAV(a, b) for (auto&(a) : (b))
const int xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
template <typename t> bool ckmin(t& a, const t& b) { return a > b ? a = b, true : false; }
template <typename t> bool ckmax(t& a, const t& b) { return a < b ? a = b, true : false; }

int main() {

    bitset<100010> poss[100];
    while(true) {
        int n;
        int x;
        scanf("%d %d", &n, &x);

        if(!n && !x) break;
            
        F0R(i, n) 
            poss[i].reset(); 

        vi vals(n, -1);
        F0R(i, n) {
            int a, b;
            scanf("%d.%d", &a, &b);
            vals[i] = a * 100 + b;
        }

        x--;
        poss[x][vals[x]] = true;

        int res = 10000;
        FOR(i, vals[x], 10000) {
            if(!poss[x][i])
                continue;

            if(i > 5000) {
                res = i;
                break;
            }

            F0R(j, n){
                if(poss[j][i])
                    continue;
                int newPoss = i + vals[j];
                F0R(k, n) 
                    poss[k][newPoss] = poss[k][i];
                poss[j][newPoss] = true;
            }
        }
        cout << fixed << setprecision(2) << 100.00*vals[x]/res << endl;
    }

    return 0;
}	
