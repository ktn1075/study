# 제프리 리처의 WINDOWS vai C/C++

</br>

## 문자와 문자열로 작업하기 (2023-02-11)

- 문자인코딩 
  - UTF-8 : 1,2,3,4 바이트로 인코딩 수행하며, 0x0080 미만에 있다면 1바이트, 0x07FF 이내면 2바이트, 0x0800 이상의 문자들은 3바이트로 인코딩한다.
  - UTF-32 : 모든 문자를 4byte로 인코딩 파일저장이나 네트워크 전송시에는 거의 사용되지 않는다.

- ANSI 문자와 유니코드 문자 그리고 문자열 자료형
  - ANSI 문자열 : 1바이트 문자로 구성된 문자열
  - c/c++ 컴파일러는 16비트 유니코드를 표현하기 위한 wchar_t 자료형을 내장 자료형으로 처리할 수 있는 기능 추가 
    ```C++
      wchar_t c= L'A';
    ```
  - API들을 보다보면 끝이 W,A 로 끝나는 함수가 있다. A는 ANSI W는 wideCharacter 16비트 유니코드를 문자열로 취급한다.

- _S 가 붙은 안전한 함수나 Tchar 활용
  - _s 문자열 함수는 내부적으로 가장 먼저 인자의 유효성을 검사한다. NULL, 정수값 유효범위, 열거형 값이 유효한지 
  - Tchar 유니코드,ANSI 에 맞게 연결된 함수 호출 
 
- 유니코드 장점
  - 지역화가 유리하다.
  - 단일의 바이너리 파일로 모든 언어 지원가능
  - 유니코드 사용시 윈도우가 제공하는 모든 함수를 쉽게 이용가능
  - 유니코드 사용시 .NET과 상호 운용이 쉽다.



## 커널오브젝트 (2023-02-11 ~ 2023-02-12)
  
  - Section 1 
    - 커널 오브젝트 정의 : 운영체제에서 리소스(쓰레드,프로세스,파일) 들을 관리하기 위한 데이터를 저장하는 메모리 블록 
      - 커널 오브젝트는 커널에 의해 할당된 간단한 메모리 블록
      - 커널에 의해서만 접근이 가능한 구조체로 구성 
      - 커널 오브젝트에 대한 세부 정보 저장 (보안디스크립터, 사용카운트) 공통 부분
      - 커널 오브젝트 생성시 함수는 각 커널 오브젝트를 구분 하기 위한 핸들 값을 반환
      - 핸들 값은 르로세스 내의 모든 스레드에서 사용 가능하지만 의미는 없다 (64bit , 32bit)
      - 프로세스 별로 독립된 핸들 테이블을 가지고 있다. 

    - Usage(사용카운트) 
      - 커널 오브젝트는 프로세스가 아니라 커널에 의해 소유되기 때문에 프로세스가 종료된다고해서 오브젝트가 삭제되는게 아니다.
      - 사용 카운트를 통해 얼마나 많은 프로세스가 커널 오브젝트를 사용하고 있는지 알 수 있다.
      - 최초 생성시 사용 카운트는 1로 설정 
      - 다른 프로세스가 접근 권한 획득시 사용 카운트 증가
      - 0이되면 커널오브젝트 삭제
    
    - 보안 디스크립터
      - 커널 오브젝트 소유권, 접근권한, 접근제한 여부 정보를 가지고있다.
      - 커널 오브젝트를 생성하는 거의 대부분의 함수들은 SECURITY_ATTRIBUTES 구조체에 대한 포인터를 받는다.
      - 현재 프로세스의 보안토큰을 근간하는 기본 보안디스크립터를 사용하기에 NULL 전달 무관 

  - Section 2 
    - 핸들 테이블 : 커널오브젝트에 접근하기 위한 핸들을 관리하기위한 테이블 
      - 프로세스 핸들 테이블의 구조 : 인덱스, 메모리블록 포인터, 액세스마스크, 플래그 
      - 프로세스 초기화 되면 운영체제는 프로세스를 위한 커널 오브젝트를 생성 
      
  - Section 3 
    - 프로세스 간 커널 오브젝트의 공유 
      - 오브젝트 핸들의 상속을 이용하는 방법 
        - 오브젝트 핸들의 상속은 오브젝트를 공유하고자 하는 프로세스들이 페어런트-차일드 관계를 가질때 상속이 가능
        - 윈도우는 오브젝트 핸들의 상속을 지원한다. 오브젝트 자체의 상속이 아니다.
        - 오브젝트 핸들 상속은 차이들 프로세스를 새로 생성할 때에만 적용이 가능하다.
        - 차일드 프로세스는 어떤 핸들이 상속된 것인지 알 수 없다.
    - 명명된 오브젝트를 사용하는 방법
      ```C++
      HANDLE CreateMutex(
        PSECURITY _ATTRIBUTES psa,
        BOOL bInitialOwner,
        PCTSTR pszNAME); 
       ```
       pszNAME 에 NULL 이 아닌 '\0' 끝나는 문자열[260] 전달하면 해당 이름의 커널 오브젝트를 생성 할 수 있다.
       
## 프로세스 (2023-02-13 ~ 2023-02-15)

- 프로세스 : 실행 중인 프로그램의 인스턴스 즉 프로그램이 실행되어 메모리에 올라간 상태를 프로세스라고 한다
  - 프로세스 컴포넌트
    - 프로세스 관리하기 위한 목적으로 OS 가 사용하는 '커널 오브젝트'
    - 실행 모듈이 DLL 의 코드와 데이터를 수용하는 '주소 공간'
  - 프로세스는 자력으로 수행될 수 없다. 프로세스가 무언가를 수행하기 위해서는 반드시 프로세스 컨텍스트 내에서 수행되는 스레드가 존재 해야한다.
  - 프로세스가 생성되면 시스템은 자동적으로 첫 번째 쓰레드를 생성

