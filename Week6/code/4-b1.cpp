//汤皓宇 计算机 2454307

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch(num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
		}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/


int main()
{
    double n;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> n;
    cout << "大写结果是:" << endl;
    n += 0.009;
    int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
    bool pre = false;
    tmp3 = (int)(n / (int)1e9);
    n -= (int)(n / (int)1e9) * 1e9;
    tmp4 = (int)(n / (int)1e8);
    n -= (int)(n / (int)1e8) * 1e8;
    daxie(tmp3, false);
    if(tmp3)
        cout << "拾";
    pre = pre || tmp3 ? true : false;
    daxie(tmp4, false);
    pre = pre || tmp4 ? true : false;
    if(tmp3 || tmp4)
        cout << "亿";
    tmp1 = (int)(n / (int)1e7);
    n -= (int)(n / (int)1e7) * 1e7;
    tmp2 = (int)(n / (int)1e6);
    n -= (int)(n / (int)1e6) * 1e6;
    tmp3 = (int)(n / (int)1e5);
    n -= (int)(n / (int)1e5) * 1e5;
    tmp4 = (int)(n / (int)1e4);
    n -= (int)(n / (int)1e4) * 1e4;
    daxie(tmp1, false);
    if(tmp1)
        cout << "仟";
    if(!tmp1 && pre && tmp2) {
        daxie(0, true);
        pre = 0;
    }
    pre = pre || tmp1 ? true : false;
    daxie(tmp2, false);
    if(tmp2)
        cout << "佰";
    if(!tmp2 && pre && tmp3) {
        daxie(0, true);
        pre = 0;
    }
    pre = pre || tmp2 ? true : false;
    daxie(tmp3, false);
    if(tmp3)
        cout << "拾";
    if(!tmp3 && pre && tmp4) {
        daxie(0, true);
        pre = 0;
    }
    pre = pre || tmp3 ? true : false;
    daxie(tmp4, false);
    pre = pre || tmp4 ? true : false;
    if(tmp1 || tmp2 || tmp3 || tmp4)
        cout << "万";
    pre = pre || tmp4 ? true : false;
    tmp1 = (int)(n / (int)1e3);
    n -= (int)(n / (int)1e3) * 1e3;
    tmp2 = (int)(n / (int)1e2);
    n -= (int)(n / (int)1e2) * 1e2;
    tmp3 = (int)(n / (int)1e1);
    n -= (int)(n / (int)1e1) * 1e1;
    tmp4 = (int)(n);
    n -= (int)(n);
    daxie(tmp1, false);
    if(tmp1)
        cout << "仟";
    if(!tmp1 && pre && tmp2) {
        daxie(0, true);
        pre = 0;
    }
    pre = pre || tmp1 ? true : false;
    daxie(tmp2, false);
    if(tmp2)
        cout << "佰";
    if(!tmp2 && pre && tmp3) {
        daxie(0, true);
        pre = 0;
    }
    pre = pre || tmp2 ? true : false;
    daxie(tmp3, false);
    if(tmp3)
        cout << "拾";
    if(!tmp3 && pre && tmp4) {
        daxie(0, true);
        pre = 0;
    }
    pre = pre || tmp3 ? true : false;
    daxie(tmp4, false);
    pre = pre || tmp4 ? true : false;
    if(pre)
        cout << "圆";

    tmp1 = (int)(n * 10);
    n -= (int)(n * 10) * 0.1;
    tmp2 = (int)(n * 100);
    if(!tmp1 && !tmp2) {
        if(!pre) {
            daxie(0, true);
            cout << "圆";
        }
        cout << "整";
    }

    daxie(tmp1, false);
    if(tmp1)
        cout << "角";
    if(tmp1 && !tmp2)
        cout << "整";
    if(!tmp1 && pre && tmp2)
        daxie(0, true);
    daxie(tmp2, false);
    if(tmp2)
        cout << "分";
    cout << endl;
    return 0;
}