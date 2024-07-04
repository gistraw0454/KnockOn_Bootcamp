#!/bin/bash

echo "셸 스크립트 작성해보았어요 !"
read name #사용자로부터 입력 받음
echo "$name님 오늘은 $(date +%A)입니다."

#----------------------------------------------------
age = 20
if [$age -ge 18]; then	# -ge는 비교연산자 크거나같다 -eq는 같다 -lt 작다
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
