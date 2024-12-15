#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <chrono>
#include <cmath>

using namespace std;

/**
 * @brief Funkcja matematyczna, ktora bedziemy calkowac.
 *
 * Funkcja f(x) = 4 / (1 + x^2), ktorej calka na przedziale [0, 1]
 * daje przyblizenie liczby PI.
 *
 * @param x Wartosc zmiennej niezaleznej.
 * @return double Wynik funkcji dla danego x.
 */
double funkcja(double x) {
    return 4.0 / (1.0 + x * x);
}

int main()
{
    
}

