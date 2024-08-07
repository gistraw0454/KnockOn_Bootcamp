# 🌈 01. Linux 운영체제
```
window OS, mac OS와 같은 단어를 많이 들어보셨을 겁니다. 여기서 OS란 Operation System을 의미하는데요, OS의 종류는 매우매우 많습니다.

우리는 Linux 기반의 운영체제를 공부할 것 입니다. Linux기반의 운영체제의 특징이 무엇인지, Linux기반의 운영체제는 어느 것이 있는지 공부해 봅시다. 특히 Debian 운영체제에 대해서 공부를 진행해 봅시다
```
## Linux 기반 운영체제 특징
### 특징
1. 모놀리식 커널 : 모든 시스템 기능을 하나의 커널 이미지에 통합한 구조
    - 높은성능 : 시스템 기능을 빠르게 호출하고 실행가능
    - 작은 메모리 사용량 : 모놀리식 커널은 다른 유형의 커널에 비해 메모리 사용량이 적음
2. 가상메모리 SWAP 
    - 효율적인 메모리 관리 : 가상 메모리 시스템은 물리 메모리를 효율적으로 활용할 수 있다. (하드디스크 일부를 RAM(메모리)처럼 사용하면서)
    - 큰메모리 공간 : 가상 메모리 시스템은 물리 메모리 보다 훨씬 큰 메모리 공간을 사용할 수 있다.
3. 포크 (fork) 및 exec 시스템 호출:
    - fork 시스템 호출 : 현재 프로세스의 사본을 만듦.
    - exec 시스템 호출 : 새 프로세스의 메모리 공간을 새로운 프로그램에 대체
    프로세스를 빠르게 생성하고 다양한 프로그램을 실행가능
4. 네트워킹 지원
    - 리눅스커널은 TCP/IP 프로토콜 스택을 기본적으로 지원, 다양한 네트워킹 도구와 유틸리티 제공.
    - 리눅스를 서버, 라우터, 방화벽 등 다양한 네트워킹 장치로 사용할 수 있도록함.
5. 파일 시스템 지원
6. 계층적인 파일 구조
    - `/` root 를 기준으로 하위디렉터리들이 존재하는 tree 구조로 파일구조가 이루어져있음
7. 장치의 파일화
    - 하드웨어 장치를 모두 파일화하여 사용
    - 특정 하드웨어에 명령을 내리기위해 해당 하드웨어의 장치 파일에 명령을 내림
8. 동적 라이브러리 지원
9. 가상 콘솔 지원
10. 파이프 지원 `|`
    - 파이프 : 어떤프로세스의 표준 출력이 다른 프로세스의 표준 입력으로 쓰이도록 함. 
    - 프로세스 통신을 위해 도입
11. GUI 지원
### 장점
1. 개방성
    - 리눅스 커널과 대부분의 리눅스 배포판은 오픈소스 소프트웨어다. (소스코드가 공개되어 누구나 자유롭게 이용,수정,배포가능)
2. 보안성
    - 샌드박스 (sandbox) : 악성코드의 실행 제한
        - 외부로부터 받은 파일을 바로 실행하지 않고 보호된 영역에서 실행시켜봄으로써 외부로부터 들어오는 파일과 프로그램이 내부 시스템에 악영향을 주는 것을 방지
    - 빠른 보안 업데이트 가능
        - 사용자가 수정,배포 가능하기에 빠른 속도로 유연하게 보안문제 해결가능
    - Linux 배포자가 분산되어있고 악성코드가 주로 윈도우를 타겟으로 하기때문에 상대적으로 멀웨어로 부터 자유로움
3. 유연성
    - 다양한 하드웨어 플랫폼에서 실행될 수 있으며, 다양한 요구에 맞게 사용자 정의가능
    - 서버 : 웹 서버, 데이터베이스서버, 애플리케이션 서버 등 다양한 서버 환경에서 사용
        - 무료, 오픈소스, 안정성높음
        - GUI가 없는 환경(CLI)은 가벼워서 서버 성능도 좋고 보안에도 좋음
    - 데스크탑 : 리눅스는 다양한 데스크탑 환경 제공, 개인용컴퓨터, 노트북 등에서 사용
    - 임베디드 시스템 : 리눅스는 라우터, 스마트폰, 스마트TV 등 다양한 임베디드 시스템에서 사용 (안드로이도도 linux 기반)
