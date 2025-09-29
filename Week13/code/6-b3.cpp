//汤皓宇 计算机 2454307
#include <iostream>
using namespace std;

# define LEN 32

int main() {
    char binary[LEN + 1];
    cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
    cin.getline(binary, LEN, '\n');
    char* p = binary;
    unsigned int decimal = 0;
    while(*p != '\0') {
        decimal = decimal * 2 + (*p - '0');
        p++;
    }
    cout << decimal << endl;
    return 0;
}