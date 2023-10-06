#include <iostream> 
using namespace std;

void permut_to_invtab(int a[], int b[], int n)
{
    int max = 0, imax = 0, kolvo = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            imax = i;
        }
    }
    for (int l = 0; l <= n; l++)
    {
        kolvo = 0;

        for (int j = imax; j >= 0; j--)
        {
            if (a[imax] < a[j])
            {
                kolvo++;
                b[n - l - 1] = kolvo;
            }
        }
        max--;
        for (int i = 0; i < n; i++)
            if (a[i] == max)
            {
                imax = i;
                break;
            }
    }
}


int main()
{
    int N;
    cin >> N;
    int* a = (int*)malloc(N * sizeof(int));
    int* b = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        b[i] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] > N)
        {
            cout << "Invalid value";
            break;
        }
    }
    permut_to_invtab(a, b, N);

    for (int i = 0; i < N; i++)
    {
        cout << b[i] << ' ';
    }