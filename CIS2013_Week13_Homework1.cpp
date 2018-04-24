
#include <iostream>
#include <cstring>
using namespace std;
int number = 100;

class BankAccount {
	public:
		int balance;
		
		void deposit(int x){
			balance += x;
		}
		void withdraw(int y){
			balance -= y;
		}
		BankAccount(){
			string nm = "Anonymous";
			string ph = "555-555-5555";
			BankAccount(nm,ph);
		}
		BankAccount(string n, string p){
			rate = 5.0;
			name = n;
			phone = p;
			acct_numb = number++;
			balance = 0;
		}
		void print(){
			cout << "Account: " << acct_numb << endl;
			cout << "User: " << name << endl;
			cout << "Phone: " << phone << endl;
			cout << "Balance: " << balance << endl;
			cout << "Rate: " << rate << endl;
		}
		
	private:
		string name;
		string acct_numb;
		string phone;
		
		float rate;
};

class Savings: public BankAccount {
	public:
		Savings():BankAccount(){
			minimum_balance = 100;
			withdraw_limit = 100;
		}
		Savings(string n, string p):BankAccount(n,p){
			minimum_balance = 100;
			withdraw_limit = 100;
		}
		void withdraw(int y){
			if(y < withdraw_limit){
				// balance -= y;
				if(balance <minimum_balance){
					cout << "Warning: You are below your minimum balance." << endl;
				}
			} else {
				cout << "You are only allowed to withdraw " << withdraw_limit <<
					" from this account. Transaction terminated." << endl;
			}
		}
		
	private:
		int minimum_balance;
		int withdraw_limit;
};

class Checking : public BankAccount {
	public:
		
		Checking(string n, string p):BankAccount(n,p){
			overdraft_fee = 25;
		}
	private:
		int overdraft_fee;
};

int main(){
	// Now create menus...
	// string name, phone
	// Ask for name and ask for phone;
	// Create checking account type
	// string phone = "405-555-5656";
	// Savings chk_acct("Bob", phone);
	// Savings chk_acct2;
	
	// chk_acct.print();
	// chk_acct2.print();
	// Print balance
	// cout << "Your balance is " << chk_acct.balance << endl;
	// withdraws
	// chk_account.withdraw(200);
	
	char d, w, p, E; 
	char choice;
	int ans;
	string name, phone, accnt;
	
	cout << endl;
	cout << "			  *************************************************" << endl;
	cout << endl;
	cout << "					Welcome to our Bank! " << endl;
	cout << endl;
	cout << " What is your name and phone number for a new account? " << endl;
	cin >> name >> phone;
		
	cout << "You can open a new bank account.  "<< endl;
	
	
	
	do {
	cout << " " << endl;
	cout << "Would you like to open Saving or Checking account?" <<endl;
	cin >> accnt;
	cout << " " << endl;
	if (accnt == "Savings" || accnt == "savings") {
		Savings newS (name, phone);
		cout << "Savings account created. ";
		break;
	} else if (accnt == "Checking" || accnt == "checking") {
		Checking newC (name, phone);
		cout << "Checking account created. ";
		break;
	} else {
		cout << "Misspelled, try again ";
		cout << " " << endl;
	}
	}
	while (1);
	
	do {
	cout << " " << endl;
	cout << "Select an action with your account: " << endl;
	cout << " " << endl;
	cout << "Make a deposit (d) "<< endl;
	cout << "Withdraw money (w) " << endl;
	cout << "Print total balance (p) " << endl;
	cout << "Log out of the account (E) " << endl;
	
	cout << " " << endl;
	cout << "Your choice is : ";
	cin >> choice;
		switch (choice)
		{
		case 'd' :
			if (accnt== "Savings" || accnt== "savings") {
			newS.deposit ();
			} else if (accnt="Checking" || accnt== "checking") {
			newC.deposit ();
			}
		break;
		case 'w' :
			if (accnt=="Savings" || accnt== "savings") {
			newS.withdraw ();
			} else if (accnt="Checking" || accnt== "checking") {
			newC.withdraw ();
			}
		break;
		case 'p' :
			if (accnt=="Savings" || accnt== "savings") {
			newS.print ();
			} else if (accnt=="Checking" || accnt== "checking") {
			newC.print ();
			}
				break;
		case 'E' :
		exit (1);
		break;
				
		default : 
		cout << "Illegal value.";
		}
		
	}
	while (ans=1);
	
	return 0;
}