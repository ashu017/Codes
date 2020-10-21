int N = 1000002;
int ar[1000002];
void sieve()
{
    for(int i=1;i<=N;i++)
        ar[i] = 1;
    ar[0] = 0;
    for(int i=2;i*i<=N;i++)
    {
        if(ar[i] && i*i<=N)
        {
            for(int j = i*i; j<=N;j+=i)
                ar[j] = 0;
        }
    }
}
