#include "tarith.h"

#include <gtest.h>

// INT

TEST(calculator_int, test_numbers) 
{

	Calculator yr("235");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_int, test_numbers_not_sort)
{

	Calculator yr("230");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_int, test_numbers_with_operation)
{

	Calculator yr("230+2");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_int, test_numbers_with_operation_different_numbers)
{

	Calculator yr("230+993");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_int, test_numbers_with_operation_few_actions)
{

	Calculator yr("230+993*12");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(Stack_int, test_stack_filling)
{

	Calculator yr("230+993*12");
	yr.stackFilling();
	std::cout << yr << std::endl;

	ASSERT_NO_THROW(yr.print_stack());
}

TEST(calculator_int, test_culculation)
{

	Calculator yr("230+993*12");
	yr.stackFilling();
	yr.calculation();

	EXPECT_EQ(12146, std::stod(yr[0]));
}

TEST(calculator_int, test_culculation_2)
{

	Calculator yr("230+993*12-2");
	yr.stackFilling();
	yr.calculation();

	EXPECT_EQ(12144, std::stod(yr[0]));
}

TEST(calculator_int, test_many_operations)
{

	Calculator yr("2-56*2+4/2+45/9+5-2*6");
	yr.stackFilling();
	yr.calculation();

	EXPECT_EQ(-110, std::stod(yr[0]));
}

// FLOAT

TEST(calculator_float, test_numbers)
{

	Calculator yr("235.23");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_float, test_numbers_not_sort)
{

	Calculator yr("230.20");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_float, test_numbers_with_operation)
{

	Calculator yr("230.90+2.09");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_float, test_numbers_with_operation_different_numbers)
{

	Calculator yr("230.1+993.2");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(calculator_float, test_numbers_with_operation_few_actions)
{

	Calculator yr("230.2+993.1*12.11");

	ASSERT_NO_THROW(std::cout << yr);
}

TEST(Stack_float, test_stack_filling)
{

	Calculator yr("230.1+993.2*12.30");
	yr.stackFilling();
	std::cout << yr << std::endl;

	ASSERT_NO_THROW(yr.print_stack());
}

TEST(calculator_float, test_culculation)
{

	Calculator yr("230.0+993.1*12.20");
	yr.stackFilling();
	yr.calculation();

	EXPECT_EQ(12345.82, std::stod(yr[0]));
}

TEST(calculator_float, test_culculation_2)
{

	Calculator yr("230.1+993.1*12.23-2.0");
	yr.stackFilling();
	yr.calculation();

	EXPECT_EQ(12373.713, std::stod(yr[0]));
}

TEST(calculator_float, test_many_operations)
{

	Calculator yr("2.1-56.3*2.2+4.0/2.0+45.9/9.45+5.2-2.98*6.9+2.264857");
	yr.stackFilling();
	yr.calculation();

	EXPECT_EQ(-128, std::stod(yr[0]));
}

// add ()

TEST(calculator_skobki, test_many_operations)
{

	Calculator yr("2+3*(2+3)");
	yr.stackFilling();
	yr.calculation();

	EXPECT_EQ(17, std::stod(yr[0]));
}