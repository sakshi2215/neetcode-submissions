class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] < 0){
                while(!s.empty() && s.top()>0 && s.top() < abs(asteroids[i])){
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(asteroids[i])){
                    s.pop();
                }
                //in case the stack is empty / negative and c/n element is going in negative direction
                else if(s.empty() || s.top() < 0){
                    s.push(asteroids[i]);
                }

            }
            else{
                s.push(asteroids[i]);
            }
        }
        int n = s.size();
        vector<int>ans(n);
        
        while(!s.empty()){
            ans[n-1] = s.top();
            n--;
            s.pop();
        }
        return ans;
    }
};