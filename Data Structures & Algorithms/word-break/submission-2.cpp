class Solution {
public:
    void ispossible(string s, unordered_map<string, int>& mp,
                    bool &possible, int index, string temp,
                    vector<int>& memo) {
        
        if (index == s.size()) {
            if (temp == "" || mp.find(temp) != mp.end()) {
                possible = true;
            }
            return;
        }

        // memo only when temp is empty (new word starting point)
        if (temp == "" && memo[index] != -1) {
            possible = memo[index];
            return;
        }

        temp += s[index];

        bool before = possible;

        if (mp.find(temp) != mp.end()) {
            ispossible(s, mp, possible, index + 1, "", memo);
        }
        ispossible(s, mp, possible, index + 1, temp, memo);

        // store memo only for fresh start states
        if (temp.size() == 1) {
            memo[index] = possible;
        }

        return;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;

        for (auto str : wordDict) {
            mp[str] = 1;
        }

        bool possible = false;
        string temp = "";

        vector<int> memo(s.size(), -1);

        ispossible(s, mp, possible, 0, temp, memo);

        return possible;
    }
};