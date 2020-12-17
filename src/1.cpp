#include <iostream>

using namespace std;

// 判断一个括号字符串是一个符合括号规则的字符串。例如下面的是
// ()()()、((()))、(())()等等
// 下面的就不属于符合括号规则
// )()(等等。

// 常规解法:
// 利用栈结构来解决。
// 1. 遍历字符串。第一个必须是(，不然是不合法的字符串。
// 2. 遇到(字符将(入栈，遇到)字符字符，弹出栈顶元素，并判断弹出的元素是否是(
// 3. 如果不是(，则这个字符串是不合法的。如果是，则继续上面的操作，直到最后一个字符。如果最后栈是空的表示这个一个合法的。

// 另外一种解法
bool valid(string str) {
    int balance = 0;
    for (char c : str) {
        if (c == '(') {
            ++balance;
        } else {
            --balance;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
}

