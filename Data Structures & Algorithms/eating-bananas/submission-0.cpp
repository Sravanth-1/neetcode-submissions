class Solution {
public:
    bool ispossible(int mid, vector<int>&piles, int h){
        for(int i = 0; i< piles.size(); i++){
            h -= ceil((double)piles[i]/mid);
            if(h < 0){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while(low <= high){
            int mid = (low+high)/2;
            if(ispossible(mid, piles, h)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
