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
    vector< vector<bool> > visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == word[0]) {
          if (dfs(matrix, word, 0, i, j, visited)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  private:
  /**
   * 深度优先搜索
   * 判断字符串word[cur,...]是否在matrix中能够匹配到
   * 
   **/ 
  bool dfs(vector< vector<char> > &matrix, string& word, int cur, int i, int j, vector< vector<bool> > &visited) {
    if (cur == word.length()) {
      return true;
    }
    // 判断边界，超出边界不匹配
    if (i == matrix.size() || i == -1) {
      return false;
    }
    if (j == matrix[0].size() || j == -1) {
      return false;
    }
    
    // word与matrix[i][j]不匹配，则返回
    if (word[cur] != matrix[i][j]) {
      return false;
    }
    // 如果该节点遍历过，则返回
    if (visited[i][j]) {
      return false;
    }

    visited[i][j] = true;
    // 向左边移动一位
    if (dfs(matrix, word, cur+1, i, j-1, visited)) {
      return true;
    } 
    // 向右
    if (dfs(matrix, word, cur+1, i, j+1, visited)) {
      return true;
    }
    // 向上
    if (dfs(matrix, word, cur+1, i-1, j, visited)) {
      return true;
    }

    // 向下
    if (dfs(matrix, word, cur+1, i+1, j, visited)) {
      return true;
    }
    visited[i][j] = false;
    return false;
  }
};

int main() {
  vector< vector<char> > matrix(4, vector<char>(6));
  char eles[4][6] = {
    {'0', '0', '0', '0', '0', '0'},
    {'0', '0', 'a', 'b', '0', '0'},
    {'0', '0', '0', 'c', 'd', '0'},
    {'0', '0', '0', '0', 'e', '0'}
  };
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      matrix[i][j] = eles[i][j];
    }
  }

  
  Solution* solution = new Solution();
  string word = "abcde";
  cout << solution->exist(matrix, word) << endl;
}