class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>fleetPair;

        for(int i=0; i<position.size(); i++){
            fleetPair.push_back({position[i], speed[i]});
        }
        sort(fleetPair.begin(), fleetPair.end(), [](const auto &a, const auto&b){
            return a.first < b.first;
        });

        vector<double>time(position.size(), 0);
        for(int i=0; i<position.size(); i++){
            time[i] = (double)(target - fleetPair[i].first)/fleetPair[i].second;
        }

        stack<double>st;
        for(int i=position.size()-1; i>=0; i--){
            if(st.empty() || time[i] > st.top()){
                st.push(time[i]);
            }

        }
        return st.size();


}
};
