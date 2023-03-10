
# 기본적인 언어, STL, 시스템프로그래밍에 대한 이해도가 부족한 상황에서 이책을 보는건 효율성이 낮기때문에 2월 11일부로 잠시 중단 
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
    </br> string_view class는 이러한 고민을 해결할 수 있다. string_view는 const string& 대신하여 사용 할 수 있으며,
    </br> --------  스트링을 복사하지 않는다. -> 오버헤드가 없다 (예제 확인)
    
- [예제 소스코드 ](https://github.com/ktn1075/study/blob/main/Language/C%2B%2B/ProfesionalC%2B%2B/ch02.cpp)
     
</br>
     
### Ch03 Coding Style Guide (2023-02-09)

- 주석 기본 
  - 매개변수와 반환값에 대해 명시해준다.
  - 알고리즘에 대해 불변속성에 대한 주석을 추가하면 좋다.
  - 메타정보를 추가한다.
- 머리말 주석
  - 소스 파일 첫머리에 명시할 내용을 표준 주석으로 정해둔다
- 고정 양식 주석
  - Doxygen - 도구에서 정한 표준 양식에 따라 주석을 작성한다.

</br>

- 코드 분할
  - 코드를 더 작은 단위로 나눠서 작성하는 방식이다. 한 작업을 처리하는데 필요한 로직이 
    </br> 복잡하다면 이를 별도의 메서드로 분할한다.    

</br>

- 리팩토링 
  - 추상화를 높이는 기법
    - 필드 캡슐화 : 필드를 private로 설정하고, getter setter 메서드로 접근
    - 타입 일반화 : 코드를 좀 더 공유할 수 있도록 좀 더 일반적인 타입을 사용한다.
  - 코드를 좀 더 논리적으로 분할하는 기법
    - 메서드 추출 : 더 작은 메서드 단위로 정의
    - 클래스 추출 : 기존 클래스에 있는 코드 중 일부를 새 클래스로 옮긴다.
  - 명칭과 위치를 개선하는 기법 
    - 메서드 및 필드이동 
    - 메서드 및 필드 이름변경
 
</br>

- 명명규칙
  - 이름의 첫 글자로 숫자가 나올 수 없다.
  - 더블 언더스코어는 특정한 용도로 사용되기때문에 이름에 넣을 수 없다.
  - 언더스코어로 시작하는 이름도 특정한 용도로 사용하기 때문에 쓸 수 없다.
  - 상수 사용시 정확한 이름을 지정해준다.


요약 - 코드의 가독성을 높이는 데 얼마나 도움이 되는지에 따라 선정해야한다.

</br>

### Ch04 전문가다운 C++ 프로그램 다지기 (2023-02-10)

- 프로그램 디자인
  - 요구사항 분석에서 도출한 기능 및 비기능 요구사항을 모두 만족하는 프로그램을 구현하기 위한 구조에 대한 명세서이다.
    - 프로그램을 구성하는 서브시스템 : 인터페이스와 서브시스템 사이의 의존성, 데이터흐름, 입출력, 기본 스레드 활용모델
    - 서브시스템별 세부사항 : 클래스 구성, 클래스 계층도, 데이터 구조, 알고리즘, 개별 스레드 활용 모델, 에러처리 방법 
</br>

- C++ 디자인에 관련된 두 가지 원칙
  - 추상화 : 구현과 인터페이스 분리의 중요성 , 내부 구현 방식을 이해하지 않아도 코드를 사용 할 수 있다. 
  ```C+
    ChessPiece* chessBoard[8][8]; 
    chessBoard[0][0] = NEW rook();   // 이렇게 사용할 시 사용자는 체스보드의 크기를 항상 알아야 한다.
    
    // but
    class Board
    {
      public:
      void setPieceAt(size_t x, size_t y, ChessPiece* piece);
      ChessPiece* getPieceAt(size_t x, size_t y);
      bool isEmpty(size_t x, size_t y);
    }
  ```
 
  - 재사용 : 기존 코드를 재사용 할 수있게 클래스, 알고리즘, 데이터 구조들 디자인 해야한다. c++에서는 코드를 범용적으로 만들 수 있도록 템플릭 이라는 기능을 제공한다. 
  ```C+
  template <typename PieceType>
  class GameBoard
  {
    public:
      void setPieceAt(size_t x, size_t y, PieceType* piece)
      {

      }
      PieceType* getPieceAt(size_t x, size_t y)
      {

      }
      bool isEmpty(size_t x, size_t y) const
      {

      }
    };
    class jangiType{};
    class ChessType{};
    GameBoard <ChessType> c;
    GameBoard <jangiType> j;
  ```
  
- [예제 소스코드 ](https://github.com/ktn1075/study/blob/main/Language/C%2B%2B/ProfesionalC%2B%2B/ch04.cpp)

</br>

### Ch05 객체지향 다지기 (2023-02-11)
