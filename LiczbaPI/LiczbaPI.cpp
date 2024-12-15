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

/**
 * @brief Oblicza wartosc calki dla podanego przedzialu metoda trapezow.
 *
 * @param poczatek Poczatek przedzialu calkowania.
 * @param koniec Koniec przedzialu calkowania.
 * @param kroki Liczba krokow podzialu przedzialu.
 * @return double Wynik calki na przedziale [poczatek, koniec].
 */
double calkaFragment(double poczatek, double koniec, int kroki) {
    double krokRozmiar = (koniec - poczatek) / kroki;
    double wynik = 0.0;

    for (int i = 0; i < kroki; ++i) {
        double x1 = poczatek + i * krokRozmiar;
        double x2 = x1 + krokRozmiar;
        wynik += 0.5 * (funkcja(x1) + funkcja(x2)) * krokRozmiar;
    }

    return wynik;
}


/**
 * @brief Oblicza wartosc calki oznaczonej z wykorzystaniem wielowatkowosci.
 *
 * Dzielenie obliczen na fragmenty przy uzyciu watkow.
 *
 * @param poczatek Poczatek przedzialu calkowania.
 * @param koniec Koniec przedzialu calkowania.
 * @param kroki Laczna liczba krokow podzialu przedzialu.
 * @param liczbaWatkow Liczba watkow do zrownoleglenia obliczen.
 * @return double Wynik calki dla calego przedzialu [poczatek, koniec].
 */
double calkaRownolegla(double poczatek, double koniec, int kroki, int liczbaWatkow) {
    vector<thread> watki;          ///< Wektor przechowujacy watki.
    vector<double> wyniki(liczbaWatkow, 0.0); ///< Wektor wynikow z kazdego watku.

    double szerokoscSegmentu = (koniec - poczatek) / liczbaWatkow;
    int krokiNaWatek = kroki / liczbaWatkow;

    for (int i = 0; i < liczbaWatkow; ++i) {
        double startWatek = poczatek + i * szerokoscSegmentu;
        double koniecWatek = startWatek + szerokoscSegmentu;

        watki.emplace_back([&, i, startWatek, koniecWatek]() {
            wyniki[i] = calkaFragment(startWatek, koniecWatek, krokiNaWatek);
            });
    }

    for (auto& watek : watki) {
        watek.join(); ///< Czekamy na zakonczenie wszystkich watkow.
    }

    double wynikCalkowity = 0.0;
    for (double czesc : wyniki) {
        wynikCalkowity += czesc;
    }

    return wynikCalkowity;
}

int main()
{
    
}

