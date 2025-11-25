/**
 * @class Loan
 * @brief Represents a simple loan with principal, interest rate, and tenure.
 */
class Loan {
private:
    long double loan_amount;    /**< Principal loan amount */
    long double interest_rate;  /**< Annual interest rate in percent */
    int number_of_years;        /**< Loan tenure in years */

public:
    /**
     * @brief Construct a new Loan object
     * @param amount Principal amount (must be >0)
     * @param rate Interest rate in percent (must be >0)
     * @param years Loan tenure in years (must be >0)
     * @throws std::invalid_argument if any value is <= 0
     */
    Loan(long double amount, long double rate, int years);

    /**
     * @brief Calculate total amount to be paid (principal + interest)
     * @return long double Total loan amount
     */
    long double calculate_total_amount();

    /**
     * @brief Calculate total interest over the loan tenure
     * @return long double Total interest amount
     */
    long double calculate_total_interest();

    /**
     * @brief Calculate monthly EMI
     * @return long double Monthly installment
     */
    long double calculate_monthly_amount();
};
