class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int last = numbers.size()-1;

        while(start < last){
            if(numbers[start]+ numbers[last] == target){
                return {start+1, last+1};
            }
            if(numbers[start]+ numbers[last] > target){
                last--;
            }else{
                start++;
            }
        }

    }
};
