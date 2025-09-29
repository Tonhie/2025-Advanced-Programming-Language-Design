//汤皓宇 计算机 2454307
#include <iostream>
using namespace std;

# define LEN 80

int main() {
    cout << "请输入一个长度小于80的字符串（回文串）" << endl;
    char str[LEN + 1];
    fgets(str, LEN, stdin);
    char *head, *tail;
    bool isSymmetry = true;
    head = str;
    tail = str + strlen(str) - 1;
    if(*tail == '\n')
        -- tail;
    while(head < tail) {
        if(*head != *tail) {
            isSymmetry = false;
            break;
        }
        head++, tail --;
    }
    cout << (isSymmetry ? "yes" : "no") << endl;
    return 0;
}