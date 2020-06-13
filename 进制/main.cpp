#include <iostream>
#include <string>
using namespace std;
struct numi {
	string num;
	int wei;
};
numi inputS(numi b)
{
	numi a = b;
	switch (b.num[b.num.length()-1])
	{
		case 'b':
		case 'B':
			a.wei = 2;
			break;
		case 'O':
		case 'o':
			a.wei = 8;
			break;
		case 'H':
		case 'h':
			a.wei = 16;
			break;
		case 'D':
		case 'd':
			a.wei = 10;
			break;
		default:
			cout << "输入错误" << endl;
			break;
	}
	a.num.pop_back();
	return a;
}
//输入一个任意进制的数转换为10进制
//当d低于十进制
int func(int x, int d)
{
	int ans = 0, index = 1;
	while (x)
	{
		int c = x % 10;
		ans += c * index;
		x = x / 10;
		index *= d;
	}
	return ans;
}
//当大于10进制时候
int transfer(string s, int d)
{
	int sum = 0, k = 1; //初始化
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			sum += (s[i] - 'A' + 1 + 9) * k;
		}
		else
		{
			sum += (s[i] - '0') * k;
		}
		k *= d;
	}
	return sum;
}
numi caoZuo(char a,numi num1,numi num2)
{
	int num1i=num1.wei;
	int num2i=num2.wei;
	int num1n=0;
	int num2n=0;
	if (num1i > 10)
	{
		num1n=transfer(num1.num, num1i);
	}
	else {
		num1n = func(atoi(num1.num.c_str()),num1.wei);
	}
	if (num2i > 10)
	{
		num2n = transfer(num2.num, num2i);
	}
	else {
		num2n = func(atoi(num2.num.c_str()), num2.wei);
	}
	numi back;
	switch (a)
	{
	case '+':
		back.num = to_string(num1n + num2n);
		break;
	case '-':
		back.num = to_string(num1n - num2n);
		break;
	case '*':
		back.num = to_string(num1n * num2n);
		break;
	case '/':
		back.num = to_string(num1n / num2n);
		break;
	default:
		cout << "运算错误" << endl;
		break;
	}
	back.wei = 10;
	return back;
}
int JingZhi1;
int JingZhi2;
int main()
{
	numi num1;
	char cas;
	numi ans;
	cout << "输入格式“第一个操作数 （+，-，*，/） 第二个操作数”(注意中间的空格)" << endl;
	cin >> num1.num;
	cin >> cas;
	numi num2;
	cin >> num2.num;
	ans=caoZuo(cas, inputS(num1), inputS(num2));
	cout << "数值" << "	" << "进制" << endl;
	cout << ans.num<<"	"<<ans.wei << endl;
}
/*二进制是Binary，简写为B
八进制是Octal，简写为O
十进制为Decimal，简写为D
十六进制为Hexadecimal，简写为H*/