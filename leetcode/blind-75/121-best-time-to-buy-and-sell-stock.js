var maxProfit = function (prices) {
	if (prices.length === 1) return 0;

	let [left, right] = [0, 1];
	let maxIdx = prices.length - 2;
	let maxProfit = 0;
	while (left <= maxIdx) {
		if (prices[left] >= prices[right]) {
			left++;
			right = left + 1;
		} else {
			let profit = prices[right] - prices[left];
			if (maxProfit < profit) {
				maxProfit = profit;
			}
			if (right === maxIdx + 1) {
				left++;
				right = left + 1;
			} else {
				right++;
			}
		}
	}
	return maxProfit;
};

// better solution
var maxProfit = function (prices) {
	if (prices.length === 1) return 0;

	min_price = prices[0];
	max_profit = 0;

	for (let price of prices) {
		if (min_price > price) min_price = price;
		profit = price - min_price;
		if (max_profit < profit) {
			max_profit = profit;
		}
	}
	return max_profit;
};
