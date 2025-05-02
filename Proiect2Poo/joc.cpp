#include "joc.h"
#include <iostream>
#include <random>
#include <ctime>

#include "regula_feedback.h"

Joc::Joc() : nrIncercari(0) {}

void Joc::genereazaCod() {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> dis(0, 9);

    codSecret.clear();
    for (int i = 0; i < lungimeCod; ++i)
        codSecret.push_back(dis(gen));
}

void Joc::citesteRegula() {
    std::cout << "Alege dificultatea (1 - Usor, 2 - Mediu, 3 - Greu): ";
    int optiune;
    std::cin >> optiune;

    switch (optiune) {
        case 1:
            regula = std::make_unique<RegulaUsor>();
            break;
        case 2:
            regula = std::make_unique<RegulaMediu>();
            break;
        case 3:
            regula = std::make_unique<RegulaGreu>();
            break;
        default:
            std::cout << "Optiune invalida. Se foloseste dificultatea implicita (Usor).\n";
            regula = std::make_unique<RegulaUsor>();
            break;
    }
}

void Joc::valideazaIncercare(const std::vector<int>& incercare) {
    if (incercare.size() != lungimeCod)
        throw std::runtime_error("Numar invalid de cifre.");
    for (int cifra : incercare)
        if (cifra < 0 || cifra > 9)
            throw std::runtime_error("Cifrele trebuie sa fie intre 0 si 9.");
}

void Joc::joacaRunda() {
    while (nrIncercari < maxIncercari) {
        std::vector<int> incercare;
        std::cout << "Introdu " << lungimeCod << " cifre (fara spatii): ";
        std::string input;
        std::cin >> input;

        incercare.clear();
        for (char c : input) {
            if (isdigit(c))
                incercare.push_back(c - '0');
        }

        try {
            valideazaIncercare(incercare);
        } catch (const std::exception& e) {
            std::cerr << "Eroare: " << e.what() << std::endl;
            continue;
        }

        nrIncercari++;
        std::string feedback = regula->feedback(codSecret, incercare);
        std::cout << feedback << std::endl;

        if (codSecret == incercare) {
            std::cout << "Ai ghicit codul secret in " << nrIncercari << " incercari!" << std::endl;
            afiseazaScor();
            return;
        }
    }

    std::cout << "Ai epuizat toate incercarile. Codul era: ";
    for (int cifra : codSecret)
        std::cout << cifra;
    std::cout << std::endl;
}

void Joc::afiseazaScor() const {
    int scor = std::max(1, 11 - nrIncercari);
    std::cout << "Scorul tau este: " << scor << " / 10" << std::endl;
}

void Joc::startJoc() {
    std::cout << "Jocul a început!" << std::endl;
    citesteRegula();
    genereazaCod();
    joacaRunda();
    std::cout << "Jocul s-a terminat!" << std::endl;
}