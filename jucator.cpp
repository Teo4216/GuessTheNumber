#include "jucator.h"

Jucator::Jucator(const std::string& nume) : nume(nume), scor(0) {}

void Jucator::seteazaScor(int s) {
    scor = s;
}

int Jucator::getScor() const {
    return scor;
}

const std::string& Jucator::getNume() const {
    return nume;
}