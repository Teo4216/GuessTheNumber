#pragma once
#include <vector>
#include <string>
#include <memory>

class RegulaFeedback {
public:
    virtual std::string feedback(const std::vector<int>& cod, const std::vector<int>& incercare) const = 0;
    virtual std::unique_ptr<RegulaFeedback> clone() const = 0;
    virtual ~RegulaFeedback() = default;
};

class RegulaUsor : public RegulaFeedback {
public:
    std::string feedback(const std::vector<int>& cod, const std::vector<int>& incercare) const override;
    std::unique_ptr<RegulaFeedback> clone() const override;
};

class RegulaMediu : public RegulaFeedback {
public:
    std::string feedback(const std::vector<int>& cod, const std::vector<int>& incercare) const override;
    std::unique_ptr<RegulaFeedback> clone() const override;
};

class RegulaGreu : public RegulaFeedback {
public:
    std::string feedback(const std::vector<int>& cod, const std::vector<int>& incercare) const override;
    std::unique_ptr<RegulaFeedback> clone() const override;
};
