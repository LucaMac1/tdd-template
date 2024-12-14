#pragma once

#include <string>
#include <functional>

class Ifoo
{
public:
    virtual int fooInt(const std::string& str) = 0;
    virtual void fooStr(std::string& str) = 0;
    virtual void fooThrow() = 0;
    virtual void callbackMethod(const std::function<void(void)>& callback) = 0;
};