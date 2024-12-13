#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class example
{
public:
    int foo()
    {
        return 1;
    }
};

class testFixture : public testing::Test
{
public:
    testFixture()
    {
        std::cout << "Constructor is called" << std::endl;
        ex = new example();
    }

    ~testFixture()
    {
        std::cout << "Destuctor is called" << std::endl;
        delete ex;
        ex = nullptr;
    }

    void SetUp()
    {
        std::cout << "SetUp is called" << std::endl;
    }

    void TearDown()
    {
        std::cout << "TearDown is called" << std::endl;
    }

protected:
    example *ex;
};

TEST_F(testFixture, test1)
{
    ASSERT_EQ(1, ex->foo());
}

TEST_F(testFixture, test2)
{
    ASSERT_NE(0, ex->foo());
}

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }