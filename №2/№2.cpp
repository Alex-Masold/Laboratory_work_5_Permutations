#include <iostream> 
using namespace std;

int invtab_to_permut(int b[], int a[], int n)
{
    bool flag;
    int kolvo, count = 0;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        count++;
        kolvo = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == 0)
            {
                kolvo++;
            }

            if (kolvo - 1 == b[i])
            {
                a[j] = count;
                flag = true;
                break;
            }

        }
        if (!flag)
            return 0;
    }
    return 1;
}

int main()
{
    int N;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];
    for (int i = 0; i < N; i++)
        a[i] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    if (invtab_to_permut(b, a, N))
    {
        for (int i = 0; i < N; i++)
        {
            cout << a[i] << ' ';
        }
    }
    else cout << "NO";
}