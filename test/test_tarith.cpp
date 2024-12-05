#include "tarith.h"

#include <gtest.h>

TEST(Calculator, test_numbers) 
{

	Calculator yr("235");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(Calculator, test_numbers_not_sort)
{

	Calculator yr("230");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(Calculator, test_numbers_with_operation)
{

	Calculator yr("230+2");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(Calculator, test_numbers_with_operation_different_numbers)
{

	Calculator yr("230+993");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(Calculator, test_numbers_with_operation_few_actions)
{

	Calculator yr("230+993*12");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(Stack, test_stack_filling)
{

	Calculator yr("230+993*12");
	yr.stackFilling();
	std::cout << yr << std::endl;

	ASSERT_NO_THROW(yr.print_stack());
}

TEST(calculator, test_culculation)
{

	Calculator yr("230+993*12");

	EXPECT_EQ(12146, yr.calculation());
}

TEST(calculator, test_many_operations)
{

	Calculator yr("2-56*2+4/2+45/9+5-2*6");

	EXPECT_EQ(-110, yr.calculation());
}