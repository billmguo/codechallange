class Solution {
public:
    string solveEquation(string equation) {
        int n = equation.size(), a = 0, b = 0, sign = 1, j = 0;
        for (int i = 0; i < n; ++i) {
            if (equation[i] == '+' || equation[i] == '-') {
                if (i > j) b += stoi(equation.substr(j, i - j)) * sign;
                j = i;
            } else if (equation[i] == 'x') {
                if (i == j || equation[i - 1] == '+') {
                    a += sign;                 
                } else if (equation[i - 1] == '-') {
                    a -= sign;
                } else {
                    a += stoi(equation.substr(j, i - j)) * sign;
                }
                j = i + 1;
            } else if (equation[i] == '=') {
                if (i > j) b += stoi(equation.substr(j, i - j)) * sign;
                sign = -1;
                j = i + 1;
            }
        }
        if (j < n) b += stoi(equation.substr(j)) * sign;
        if (a == 0 && a == b) return "Infinite solutions";
        if (a == 0 && a != b) return "No solution";
        return "x=" + to_string(-b / a);
    }
};
