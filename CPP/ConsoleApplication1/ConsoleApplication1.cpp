#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
   
    int n;
    cin >> n;
    n += 2;
    int** arr = new int* [n];

    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            if (i > 0 && i < n - 1 && j > 0 && j < n - 1) {
                cin >> arr[i][j];
            }
            else {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    stack<int> y;
    stack<int> x;
    y.push(1);
    x.push(1);

    while (y.top() != n - 2 || x.top() != n - 2)
    {
        if (y.top() == n - 2 && x.top() == n - 2)
            break;

        if (arr[y.top()][x.top() + 1] == 0)
        {
            arr[y.top()][x.top() + 1] = 1;
            y.push(y.top());
            x.push(x.top() + 1);
        }

        else if (arr[y.top() + 1][x.top()] == 0)
        {
            arr[y.top() + 1][x.top()] = 1;
            y.push(y.top() + 1);
            x.push(x.top());


        }

        else if (arr[y.top()][x.top() - 1] == 0)
        {
            arr[y.top()][x.top() - 1] = 1;
            y.push(y.top());
            x.push(x.top() - 1);



        }
        else if (arr[y.top() - 1][x.top()] == 0)
        {
            arr[y.top() - 1][x.top()] = 1;
            y.push(y.top() - 1);
            x.push(x.top());


        }
        else if (y.top() == 1 && x.top() == 1)
        {
            break;
        }
        else
        {
            y.pop();
            x.pop();
        }
    }

    if (y.top() == 1)
    {
        cout << "no path" << endl;
    }
    else
    {
        cout << "ok" << endl;
    }

    while (y.size() != 0)
    {
        cout << y.top() - 1<< x.top()-1 << " " << endl;
        y.pop();
        x.pop();
    }


    
     
    // 释放内存
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}