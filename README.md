JNI를 사용하게된 계기
=
**Java에서는 윈도우의 권한이 부족하기에 JNI의 라이브러리를 통해 윈도우의 권한에 접근하기 쉬운 C++을 연동하여 기능을 구현하기 위해 연습하게 되었다.**

Java 헤더 파일 생성
=
**1. Java 파일을 만든다.**

**2. 파일 탐색기로 해당 java 파일이 있는 곳으로 이동 후 Shift + 우클릭을 하여 "여기에 PowerShell 창 열기"를 실행한다.**

![1](https://github.com/KRMorando/Java_Jni/assets/16814507/f398c901-beca-4f9f-b939-5444ae1e99a2)

**3. Java의 헤더 파일을 생성하기 위해 다음과 같은 절차를 진행한다.**
   * _**javac -h . JniTest.java**_ 를 PowerShell창에 입력한다.
   * 의미: javac -h (위치: .은 현재 폴더 대상) (파일 이름)

   ![1](https://github.com/KRMorando/Java_Jni/assets/16814507/37caf481-ec25-4efd-8514-05e325386df8)

dll 파일 생성
=
**1. Visual Studio를 열어 새로운 프로젝트를 생성한다.**

**2. Windows 데스크톱 마법사 (C++) 템플릿을 고르고 에플리케이션 종류는 동적 연결 라이브러리(.dll)로 설정해준다.**

![1](https://github.com/KRMorando/Java_Jni/assets/16814507/303695db-3623-4f58-bb5a-3bd74fdfdfb9)

**3. 솔루션 탐색기에서 프로젝트 우클릭 -> 속성 -> 구성 속성 -> VC++ 디렉터리에서 외부 include 디렉토리를 다음과 같이 변경 후 적용을 한다.**

    (JDK경로)\include; (JDK경로)\include\win32;

![image](https://github.com/KRMorando/Java_Jni/assets/16814507/5babe759-83fc-4664-9632-220ce759331e)
   
   * 첫번째 경로를 따라가보면 jni.h가 있고 이를 불러오기 위한 경로이다.<br>
   두번째 경로를 따라가보면 jni_md.h가 있고 이를 불러오기 위한 경로이다.
     
**4. 3번에서 생성했던 자바 헤더 파일을 복사해서 솔루션 탐색기에 있는 헤더 폴더에 붙여넣기 해준다.**

**5. 해당 프로젝트가 있는 경로를 파일 탐색기로 찾아가 폴더 내부에도 자바 헤더 파일을 붙여넣기 해준다.**

![image](https://github.com/KRMorando/Java_Jni/assets/16814507/b8949083-002e-41b7-93b8-94296852f73f)

**6. dllmain.cpp 파일명을 JniTest.cpp로 바꾼다. (원하는 이름으로 바꾼다.)**

![1](https://github.com/KRMorando/Java_Jni/assets/16814507/b590e5fd-d77c-4f08-bab5-951e3fa053d4)

**7. JniTest.cpp 에서 JniTest.java에서 native 로 선언한 함수들의 기능을 구현한다.**

**8. 빌드를 한다. (오류가 떠도 무시하면 된다. 우리가 원하는 것은 .dll 파일이기 때문이다.)**

결과 확인
=
**1. C++ 프로젝트가 있는 경로를 파일 탐색기로 찾아간 후 다음 경로를 들어간다.**

    (프로젝트 경로)\x64\Debug
    
**2. 해당 경로를 들어가면 빌드를 통해 생성된 JniTest.dll 을 복사한다.**

**3. 파일탐색기로 다음 경로를 들어간 후 .dll 파일을 붙여넣기해준다.**

    (자바 작업 환경)\(프로젝트이름)

**4. 자바 프로젝트에서 실행을 시킨 후 "Hello World"가 출력되는지 확인하면 끝~!**
