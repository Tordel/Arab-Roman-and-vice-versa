#include <iostream>
#include <string>

using namespace std;

string situatie_special_de_usoara;

int roman_to_arabic(char roman_letter) {
	switch (roman_letter) {
	case 'M':
		return 1000;
		break;
	case 'D':
		return 500;
		break;
	case 'C':
		return 100;
		break;
	case 'L':
		return 50;
		break;
	case 'X':
		return 10;
		break;
	case 'V':
		return 5;
		break;
	case 'I':
		return 1;
		break;
	default:
		return -1;
	}
}

string arabic_to_roman(int arabic) {
	int unitati = arabic % 10;
	int zeci = (arabic % 100) - (arabic % 10);
	int sute = (arabic % 1000) - (arabic % 100);
	int mii = arabic - (arabic % 1000);
	string numar_roman = "";
	if (mii > 0) {
		for (int i = mii; i > 0; i -= 1000) {
			numar_roman += 'M';
		}
	}
	if (sute > 0 && sute < 400) {
		for (int i = sute; i > 0; i -= 100) {
			numar_roman += 'C';
		}
	}
	if (sute > 0 && sute == 400) 
		numar_roman += "CD";
	if (sute > 0 && sute == 500)
		numar_roman += 'D';
	if (sute > 500 && sute < 900) {
		numar_roman += 'D';
		for (int i = sute; i > 500; i -= 100) {
			numar_roman += 'C';
		}
	}
	if (sute == 900)
		numar_roman += "CM";
	if (zeci > 0 && zeci < 40) {
		for (int i = zeci; i > 0; i -= 10) {
			numar_roman += 'X';
		}
	}
	if (zeci == 40)
		numar_roman += "XL";
	if (zeci == 50)
		numar_roman += 'L';
	if (zeci > 50 && zeci < 90) {
		numar_roman += 'L';
		for (int i = zeci; zeci > 50; zeci -= 10) {
			numar_roman += 'X';
		}
	}
	if (zeci == 90)
		numar_roman += "XC";
	if (unitati > 0 && unitati < 4) {
		for (int i = unitati; i > 0; i -= 1) {
			numar_roman += 'I';
		}
	}
	if (unitati == 4)
		numar_roman += "IV";
	if (unitati == 5)
		numar_roman += 'V';
	if (unitati > 5 && unitati < 9) {
		numar_roman += 'V';
		for (int i = unitati; i > 5; i -= 1) {
			numar_roman += 'I';
		}
	}
	if (unitati == 9)
		numar_roman += 'IX';
	return numar_roman;
}

void UppercaseString(string &x) {
	for (int i = 0; i < x.length(); ++i)
		x[i] = toupper(x[i]);
}

void verify_roman(string y) {
	int length = y.length();
	size_t found = y.find("IIII");
	if (found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("XXXX");
	if (found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("LL");
	if (found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("CCCC");
	if (found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("DD");
	if (found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("MMMM");
	if (found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("III");
	if (found + 3 < length && found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("IV");
	if (found + 2 < length && found != string::npos) {
		throw 1;
		return;
	}
	found = y.find("IX");
	if (found + 2 < length && found != string::npos) {
		throw 1;
		return;
	}
	found = y.find('L');
	if (found == 0)
		return;
	if (found != string::npos && y[found - 1] == y[found - 2] && y[found - 1] == 'X') {
		throw 1;
		return;
	}
	found = y.find('C');
	if (found != string::npos) {
		if (found == 0)
			return;
		if (found == 1 && y[found - 1] != 'X') {
			throw 1;
			return;
		}
		else if (y[found - 1] == y[found - 2] && y[found - 1] == 'X') {
			throw 1;
			return;
		}
		else {
			for (int i = found; i >= 0; --i) {
				if (y[i] == 'L' || y[i] == 'I') {
					throw 1;
					return;
				}
			}
		}
	}
	found = y.find('D');
	if (found != string::npos) {
		if (found == 0)
			return;
		if (y[found - 1] == y[found - 2] && y[found - 1] == 'C') {
			throw 1;
			return;
		}
		else {
			for (int i = found; i >= 0; --i) {
				if (y[i] == 'L' || y[i] == 'X' || y[i] == 'I') {
					throw 1;
					return;
				}
			}
		}
	}
	found = y.find('M');
	if (found != string::npos) {
		if (found == 0)
		return;
		if (found == 1 && y[found - 1] != 'C') {
			throw 1;
			return;
		}
		else if (y[found - 1] == y[found - 2] && y[found - 1] == 'C') {
			throw 1;
			return;
		}
		else {
			for (int i = found; i >= 0; --i) {
				if (y[i] == 'D' || y[i] == 'L' || y[i] == 'X' || y[i] == 'I') {
					throw 1;
					return;
				}
			}
		}
	}
}

int main() {
	bool rom_sau_arab;
	cout << "Arab-Roman sau Roman-Arab?" << endl;
	string roman_sau_arab;
	cin >> roman_sau_arab;
	UppercaseString(roman_sau_arab);
	while (true) {
		if (roman_sau_arab == "ARAB-ROMAN") {
			rom_sau_arab = 0;
			break;
		}
		else if (roman_sau_arab == "ROMAN-ARAB") {
			rom_sau_arab = 1;
			break;
		}
		else {
			cout << "Introduceti metoda de conversie." << endl;
			cin >> roman_sau_arab;
			UppercaseString(roman_sau_arab);
		}
	}
	if (rom_sau_arab == 1) {
		string roman_nr;
		int arab = 0;
		cout << "Introduceti numarul roman:";
	introd: cin >> roman_nr;
		if (roman_nr.length() == 1) {
			situatie_special_de_usoara = roman_nr[0];
			UppercaseString(situatie_special_de_usoara);
			if (roman_to_arabic(situatie_special_de_usoara[0]) == -1) {
				cout << "Numarul este invalid! Introduceti numarul roman:";
				goto introd;
			}
			cout << "Numarul este: " << roman_to_arabic(situatie_special_de_usoara[0]);
			return 0;
		}
		UppercaseString(roman_nr);
		try {
			verify_roman(roman_nr);
		}
		catch (int e) {
			cout << "Nu exista numarul";
			return 0;
		}
		int nr_st = roman_to_arabic(roman_nr[0]), nr_dr;
		int lungime = roman_nr.length();
		for (int i = 0; i < lungime; ++i) {
			nr_dr = roman_to_arabic(roman_nr[i + 1]);
			if (nr_dr == -1 || nr_st == -1) {
				cout << "Numarul este invalid! Introduceti numarul roman:";
				goto introd;
			}
			if (nr_st < nr_dr) {
				arab += nr_dr - nr_st;
				nr_st = roman_to_arabic(roman_nr[i + 2]);
				++i;
			}
			else {
				arab += nr_st;
				nr_st = nr_dr;
			}
		}
		cout << "Numarul este:" << arab;
		return 0;
	}
	if (rom_sau_arab == 0) {
		int nr;
		cout << "Introduceti numarul arab:";
		cin >> nr;
		string eroare = "Nu ati introdus un numar natural! Introduceti numarul arab:";
		while (true) {
			if (cin.fail() || nr > 3999) {
				cout << eroare;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> nr;
			}
			else
				break;
		}
		cout << arabic_to_roman(nr);
		return 0;
		}
}