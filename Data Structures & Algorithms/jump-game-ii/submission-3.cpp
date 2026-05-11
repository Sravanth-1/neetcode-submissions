class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>> q;
        q.push({0, 0});
        vector<int> vis(nums.size()+200, 0);
        while(!q.empty()){
            int index = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(index == nums.size()-1){
                return steps;
            }

            for(int i = 1; i<=nums[index]; i++){
                if(vis[index+i] == 0){
                    q.push({index+i, steps+1});
                    vis[index+i] = 1;
                }
            }
        }
        return -1;
    }
};