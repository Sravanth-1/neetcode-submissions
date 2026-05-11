class Solution {
public:
    void dfs(string s, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>&adj, vector<string> & dfsvec){
        while(!adj[s].empty()){
            auto i = adj[s].top();
            adj[s].pop();
            dfs(i, adj, dfsvec);
        }
        dfsvec.push_back(s);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto i: tickets){
            adj[i[0]].push(i[1]);
        }
        vector<string> dfsvec;
        dfs("JFK", adj, dfsvec);
        reverse(dfsvec.begin(), dfsvec.end());
        return dfsvec;
    }
};
