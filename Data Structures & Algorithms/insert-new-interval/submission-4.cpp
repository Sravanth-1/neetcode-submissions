class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int done = 0;
        for(int i = 0; i< intervals.size(); i++){
            if(intervals[i][0] < newInterval[0] && intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
                continue;
            }
            if(!done && intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]){
                result.push_back(intervals[i]);
                result.back()[1] = max(result.back()[1], newInterval[1]);
                done = 1;
                continue;
            }
            if(!done){
                result.push_back(newInterval);
                done = 1;
            }
            if(result.size() > 0 && result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
                continue;
            }
            result.push_back(intervals[i]);
        }
        if(!done){
            result.push_back(newInterval);
        }
        return result;
    }
};
