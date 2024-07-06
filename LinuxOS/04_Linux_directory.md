# 🌈 04. Linux 디렉토리 구조
## 💡 디렉토리 구조
1. **절대경로와 상대경로**
- 절대경로 (Absolute Path) : `/`로 시작
- 상대경로 (Relative Path) 
2. **루트 디렉토리 구조와 각 디렉토리의 특징**
- `/` (Root Directory)
    - 시스템 최상위 디렉토리
    - 모든 다른 디렉토리 및 파일은 이 디렉토리 하위에 위치
    - 운영체제의 모든 파일 및 디렉토리가 이 디렉토리 하위에 위치
- `/bin` (Binary Binaries)
    - 바이너리 실행 파일들이 있는 디렉토리
    - 주여 리눅스 명령어들이 이 디렉토리에 위치 (ls, cp, mv)
- `/boot` (Boot Loader Files)
    - 부팅로더 파일과 커널 이미지가 있는 디렉토리
    - 부팅 프로세스에 필요한 파일들이 여기 위치
- `/dev` (Device Files)
    - 장치 파일들이 있는 디렉토리
    - 시스템의 하드웨어 장치와 상호작용하기 위한 특수 파일들이 위치
- `/etc` (Etcetera)
    - 시스템의 설정 파일들이 있는 디렉토리
    - 대부분의 시스템 구성 파일들이 여기에 위치 (네트워크 구성, 사용자 계정 및 패스워드, 서비스 설정)
- `/home` (Home Directories)
    - 사용자의 홈 디렉토리들이 있는 디렉토리
    - 각 사용자에 대한 홈 디렉토리들이 여기에 위치
- `/lib` (Library Files)
    - 공유 라이브러리 파일들이 있는 디렉토리
    - 프로그램이 실행될 때 필요한 라이브러리들이 여기에 위치
- `/media` (Removable Media)
    - 이동식 미디어 (USB드라이브, CD-ROM 등)가 마운트되는 디렉토리
    - 이동식 미디어 마운트하여 사용할 때 여기에 접근 가능
    >마운트 : 파일시스템을 특정한 디렉토리에 연결하는것. 다른저장장치 (하드디스트 USB 네트워크 드라이브)에 저장된 파일들에 접근하기 위해 해당 장치를 시스템의파일 트리에 연결하는 과정
- `/mnt` (Mount Point)
    - 일시적으로 파일 시스템을 마운트하는 디렉토리
    - 일반적으로 시스템 유지보수작업 또는 임시 파일 시스템을 마운트 할 때 사용
- `/opt` (Optional Package)
    - 추가적인 소프트웨어 패키지들이 설치되는 디렉토리
    - 주로 사용소프트웨어나 사용자 지정 소프트웨어 패키지들이 여기에 설치
- `/sbin` (System Binaries)
    - 시스템 관리용 바이너리 실행 파일들이 있는 디렉토리
    - 주로 시스템 관리자들이 시스템 구성을 위해 사용하는 명령어들이 여기에 위치
- `/tmp` (Temporary Files)
    - 일시적인 파일들이 있는 디렉토리
    - 시스템 및 사용자 프로세스들이 일시적으로 파일을 생성하고 사용할 때 여기에 위치
- `/usr` (Unix System Resources)
    - 시스템 리소스들이 있는 디렉토리
    - 시스템이 아닌 사용자가 사용하는 프로그램들이 저장되는 곳
    - 시스템 소프트웨어 및 데이터가 여기에 위치 (사용자 프로그램, 라이브러리, 문서, 공유 데이터)
- `/var` (Vairable)
    - 시스템이 실행되는 동안 변하는 파일들이 있는 디렉토리
    - 로그파일, 캐시, 임시파일 등이 여기에 위치
- `/lost+found`
    - 파일 시스템 오류가 발생했을때, fsck(File System Consistency Check) 유틸리티가 손상된 파일이나 디렉토리를 복구할 때 사용하는 디렉토리
    - 일반적으로 사용자가직접 파일을 저장하거나 관리하지 않는다.
    - 파일시스템 관리 도구에 의해 자동 생성됨
