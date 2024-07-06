# 🌈 03. Redirect
## 💡 리다이렉트!!
1. **redirection?**
2. **리다이렉션 기호**
3. **파일 디스크립터 (stdin,stdout,stderr)**
```bash
#다음과 같은 명령어를 이해해봅시다
~$ find / -name "*.txt" 1>& a.txt
~$ ls -al -KnockOn 1> b.txt 2> a.txt
~$ ls -knockOn > c.txt 2>&1
```