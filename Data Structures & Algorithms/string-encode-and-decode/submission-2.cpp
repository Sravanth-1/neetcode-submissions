class Solution {
public:

    string encode(vector<string>& strs) {
        string encoding = "";
        for(auto str : strs){
            encoding += to_string(str.size()) + '#' + str;
        }
        return encoding;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int start = 0;
        while(start < s.size()){
            int end = s.find('#', start);
            int length = stoi(s.substr(start, end-start));
            result.push_back(s.substr(end+1, length));
            start = end+1+length;
        }
        return result;
    }
};
