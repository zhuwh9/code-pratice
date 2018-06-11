bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if (pushV.size() == 0) return false;
    vector<int> stack;
    for (int i = 0, j = 0; i < pushV.size();) {
        stack.push_back(pushV[i]);
        i++;
        while (j < popV.size() && stack.back() == popV[j]) {
            stack.pop_back();
            j++;
        }
    }
    return stack.empty();
}
