class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, -1);

        for(auto i: words){
            for(auto j : i){
                indegree[j-'a'] = 0;
            }
        }

        for(int i = 1; i< words.size(); i++){
           int t = 0;
           for(int j = 0; j< min(words[i].size(), words[i-1].size()); j++){
               if(words[i][j] != words[i-1][j]){
                adj[words[i-1][j]-'a'].push_back(words[i][j]-'a');
                indegree[words[i][j]-'a']++;
                t = 1;
                break;
               }
           }
           if(t == 0 && words[i-1].size() > words[i].size()){
            return "";
           }
        }

        queue<int> q;

        for(int i = 0; i< 26; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        string s = "";
        while(!q.empty()){
            int chara = q.front();
            q.pop();
            s+= (chara+'a');
            for(auto i: adj[chara]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        for(int i = 0; i< 26; i++){
            if(indegree[i] > 0){
                return "";
            }
        }
        return s;
    }
};
