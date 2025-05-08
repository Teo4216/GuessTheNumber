#pragma once
#include <string>

class Jucator {
private:
    std::string nume;
    int scor;
public:
    Jucator(const std::string& nume);

    void seteazaScor(int s);
    int getScor() const;
    const std::string& getNume() const;
};
