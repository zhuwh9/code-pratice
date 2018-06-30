class Solution {
public:
bool IsContinuous(vector<int> numbers) {
    if (numbers.size() != 5)
        return false;
	sort(numbers.begin(), numbers.end());
	int i = 0, count = 0;
	for (; i < numbers.size(); i++) {
		if (!numbers[i])
			count++;
		else
			break;
	}
	for (int j = i; j < numbers.size() - 1; j++) {
        if (numbers[j+1] == numbers[j])
            return false;
		int diff = numbers[j+1] - numbers[j] - 1;
		count -= diff;
		if (count < 0)
			return false;
	}
	return true;
}
};
