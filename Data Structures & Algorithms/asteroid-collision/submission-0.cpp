class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int i=0; i<asteroids.size(); i++){
            //if the asteroid is moving in positive direction then store it in stack
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            // if the asteroids are moving in negative direction
            else{
                //if the current asteroid is bigger then the top element
                //keep popping until the condition fails
                while(!st.empty() && st.top() > 0 &&  st.top() < abs(asteroids[i])){
                    st.pop();
                }
                //if the two asteroids are of same size then collide
                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                }
                //in case the stack is empty / negative and c/n element is going in negative direction
                else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }

            
            }
        }
        int size = st.size();
        vector<int>ans(size);

        while(!st.empty()){
            ans[--size] = st.top();
            st.pop();
        }
        return ans;
    }
};