# Algorithm 1st Week: Sorting
알고리즘 스터디 첫번째 주: 정렬

## In this README
I will write
  + How to use STL  ```sort```
  + Merge Sort: Base of STL ```stable_sort```   
  + Quick Sort: Base of STL ```sort```
  + Counting Sort: 범위가 정해져 있는 수의 최적 정렬 방식

## How to use STL ```sort```
우선 ```algorithm``` header을 include를 해야 하고 sort 함수 내에서 정렬의 시작 범위와 끝 범위를 지정해줘야 한다.   
```sort(정렬 시작 범위, 정렬 끝 범위);```

vector(변수명 vec으로 설정함)의 시작부터 끝까지 정렬할 때는 다음과 같이 사용   
```sort(vec.begin(), vec.end());```   

더 자세한 정보는   
http://www.cplusplus.com/reference/algorithm/sort/   
로 들어가서 확인 가능   

## Merge Sort: Basr of STL ```stable_sort```   
분할 정복(Divide and Conquer) 방법으로 설계한 가장 간단한 정렬 방법으로 다음과 같은 과정으로 정렬을 시킨다.
  1. 데이터 배열을 무수히 이분시킨다 (Divide)   
  2. 이분된 부분 배열 그룹끼리 병합(Merge)을 할 때 정렬을 수행한다 (Conquer)   
  3. 정렬된 모든 부분 배열을 합쳐 정렬된 전체 배열을 완성시킨다.   

이를 코드 상으로 표현하면

```
///Merge Sort Algorithm
//Conquer! (쪼개진 배열의 순서를 결정시켜줍니다)
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    //부분 배열 제작
    int L[n1], R[n2]; 
  
    //부분 배열 내의 원소 할당
    for (int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (int j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    
    //정렬된 원소를 다시 원래 배열에 삽입 => 정렬된 부분 배열 확보
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    int i = 0;
    int j = 0;
    int k = l; //부분 배열의 정렬 시작 부분
    while (i < n1 && j < n2) 
    { 
        /*
        이 과정만 수행해도 정렬이 보장되는 이유
        : 하부 부분 정렬이 이미 merge 과정에서 정렬이 되었기에
        순서대로 비교만 해도 정렬이 되는 것
        */
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    //위의 과정에서 j가 남았을 때(i가 부분 배열의 끝 인덱스까지 도달하지 못 했을 때)
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    //위의 과정에서 j가 남았을 때(j가 부분 배열의 끝 인덱스까지 도달하지 못 했을 때)
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    
}

///Divide It(배열을 무수히 쪼개줍니다)
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // 오버플로우 문제로 인해 m을 (l+r)/2로 표현하지 않음
        int m = l+(r-l)/2; 
  
        // 배열 앞 부분을 무수히 쪼개줍니다.
        mergeSort(arr, l, m); 
        // 배열 뒷 부분을 무수히 쪼개줍니다.
        mergeSort(arr, m+1, r); 
        //Conquer Process Call
        merge(arr, l, m, r); 
    } 
} 
```

Merge Sort는 C++ STL 내에 ```stable_sort```함수의 기저 알고리즘이다.
해당 알고리즘의 시간 복잡도는 모든 경우에서 O(nlogn) 이다. (Best/Average/Worst)

## Quick Sort: Base of STL ```sort``` 
피봇을 활용하는 Merge Sort

최우측 원소를 Pivot으로 하는 Quick Sort 알고리즘

```
int partition(int arr[], int l, int r)
{
  //피봇을 가장 오른쪽 원소로
  int pivot = arr[r];
  int i = l-1;
  for(int j = l; j <= r-1; j++)
  {
    if(arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  /*
 다음과 같은 과정을 반복하면
 i는 (pivot보다 작은 원소의 개수 - 1)의 인덱스를 가리키게 될 것이고
 arr[l]부터 arr[i]까지의 원소는 전부 pivot보다 크기가 작은 원소이다.
  */
  swap(&arr[i+1], &arr[r]);
  //이때 i+1번째 원소와 pivot의 위치를 바꾸게 된다면
  //pivot의 위치를 기준으로 왼쪽에는 pivot보다 작은 원소들이 오른쪽에는 큰 원소들이 위치할 수밖에 없다.
  return (i+1);
}

void quickSort(int arr[], int l, int r) //배열과 배열의 정렬 시작, 끝 인덱스를 입력 받음
{
  if(l < r)
  {
    //Conquer(여기는 정복 과정이 먼저 나오네?)
    int p = partition(arr, l, r);
    
    //Divide it(Merge Sort와 비슷하지 않나요?)
    //partition을 거치고 quickSort(Divide)과정을 거친다.
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
  }
}
```
C언어에서는 ```stdlib``` 헤더에 ```qsort```함수가 있는데 이는 Quick Sort를 구현하여 라이브러리에 저장시킨 함수이다.   

```
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
```

또한 C++ STL의 ```sort``` 함수는 이 Quick Sort를 STL 라이브러리에 구현시킨 함수이다.
최악의 경우에 대해서 O(n^2)이고 이외의 모든 경우에 대해서 O(nlogn)의 시간복잡도를 보인다.

## Counting Sort: 범위가 정해져 있는 수의 최적 정렬 방식
정렬 알고리즘을 처음 배울 때(당연히 자료구조 수업시간이겠지) 정렬의 최선 시간복잡도는 O(nlogn)이라 배웠는데  
시간복잡도가 O(n)인 정렬이 있다??!!

### 어떻게 이게 가능하지? No Swap, Just Contain It!
```
    int sz[10000] = {0, };
    int N;
    
    cin >> N;
    //수가 들어올 때마다 해당하는 index 내의 원소 수를 1씩 증가시킴
    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        sz[temp-1]++;
    }
    //최종결론: 각 수(index)가 얼마나 나와있는지 arr[index-1]만큼 저장되어있음
    for(int i=0; i<10000; i++){
        for(int j=0; j<sz[i]; j++){
            cout << i+1 << '\n';
        }
    }
```

## 함수 객체와 연산자 오버로딩을 이용한 정렬
은 스터디 시간에 이야기하는 걸로 합시다
