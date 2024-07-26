# 🌈 12. 동적할당
## 💡 동적 할당?
1. **동적할당의 개념과 필요성**
- 동적할당이란?
    - 프로그램이 실행되는 도중에, 필요한 메모리 공간을 할당 받는것
    - 실행 시간에 사용자의 요구에 따라 그 크기가 변해야 할때 동적할당을 사용.
- 필요성?
    - 사용자가 입력한 데이터의 수에 따라 배열의 크기가 달라져야하는 상황에, 동적할당을 사용하지 않으면 매우 비효율적일 것이다.
    - 동적 할당을 통해 필요한 메모리 공간을 유연하게 확보할 수 있다.
2. **동적할당의 사용 방법과 함수들**
- 동적할당 사용법
    - **동적할당 헤더파일**
        - `#include <stdlib.h>` : 동적할당을 위한 헤더파일
    - **malloc**
        - `int *ptr = (int *)malloc(sizeof(int) * 5);` : 5개의 정수공간을 할당
    - **calloc**
        - `int *ptr = (int *)calloc(5,sizeof(int));` : 5개의 정수공간을 할당하고 0으로 초기화
    - **realloc**
        - `ptr = (int *)realloc(ptr, sizeof(int) * 10);` : 이미할당된 공간을 10개의 정수크기로 재할당
    - **동적할당 해제**
        - `free(ptr);`
    - 크기 인자들은 byte단위로 명시한다 ! 메모리 할당에 성공하면 할당된 함수의 시작위치를 가리키는 포인터를 리턴한다.

3. **동적할당과 구조체**
- 구조체는 서로 다른 타입의 변수들을 하나로 묶어 새로운 타입을 만들어내는 기능을 함
    - 프로그램이 커지고 복잡해질수록 구조체+동적할당 많이 사용
    ```c
    // 구조체 동적할당 예시
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct{
        char name[20];
        int age;
        float score;
    }Student;
    
    int main(){
        // Student 구조체 포인터에 동적 할당
        Student *s = (Student*)malloc(sizeof(Student));
        //만약 Student *s = (Student*)malloc(sizeof(Student)*100) 이런식으로하면 구조체 배열을 쉽게 할당할 수 있다.
        
        if (s==NULL){
            printf("메모리 동적할당 실패");
            return -1;
        }

        s-> age =20;
        s->score = 88.5;
        strcpy(s->name,"홍길동");

        printf("이름: %s, 나이: %d, 점수: %.2f\n",s->name,s->age,s->score);

        //메모리 해제
        free(s);
        return 0;
    }
    ```
    근데 난... 이코드에서 이렇게 쓰는게 특별히 의미가 있는진 잘 모르겠다...

4. **typedef 와의 연계**
- typedef 를 사용하면 구조체 타입을 더 간단하게 선언할 수 있다.
    - struct Student 대신 Student 만으로도 선언가능.
5. **동적할당의 주의점과 메모리 누수**
- free로 할당해제를 꼭 해줘야한다. 메모리 누수 방지를 위함.
- 메모리 누수?
    - 컴퓨터 프로그램이 필요하지 않은 메모리를 계속 점유하고 있는 현상
    - 할당된 메모리를 사용 후 반환되지 않은 것이 누적되면 메모리가 낭비된다.
    - 메모리 누수가 있는 프로그램은 흔히말하는 몇일 잘돌다 죽는 프로그램이 될 수 있다.

>동적할당은 프로그램 실행 중에 필요한 만큼의 메모리를 할당받는 것을 말합니다.
>동적할당을 사용하면 메모리의 효율적인 사용이 가능하며, 배열과 같이 미리 크기를 지정하지 않아도 되는 장점이 있습니다.

>동적할당은 malloc, calloc, realloc 함수를 이용하여 수행할 수 있으며, 할당받은 메모리는 반드시 free 함수를 이용하여 해제해야 합니다.
## 📄 코드 분석
```c
// 다음과 같은 코드가 오류가 나지 않게 수정하여 봅시다.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    arr = (int*)malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++){
        arr[i] = i;
    }

	//여기에 작성
    arr = (int*)realloc(arr,sizeof(int)*10);

	for(int i = 5; i < 10; i++){
        arr[i] = i;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}
//>> 0 1 2 3 4 5 6 7 8 9
```
```c
// 아래의 코드를 개선하여 봅시다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int age;
}Student;

int main() {
    Student *s;
    s = (Student*)malloc(sizeof(Student));

    strcpy(s->name, "Nogony");
    s->age = 20;

    printf("Name: %s, Age: %d\n", s->name, s->age);
    free(s);

    return 0;
}
```
```c
// 동적할당을 이용하여 이중 포인터를 활용한 2차원 배열 구현 한 모습입니다.
// 아래의 코드에서 오류가 나는 이유를 찾아 수정하여 봅시다.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;
    int row = 3;
    int col = 4;

    arr = (int**)malloc(sizeof(int*) * row);
    
    // 오류! 각 행에 대해서도 동적할당을 해줘야한다.!! 
    for (int i=0; i<row ; i++){
        arr[i] = (int*)malloc(sizeof(int)*col);
    }


    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = i * col + j;
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}

```
## 🔥 Challenge !!
1. **1번째 예시에서 동적할당 받은 배열의 크기를 늘려보기 (realloc 함수 사용)**
2. **2번째 예시에서 typdef를 이용하여 코드 개선하기**
3. **3번째 예시에서 오류가 나는 이유를 찾아 수정해보기**