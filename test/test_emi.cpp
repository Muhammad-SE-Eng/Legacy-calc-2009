#include "gtest/gtest.h"
#include "Loan.h"
#include <stdexcept>

// Test 1: Total amount calculation
TEST(LoanTest, TotalAmount) {
    Loan loan(100000, 12, 10);
    EXPECT_EQ(loan.calculate_total_amount(), 220000);
}

// Test 2: Total interest calculation
TEST(LoanTest, TotalInterest) {
    Loan loan(100000, 12, 10);
    EXPECT_EQ(loan.calculate_total_interest(), 120000);
}

// Test 3: Monthly amount calculation
TEST(LoanTest, MonthlyAmount) {
    Loan loan(100000, 12, 10);
    EXPECT_NEAR(loan.calculate_monthly_amount(), 1833.33, 0.01);
}

// Test 4: Zero principal should throw invalid_argument
TEST(LoanTest, ZeroPrincipal) {
    EXPECT_THROW(Loan loan(0, 12, 10), std::invalid_argument);
}

// Test 5: Zero interest should throw invalid_argument
TEST(LoanTest, ZeroInterest) {
    EXPECT_THROW(Loan loan(120000, 0, 10), std::invalid_argument);
}

// Test 6: Negative interest should throw invalid_argument
TEST(LoanTest, NegativeInterest) {
    EXPECT_THROW(Loan loan(100000, -5, 10), std::invalid_argument);
}

// Test 7: Negative months should throw invalid_argument
TEST(LoanTest, NegativeYears) {
    EXPECT_THROW(Loan loan(100000, 12, -10), std::invalid_argument);
}

// Test 8: Large tenure / large principal test (check overflow)
TEST(LoanTest, LargeTenure) {
    EXPECT_NO_THROW({
        Loan loan(1e9, 5, 600); // 1 billion principal, 5% interest, 600 years
        double total = loan.calculate_total_amount();
        double monthly = loan.calculate_monthly_amount();
        EXPECT_GT(total, 0);
        EXPECT_GT(monthly, 0);
    });
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
