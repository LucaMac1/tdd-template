#include "foo.hpp"

int foo::fooInt(const std::string &str)
{
    return str.size();
}

void foo::fooStr(std::string& str){
    str = "Hello, Everybody";
    return;
}

void foo::fooThrow(){
    // throw runtime error
    return;
}

void foo::callbackMethod(const std::function<void(void)>& callback){
    callback();
    return;
}