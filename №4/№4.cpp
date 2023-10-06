#include <iostream> 
using namespace std;

void next_permut(char a[], int n)
{
    int indI = -1, indJ;
    int temp, min;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            indI = i - 1;
            break;
        }
    }
    if (indI != -1)
    {
        for (int i = n - 1; i > indI; i--)
        {
            if (a[i] > a[indI])
            {
                indJ = i;
                break;
            }
        }
        temp = a[indI];
        a[indI] = a[indJ];
        a[indJ] = temp;
        for (int i = 0; i < (n - 1 - indI) / 2; i++)
        {
            temp = a[indI + i + 1];
            a[indI + i + 1] = a[n - i - 1];
            a[n - i - 1] = temp;
        }
    }
    else
    {
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[min])
                    min = j;
            }
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    char* a = new char[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    next_permut(a, N);
    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
}