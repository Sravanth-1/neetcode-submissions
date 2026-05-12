class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int start = 0;
        int end = 0;
        int maxfreq = 0;
        int maxlen = 0;
        while(end < s.size()){
            count[s[end]-'A']++;
            maxfreq = max(maxfreq, count[s[end]-'A']);

            if(end-start+1 - maxfreq <= k){
                maxlen = max(maxlen, end-start+1);
            }else{
                while(start <= end){
                    count[s[start]-'A']--;
                    start++;
                    if(end-start+1 - maxfreq <= k){
                        break;
                    }
                }
            }
            end++;
        }

        return maxlen;
    }
};