- Section 1 첫 번째 윈도우 애플리케이션 작성 
  - 윈도우 애플리케이션은 애플리케이션이 수행을 시작할 entry point 함수를 반드시 가져야한다. 
    - GUI : ANSI : _tWinMain(), GUI : UNICODE : _tWinMain(wWinMain)
    - CUI : ANSI : _tmain(main), CUI : UNICODE ; _tmain(wmain)
  - 시작 루틴 
    - 새로운 프로세스의 전체 명령행을 가리키는 포인터를 획득
    - 새로운 프로세스의 환경변수를 가리키는 포인터를 획득
    - C/C++ 런타임 라이브러리의 전역변수를 초기화
    - C/C++ 런타임 라이브러리의 메모리 할당 함수와 저수준 입출력 루틴이 사용하는 힙을 초기화
    - 모든 전역 오브젝트와 static C++ 클래스 오브젝트의 생성자 호출
    - entry point 함수 호출 
  - 종료 루틴
    - entry point 함수 리턴 (nMainRetVal) 
    - exit 함수호출
      - _onexit 함수를 이용하여 등록해 두었던 함수를 호출
      - nMainRetval 값을 인자로 하여 ExitProcess 함수를  호출 
      - 운영체제는 프로세스 종료하고 프로세스 종료 코드를 설정
  - 프로세스 인스턴스 핸들
    - 모든 실행 파일과 DLL파일은 프로세스의 메모리 공간 상에 로드될 때 고유의 인스턴스 핸들을 할당 받는다. OS 프로그램들을 구별하기 위한 ID 값
    - (W)WinMain의 첫 번째 매개변수인 hInstanceExe 를 통해 전달된다.
    - 핸들 값은 보통 리소스를 로드할 때 사용 된다.
    - HINSTANCE 자료형은 인스턴스 핸들을 저장할때 사용되며 HMODULE과 완전히 동일하다.
   ```C++
      // 프로세스 내 실행,DLL 시작 주소를 얻기 위한 2가지 방법 
      #include<Windows.h>
      #include <minwindef.h>
      #include <libloaderapi.h>
      #include <tchar.h>

      extern "C" const IMAGE_DOS_HEADER __ImageBase;

      void DumpModule()
      {
	      // GetModuleHandle 함수사용 NULL 인경우 실행파일의 시작주소를 반환 
	      HMODULE hMoudle = GetModuleHandle(NULL); 
	      _tprintf(TEXT("with GETmoude(null) = 0x%x\r\n"), hMoudle);
	      _tprintf(TEXT("with IMAGEBASE = 0x%x\r\n"), (HINSTANCE)&__ImageBase);

	      hMoudle = NULL;
            
	      GetModuleHandleEx(
		    GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		    (PCTSTR)DumpModule,
		    &hMoudle);

	      _tprintf(TEXT("get hmoudle = 0x%x\r\n"), hMoudle);
      }

      int _tmain(int argc, TCHAR* argv[])	
      {
	      DumpModule();
	      return(0);
      } 
   ```
    - 프로세스의 환경변수 
      - 모든 프로세스는 자기 자신과 연관된 환경블록이 존재한다. 환경블록이란 프로세스의 주소 공간에 할당된 메모리 블록을 의미
      - 각 문자열의 첫 번째 부분은 환경변수의 이름이고 뒤이어 =가 있고 그다음의로 할당하고자 하는 변수의 값이 나타난다.\
   
     ```C++
      
      	// 환경변수 값 가지고오는 방법 첫번째
      	#include<Windows.h>
      	#include <minwindef.h>
      	#include <libloaderapi.h>
      	#include <tchar.h>
	void DumpEnvStrings()
	{

	PTSTR pEnvBlock = GetEnvironmentStrings();
	TCHAR szName[MAX_PATH];
	TCHAR szValue[MAX_PATH];
	PTSTR pszCurrent = pEnvBlock;
	HRESULT hr = S_OK;
	PCTSTR pszPos = NULL;
	int current = 0;

	while (pszCurrent != NULL)
	{
		if (*pszCurrent != TEXT('='))
		{
			pszPos = _tcschr(pszCurrent, TEXT('='));

			pszPos++;

			size_t cbNameLength = (size_t)pszPos - (size_t)pszCurrent - sizeof(TCHAR);

			hr = StringCbCopyN(szName, MAX_PATH, pszCurrent, cbNameLength);

			if (FAILED(hr))
			{
				break;
			}

			hr = StringCchCopyN(szValue, MAX_PATH, pszPos, _tcslen(pszPos) + 1);

			if (SUCCEEDED(hr))
			{
				_tprintf(TEXT("[%u] %s=%s\r\n"), current, szName, szValue);


				if (hr == STRSAFE_E_INSUFFICIENT_BUFFER)
				{
					_tprintf(TEXT("[%u] %s=%s...\r\n"), current, szName, szValue);
				}
			}
			else {
				_tprintf(TEXT("[%u] %s\r\n"), current,pszCurrent);
			}

			current++;

			while (*pszCurrent != TEXT('\0'))
				pszCurrent++;
			pszCurrent++;

			if (*pszCurrent == TEXT('\0'))
				break;
		};
	
		FreeEnvironmentStrings(pEnvBlock);
		}
	}

      	}
    '''
