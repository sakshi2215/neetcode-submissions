class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0;
        int j = people.size()-1;
        sort(people.begin(), people.end());
        int count =0;

        while(i <= j){
            if(i==j){
                count++;
                return count;
            }
            if(people[i]+people[j] > limit){
                count++;
                j--;
            }
            else{
                count++;
                i++;
                j--;
            }
            
        }
        return count;
    }
};