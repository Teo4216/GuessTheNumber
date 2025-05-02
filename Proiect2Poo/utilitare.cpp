#include "utilitare.h"
#include <random>

std::vector<int> genereazaCodAleator(int lungime) {
    std::vector<int> cod;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);
    for (int i = 0; i < lungime; ++i) {
        cod.push_back(dis(gen));
    }
    return cod;
}
