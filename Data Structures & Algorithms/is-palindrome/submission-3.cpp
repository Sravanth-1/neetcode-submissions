class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int last = s.size()-1;
        while(start <= last){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[last])){
                last--;
                continue;
            }
            s[start] = tolower(s[start]);
            s[last] = tolower(s[last]);
            if(s[start] != s[last]){
                return false;
            }
            start++;
            last--;
        }

        return true;
    }
};
