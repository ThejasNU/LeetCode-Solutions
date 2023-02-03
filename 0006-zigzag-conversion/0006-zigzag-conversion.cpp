class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        string answer;
        int n = s.size();
        int charsInSection = 2 * (numRows - 1);
        for (int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;
            while (index < n) {
                answer.push_back(s[index]);
                // If currRow is not the first or last row
                // then we have to add one more character of current section.
                if (currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;
                    
                    if (secondIndex < n) {
                        answer += s[secondIndex];
                    }
                }
                // Jump to same row's first character of next section.
                index += charsInSection;
            }
        }
        return answer;
    }
};