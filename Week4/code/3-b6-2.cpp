//ÌÀğ©Óî ¼ÆËã»ú 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    double n;
    cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
    cin >> n;
    cout << "´óĞ´½á¹ûÊÇ:" << endl;
    n += 0.009;
    int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
    bool pre = false;
    tmp3 = (int)(n / (int)1e9);
    n -= (int)(n / (int)1e9) * 1e9;
    tmp4 = (int)(n / (int)1e8);
    n -= (int)(n / (int)1e8) * 1e8;
    switch(tmp3) {
    case 1:
        cout << "Ò¼";
        break;
    case 2:
        cout << "·¡";
        break;
    case 3:
        cout << "Èş";
        break;
    case 4:
        cout << "ËÁ";
        break;
    case 5:
        cout << "Îé";
        break;
    case 6:
        cout << "Â½";
        break;
    case 7:
        cout << "Æâ";
        break;
    case 8:
        cout << "°Æ";
        break;
    case 9:
        cout << "¾Á";
        break;
    }
    if(tmp3)
        cout << "Ê°";
    pre = pre || tmp3 ? true : false;
    switch(tmp4) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    pre = pre || tmp4 ? true : false;
    if(tmp3 || tmp4)
        cout << "ÒÚ";
    tmp1 = (int)(n / (int)1e7);
    n -= (int)(n / (int)1e7) * 1e7;
    tmp2 = (int)(n / (int)1e6);
    n -= (int)(n / (int)1e6) * 1e6;
    tmp3 = (int)(n / (int)1e5);
    n -= (int)(n / (int)1e5) * 1e5;
    tmp4 = (int)(n / (int)1e4);
    n -= (int)(n / (int)1e4) * 1e4;
    switch(tmp1) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp1)
        cout << "Çª";
    if(!tmp1 && pre && tmp2) {
        cout << "Áã";
        pre = 0;
    }
    pre = pre || tmp1 ? true : false;
    switch(tmp2) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp2)
        cout << "°Û";
    if(!tmp2 && pre && tmp3) {
        cout << "Áã";
        pre = 0;
    }
    pre = pre || tmp2 ? true : false;
    switch(tmp3) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp3)
        cout << "Ê°";
    if(!tmp3 && pre && tmp4) {
        cout << "Áã";
        pre = 0;
    }
    pre = pre || tmp3 ? true : false;
    switch(tmp4) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    pre = pre || tmp4 ? true : false;
    if(tmp1 || tmp2 || tmp3 || tmp4)
        cout << "Íò";
    pre = pre || tmp4 ? true : false;
    tmp1 = (int)(n / (int)1e3);
    n -= (int)(n / (int)1e3) * 1e3;
    tmp2 = (int)(n / (int)1e2);
    n -= (int)(n / (int)1e2) * 1e2;
    tmp3 = (int)(n / (int)1e1);
    n -= (int)(n / (int)1e1) * 1e1;
    tmp4 = (int)(n);
    n -= (int)(n);
    switch(tmp1) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp1)
        cout << "Çª";
    if(!tmp1 && pre && tmp2) {
        cout << "Áã";
        pre = 0;
    }
    pre = pre || tmp1 ? true : false;
    switch(tmp2) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp2)
        cout << "°Û";
    if(!tmp2 && pre && tmp3) {
        cout << "Áã";
        pre = 0;
    }
    pre = pre || tmp2 ? true : false;
    switch(tmp3) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp3)
        cout << "Ê°";
    if(!tmp3 && pre && tmp4) {
        cout << "Áã";
        pre = 0;
    }
    pre = pre || tmp3 ? true : false;
    switch(tmp4) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    pre = pre || tmp4 ? true : false;
    if(pre)
        cout << "Ô²";

    tmp1 = (int)(n * 10);
    n -= (int)(n * 10) * 0.1;
    tmp2 = (int)(n * 100);
    if(!tmp1 && !tmp2) {
        if(!pre)
            cout << "ÁãÔ²";
        cout << "Õû";
    }

    switch(tmp1) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp1)
        cout << "½Ç";
    if(tmp1 && !tmp2)
        cout << "Õû";
    if(!tmp1 && pre && tmp2)
        cout << "Áã";
    switch(tmp2) {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if(tmp2)
        cout << "·Ö";
    cout << endl;
    return 0;
}