#pragma once

#include <string>
#include <Ifoo.hpp>
class dummy
{
public:
    // Inject foo object
    dummy(Ifoo &f) : m_fooIf(f) {}

    int dummyInt(const std::string &str);
    void dummyStr(std::string& str);
    void dummyThrow();
    void dummyCallbackMethod(const std::function<void(void)>& callback);

private:
    Ifoo &m_fooIf;
};