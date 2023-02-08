#include<string>
#include<cstring>
#include<iostream>
#include<string_view>

using namespace std;

// c++ 17����
void test(const char* str)
{
	cout << str << "\n";
}

bool contains_very(string_view str) {
	return str.find("very") != string_view::npos;
}

void* operator new(size_t count) {
	cout << count << " bytes �Ҵ� " << endl;
	return malloc(count);
}

int main(void)
{
	// C Style ���ڿ��� ������ ���ڿ��� ���� ��Ÿ���� '\0' �� �����Ͽ� �Ҵ��Ѵ�.
	char text1[] = "abcdef";
	size_t s1 = sizeof(text1);
	size_t s2 = strlen(text1);


	//raw string literal
	const char* str = R"("Hello World!")";
	const char* str2 = R"(LINE
LINE2)";
	cout << str2 << "\n";



	// c++ 17 ���� const ��Ʈ�� ���ڿ� ����
	string t1 = "2342344";	
	test(t1.c_str());

	// string_view Ȱ���� ���ڿ� ����.
	cout << boolalpha << contains_very("c++ string is very easy to use")
		<< endl;

	cout << contains_very("c++ string is not easy to use") << endl;

	string str3 = "some long long long long long string";
	cout << "--------------------" << endl;
	cout << contains_very(str3) << endl;

	// string_view substr �� �޸� �Ҵ� �߻� x 
	// string_view�� ���� �����ϴ°Ծƴ϶� ���ڿ��� ���� �ּҰ��� �����Ѵ�.
	// string �̳� const char*�� �����ϴ��� �޸� �Ҵ� �߻� x 
	// string_view Ư�� �� ���ڿ��� �д°� �����̱� ������ ���� ���ڿ��� �����ϴ� ����� �����Ѵ�.
	// substr�� ��� string ������ O(n) ���� ���������, string_view �� ��� substr�� �Ǵٸ� view
	// �� ���� �ϹǷ� O(1)�� �ſ� ������ ����ȴ�.


}