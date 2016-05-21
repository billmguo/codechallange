/* array of size n is given with random number both positive and negative included.
For example an array with n elements is defined as A_0,A_1.....A_n-1.
Now f(0) is defined as sum of i*Ai.

Rotate array by 1 clockwise
f(1) as sum of i*Ai

Rotate array by 1 again clockwise
f(2) as sum of i*Ai.

Find the f(n) which will be maximum of ( f(0), f(1).....f(n-1) ).

Example
Array [4,3,2,6]
f(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 +18 = 25

Rotate array by 1 i.e. [6,4,3,2] clockwise
f(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 +6 + 6 = 16

Rotate array by 1 again i.e. [2,6,4,3] clockwise
f(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 +8 + 9 = 23

Rotate array by 1 again i.e. [3,2,6,4] clockwise
f(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So f(3) is the maximum
*/
int findrotatefunc(vector<int> &nums) {
	int sum = 0, f = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		f += i * nums[i];
	}
	for (int i = 1; i < n; i++) {
		f += sum - n * nums[n-i];
	}
	return f;
}

