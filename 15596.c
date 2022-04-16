long long sum(int *a, int n)
{
    long long i, sum=0;
    
    for(i=0; i<n; i++)
        sum += a[i];
    
    return sum;
}