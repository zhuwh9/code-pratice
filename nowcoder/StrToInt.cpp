class Solution {
public:
int StrToInt(string str) {
	int i = 0;
	for (; i < str.size(); i++) {
		if (str[i] == ' ')
			continue;
		else
			break;
	}
    int symbol = 1;
	vector<int> num;
	for (; i < str.size(); i++) {
		if (str[i] <= '9' && str[i] >= '0') {
			num.push_back(str[i] - '0');
		} else if (str[i] == '+') {
		    symbol = 1;
	    } else if (str[i] == '-') {
		    symbol = -1;
	    } else if ((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')) {
		    return 0;
	    }
	}
	int result = 0;
	int size = num.size();
	for (int j = 0; j < size; j++) {
		result = result * 10 + num[j];
	}
	return result * symbol;
}
};