- `/proc`
    - 프로세스 정보를 포함하는 가상파일 시스템
    - 시스템에서 실행 중인 모든 프로세스에 대한 정보를 제공 ( 프로세스 ID, 메모리 사용량, 네트워크 상태 등의 정보를 제공 )
    - 일반적으로 시스템 관리 작업 및 모니터링 도구에서 사용됨.
- `/root` 
    - 사용자 홈 디렉토리를 나타내기위해 사용
    - root는 시스테 관리자의 역할을 나타내는 것,`/` 는 파일 시스템의 최상위 디렉토를 가리키는 것
- `/run` 
    - 시스템 부팅 중 생성되는 런타임 데이터와 PID 파일을 포함 하는 디렉토리
        - PID 파일 (데몬프로세스의 실행상태를 관리하고 추적하기 위해 사용되는 파일, 해당 프로세스의 프로세스ID 저장)
            - 데몬프로세스 : 백그라운드에서 실행되는 컴퓨터 프로그램이며, 사용자의 상호작용없이 시스템이나 다른 프로세스를 지원하거나 관리하는 역할 수행
- `/snap` 
    - snap 패키지 관리 시스템에 의해 설치된 스냅 패키지들을 포함하는 디렉토리
    - snap 패키지는 응용 프로그램과 그 종속성을 캡슐화하여 시스템에 설치하고 실행하는데 사용
- `/srv` 
    - 서비스 관련 데이터를 저장하는 디렉토리
    - 네트워크 서비스 (HTTP,FTP) 의 데이터 파일들을 보관하는데 사용될수있다.
- `/sys` 
    - 커널과 관련된 정보를 포함하는 가상 파일 시스템
    - 시스템의 하드웨어 및 커널 매개변수와 같은 시스템 정보에 대한 접근을 제공
    - 일반적으로 `/proc`과 함께 시스템 정보를 관리하고 모니터링하는데 사용
```txt
루트 디렉토리의 기본 구조와 내부에 있는 각 파일의 역할을 아는것은 해킹에 매우 중요한 요소 중 하나입니다. 

어느 부분에 주요 정보가 담긴 파일이 존재하는지, 어느 디렉토리를 활용해야 주요 정보에 도달할 수 있는지 등을 활용할 수 있습니다.

예를 들어 /etc/shadow, /etc/passwd 등이 존재합니다
```
### etc dircetory 
- `/etc/passwd`
    - 사용자 계정에 대한 정보를 포함하는 파일. 
    - 각 행은 하나의 사용자를 나타내며, 사용자 이름, 홈디렉토리경로, 사용자 ID등의 정보를 포함
- `/etc/group`
    - 그룹정보를 포함하는 파일
    - 각 행은 하나의 그룹을 나타내며, 그룹이름, 그룹id, 해당 그룹에 속한 사용자 목록 등의 정보를 포함
- `/etc/shadow`
    - 사용자 계정의 보안관련정보(암호화된 비밀번호)를 포함하는 파일 (일반사용자가 읽을 수 없음)
- `/etc/hosts/`
    - 호스트 이름과 IP 주소를 매핑하는 파일. 일반적으로 시스템이 로컬 네티워크에서 사용하는 호스트이름을 관리하는데 사용
- `/etc/hostname`
    - 시스템의 호스트이름을 저장하는 파일. 이파일은 시스템의 호스트이름을 지정하고 변경하는데 사용
- `/etc/network/interfaces` (`/etc/netplan/`)
    - 네트워크 인터페이스의 설정을 관리하는 파일이거나 디렉토리다.
    - 네트워크 설정을 수정하고 관리한느데 사용
- `/etc/fstab`
    - 파일 시스템 테이블 파일.
    - 시스템 부팅시에 마운트할 파일 시스템을 지정하는데 사용
    - 각 파일 시스템의 마운트 지점과 옵션을 설정
