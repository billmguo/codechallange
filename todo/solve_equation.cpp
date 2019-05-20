class Solution {
public:
    string solveEquation(string equation) {
        int a = 0, b = 0;
        auto found = equation.find("=");
        helper(equation.substr(0, found), true, a, b);
        helper(equation.substr(found + 1), false, a, b);
        if (a == 0 && a == b) return "Infinite solutions";
        if (a == 0 && a != b) return "No solution";
        return "x=" + to_string(b / a);
    }
    void helper(string e, bool isLeft, int& a, int& b) {
        int sign = 1, num = -1;
        e += "+";
        for (int i = 0; i < e.size(); ++i) {
            if (e[i] == '-' || e[i] == '+') {
                num = (num == -1) ? 0 : (num * sign);
                b += isLeft ? -num : num;
                num = -1;
                sign = (e[i] == '+') ? 1 : -1;
            } else if (e[i] >= '0' && e[i] <= '9') {
                if (num == -1) num = 0;
                num = num * 10 + e[i] - '0';
            } else if (e[i] == 'x') {
                num = (num == -1) ? sign : (num * sign);
                a += isLeft ? num : -num;
                num = -1;
            }
        }
    }
};
