class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        for(auto str: wordList){
            mp[str]++;
        }
        if(mp.find(endWord) == mp.end()){
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            if(s == endWord){
                return level;
            }
            for(int i = 0; i< s.size(); i++){
                for(char j = 'a'; j <= 'z'; j++){
                    string temp = s;
                    temp[i] = j;
                    if(mp.find(temp) != mp.end()){
                        q.push({temp, level+1});
                        mp.erase(temp);
                    }
                }
            }
        }
        return 0;

    }
};
