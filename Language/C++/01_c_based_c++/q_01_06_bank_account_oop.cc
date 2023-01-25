#include <iostream>

using namespace std;

class BankManagement 
{
public:
	BankManagement() 
	{
		_HEAD_account = new Account;
		_HEAD_account->next = NULL;
		_HEAD_account->account_ID = -1;
		_HEAD_account->balance = -1;
	}

	int show_and_receive_option() // 메뉴 출력
	{
		cout << "-----Menu-----" << "\n";
		cout << "1. 계좌개설" << "\n";
		cout << "2. 입 금" << "\n";
		cout << "3. 출 금" << "\n";
		cout << "4. 계좌정보 전체 출력" << "\n";
		cout << "5. 프로그램 종료" << "\n";
		cout << "선택: ";
		int _option = 0;
		cin >> _option;
		return _option;
	}

	void make_accout(void) 
	{
		cout << "\n\n";
		cout << "[계좌개설]" << "\n";
		Account * _iter = _HEAD_account;
		while (_iter->next != NULL) 
			_iter = _iter->next;
		_iter->next = new Account;
		_iter = _iter->next;
		cout << "\n계좌ID: ";
		cin >> _iter->account_ID;
		cout << "\n이 름: ";
		cin >> _iter->member_name;
		cout << "\n잔 액: ";
		cin >> _iter->balance;
		cout << "\n\n";
		_iter->next = NULL;
	}

	void deposit_money(void) 
	{
		cout << "\n\n";
		cout << "[입  금]" << "\n";
		cout << "계좌ID: ";
		int input_account_id = 0;
		cin >> input_account_id;
		Account * _iter = _HEAD_account->next;
		while (_iter != NULL) 
		{
			if (_iter->account_ID == input_account_id)
				break;
			_iter = _iter->next;
		}

		if (_iter == NULL)
		{
			cout << "없는 아이디 입니다. 확인 후 다시 입력 해 주세요" << "\n";
		}
		else 
		{
			cout << "입금액: ";
			int input_deposit_money = 0;
			cin >> input_deposit_money;
			_iter->balance += input_deposit_money;
			cout << "입금완료" << "\n";
		}
		cout << "\n\n";
	}

	void withdraw_money(void) 
	{
		cout << "\n\n";
		cout << "[출  금]" << "\n";
		cout << "계좌ID: ";
		int input_account_id = 0;
		cin >> input_account_id;
		Account * _iter = _HEAD_account->next;
		
		while (_iter != NULL) 
		{
			if (_iter->account_ID == input_account_id)
				break;
			_iter = _iter->next;
		}
		
		if (_iter == NULL)
		{
			cout << "없는 아이디 입니다. 확인 후 다시 입력 해 주세요" << "\n";
		}
		else 
		{
			cout << "출금액: ";
			int input_withdraw_money = 0;
			cin >> input_withdraw_money;
			_iter->balance -= input_withdraw_money;
			cout << "출금완료" << "\n";
		}
		cout << "\n\n";
	}
	
	void show_all_acc_info(void) 
	{
		cout << "\n\n";
		Account * _iter = _HEAD_account->next;
		cout << "--------------" << "\n";
		while (_iter != NULL) 
		{
			cout << "\n";
			cout << "계좌ID: " << _iter->account_ID << "\n\n";
			cout << "이 름: " << _iter->member_name << "\n\n";
			cout << "잔 액: " << _iter->balance << "\n\n";
			_iter = _iter->next;
			cout << "--------------\n";
		}
		cout << "\n\n";
	}	 

private:
	typedef struct account 
	{
		int account_ID;
		int balance;
		char member_name[100];
		struct account * next;
	} Account;
	Account * _HEAD_account;
};


int main(void) 
{
	int input_option = 0;
	BankManagement * myBankManagement = new BankManagement();
	while (true) 
	{
		input_option = myBankManagement->show_and_receive_option();
		if (input_option == 1) 
			myBankManagement->make_accout();
		else if (input_option == 2)
			myBankManagement->deposit_money();
		else if (input_option == 3)
			myBankManagement->withdraw_money();
		else if (input_option == 4) 
			myBankManagement->show_all_acc_info();
		else if (input_option == 5)
		   	break;
		else
		{
			cout << "\n잘못된 입력입니다.\n" << "\n";
		}
	}
}	
