#include "../template.cc"

vvii adj;
ll dfs(int v) {
    ll res = 1;
    for(auto [amt, u] : adj[v])
        res += amt*dfs(u);
    return res;
}

void solve() {
    map<string, int> toId;
    getInp([&](auto& cin, int) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3 >> s3;

        string name = s1 + s2;

        if(!toId[name])
            toId[name] = SZ(toId);
        adj.resize(SZ(toId) + 1);

        string amtStr;
        while(cin >> amtStr >> s1 >> s2 >> s3 && amtStr != "no") {
            int amt = stoi(amtStr);
            string name2 = s1 + s2;

            if(!toId[name2])
                toId[name2] = SZ(toId);
            adj.resize(SZ(toId) + 1);

            adj[toId[name]].eb(amt, toId[name2]);

            if(s3.back() == '.') break;
        }
    });

    cout << dfs(toId["shinygold"]) - 1 << endl;
}

