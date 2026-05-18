class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxfreq = 0;
        int last = 0;
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'A']++;
            maxfreq = max(maxfreq, freq[s[i]-'A']);
            if(i-last+1-maxfreq > k){
                freq[s[last]-'A']--;
                last++;
            }
            maxlen = max(i-last+1, maxlen);
        }
        return maxlen;
    }
};
