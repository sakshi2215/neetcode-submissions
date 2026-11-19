class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);

            } else if (operations[i] == "C") {
                s.pop();
            } else if (operations[i] == "D") {
                int a = s.top();
                s.push(2 * a);
            } else {
                s.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};