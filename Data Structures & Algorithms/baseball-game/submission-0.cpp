class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> score;

        for (int i = 0; i < operations.size(); i++) {
            string ch = operations[i];
            if (ch == "C") {
                if (!score.empty()) {
                    score.pop();
                }
            } else if (ch == "D" && !score.empty()) {
                int top = score.top();
                score.push(2 * top);
            } else if (ch == "+") {
                int top = 0;
                top+=score.top();
                int first = top;
                score.pop();
                top+=score.top();
                score.push(first);
                score.push(top);

            } else {

                score.push(stoi(ch));
            }
        }
        int sum = 0;
        while (!score.empty()) {
            sum+=score.top();
            score.pop();
        }
        return sum;
    }
};