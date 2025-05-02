#pragma once
#include <exception>
#include <string>

class ExceptieJoc : public std::exception {
protected:
    std::string mesaj;
public:
    explicit ExceptieJoc(std::string msg) : mesaj(std::move(msg)) {}
    const char* what() const noexcept override { return mesaj.c_str(); }
};

class ExceptieInputInvalid : public ExceptieJoc {
public:
    using ExceptieJoc::ExceptieJoc;
};

class ExceptieCodGresit : public ExceptieJoc {
public:
    using ExceptieJoc::ExceptieJoc;
};

class ExceptieMaxIncercari : public ExceptieJoc {
public:
    using ExceptieJoc::ExceptieJoc;
};
