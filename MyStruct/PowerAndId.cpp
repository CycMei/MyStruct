#include<vector>
#include<string>
#include<iostream>
using namespace std;
int mPower(int a, int b) {
	int value = 1;
	while (true) {
		int one = b % 2;
		b = b / 2;
		if (one == 1)
			value *= a;
		if (b == 0)
			break;
		a = a*a;
	}
	return value;
}
void getLastNumber(const std::string &ResStr) {
	const std::vector<std::string> tempArr{ "7","9","10","5","8","4","2","1","6","3","7","9","10","5","8","4","2" };
	const std::string copyTempArr = "10X98765432";
	int sum = 0;
	for (int i = 0; i != tempArr.size(); ++i) {
		char temp[2] = { '\0','\0' };
		temp[0] = ResStr[i];
		std::string stemp(temp);
		sum=sum+std::stoi(stemp)*std::stoi(tempArr[i]);
	}
	int res = sum % 11;
	if (copyTempArr[res] == *(ResStr.end() - 1))
		std::cout << "身份证号正确" << std::endl;
	else
		std::cout << "身份证号错误" << std::endl;
}
void test() {
	std::string ID{ "445222198901083707" };
	getLastNumber(ID);
}
