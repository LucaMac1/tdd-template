#pragma once

#include <gmock/gmock.h>
#include "Ifoo.hpp"

/*You don't necessarily have to extend an interface when you
mock, but in this case we are doing so.*/

class MockFoo : public Ifoo
{
public:
    MOCK_METHOD(int, fooInt, (const std::string&), (override));
    MOCK_METHOD(void, fooStr, (std::string&), (override));
    MOCK_METHOD(void, fooThrow,(), (override));
    MOCK_METHOD(void, callbackMethod,(const std::function<void(void)>&), (override));
};