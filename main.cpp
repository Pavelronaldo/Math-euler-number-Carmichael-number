#include <iostream>

int euler(int n){ // returns maximum count of simple numbers lesser than n
    int ret = 1;
    for (int i = 2; i * i <= n; ++i)
    {
        int p = 1;
        while (n % i == 0)
        {
            p *= i;
            n /= i;
        }
        p /= i;
        if (p >= 1) ret *= (p * (i - 1));
    }
    return --n ? n * ret : ret;
}

int gcd(int a, int b) // returns greatest common divisor
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

bool is_prime(int n) { // check if number is prime
    if (n <= 1)
        return true;
    if (n == 2)
        return true;
    if (n%2==0)
        return false;
    for (int j = 3; j * j <= n; j+=2)
         if (n % j == 0) return false;

    return true;
}

int power(int x, int y, int mod) { // recursive function that returns special power using mod
    if (y == 0)
        return 1;
    int temp = power(x, y / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (y % 2 == 1)
        temp = (temp * x) % mod;
    return temp;
}

bool isCarmichaelNumber(int n) { // checks if given number is Charmichael number
    for (int b = 2; b < n; b++) {
        // If "b" is relatively prime to n
        if (gcd(b, n) == 1) {
  
            // And pow(b, n-1)%n is not 1,
            // return false.
            if (power(b, n - 1, n) != 1){
                return false;
            }
        }
    }
    return true;
}

void test_case(){
    std::cout << euler(37) << std::endl;
    std::cout << euler(1) << std::endl;
    std::cout << euler(2) << std::endl;
    std::cout << euler(3) << std::endl;
    if(isCarmichaelNumber(561) && !is_prime(561)) std::cout << "561 is Charmichael number" << std::endl;
    else std::cout << "Number is not Charmichael" << std::endl;
    if(isCarmichaelNumber(1105) && !is_prime(1105)) std::cout << "1105 is Charmichael number" << std::endl;
    else std::cout << "Number is not Charmichael" << std::endl;
    if(isCarmichaelNumber(2000) && !is_prime(2000)) std::cout << "2000 is Charmichael number" << std::endl;
    else std::cout << "Number is not Charmichael" << std::endl;
}


int main(int argc, char const *argv[])
{
    test_case();
    return 0;
}
