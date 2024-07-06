# 🌈 02. Linux 운영체제 명령어
- 명령어 옵션 : `-` 나 `--` 뒤에 알파벳 붙여 사용하는 것
    - 보통 `<명령어> -h or --help` 를 입력하면 해당 명령어의 다양한 옵션과 사용법을 볼 수 있습니다. ex) ls --help

## 💡 리눅스 운영체제 명령어
1. **`cd, echo, more, cat, head, tail, mkdir, mv, cp, rm, sudo, touch,ifconfig, grep …` 등등**
    - touch : touch -d "yesterday" file.txt 파일의 최근 수정시간 바꿀때사용
    - ifconfig : 모든 활성 인터페이스 세부정보 표시. 서버에 할당된 IP주소 확인하는데 사용
    [ifconfig 참고](https://github.com/gistraw0454/KnockOn_Bootcamp/blob/main/LinuxOS/08_ufw.md)
    - grep : 파일내 패턴 검색
        ```bash
        # 파일내 keyword라는 단어가 포함된 모든 줄 출력
        grep "keyword" file.txt 

        #대소문자 구분없이 검색
        grep -i "keyword" file.txt

        #정규표현식 사용한 검색
        grep "^start" file.txt

        #특정 디렉토리 내의 모든 파일에서 패턴검색
        grep -r "keyword" directory/
        ```
    - find : 시스템에서 파일을 검색하는데 사용
    - chown [옵션] 사용자 : 사용자 소유권 변경
        

2. **다중 명령어  ( `|` , `;` , `&` , `&&` )**
    - `|` : 한 명령어의 출력을 다른 명령어의 입력으로 전달
        ```bash
        ex) 현재 디렉토리의 파일 목록을 출력후, 그 중 example이 들어가 있는 파일 이름을 찾아 출력
        ❯ ls | grep "hello"
            hello.c
            hello2.c
        ```
    - `;` : 여러 명령어를 순차적으로 실행. 앞명령어의 실패여부 상관x
    - `&` : 명령어를 백그라운드에서 실행
        ```bash
        sleep 10 &
        ```
    - `&&` : 첫번째 명령어가 성공한 경우만 두번째 명령어 실행
        ```bash
        ❯ sleep 10 && echo "잘잤노" # 10초뒤에 echo 실행
        ```
    - `||` : 첫번째 명령어가 성공하면 뒤에 명령어 실행하지 않음

3. **명령어 주석**
    `#`,`<<'END'`~~~~~`END` 이렇게하면 여러줄 주석가능

## 🔥 Challenge !
1. **shell?**
    - 사용자가 입력한 명령어를 해석하여 커널에 전달하는 역할을 수행하는 command interpreter
    - DOS 의 command.com과 동일한 기능을 수행하는 프로그램
    - 커널에 해석한 명령어를 전달할 때 셸은 커널과 사용자 간의 대화식 인터페이스를 제공하여 접근을 더 쉽게 도울 수 있다.
    - redirection과 pipe기능 제공과 foreground/background process 실행가능
    - Bourne Shell ($)
        - /bin/sh 본셸, /bin/ksh 콘셸, /bin/bash 배시셸 , /bin/zsh 지셸
    - C Shell (%) : 본셸의 모든기능 + 명령어 히스토리(history), 별명(alias), 작업제어기능 
        - /bin/csh C셸, /bin/tcsh tcsh셸
2. **/bin/bash vs /bin/sh**
    - /bin/sh : $ Prompt 사용. 처음으로 등장한 셸. history, alias 등 제어들을 사용할 수 없음.
    - /bin/bash : 본셸 기반으로 개발된 셸. C, 콘셸 기능도 제공. @ubuntu:~$ Prompt 사용. 리눅스에서 기본적으로 사용
    
    모든 시스템에서 bash가 기본적으로 설치되어있는 것은 아니므로, 호환성이 중요한 경우 /bin/sh 를 사용하자.
