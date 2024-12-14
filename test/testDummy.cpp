#include <iostream>
#include <gtest/gtest.h>
#include "dummy.hpp"
#include "MockFoo.hpp"
#include <memory>

class testFixtureDummy : public testing::Test
{
public:
    testFixtureDummy() {};
    ~testFixtureDummy() {};

protected:
    void SetUp()
    {
        // std::cout << "SetUp is called" << std::endl;
        /*We don't want to test foo class here. That's why we need mock*/
        m_DummyPtr = std::make_unique<dummy>(mockFoo);
    }

    void TearDown()
    {
        // std::cout << "TearDown is called" << std::endl;
    }

    MockFoo mockFoo;
    std::unique_ptr<dummy> m_DummyPtr;
};

TEST_F(testFixtureDummy, dummyInt)
{
    std::string exampleStr{"test"};
    EXPECT_CALL(mockFoo, fooInt(exampleStr)).Times(1).WillOnce(testing::Return(exampleStr.size()));
    // EXPECT_CALL(mockFoo,fooInt(testing::_)).Times(1).WillOnce(testing::Return(exampleStr.size()));
    auto result = m_DummyPtr->dummyInt(exampleStr);
    ASSERT_EQ(result, exampleStr.size());
}

TEST_F(testFixtureDummy, dummyInt2)
{
    std::string exampleStr{"test"};
    EXPECT_CALL(mockFoo, fooInt(exampleStr)).Times(1).WillOnce(testing::Return(12));
    auto result = m_DummyPtr->dummyInt(exampleStr);
    ASSERT_NE(result, exampleStr.size());
}

TEST_F(testFixtureDummy, dummyStr)
{
    std::string inputStr{""};
    std::string resultStr{"Hello, Everybody"};
    // this is the way to return from arguments passed by reference
    EXPECT_CALL(mockFoo, fooStr(inputStr)).WillOnce(testing::SetArgReferee<0>(inputStr));
    m_DummyPtr->dummyStr(inputStr);
    ASSERT_NE(resultStr, inputStr);
}

// ACTION(throwError){
//     throw std::runtime_error("Error Test");
// }


// TEST_F(testFixtureDummy, throwTest)
// { 
//     // throwError() is the action
//     EXPECT_CALL(mockFoo, fooThrow()).WillOnce(throwError());
//     ASSERT_THROW(m_DummyPtr->dummyThrow(), std::runtime_error);
// }

void throwFunction(){
    std::cout << "ERROR!\n";
    throw std::runtime_error("ERROR TEST");
}

TEST_F(testFixtureDummy, throwTest)
{ 
    EXPECT_CALL(mockFoo, fooThrow()).WillOnce(testing::Invoke(throwFunction));
    ASSERT_THROW(m_DummyPtr->dummyThrow(), std::runtime_error);
}

TEST_F(testFixtureDummy, testCallback)
{
    testing::MockFunction<void(void)> testFunc;

    // we can't pass testFunc here, because callbackMethod is expecting an
    // std function. 
    EXPECT_CALL(mockFoo, callbackMethod(testing::_)).Times(1).
    WillOnce(testing::InvokeArgument<0>());
    EXPECT_CALL(testFunc, Call());

    m_DummyPtr->dummyCallbackMethod(testFunc.AsStdFunction());

}