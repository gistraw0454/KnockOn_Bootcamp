# 🌈 05. Vim
## 💡 방화벽과 리눅스 방화벽 시스템 UFW
1. **vim 이란?**
- vi improved (vi 향상된 버전)
- Normal 모드 : ese 눌러 나온 화면
    - hjkl
    - x 문자하나 삭제
    - dd 행 삭제
    - p 붙여넣기
    - /텍스트 검색모드 n과 N으로 이동
    - w 다음단어 b 이전단어
    - gg 파일 젤 앞 G 파일 젤 끝
    - u 실행취소 Ctrl+R 다시 실행
- Insert 모드 : I 눌러 나온 텍스트입력 화면
- Visual 모드 : v V 눌러 나온 화면 
    - 텍스트 선택후 y 복사 d 삭제
- Command-Line 모드 : `:` 로 시작 
    - :w :q :wq :q! 
    - :set 
        - number 행번호 표시 nonnumber 행번호 숨김 relativenumber 상대적행번호 표시
        - ignorecase 검색시 대소문자 구분x smartcase 검색시 대소문자 구분하지만 대문자를 포함한 검색어를 입력하면 대소문자 구분 해제
        - tabstop 탭문자의 너비 설정
        - expandtab 탭 문자를 공백 문자로 대체
        - syntax 문법 강조 활성화
        - autoindent 자동 들여쓰기 활성화
        - wrap 텍스트가 화면 너비를 초과할때 줄바꿈 활성화 wrap! 비활성화
        - mouse 마우스지원 활성화
     
2. **how to install vim & use vim**
    ```
    sudo apt install vim
    ```
## 🔥 Challenge !

1. **.sh 파일이란?**
- shell script file
- 리눅스 및 유닉스 기반 시스템에서 셸이라고 불리는 명령 줄 인터페이스를 사용하여 실행되는 스크립트 파일
- 셸 스크립트 언어로 vim을 사용하여 작성, 터미널에서 실행
- 실행 권한을 부여한 후 해당 스크립트 파일을 실행하면 셸이 스크립트 파일을 읽어들여 해당 명령어를 실행한다.
- 시스템 관리나 자동화된 작업을 수행하는데 매우 유용

2. **.sh 파일 작성법**

    1. 텍스트 편집기 열기
    ```bash
    vim 파일이름.sh
    ```
    2. 셸 스크립트 작성
    ```shell
    #!/bin/bash     : 스크립트를 실행할 셸을 지정하는 shebang (!로 셔뱅라인 구분)
    echo "Hello, World!"    
    ls -l
    ```
    3. 파일 저장 :wq!
    4. 실행권한 부여
    ```bash
    chmod +x 파일이름.sh
    ```
    5. 실행
    ```bash
    ./파일이름.sh
    ```

    ex)
    ```shell
    #!/bin/bash

    echo "셸 스크립트 작성해보았어요 !"
    read name #사용자로부터 입력 받음
    echo "$name님 오늘은 $(date +%A)입니다."

    #----------------------------------------------------
    age = 20
    if [$age -ge 18]; then  # -ge는 비교연산자 크거나같다 -eq는 같다 -lt 작다
            echo "으른"
    else
            echo "baby"
    fi #if 문의 끝을 나타냄

    #----------------------------------------------------
    for fruit in apple banana orange
    do
            echo "나는 $fruit 좋아함"
    done
    #while 문도 동일 형태 while do done

    #----------------------------------------------------
    target_dir = "/path/"
    cd "$target_dir" || exit #실패시 스크립트 종료
    ls -l
    ```
3. **auto_move.sh 파일을 작성해서 해당 파일을 실행하면 자동으로 특정한 디렉토리로 이동하여 해당 디렉토리의 내용을 보여주는 프로그램 만들기**
```shell
#!/bin/bash

target_dir="/../"
cd "$target_dir" || exit
ls
```
> 그냥 실행하면 서브쉘에서 실행이된다. 그래서 서브쉘에서만 적용이되고 실제로 경로가 바뀌진 않는다. 따라서 source ./명령어 로 실행시키면 현재 쉘에서 실행되게 된다.