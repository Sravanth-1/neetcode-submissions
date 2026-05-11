class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> car;
        for(int i = 0; i< position.size(); i++){
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end());

        double last = INT_MIN;
        int fleet = 0;
        for(int i = position.size()-1; i>= 0; i--){
            double time = (double)(target-car[i][0])/car[i][1];
            cout << time;
            if(time > last){
                last = time;
                fleet++;
            }
        }
        return fleet;
    }
};