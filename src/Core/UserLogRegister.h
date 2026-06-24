#pragma once

#include "IPersistable.h"

class UserLogRegister : public IPersistable
{
private:
    std::string m_DateTime;
    std::string m_UserName;

public:
    UserLogRegister() = default;
    UserLogRegister(const std::string& userName);

    std::string ToLine(const std::string& separator = "#//#") const override;
    void FromLine(std::string line, const std::string& separator = "#//#") override;
    inline std::string GetKey() const override { return m_DateTime; }
    bool IsEmpty() const override { return m_UserName.empty(); }

    inline std::string GetDateTime() const { return m_DateTime; }
    inline std::string GetUserName() const { return m_UserName; }
};