4. 다양한 배포판 존재 
    - Redhat, Debian, Ubuntu..
5. 다중 사용자 및 다중 처리 시스템
    - Multi-User : 하나의 시스템에 다수의 사용자들이 동시에 접속해 사용가능
    - Multitasking : 다수의 작업에 대해 CPU등의 공용자원을 나눠 사용하는 방식으로 동시 사용 지원
6. 뛰어난 네트워크환경
    - 네트워크서버 사용가능. 인터넷, 이더넷에 안정적으로 연결가능
        - 이더넷은 물리적인 것에 대한 것이고요, 인터넷은 가상적인 것에 대한 것
        - 이더넷은 HW, SW, 통신 방식등에 대해 규정을 해놓은 것이고 인터넷은 이더넷 위에서 서비스가 되는 가상적인 것들에 대한 것
    - 다양한 네트워크 환경 지원(SLIP,ATM,...)
    - 대부분의 네트워크 프로그램 지원(TCP/IP, TPX,..)
7. 개발 친화적

## Lunix 운영체제 종류
- 우분투 리눅스 (Ubuntu Linux)
    - GUI지원, Unity 환경지원, ufw 방화벽을 사용하여 방화벽 설정이 간편, 개인용 데스크톱 환경에 최적화
- 페도라 리눅스 (Fedora Linux)
    - 커팅에지기술, 레드햇에 들어갈 기능을 테스트하는 성격이 강함.
    - 최신 소프트웨어 및 기술을 빠르게 경험가능, 개발자 및 첨단 사용자에게 적합, 안정성 떨어짐
- 칼리 리눅스 (Kali Linux)
    - 침투테스트 및 보안 취약점분석에 특화된 도구 및 기능 제공
    - 다양한 공격도구및 취약점 분석 기능 내장, 안정성 높음, 일반사용자에겐 부적합
- 레드햇 리눅스 (Red Hat Linux)
    - 기업서버환경에 최적화된 안정적으로 강력한 플랫폼, 유료
    - 엔터프라이즈 환경에서 검증된 안정성과 성능, 설치쉬움, 폭넓은 하드웨어지원, 대규모 데이터베이스환경에도 안정적으로 동작
- 리눅스 민트 (Linux Mint)
    - 우분투 기반, 쉬움, 업뎃지연, 커스터마이징 옵션 제한
- 센트 OS (CentOS)
    - 레드햇 엔터프라이즈 리눅스와 호환되는 무료 배포판, 서버환경에 적합
    - 레드햇을 그대로 빌드하여 상표권만 제거했다 봐도됨.
    - 전세계 점유율 1위
- 오픈수세 (OpenSUSE)
    - 한글화가능, YaST 지원, 쉬움, 지원부족
## Debian 운영체제
- 누구나 자유롭게 사용, 배포, 수정가능
- 자유로운 소프트웨어로 구성된 GNU/리눅스 배포판 중 가장 오래되고 영향력이 큰 배포판 중 하나
1. 데비안 특징
    - 안정성 : 철저한 테스트를 거친 안정적인 배포판으로 유명. "테스트 중" 버전과 "안정" 버전을구분하여 사용자에게 안정적인 운영 환경제공
    - 자유 : 자유로운 소프트웨어
    - 다양성 : 다양한 하드웨어 아키텍처를 지원. 다양한 데스크탑 환경과 애플리케이션 설치가능
    - 커뮤니티 : 사용자는 활발한 커뮤니티에서 다양한 정보와 지원을 얻을 수 있음.
    - 다양한 사용자 맞춤화 : 다양한 데스크탑 환경과 애플리케이션을 설치하여 사용자 맞춤화 가능
    - 최신 소프트웨어 : 불안정 버전과 테스트중 버전을 통해 최신 소프트웨어를 경험할 수 있다.
    - 초보자용 X , 최신 소프트웨어 버전 제공 지연, 무료버전