- `/etc/apt/sources.list` (`/etc/apt/sources.list.d/)
    - APT 패키지 관리 시스템의 소프트웨어 저장소 정보를 포함하는 파일 또는 디렉토리
    - 시스템 패키지 관리 및 업데이트를 위해 사용
- `/etc/apt/apt.conf` (`/etc/apt/apt.conf.d/`)
    - APT 패키지 관리 도구의 전반적인 동작을 설정하는 파일 또는 디렉토리
    - APT동작을 수정하고 사용자 정의 설정을 추가하는데 사용
- `/etc/ssh/sshd_config`
    - SSH 서버의 설정파일
    - SSH 서버의 동작을 제어하는데 사용(인증방법, 포트번호, 사용자 접속권한 등 설정)
- `/etc/crontab` (`/etc/cron.d/`)
    - cron 시스템의 전반적인 설정 파일이거나 디렉토리
    - cron은 예약된 작업 (job)을 실행하는 시스템 서비스로, 정기적인 작업 스케줄을 설정하는데 사용
- `/etc/sudoers` (`/etc/sudoers.d/`)
    - sudo 명령의 권한 설정 파일 또는 디렉토리
    - 사용자 또는 그룹에게 특정 명령을 루트 권한으로 실행할 수 있는 권한을 부여하는데 사용
- `/etc/environment`   
    - 시스템 환경변수를 설정하는 파일
    - 시스템 전체적으로 사용할 환경변수를 설정하는데 사용
- `/etc/sysctl.conf` (`/etc/sysctl.d/`)
    - 시스템 커널 설정을 수정하는데 사용되는 파일 또는 디렉토리
    - 시스템의 네트워크, 메모리, 파일 시스템 등의 커널 파라미터를 설정하는데 사용
- `/etc/ngix/nginx.conf` (`/etc/ngix/sites-available/`)
    - nginx 웹 서버의 주요 설정 파일 이거나 가상 호스트 설정 파일이 있는 디렉토리
    - nginx 웹 서버의 동작을 설정하고 가상 호스트를 관리하는데 사용
        - Nginx 엔진엑스   
            - 높은 성능과 안정성을 가진 오픈소스 웹 서버 및 리버스 프록시 소프트웨어
            - 정적 파일 서빙, 동적콘텐츠 처리, 로드 밸런싱, SSL종료, 웹 애플리케이션 프록시 등 다양한 용도로 사용
            - 주로 높은 트래픽을 처리해야하는 웹 사이트나 웹 애플리케이션에 적합

```bash
#다음과 같은 명령어를 이해해봅시다
~$ find / -name *.txt 1>> /dev/null # 루트에서 이름이 .txt인 모든 파일을 찾고, 해당결과를 stdout 으로 보낸다. 
                                    # 1>>/dev/null : 표준출력을 /dev/null로 리다이렉트 하는 것으로, 결과를 무시하고 버림
~$ find / -name *.txt 2>> /dev/null # 루트에서 이름이 .txt인 모든 파일을 찾고, stderr로 발생한 오류메세지를 /dev/null로 리다이렉트하여 오류를 무시 
~$ /bin/bash    #새로운 bash 셸 실행
~$ /bin/ls  #ls 명령어 실행
~$ head /var/log/apt/history.log    # apt, apt-get 설치이력의 상위 몇줄을 출력
```
> apt,apt-get을 이용한 모든작업은 `/var/log/apt/` 아래의 로그파일에 기록됨. 그중 설치이력에 대한건 `history.log`에 저장.

## 🔥 Challenge !
1. **`ls -al` 을 입력했을때 아무런 출력이 없도록 하기**
    ```bash
    ls -al 1 > /dev/null
    ```
2. **`hihi`라는 명령어(존재하지 않는 명령어)를 입력해도 아무런 오류메세지가 없도록 하기**
    ```bash
    hihi 2 > /dev/null
    ```
3. **모든 사용자의 암호화된 비밀번호 출력하기**
    ```bash
    cat /etc/shadow #권한 없으면 sudo cat /etc/shadow
    ```