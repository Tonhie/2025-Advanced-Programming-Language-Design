#include <iostream>
#include<string.h>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
int main() {
    int length, upper, lower, num, other_2;
    char ch[1024];
    cin.getline(ch, 1024, '\n');
    char code[10][17] = { 0 };
    cin >> length >> upper >> lower >> num >> other_2;
    if (cin.good() == 0) {
        cout << "错误1" << endl;
        return 0;
    }
    if ((length > 16) || (length < 12)) {
        cout << "错误2" << endl;
        return 0;
    }
    if ((upper < 2) || (upper > length)) {
        cout << "错误3" << endl;
        return 0;
    }
    if ((lower < 2) || (lower > length)) {
        cout << "错误4" << endl;
        return 0;
    }
    if ((num < 2) || (num > length)) {
        cout << "错误5" << endl;
        return 0;
    }
    if ((other_2 < 2) || (other_2 > length)) {
        cout << "错误6" << endl;
        return 0;
    }
    if ((upper + lower + num + other_2) > length) {
        cout << "错误7" << endl;
        return 0;
    }
    for (int y = 0; y < 10; y++) {
        cin.getline(code[y], 16, '\n');
    }
    
    for (int x = 0; x < 10; x++)
    {
        int upper_2 = 0, lower_2 = 0, num_2 = 0, other_3 = 0;
        for (int z = 0; z < length; z++) {
            if ((code[x][z] >= 'A') && (code[x][z] <= 'Z'))
                upper_2++;
            if ((code[x][z] >= 'a') && (code[x][z] <= 'z'))
                lower_2++;
            if ((code[x][z] >= '0') && (code[x][z] <= '9'))
                num_2++;
            for (int others = 0; others < 15; others++) {
                if (code[x][z] == other[others])
                    other_3++;
            }
        }
        if (upper_2 < upper) {
            cout << "错误8" << endl;
            return 0;
        }
        if (lower_2 < lower) {
            cout << "错误9" << endl;
            return 0;
        }
        if (num_2 < num) {
            cout << "错误0" << endl;
            return 0;
        }
        if (other_3 < other_2) {
            cout << "错误" << endl;
            return 0;
        }
        if (upper_2 + lower_2 + num_2 + other_3 != length) {
            cout << "错误" << endl;
            return 0;
        }
    }
    cout<<"正确"<<endl;
    return 0;
}