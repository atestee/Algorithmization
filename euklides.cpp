#include <iostream>
#include <stdio.h>
#include <tuple>

// Euklidean algorithm
// source: Průvodce světem algoritmů --> http://pruvodce.ucw.cz/static/pruvodce.pdf

// Lemma G:
// gcd(x, x) = x
// gcd(x, y) = gcd(y, x)
// gcd(x, y) = gcd(x-y, y) for x > y

int subtraction_euklides(int x, int y) {
    int a = x;
    int b = y;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int euklides(int x, int y) {
    int a = x;
    int b = y;
    int c;
    while(true) {
        if (a < b) {
            c = a;
            a = b;
            b = c;
        }
        if (b == 0) {
            return a;
        }
        a = a % b;
    }
}

// Extended euclidean algorithm for calculating Bezout's coefficients
// Bezout's coefficients: gcd(x, y) = a * x + b * y

// source: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
std::tuple<int, int, int> extended_euklid(int x, int y) {
    int r0 = x;
    int r1 = y;
    int s0 = 1;
    int s1 = 0;
    int t0 = 0;
    int t1 = 1;
    int temp;
    int q;

    while(true) {
        if (r0 < r1) {
            temp = r0;
            r0 = r1;
            r1 = temp;
        }
        if(r1 == 0) {
            return std::make_tuple(r0, s0, t0);
        }
        q = int(r0 / r1);

        temp = r1;
        r1 = r0 - q * r1;
        r0 = temp;

        temp  = s1;
        s1 = s0 - q * s1;
        s0 = temp;

        temp = t1;
        t1 = t0 - q * t1;
        t0 = temp;
    }
}

int main() {
    int x = 81201;
    int y = 56660;

    int res = euklides(x, y);

    auto res2 = extended_euklid(x, y);

    std::cout << "gcd(" << x << ", " << y << ") = " << res << '\n';

    std::cout << "gcd(" << x << ", " << y << ") = " << std::get<1>(res2) << " * " << x << " + " << std::get<2>(res2) << " * " <<  y << '\n';
}