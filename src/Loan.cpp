#include "Loan.h"
#include <stdexcept>

Loan::Loan(long double amount,long double rate,int years){

     if (amount <= 0 || rate <= 0 || years <= 0){
        throw std::invalid_argument("Values must be positive.");
     }
        loan_amount=amount;
        interest_rate=rate;
        number_of_years=years;
    }

long double Loan::calculate_total_amount(){
        return loan_amount+calculate_total_interest();

    }

long double Loan::calculate_total_interest(){
    return loan_amount*interest_rate*number_of_years/100.0;
}

long double Loan::calculate_monthly_amount(){
    return calculate_total_amount()/(number_of_years*12);

}
