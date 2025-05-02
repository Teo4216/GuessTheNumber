#pragma once
#include <vector>
#include <memory>
#include <string>
#include "regula_feedback.h"

class Joc {
private:
    std::vector<int> codSecret;
    std::unique_ptr<RegulaFeedback> regula;
    int nrIncercari;
    static const int lungimeCod = 4;
    static const int maxIncercari = 10;

    void genereazaCod();
    void citesteRegula();
    void joacaRunda();
    void valideazaIncercare(const std::vector<int>& incercare);
    void afiseazaScor() const;

public:
    Joc();
    void startJoc();
};