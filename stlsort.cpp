#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int N;
    vector<int> q;
    
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        q.push_back(temp);
    }
    sort(q.begin(), q.end());
    
    for(int i=0; i<N; i++)
    {
        cout << q[i] << '\n';
    }
    
    return 0;
}