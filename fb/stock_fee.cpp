class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*hold[i] - the maximum profit you can earn if you have to hold at day[i]
        sold[i] - the maximum profit you can earn if you have to sold at day[i]
        Formula:
        hold[i] = max(hold[i - 1], sold[i - 1] - p[i])       // if hold at [i-1], no op; if sold at [i-1], buy at [i] with cost of p[i];
        sold[i] = max(sold[i - 1], hold[i - 1] + p[i] - fee) // if sold at [i-1], no op; if hold at [i-1], sell at [i] with gain of p[i] - fee;

        Initialization:
        hold[0] = 0 - price[0];  // buy shares with cost of p[0];
        sold[0] = 0;             // no op no cost;
        */
        int n = prices.size();
        vector<int> hold(n, 0);
        vector<int> sold(n, 0);
        if (n < 2)
            return 0;
        hold[0] = - prices[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
            sold[i] = max(sold[i-1], hold[i - 1] + prices[i] - fee);
        }
        return sold[n - 1];
        
    }
};

int getmaxstock_withfee(vector<int> prices, int fee) {
	int local =  0;
	int global = 0;
	for (int i = 1; i < prices.size();i++) {
		int profit = prices[i] - profits[i-1] - fee;
		local = (proit > 0?) profit:0 + max(local, global);
		global = max(global, local);
	}
	return global;
}

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = int2string(num);
        return res.substr(1);
    }
private:   
    vector<pair<int, string>> rep{{pow(10, 9), " Billion"}, {pow(10, 6), " Million"}, {pow(10, 3), " Thousand"}, {pow(10, 2), " Hundred"}};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
     
    string int2string(int n) {
        for (int i = 0; i < rep.size(); i++) {
            if (n >= rep[i].first) {
                return int2string(n / rep[i].first) + rep[i].second + int2string(n % rep[i].first);
            }
        }
        if (n >= 20) {
            return  " " + tens[n / 10] + int2string(n % 10);
        } else if (n >= 1) {
            return " " + digits[n];
        } else {
            return "";
        }
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();
        int j = 1;
        for (int i = 2; i < nums.size();i++) {
            if (nums[i] != nums[j - 1]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1 ;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        if (nums.empty())
            return 0;
        for (int i = 0; i < nums.size();i++) {
            if (nums[i] != nums[j]) {
                j++;
                swap(nums[i],nums[j]);
            }
        }
        return j + 1;
    }
};
