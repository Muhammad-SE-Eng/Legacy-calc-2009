#include "Loan.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


int main(){

   long double loan_amount,interest_rate;
   int number_of_years;

   ifstream config("config.txt");
   if(config.is_open()){
    config>>loan_amount;
    config>>interest_rate;
    config>>number_of_years;
    cout<<"Details got from config file!"<<endl;
    config.close();
   }
   else{
    cout<<"Enter the loan amount: ";
	cin>>loan_amount;
    if(loan_amount<=0){
        cout<<"Invalid loan amount. Amount must be positive and non-zero!"<<endl;
        return 1;
    }
	cout<<endl;

	cout<<"Enter the interest rate: ";
	cin>>interest_rate;
    if(interest_rate<=0){
        cout<<"Invalid interest rate. Must be positive!"<<endl;
        return 1;
    }
	cout<<endl;

	cout<<"The number of years: ";
	cin>>number_of_years;
    if(number_of_years<=0){
        cout<<"Invalid year. Year must be greater than zero!"<<endl;
        return 1;
    }
	cout<<endl;
}

    Loan loan(loan_amount,interest_rate,number_of_years);

    cout<<fixed<<setprecision(2);
    cout<<"Total amount to be paid: "<<loan.calculate_total_amount()<<endl;
    cout<<"Total interest rate: "<<loan.calculate_total_interest()<<endl;
    cout<<"Monthly amount to be paid: "<<loan.calculate_monthly_amount()<<endl;


    return  0;
}