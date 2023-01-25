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

	int show_and_receive_option() // �޴� ���
	{
		cout << "-----Menu-----" << "\n";
		cout << "1. ���°���" << "\n";
		cout << "2. �� ��" << "\n";
		cout << "3. �� ��" << "\n";
		cout << "4. �������� ��ü ���" << "\n";
		cout << "5. ���α׷� ����" << "\n";
		cout << "����: ";
		int _option = 0;
		cin >> _option;
		return _option;
	}

	void make_accout(void) 
	{
		cout << "\n\n";
		cout << "[���°���]" << "\n";
		Account * _iter = _HEAD_account;
		while (_iter->next != NULL) 
			_iter = _iter->next;
		_iter->next = new Account;
		_iter = _iter->next;
		cout << "\n����ID: ";
		cin >> _iter->account_ID;
		cout << "\n�� ��: ";
		cin >> _iter->member_name;
		cout << "\n�� ��: ";
		cin >> _iter->balance;
		cout << "\n\n";
		_iter->next = NULL;
	}

	void deposit_money(void) 
	{
		cout << "\n\n";
		cout << "[��  ��]" << "\n";
		cout << "����ID: ";
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
			cout << "���� ���̵� �Դϴ�. Ȯ�� �� �ٽ� �Է� �� �ּ���" << "\n";
		}
		else 
		{
			cout << "�Աݾ�: ";
			int input_deposit_money = 0;
			cin >> input_deposit_money;
			_iter->balance += input_deposit_money;
			cout << "�ԱݿϷ�" << "\n";
		}
		cout << "\n\n";
	}

	void withdraw_money(void) 
	{
		cout << "\n\n";
		cout << "[��  ��]" << "\n";
		cout << "����ID: ";
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
			cout << "���� ���̵� �Դϴ�. Ȯ�� �� �ٽ� �Է� �� �ּ���" << "\n";
		}
		else 
		{
			cout << "��ݾ�: ";
			int input_withdraw_money = 0;
			cin >> input_withdraw_money;
			_iter->balance -= input_withdraw_money;
			cout << "��ݿϷ�" << "\n";
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
			cout << "����ID: " << _iter->account_ID << "\n\n";
			cout << "�� ��: " << _iter->member_name << "\n\n";
			cout << "�� ��: " << _iter->balance << "\n\n";
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
			cout << "\n�߸��� �Է��Դϴ�.\n" << "\n";
		}
	}
}	
