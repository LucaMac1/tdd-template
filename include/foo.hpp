#pragma once

#include "Ifoo.hpp"

class foo : public Ifoo
{
public:
    int fooInt(const std::string &std);
    void fooStr(std::string &str);
    void fooThrow();
    void callbackMethod(const std::function<void(void)>& callback);
};