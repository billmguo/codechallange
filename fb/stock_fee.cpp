int getmaxstock_withfee(vector<int> prices, int fee) {
	int buy = prices[0];
	int sell = prices[0];
	int profit = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i-1])
			sell = prices[i];
		else {
			if (sell - buy > fee) {
				profit += (sell - buy -fee);
			}
			buy = prices[i];
			sell = prices[i];
		}
	}
	if (sell - buy > fee)
		profit += (sell - buy -fee);
	return profit;
}

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
