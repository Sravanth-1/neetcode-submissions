class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rightmax(height.size(), 0);
        for(int i =  height.size() - 2; i >= 0; i--){
            rightmax[i] = max(rightmax[i+1], height[i+1]);
        }
        int base = 0;
        int trapped = 0;
        for(int i = 1; i< height.size(); i++){
            base = max(base, height[i-1]);
            trapped += max(0, (min(base, rightmax[i]) - height[i]));
        }

        return trapped;
    }
};

                          
