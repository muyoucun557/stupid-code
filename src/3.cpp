#include <iostream>
#include <vector>

using namespace std;
// 在一个矩阵中查找一个字符串，可以上下左右移动，但是不能回头，如果能找到这个字符串返回 true
// const str = "abcde";
// const matrix = [
//   ["0", "0", "0", "0", "0", "0"],
//   ["0", "0", "a", "b", "0", "0"],
//   ["0", "0", "0", "c", "d", "0"],
//   ["0", "0", "0", "0", "e", "0"],
// ];

class Solution {
  public:
    bool exist(vector< vector<char> > matrix, string word) {
    // m行n列
    int m = matrix.size();
    int n = matrix.size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == word[0]) {
          if (dfs()) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  
}