#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class SavingsAccount
{
public:
    
    SavingsAccount(int acc, int dol, int cent);
    SavingsAccount();
    
    void Deposit(int dol, int cent,int i);
    void Withdrawal(int dol, int cent,int i);
    void ShowBalance(int i) const;
    void savedetails(int acc,int i) const;
private:
    int dollars;
    int cents;
    int accountnumber;
    float balance;
    float balancelist[4];
};

int main()
{
    
    
    int accr[4] = { 1223321,1223322,1223323,1223324 };
    int accnum;   ///user input account number
    int index;   ///I will use this to find the index of the account number 
                ///we can use the index to find the balance cause it will use serially.


    
    //Creating Objects
    SavingsAccount accountDetails[4]={SavingsAccount(accr[0],100,50),SavingsAccount(accr[1],100,50), 
        SavingsAccount(accr[2],100,50), SavingsAccount(accr[3],100,50)};
   
    
    //setting the intial balance to 100 dollars and 50 cents
    
    cout << "Enter the Account Number: ";
    cin >> accnum;       ///Taking the account number from user
    index = 0;
    while (index < 4) {
        if (accr[index] == accnum) {
            break;                          // find the index from acc[4] array
        }
        index++;               //As the index of acc[4] and object array[4] is maintained as same we can use it
    }
    cout << "Do you want to deposit?(Y/N)";   //it will ask the user to enter the option.
    string option;
    cin >> option;
    int dollaropt;
    int centopt;
    if (option == "Y") {
        cout << "How Much money you want to deposit?" << endl; //Giving the user to deposit
        cout << "Dollars: ";
        cin >> dollaropt;
        cout << "Cents: ";
        cin >> centopt;
        accountDetails[index].Deposit(dollaropt, centopt, index);
        accountDetails[index].ShowBalance(index);
        cout << endl;
        cout << "Do you want to withdraw?(Y/N): ";       // Automatically goes to withdraw option
        cin >> option;
        if (option == "Y") {
            cout << "How Much money you want to Withdraw? " << endl;
            cout << "Dollars: ";
            cin >> dollaropt;
            cout << "Cents: ";
            cin >> centopt;
            accountDetails[index].Withdrawal(dollaropt, centopt, index);
            accountDetails[index].ShowBalance(index);
        }
    }
    else {
        cout << "Do you want to withdraw?(Y/N): ";          //if the intial option choice is N it will go to withdrawal option.
        cin >> option;
        if (option == "Y") {
            cout << "How Much money you want to Withdraw? " << endl;
            cout << "Dollars: ";
            cin >> dollaropt;
            cout << "Cents: ";
            cin >> centopt;
            accountDetails[index].Withdrawal(dollaropt, centopt, index);
            accountDetails[index].ShowBalance(index);
        }
    }
    
   
    cout << "Do you need receipt?(Y/N): ";      //Asking if the user wants to get a receipt.
    cin >> option;
    if (option == "Y") {
        accountDetails[index].savedetails(accr[index], index);
    }
    else {
        exit(5);
    }
    


    return 0;
}

SavingsAccount::SavingsAccount(int acc, int dol, int cent )
{
    accountnumber = acc;
    dollars = dol + cent / 100;
    cents = cent % 100;
}

SavingsAccount::SavingsAccount()
{
    accountnumber = 0;
    dollars = 0;
    cents = 0;
}

void SavingsAccount::Deposit(int dol, int cent,int i)
{
    
    dollars = dollars + dol + cent / 100;
    cents = cents + cent % 100;
    balance = dollars + cents / 100;
    balancelist[i] = balance;

}

void SavingsAccount::Withdrawal(int dol, int cent,int i)
{
    dollars = dollars - dol;

    if (cents < cent)
    {
        dollars = dollars - 1;
        cents = abs(100 + cents - cent);
    }
    else
        cents = cents - cent;

    // normalize
    dollars = dollars + cents / 100;
    cents = cents % 100;
    balance = dollars + cents / 100;
    balancelist[i] = balance;
}

void SavingsAccount::ShowBalance(int i) const
{
    cout << "Account Balance:"  << dollars <<" Dollars and " <<cents<< " Cents " << endl;
    
}
//saving the the bank details in txt file
void SavingsAccount::savedetails(int acc,int i) const {
    string text ="Account Number:"+ to_string(acc) + "  Balance:   " 
        + to_string(balancelist[i]) + " Dollars and "
        + to_string(cents)+ " cents";                   //converting everything into a string
    ofstream file;
    file.open("Bank-file.txt");  // open a txt file 
    file << text;                               
    file.close();

}