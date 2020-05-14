# Algorithm 1st Week: Sorting
알고리즘 스터디 첫번째 주: 정렬

## In this README
I will write
  + How to use STL  ```sort```
  + Quick Sort: Base of STL ```sort```
  + Merge Sort: Base of STL ```stable_sort```
  + Counting Sort: 범위가 정해져 있는 수의 최적 정렬 방식
  + Function Object를 이용하는 내림차순 정렬
  + Operation Overloading을 이용한 내림차순 정렬

## How to use STL ```sort```
우선 ```algorithm``` header을 include를 해야 하고 sort 함수 내에서 정렬의 시작 범위와 끝 범위를 지정해줘야 한다.   
```sort(정렬 시작 범위, 정렬 끝 범위);```

vector(변수명 vec으로 설정함)의 시작부터 끝까지 정렬할 때는 다음과 같이 사용   
```sort(vec.begin(), vec.end());```   

더 자세한 정보는   
http://www.cplusplus.com/reference/algorithm/sort/   
로 들어가서 

