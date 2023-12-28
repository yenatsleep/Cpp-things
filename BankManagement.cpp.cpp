#include <iostream>
#include <vector>

using namespace std;

//define
class BankAccount{
	private:
		string name;
		int accountNum;
		double balance;
	public:
		BankAccount(string n, int ac,double bal){
			name = n;
			accountNum = ac;
			balance = bal;
	}
		string getName(){
			return name;
	}
		int getAccountNum(){
			return accountNum;
	}
		double getBalance(){
			return balance;
	}
		void deposit(double amount){
			balance = balance + amount;
	}	
		void withdraw(double amount){
			if(balance >= amount){
				balance = balance - amount;
				cout<<"\t\tWithdraw Successfully"<<endl;
			}else{
				cout<<"\t\tInsufficient Balance"<<endl;
		}
	}	
};
class BankManagement{
	private:
		vector<BankAccount> accounts;
	public:
		void AddAccount(string name,int accountNum,double balance){
			accounts.push_back(BankAccount(name,accountNum,balance));
		}
		void showAllAccounts(){
			cout<<"\t\t All Account Holders"<<endl;
			for(int i = 0; i<accounts.size();i++){
				cout<<"Name: "<<accounts[i].getName()<<"Account Number: "<<accounts[i].getAccountNum()<<
				"Balance: "<<accounts[i].getBalance()<<endl;
			}
		}
		void searchAccount(int account){
			cout<<"\t\t Account Holder"<<endl;
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNum()==account){
				cout<<"Name: "<<accounts[i].getName()<<"Account Number: "<<accounts[i].getAccountNum()<<
				"Balance: "<<accounts[i].getBalance()<<endl;	
			}
		}
	}
		BankAccount* findAccount(int accountNum){
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNum()==accountNum){
					return &accounts[i];
			}
		}
    }
};
int main(){
	
	BankManagement bank;
	int choice;
	char op;
	do{
		cout<<"\t\t Bank Management System"<<endl; //\t\t keep the line align
		cout<<"\t\t\tMain Menu"<<endl;
		cout<<"\t\t 1. Creat New Account"<<endl;
		cout<<"\t\t 2. Show All Account"<<endl;
		cout<<"\t\t 3. Search Account"<<endl;
		cout<<"\t\t 4. Deposit Money"<<endl;
		cout<<"\t\t 5. Withdraw Money"<<endl;
		cout<<"\t\t 6. Exit"<<endl;
		cout<<"\t\t---------------------------"<<endl;
		cout<<"\t\t Enter Your Choice: ";  //customer pick between 1-6
		cin>>choice;
		switch(choice){
//now start add in different cases 1-6
			case 1:{
				string name;
				int accountNum;
				double balance;
				cout<<"\t\t Enter Name: ";
				cin>>name;
				cout<<"\t\t Enter Account Number: ";
				cin>>accountNum;
				cout<<"\t\t Enter Initial Balance: ";
				cin>>balance;
				bank.AddAccount(name,accountNum,balance);
				cout<<"\t\t Account Created Successfully"<<endl;
				break;
	    	}
	    	case 2:{
				bank.showAllAccounts();
				break;
			}
			case 3:{
				int accountNum;
				cout<<"Enter Account Number: ";
				cin>>accountNum;
				bank.searchAccount(accountNum);
				break;
			}
			case 4:{
				int accountNum;
				double amount;
				cout<<"\t\t Enter Account Number to Deposit Money: ";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\t Enter Amount to Deposit: ";
					cin>>amount;
					account->deposit(amount);
					cout<<"\t\t"<<amount<<" Deposit Successfully"<<endl;
				}else{
					cout<<"\t\t Acount Not Found"<<endl;
				}
				break;
			}
			case 5:{
				int accountNum;
				double amount;
				cout<<"\t\t Enter Account Number to Withdraw Money: ";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\t Enter Amount to withdraw: ";
					cin>>amount;
					account->withdraw(amount);
					
				}else{
					cout<<"\t\t Acount Not Found"<<endl;
				}
				break;
			}
			case 6:{
				exit(1);
				break;
			}
	}
	cout<<"\t\t Countinue or Exit [Yes/No] ??";
	cin>>op;
		
	}while(op == 'y'||op =='Y');
	
}
