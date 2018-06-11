bool JudgeSection(vector<int> &sequence, int front, int back) {
	if (front >= back) return true;
	int root = sequence[back];
	int i, middle;
	for (i = back - 1; i >= front; i--) {
		if (sequence[i] < root) break;
	}
	middle = i;
	for (; i >= front; i--) {
		if (sequence[i] > root) return false;
	}
	return JudgeSection(sequence, front, middle) && JudgeSection(sequence, middle + 1, back - 1);
}

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() == 0) return false;
	return JudgeSection(sequence, 0, sequence.size() - 1);
}
