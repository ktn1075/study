# 전문가를 위한 C++
</br>

### Ch02 String (2023-02-08)

- C Style 문자열 처리시 주의사항
  - 문자열의 길이를 구할때 sizeof와 strlen 다르다. C언어의 문자열의 끝에는 문자열의 
    </br> +1끝을 나타내는 '\0' 문자가 포함되어 더 한 만큼 메모리에 할당되기 때문이다.
  - char* 형식 저장 시 sizeof 할 경우 32비트 모드와 64비트 모드의 포인터 변수의 크기가 다르기 때문이다.

- raw string literal
  : 여러 줄에 걸쳐 작성한 스트링 리터럴로서, 그 안에 담긴 인용 부호를 이스케이프</br>
  이스케이프 시퀀스로 표현할 필요가 없고, 일반 텍스트 취급한다. 정규표현식, 파일 경로 등을 쉽게 표현가능
  
  ```c++
  const char* str =R"("Hello World!")";
  const char* str2 = R"(LINE
  LINE2)";
  ```

- C++ String Class 
  - 실제로는 클래스지만 기본 타입인것 처럼 사용한다.
  - C 스타일 string 은 == 비교가 불가능 하지만 C++ String은 가능하다. 
    </br> ※ C 스타일 string은 char 배열의 첫번째 주소값이기 때문에 
  -  = 연산자를 통해 스트링 복사가 간편하다.
  -  메모리 누수가 발생하지 않는다. string 객체는 모두 스택변수로 생성된다.
    </br> ※ RAII 패턴 : 스택의 특성을 활요해 스코프가 벗어날때 소멸자에서 해당 메모리 자원을 해제한다.
  - c_str() 메서드를 사용하면 C언어에 대한 호환성을 보장 할 수 있다.
  - 다양한 helper 함수를 제공한다. 숫자를 문자열로 to_string();
 
- string_view Class
  : 읽기 전용 스트링을 받는 함수의 매개변수 타입 지정 시 string -> c_str() or data()를 이용하여
    </br> 변환하여 호출해야 한다. 이렇게 하면 helper 함수들과 string 객체지향의 특성을 활용 할 수 없다. 
    </br> string_view class는 이러한 고민을 해결할 수 있다. string_view는 const string& 대신하 사용 할 수 있으며,
    </br> 오버헤드도 없다. 스트링을 복사하지 않는다. 

