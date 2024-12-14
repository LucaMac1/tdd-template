#include "dummy.hpp"
#include <string>

int dummy::dummyInt(const std::string &str)
{
    return this->m_fooIf.fooInt(str);
} 

void dummy::dummyStr(std::string &str)
{
    this->m_fooIf.fooStr(str);
    return;
} 

void dummy::dummyThrow(){
    this->m_fooIf.fooThrow();
}
void dummy::dummyCallbackMethod(const std::function<void(void)>& callback){
    this->m_fooIf.callbackMethod(callback);
}