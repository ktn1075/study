#include<string>
#include<cstring>
#include<iostream>
#include<string_view>

using namespace std;

// c++ 17이전
void test(const char* str)
{
	cout << str << "\n";
}

bool contains_very(string_view str) {
	return str.find("very") != string_view::npos;
}

void* operator new(size_t count) {
	cout << count << " bytes 할당 " << endl;
	return malloc(count);
}

int main(void)
{
	// C Style 문자열의 끝에는 문자열의 끝을 나타내는 '\0' 을 포함하여 할당한다.
	char text1[] = "abcdef";
	size_t s1 = sizeof(text1);
	size_t s2 = strlen(text1);


	//raw string literal
	const char* str = R"("Hello World!")";
	const char* str2 = R"(LINE
LINE2)";
	cout << str2 << "\n";



	// c++ 17 이전 const 스트링 문자열 전달
	string t1 = "2342344";	
	test(t1.c_str());

	// string_view 활용한 문자열 전달.
	cout << boolalpha << contains_very("c++ string is very easy to use")
		<< endl;

	cout << contains_very("c++ string is not easy to use") << endl;

	string str3 = "some long long long long long string";
	cout << "--------------------" << endl;
	cout << contains_very(str3) << endl;

	// string_view substr 시 메모리 할당 발생 x 
	// string_view는 값을 복사하는게아니라 문자열을 시작 주소값만 복사한다.
	// string 이나 const char*을 전달하더라도 메모리 할당 발생 x 
	// string_view 특성 상 문자열을 읽는게 목적이기 때문에 원본 문자열을 수정하는 연산들 지원한다.
	// substr의 경우 string 에서는 O(n) 으로 수행되지만, string_view 의 경우 substr로 또다른 view
	// 를 생성 하므로 O(1)로 매우 빠르게 수행된다.


}