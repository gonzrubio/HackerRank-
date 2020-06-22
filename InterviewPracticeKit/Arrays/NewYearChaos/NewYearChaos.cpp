/*
Rules: Any person in the queue can bribe the person directly in front of them to swap positions.

ie.
In:
2
5
2 1 5 3 4
5
2 5 1 3 4

Out:
3
Too chaotic.
*/

#include <iostream>
#include <algorithm> // for swap
#include <vector>

void minimumBribes(std::vector<int> q)
{
        int ans = 0;
        for (int i = q.size() - 1; i >= 0; i--){
            if (ans == -1)
                break;
            int k = i;
            while (q[k] != i + 1)
                k--;
            if (i - k > 2){
                ans = -1;
                break;
            } else {
                while (k != i){
                    swap(q[k], q[k + 1]);
                    k++;
                    ans++;
                }
            }
        }
        if (ans == -1)
            puts("Too chaotic");
        else
            cout << ans << "\n";

}

int main()
{

    std::vector<int> que{1,2,5,3,7,8,6,4} ; // Final state of the line.

    minimumBribes(que) ;

    return 0 ;
}
