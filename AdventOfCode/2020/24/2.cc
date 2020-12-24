#include "../template.cc"

vii dPos{ mp(1, 0), mp(-1, 0), mp(0, -1), mp(-1, -1), mp(1, 1), mp(0, 1) };
map<string, int> toD{{"e", 0}, {"w", 1}, {"se", 2}, {"sw", 3}, {"ne", 4}, {"nw", 5}};

void solve() {
    set<ii> black;
    vector<string> ss = getInp([&](auto& cin, int) {
        ii pos = mp(0, 0);
        char c;
        while(cin >> c) {
            string s(1, c);
            if(c == 's' || c == 'n') {
                cin >> c;
                s += c;
            }
            pos += dPos[toD[s]];
        }
        
        if(black.count(pos))
            black.erase(pos);
        else
            black.insert(pos);
    });

    F0R(_, 100) {
        map<ii, int> adj;
        for(ii pos : black) {
            adj[pos];
            for(ii d : dPos)
                adj[pos + d]++;
        }

        for(auto [pos, adjAmt] : adj) {
            if(black.count(pos) && (!adjAmt || adjAmt > 2))
                black.erase(pos);
            else if(!black.count(pos) && adjAmt == 2)
                black.insert(pos);
        }
    }

    cout << SZ(black) << endl;
}

