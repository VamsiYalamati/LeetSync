class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int asteroid : asteroids){

            bool destroyed = false;

            while(!st.empty() &&
                  st.top() > 0 &&
                  asteroid < 0){

                if(abs(st.top()) < abs(asteroid)){
                    st.pop();
                    continue;
                }
                else if(abs(st.top()) == abs(asteroid)){
                    st.pop();
                }

                destroyed = true;
                break;
            }

            if(!destroyed){
                st.push(asteroid);
            }
        }

        vector<int> ans(st.size());

        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }

        return ans;
    }
};