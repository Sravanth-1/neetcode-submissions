class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nexthighday(temperatures.size(), 0);
        stack<int> s;
        for(int i = 0; i< temperatures.size(); i++){
            if(s.empty() || temperatures[i] <= temperatures[s.top()] ){
               s.push(i);
            }else{
                while(!s.empty()){
                   if(temperatures[i] > temperatures[s.top()]){
                      nexthighday[s.top()] = i-s.top();
                      s.pop();
                   }else{
                    break;
                   }
               }
               s.push(i);
            }
        }
        return nexthighday;
    }
};