class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        int count = t.size();
        for(int i = 0; i< t.size(); i++){
            freq[t[i]-'A']++;
        }
        int last = 0;
        int beststart = -1;
        int minilen = INT_MAX;
        for(int i = 0; i< s.size(); i++){
            if(freq[s[i]-'A'] > 0){
                count--;
            }
            freq[s[i]-'A']--;

            while(last <= i && count == 0){
                if(minilen > i-last+1){
                    minilen = i-last+1;
                    beststart = last;
                }
                freq[s[last]-'A']++;
                if(freq[s[last]-'A'] > 0){
                    count++;
                }
                last++;
            }
        }
        if(beststart == -1){
            return "";
        }
        return s.substr(beststart, minilen);
    }
};
