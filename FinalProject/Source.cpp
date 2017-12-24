#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>



using namespace std;
string convertToUpper(string s);
string company = "KKid Inc.";
long money = 200;
int locations = 1;
string selection = "0";
string yesorno;
int purchasable;
int lostmoney;
int employees = 1;
int purchasecount;
int tax;
bool moneyallowed = true;
int extramoney = 100;
bool allowed = true;
int investment;

int main() {
	random_device rd;
	//start
	cout << "Welcome! What do you want your fabulous company called (if you put nothing it will be called KKid Inc.)" << endl;

	getline(cin, company);
	if (company == "") {
		company = "KKid Inc.";
	}
	if (company == "25") {
		cout << "Meh." << endl;
		money = 0;
	}
	if (company == "12") {
		money = 999999;
		cout << "Cheat Code '12' activated. You have $999999" << endl;
		cout << "Enter your real company name" << endl;
		getline(cin, company);
	}
	cout << "Congratulations " << company << " on your founding!" << endl;
	cout << "The Goal of the game is to get 500 buisnesses and 900 employees. You can earn the money to do this by pressing '4'. However, you can only do this once before another action is required." << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	while (money >= 0) {
		tax = tax + 1;
		if (locations >= 500 && employees >= 900) {
			cout << "Congratulations " << company << " on becoming a successful enterprise! The Game will now exit." << endl;
			this_thread::sleep_for(chrono:milliseconds(7000));
			std::exit;
			return EXIT_SUCCESS;
		}
		if (tax == 10) {
			cout << "You have been taxed $25!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			money = money - 25;
			tax = 0;
		}
		cout << "You have $" << money << endl;
		cout << "Select an action." << endl;
		cout << "[1] Manage Buisnesses                [2] Manage Employees" << endl;
		cout << "[3] Invest in the Stock Market       [4] Earn Money" << endl;
		cin >> selection;
		//manage buisness
		if (selection == "1") {
			cout << "You have " << locations << " Location(s). Would you like to buy more? (Yes or no) " << endl;
			purchasable = money / 100;
			
			cin >> yesorno;
			yesorno = convertToUpper(yesorno);
				//if they purchase
				if (yesorno == "YES") {

					cout << "How Many? They are $100 each." << endl;
					cout << "You can afford to purchase " << purchasable << " More Buisnesse(s)." << endl;
					cin >> purchasecount;
					cout << "Purchased!" << endl;
					lostmoney = purchasecount * 100;
					locations = locations + purchasecount;
					
					money = money - lostmoney;
					cout << "you now have " << locations << " Buisnesses!" << endl;
					cout << "You lost $50 for tax" << endl;
					money = money - 50;
					this_thread::sleep_for(chrono::milliseconds(1000));
					moneyallowed = true;
					extramoney = extramoney * 2;
					allowed = true;


				
			}
		}
		if (selection == "2") {
			cout << "You have " << employees << " employee(s). Would you like to get more? (yes or no)" << endl;
			purchasable = money / 50;
			purchasable--;
			
			cin >> yesorno;
			yesorno = convertToUpper(yesorno);
			if (yesorno == "YES") {
				cout << "How Many? They are $50 each." << endl;
				cout << "You can afford " << purchasable << " more employees." << endl;
				cin >> purchasecount;
				cout << "Purchased!" << endl;
				lostmoney = purchasecount * 50;
				employees = employees + purchasecount;
				money = money - lostmoney;
				cout << "you now have " << employees << " Employees" << endl;
				cout << "You lost $50 for tax" << endl;
				money = money - 50;
				this_thread::sleep_for(chrono::milliseconds(1000));
				moneyallowed = true;
				extramoney = extramoney * 2;
				allowed = true;

			}
		}
		if (selection == "3") {
		    investment = rd() % 2;
			if (investment == 0 && allowed == true) {
				cout << "You lost $75!" << endl;
				money = money - 75;
				cout << "You will need to make another action befrore you can invest again!" << endl;
				allowed = false;
				moneyallowed = true;
			}
			else if (investment == 1 && allowed == true) {
				cout << "You got $75!" << endl;
				money = money + 75;
				cout << "You will need to make another action befrore you can invest again!" << endl;
				allowed = false;
				moneyallowed = true;
			}
			else {
				cout << "You are not allowed to invest at the minute! please make another action first." << endl;

			}
		}
		if (selection == "4") {
			if (moneyallowed) {
				cout << "Earning Money, Please Wait" << endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
				money = money + employees * locations + extramoney;
				moneyallowed = false;
				
			}
			else {
				cout << "You are not currently allowed to earn money! Please make another action before contiuning!" << endl;
			}
			
		
		}
	}
	cout << "You lost all of your money! Good luck next time" << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
}

string convertToUpper(string s)
{
	for (unsigned int l = 0; l < s.length(); l++)
	{
		s[l] = toupper(s[l]);
	}
	return s;
}
