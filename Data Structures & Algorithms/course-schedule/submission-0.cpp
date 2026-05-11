class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i< numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            for(auto i: adj[course]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        if(count != numCourses){
            return false;
        }
        return true;
    }
};
