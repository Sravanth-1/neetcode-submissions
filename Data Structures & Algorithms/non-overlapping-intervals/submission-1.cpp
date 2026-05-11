class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];

        int count = 0;
        for(int i = 1; i< intervals.size(); i++){
            if(end > intervals[i][0]){
                end = min(end, intervals[i][1]);
                count++;
            }else{
                end = intervals[i][1];
            }
        }
        return count;
    }
};
