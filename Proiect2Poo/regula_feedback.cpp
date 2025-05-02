#include "regula_feedback.h"
#include <sstream>

std::string RegulaUsor::feedback(const std::vector<int>& cod, const std::vector<int>& incercare) const {
    int corecte = 0, pozGresita = 0;
    std::vector<bool> vizCod(cod.size(), false), vizInc(incercare.size(), false);

    for (size_t i = 0; i < cod.size(); ++i) {
        if (cod[i] == incercare[i]) {
            corecte++;
            vizCod[i] = vizInc[i] = true;
        }
    }
    for (size_t i = 0; i < cod.size(); ++i) {
        if (!vizCod[i]) {
            for (size_t j = 0; j < incercare.size(); ++j) {
                if (!vizInc[j] && cod[i] == incercare[j]) {
                    pozGresita++;
                    vizInc[j] = true;
                    break;
                }
            }
        }
    }
    std::ostringstream out;
    out << "Cifre corecte pe pozitii corecte: " << corecte
        << ", Cifre corecte pe pozitii gresite: " << pozGresita;
    return out.str();
}

std::unique_ptr<RegulaFeedback> RegulaUsor::clone() const { return std::make_unique<RegulaUsor>(*this); }

std::string RegulaMediu::feedback(const std::vector<int>& cod, const std::vector<int>& incercare) const {
    int corecte = 0;
    for (size_t i = 0; i < cod.size(); ++i)
        if (cod[i] == incercare[i]) corecte++;
    return "Cifre corecte pe pozitii corecte: " + std::to_string(corecte);
}

std::unique_ptr<RegulaFeedback> RegulaMediu::clone() const { return std::make_unique<RegulaMediu>(*this); }

std::string RegulaGreu::feedback(const std::vector<int>&, const std::vector<int>&) const {
    return "Feedback indisponibil la dificultate Greu.";
}

std::unique_ptr<RegulaFeedback> RegulaGreu::clone() const { return std::make_unique<RegulaGreu>(*this); }
