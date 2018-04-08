class Solution {
public:
string numberToWords(int num) {
    if (num == 0)
        return "Zero";
    string res = int2s(num);
    return res.substr(1);
}
private:   
    vector<pair<int,string>> rep{{pow(10,9), " Billion"},{pow(10, 6)," Million"},{pow(10,3)," Thousand"},{pow(10,2)," Hundred"}};
    vector<string> tens{"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> digits{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string int2s(int n) {
        for (int i = 0; i < rep.size(); i++) {
            if (n >= rep[i].first) {
                return int2s(n/rep[i].first) + rep[i].second + int2s(n%rep[i].first);
            }
        }
        if (n >= 20) {
            return " " + tens[n/10] + int2s(n%10);
        } else if (n >= 1)
            return " " + digits[n];
        else 
            return "";
    }
};    
