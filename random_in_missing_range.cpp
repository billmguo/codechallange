
class soultion{
	public:
		int getrandominmissingrange(vector<int> &arr){
			if (arr.size() == 0)
				return 0;
			int totalw = getweight(arr,arr.size()-1);
			int randomw  = rand() * totalw;
			int left = 0, right = arr.size() - 1;
			while (left <= right) {
				int mid = left + (right - left)/2;
				curw = getWeight(mid);
				if (curw == randomw)
					return arr[mid] + 1;
				else if (curw > randomw) {
					right = mid - 1;
				}else
					left = mi + 1;
			}	
			int diff = randomw - getweight(arr, left);
			return arr[left] + diff;
		}
		int getweight(vector<int> &arr, int index){
			return arr[index] - arr[0] - index;
		}
		int rand(){
		
		}
};
