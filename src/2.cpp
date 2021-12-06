#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class solution {
  public: 
  bool isValidXml(string str) {
    vector<string> tags;
    stack<string> stk;

    int len = str.length();
    if (len < 5) {  // 最小的xml是"<></>"，长度是5
      return false;
    }
    
    if (str[0] != '<') {  // 合法的xml字符串，第一个字符必须是<
      return false;
    }

    // 解析完字符串
    int i = 0;
    while (i < len) {
      string tempStr = "";
      if (str[i] == '<') {
        tempStr += '<';
        i++;
        while(i < len && str[i] != '>') {
          tempStr += str[i];
          i++;
        }
        tempStr += '>';
      }
      if (tempStr.length() > 0) {
        tags.push_back(tempStr);
      }
      i++;
    }

    if (tags.size() == 0) {
      return false;
    }
    
    for (int i = 0; i < tags.size(); i++) {
      if (tags[i].substr(0,2) == "</") {
        string tag = stk.top();
        if (tags[i].substr(2, tags[i].length()-1) == tag.substr(1, tag.length()-1)) {
          stk.pop();
          continue;
        }
      }
      stk.push(tags[i]);
    }
    return stk.empty();
  }
};

int main() {
  solution* sol = new solution();

  string str1 = "<html><div>123</div></html>"; // true
  cout << sol->isValidXml(str1) << endl;
  string str2 = "<div><div>123</div><div></div></div>"; // true
  cout << sol->isValidXml(str2) << endl;
  string str3 = "<html><div>123</html></div>"; // false
  cout << sol->isValidXml(str3) << endl;
}