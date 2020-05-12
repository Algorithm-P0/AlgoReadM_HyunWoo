#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int sz[10000] = {0, };
    int N;
    
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        sz[temp-1]++;
    }
    for(int i=0; i<10000; i++){
        for(int j=0; j<sz[i]; j++){
            cout << i+1 << '\n';
        }
    }
}