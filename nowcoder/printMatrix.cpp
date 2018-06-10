vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> res;
	if (matrix.size() == 0 || matrix[0].size() == 0) return res;
	int row = matrix.size(), col = matrix[0].size();
	int startRow = 0, endRow = row - 1, startCol = 0, endCol = col - 1;
    while(startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; i++) {
            res.push_back(matrix[startRow][i]);
        }
		for (int i = startRow + 1; i <= endRow; i++) {
			res.push_back(matrix[i][endCol]);
		}
		if (startRow != endRow) {
			for (int i = endCol - 1; i >= startCol; i--) {
				res.push_back(matrix[endRow][i]);
			}
		}
		if (startCol != endCol) {
			for (int i = endRow - 1; i >= startRow + 1; i--) {
				res.push_back(matrix[i][startCol]);
			}
		}
        startCol += 1;
        endCol -= 1;
        startRow += 1;
        endRow -= 1;
    }
    return res;
}
