class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, res = 0;

        for(int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            int maxf = 0;
            for(int i = 0; i < 26; i++) {
                maxf = max(maxf, freq[i]);
            }
            while((r - l + 1) - maxf > k) {
                freq[s[l] - 'A']--;
                l++;
                maxf = 0;
                for(int i = 0; i < 26; i++) {
                    maxf = max(maxf, freq[i]);
                }
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};