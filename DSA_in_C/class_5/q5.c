// Question 6: Find the complexity of the following code which tests whether a given number is prime or not?

int isPrime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
