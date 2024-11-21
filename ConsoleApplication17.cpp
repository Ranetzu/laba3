#include <iostream>
#include <string>


using namespace std;

class Tarifs {

private:

	int SellWater;
	int SellGaz;
	int SellElectric;

public:

	Tarifs(int sw, int sg, int se);

	int GetSellWater() const;
	int GetSellGaz() const;
	int GetSellElectric() const;

};
Tarifs::Tarifs(int sw, int sg, int se) {

	if (sw < 0 or sg < 0 or se < 0) {

		throw std::out_of_range("You Dead!");

	}

	SellWater = sw;
	SellGaz = sg;
	SellElectric = se;
}

int Tarifs::GetSellWater() const {

	return SellWater;

}
int Tarifs::GetSellGaz() const {

	return SellGaz;

}
int Tarifs::GetSellElectric() const {

	return SellElectric;

}

class Human {

private:
	string name;
	int dolg = 0;

public:
	Human(string name);

	string GetSecondName() const;
	int GetDolg() const;


	void AddSecondName(string na) {

		name = na;

	}
	void Adddolg(int k) {
		dolg += k;
	}

};
string Human::GetSecondName() const {

	return name;

}
int Human::GetDolg() const {

	return dolg;

}
Human::Human(string f) {

	name = f;
}

void addUslElectr(Tarifs& tarif, Human& human) {

	cout << tarif.GetSellElectric() << " to " << human.GetSecondName() << endl;
	human.Adddolg(tarif.GetSellElectric());

}
void addUslGaz(Tarifs& tarif, Human& human) {

	cout << tarif.GetSellGaz() << " to " << human.GetSecondName() << endl;
	human.Adddolg(tarif.GetSellGaz());

}
void addUslWater(Tarifs& tarif, Human& human) {

	cout << tarif.GetSellWater() << " to " << human.GetSecondName() << endl;;
	human.Adddolg(tarif.GetSellWater());

}

class Strategy {
public:

	virtual void lgota(Human& dolg) = 0;

};


class ContextStrategy {

private:
	Strategy* strategy;

public:
	void setStrategy(Strategy* strategy) {
		this->strategy = strategy;
	}
	void ExecuteStrategy(Human& dolg) {

		strategy->lgota(dolg);
	}
};



class StrategyA : public Strategy
{
	void lgota(Human& dolg) {

		cout << dolg.GetDolg() << endl;

	}
};
class StrategyB : public Strategy {

	void lgota(Human& dolg) {

		cout << dolg.GetDolg() / 2 << endl;

	}

};
int menuNum;
void menu() {
	cout << "Menu:" << endl;
	cout << "Enter 1 for enter a second name of human." << endl;
	cout << "Enter 2 for get a dolg with name." << endl;
	cout << "Enter 3 for add tarif of Water for human." << endl;
	cout << "Enter 4 for add tarif of Gaz for human." << endl;
	cout << "Enter 5 for add tarif of Electric for human." << endl;
	cout << "Enter 6 for end of work." << endl;
	cout << "Your choice is: ";
	cin >> menuNum;
}
void syst() {
	system("pause");
	system("cls");
}

int main() {
	ContextStrategy context;
	StrategyA bezLgot;
	StrategyB sLgot;
	Human mel("name");
	Tarifs tarif(1500, 1000, 2000);
	Tarifs& tar = tarif;
	string name;
	string vvod;
	int answer;
	int k = 0;
	while (menuNum != 6) {
		menu();
		switch (menuNum) {
		case 1:
			cout << "Get name of human:";
			cin >> name;
			mel.AddSecondName(name);
			cout << mel.GetSecondName() << " " << "have lgot?" << endl;
			cout << "1 for Yes/2 for No: ";
			cin >> answer;
			while (true) {
				if (cin.fail() || (cin.peek() != '\n')) {
					cout << "Wrong answer." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "1 for Yes/2 for No: ";
					cin >> answer;
				}
				else break;
			}

			if (answer == 2) {
				k = 0;
				}
			else {
				k = 1;
			}
		
			syst();
			break;
		case 2:
			cout << "Enter name:" << " " << endl;
			cin >> vvod;
			if (mel.GetSecondName() == name) {
				if (k == 0) {
					context.setStrategy(&bezLgot);
				}
				else if (k == 1)
				{
					context.setStrategy(&sLgot);
				}
			}
			else {
				cout << "Unknown name." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			context.ExecuteStrategy(mel);
			syst();
			break;
		case 3:
			addUslWater(tar, mel);
			syst();
			break;
		case 4:
			addUslGaz(tar, mel);
			syst();
			break;
		case 5:
			addUslElectr(tar, mel);
			syst();
			break;
		default:
			cout << "Unknown number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			syst();
			break;
		}// end switch
	}// end while

	return 0;
}
