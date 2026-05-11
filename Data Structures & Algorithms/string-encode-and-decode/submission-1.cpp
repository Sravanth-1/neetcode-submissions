class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto i: strs){
            int size = i.size();
            res+= to_string(size) + '#';
            res += i;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
        int pos = s.find('#', i);

        int size = stoi(s.substr(i, pos - i));

        string word = s.substr(pos + 1, size);
        res.push_back(word);

        i = pos + 1 + size;
        }
        return res;
    }
};
