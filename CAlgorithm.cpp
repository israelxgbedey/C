#include <iostream>
#include <cmath>

// Function to get the Nth number of the Fibonacci Sequence
int getNthFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int prev = 0;
    int current = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

// Function to reverse an integer
int reverseInteger(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

// Function to get the largest prime factor of n
long long getLargestPrimeFactor(long long n) {
    long long largestPrime = -1;
    while (n % 2 == 0) {
        largestPrime = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestPrime = i;
            n /= i;
        }
    }

    if (n > 1) {
        largestPrime = n;
    }

    return largestPrime;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Get the Nth Fibonacci number" << std::endl;
        std::cout << "2. Reverse an integer" << std::endl;
        std::cout << "3. Get the largest prime factor of a number" << std::endl;
        std::cout << "4. Find the sum of all prime numbers below 1000" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            std::cout << "Enter the value of N: ";
            std::cin >> n;
            int result = getNthFibonacci(n);
            std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
            break;
        }
        case 2: {
            int num;
            std::cout << "Enter an integer: ";
            std::cin >> num;
            int reversedNum = reverseInteger(num);
            std::cout << "Reversed integer: " << reversedNum << std::endl;
            break;
        }
        case 3: {
            long long num;
            std::cout << "Enter a number: ";
            std::cin >> num;
            long long largestPrimeFactor = getLargestPrimeFactor(num);
            std::cout << "The largest prime factor of " << num << " is: " << largestPrimeFactor << std::endl;
            break;
        }
        case 4: {
            int sum = 0;
            for (int i = 2; i < 1000; i++) {
                if (isPrime(i)) {
                    sum += i;
                }
            }
            std::cout << "The sum of all prime numbers below 1000 is: " << sum << std::endl;
            break;
        }
        case 5: {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
        }
    } while (choice != 5);

    return 0;
}
