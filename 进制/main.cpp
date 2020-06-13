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
			cout << "�������" << endl;
			break;
	}
	a.num.pop_back();
	return a;
}
//����һ��������Ƶ���ת��Ϊ10����
//��d����ʮ����
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
//������10����ʱ��
int transfer(string s, int d)
{
	int sum = 0, k = 1; //��ʼ��
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
		cout << "�������" << endl;
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
	cout << "�����ʽ����һ�������� ��+��-��*��/�� �ڶ�����������(ע���м�Ŀո�)" << endl;
	cin >> num1.num;
	cin >> cas;
	numi num2;
	cin >> num2.num;
	ans=caoZuo(cas, inputS(num1), inputS(num2));
	cout << "��ֵ" << "	" << "����" << endl;
	cout << ans.num<<"	"<<ans.wei << endl;
}
/*��������Binary����дΪB
�˽�����Octal����дΪO
ʮ����ΪDecimal����дΪD
ʮ������ΪHexadecimal����дΪH*/