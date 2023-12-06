#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct imot {
	char kvartal;
	char ulica[30];
	int plosht;
	int cena;
	int stai;

};
int menu();
int spravka_menu();
int entryS(imot Age[],int n);
void loadfile(imot Age[],int& n);
void filesave(imot Age[], int n);
void search_kvartal(imot Age[], int n);
void izvej_kvartal(imot Age[], int n);
void max(imot Age[], int n);
void redaktirane_cena(imot Age[], int n);
void zakupuvane(imot Age[], int n);
void append();
void list(imot Age[], int n);
void spravka_cena(imot Age[],int n);
void spravka_stai(imot Age[], int n);
void spravka_kvadratura(imot Age[], int n);
void spravka_cena_kv(imot Age[], int n);

imot input();
fstream fp;
int main() {
	int ch, n = 0;
	int ch1; \
		char otg = 'y';
	imot Age[50];
	loadfile(Age,n);
	do {
		ch = menu();
		switch (ch) {
		case 1:n = entryS(Age, n); filesave(Age, n); break;
		case 2:do {
			append(); n++;
			cout << "Dobavqne na oshte edin imot?[y/n]";
			cin >> otg;
		} while (!(otg == 'N' || otg == 'n')); break;
		case 3:list(Age, n); break;
		case 4:max(Age, n); break;
		case 5:izvej_kvartal(Age, n); break;
		case 6:redaktirane_cena(Age, n); filesave(Age, n); break;
		case 7:zakupuvane(Age, n); filesave(Age, n); break;
		case 8:search_kvartal(Age, n); break;
		case 9:do {
			ch1 = spravka_menu();
			switch (ch1) {
			case 1:spravka_cena(Age, n); break;
			case 2:spravka_stai(Age, n); break;
			case 3:spravka_kvadratura(Age, n); break;
			case 4:spravka_cena_kv(Age, n); break;
			}

		} while (ch1 != 5);
		case 10:filesave(Age, n); break;
		}
	} while (ch != 11);

}
imot input() {
	imot a = { 0 };
	cin.ignore();
	do {
		cout << endl << "Kvartal(1.Mladost,2.Chaika,3.Levski,4.Center,5.Grucki)"; 
		cout << endl << "Molq vuvedete s chislo!" << endl;
		cin>>a.kvartal;
	} while (a.kvartal <= 49 && a.kvartal >= 53);
	cin.ignore();
	cout << endl << "Ulica:"; cin.getline(a.ulica, 30);
	cout << endl << "Plosht(kv.m):"; cin >> a.plosht;
	cout << endl << "Cena(lv.):"; cin >> a.cena;
	cout << endl << "Stai:"; cin >> a.stai;
	return (a);
}
int menu() {
	int ch;
	std::cout << endl << "\t MENU";
	std::cout << endl << "1.Dobavqne na nqkolko imota v agenciqta";
	std::cout << endl << "2.Dobavqne na 1 imot v agenciqta";
	std::cout << endl << "3.Izvejdane na zapisanite imoti";
	std::cout << endl << "4.Izvejdane na max cena";
	std::cout << endl << "5.Izvejdane na imoti v opredelen kvartal";
	std::cout << endl << "6.Redaktirane na imot";
	std::cout << endl << "7.Zakupuvane na imot";
	std::cout << endl << "8.Tursene na imot po kvartal";
	std::cout << endl << "9.Spravki za imoti";
	std::cout << endl << "10.Zapazvane vuv file";
	std::cout << endl << "11.Exit";
	do {
		cout << endl << "Tvoqt izbor:";
		cin >> ch;
	} while (ch < 1 || ch>12);
	return ch;


}
int spravka_menu() {
	int ch1;
	std::cout << endl << "\t Spravki za imoti";
	std::cout << endl << "1.Izvejdane na vsichki imoti po cena";
	std::cout << endl << "2.Izvejdane na vsichki imoti po broi stai";
	std::cout << endl << "3.Izvejdane na imota s nai-golqma kvadratura";
	std::cout << endl << "4.Izvejdane na nai-evtiniq imot po cena na kvadrat";
	std::cout << endl << "5.Back";
	do {
		cout << endl << "Tvoqt izbor:";
		cin >> ch1;
	} while (ch1 < 1 || ch1>6);
	return ch1;

}
void append(){
	imot b = { 0 };
	fp.open("agenciq.dat", ios::binary | ios::app);
	if (!fp) { std::cout << endl << " Error in file " << endl; exit(1); }
	std::cout << endl << " Dobavqne na edin imot" << endl;
	b = input();
	fp.write((char*)&b, sizeof(imot));
	fp.close();
}
int entryS(imot Age[], int n) {
	int i, m;
	do {
		std::cout << endl << "Kolko imota iskate da vuvedete?" << endl;
		cin >> m;
	} while (m + n < 0 || m + n>50);
	if (m + n < 50) {
		for (i = n; i < n + m; i++) {
			cout << endl << "Imot " << i + 1;
			Age[i] = input();
		}
		return(n + m);
	}
	else {
		std::cout << endl << "Nqma svobodni mesta!";
	}
}
void filesave(imot Age[], int n) {
	fp.open("agenciq.dat", ios::out | ios::binary);
	if (!fp) {
		std::cout << "Cannot open file!" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fp.write((char*)&Age[i], sizeof(imot));
	}
	fp.close();
	if (!fp.good()) {
		std::cout << "Error occurred at writing time!" << endl;
	}
}
void list(imot Age[], int n) {
	std::cout << "\n\n\n\n\n";
	int i;
	int k = 0;
	for (i = 0; i < n; i++) {
		switch (Age[i].kvartal) {
		case '1':	std::cout<<endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
		case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
		case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
		case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
		case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
		}
		std::cout << "\t" << Age[i].ulica;
		std::cout << "\t" << Age[i].plosht << " kv.m";
		std::cout << "\t" << Age[i].cena << " lv.";
		std::cout << "\t" << Age[i].stai << " stai";
	}
	std::cout << "\n\n\n\n\n";
}
void max(imot Age[], int n) {
	imot p;
	int m = Age[0].cena;
	p = Age[0];
	for (int i = 1; i < n; i++) {
		if (Age[i].cena > m) {
			m = Age[i].cena;
			p = Age[i];
		}
	}
	std::cout << endl << "Max cena e:" << m << endl;
	switch (p.kvartal) {
	case '1':	std::cout << endl << "1.Mladost"; break;
	case '2':   std::cout << endl << "2.Chaika"; break;
	case '3':	std::cout << endl << "3.Levski"; break;
	case '4':	std::cout << endl << "4.Center"; break;
	case '5':	std::cout << endl << "5.Grucki"; break;
	}
	cout << "\t" << p.ulica;
	cout << "\t" << p.plosht << " kv.m";
	cout << "\t" << p.cena << " lv.";
	cout << "\t" << p.stai << " stai";
	std::cout << "\n\n\n\n\n";
}
void loadfile(imot Age[], int& n) {

	ifstream infile("agenciq.dat", ios::in | ios::binary);
	if (!infile) {
		std::cout << "Cannot open file!" << endl;
		return;
	}
	n = 0;
	while (infile.read((char*)&Age[n], sizeof(imot)))n++;
	infile.close();
	if (!infile.good()) {
		std::cout << "Error occurred at reading time!" << endl;
	}
}
void izvej_kvartal(imot Age[], int n) {
	char kv;
	cin.ignore();
	std::cout << endl << "Kvartal(1.Mladost,2.Chaika,3.Levski,4.Center,5.Grucki):";
	cin >> kv;
	for (int i = 0; i < n; i++) {
		if (kv == Age[i].kvartal) {
			switch (Age[i].kvartal) {
			case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
			case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
			case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
			case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
			case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
			}
			std::cout << "\t" << Age[i].ulica;
			std::cout << "\t" << Age[i].plosht << " kv.m";
			std::cout << "\t" << Age[i].cena << " lv.";
			std::cout << "\t" << Age[i].stai << " stai";
		}
	}
	std::cout << "\n\n\n\n\n";
}
void redaktirane_cena(imot Age[], int n) {
	char ul[20];
	int flag = 0;
	cin.ignore();
	std::cout << endl << "Vuvedi ime na ulica:";
	cin.getline(ul, 20);
	for (int i = 0; i < n; i++) {
		if (!strcmp(ul, Age[i].ulica)) {
			flag = 1;
			int y = 0;
			switch (Age[i].kvartal) {
			case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
			case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
			case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
			case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
			case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
			}
			std::cout << "\t" << Age[i].ulica;
			std::cout << "\t" << Age[i].plosht << " kv.m";
			std::cout << "\t" << Age[i].cena << " lv.";
			std::cout << "\t" << Age[i].stai << " stai";

			std::cout << endl << endl;
			std::cout << endl << "Nova cena na imota (lv.):";
			cin >> y;
			Age[i].cena = y;

			std::cout << endl << endl;
			switch (Age[i].kvartal) {
			case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
			case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
			case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
			case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
			case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
			}
			std::cout << "\t" << Age[i].ulica;
			std::cout << "\t" << Age[i].plosht << " kv.m";
			std::cout << "\t" << Age[i].cena << " lv.";
			std::cout << "\t" << Age[i].stai << " stai";

		}
	}
	if (!flag) {
		std::cout << endl << "Nqma takava ulica!";
	}
}
void zakupuvane(imot Age[], int n) {
	char ul[20];
	int flag = 0;
	cin.ignore();
	cout << endl << "Vuvedi ime na ulica:";
	cin.getline(ul, 20);
	for (int i = 0; i < n; i++) {
		if (!strcmp(ul, Age[i].ulica)) {
			flag = 1;
			
		}
		if(flag==1){
			Age[i] = Age[i + 1];
			cout << endl << "Imota e zakupen uspeshno";
		}
	}
	if (!flag) {
		cout <<endl<< "Ulicata ne e namerena";
	}
	else {
		n--;
	}
}
void search_kvartal(imot Age[], int n) {
	char kv;
	int flag = 0;
	cin.ignore();
	cout << endl << "Kvartal(1.Mladost,2.Chaika,3.Levski,4.Center,5.Grucki):";
	cin >> kv;
	for (int i = 0; i < n; i++) {
		if (kv==Age[i].kvartal) {
			flag = 1;
			switch (Age[i].kvartal) {
			case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
			case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
			case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
			case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
			case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
			}
			cout << "\t" << Age[i].ulica;
			cout << "\t" << Age[i].plosht << " kv.m";
			cout << "\t" << Age[i].cena << " lv.";
			cout << "\t" << Age[i].stai << " stai";
		}
	}
	if (!flag) {
		cout << endl << "Ne e nameren imot v kvartala!";
		cout << endl << "Izvejdane na imotite ot susednite kvartali!";
		cout << "\n\n\n";
		if (kv == '1') {
			for (int i = 0; i < n; i++) {
				if (Age[i].kvartal == '4') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";

				}
				else if (Age[i].kvartal == '5') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";
				}
			}
		}
		else if (kv == '2') {
			for (int i = 0; i < n; i++) {
				if (Age[i].kvartal == '3') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";

				}
				else if (Age[i].kvartal == '4') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";
				}
			}
		}
		else if (kv == '3') {
			for (int i = 0; i < n; i++) {
				if (Age[i].kvartal == '2') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";

				}
				else if (Age[i].kvartal == '4') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";
				}
			}
		}
		else if (kv == '4') {
			for (int i = 0; i < n; i++) {
				if (Age[i].kvartal == '1') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";

				}
				else if (Age[i].kvartal == '2') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";
				}
				else if (Age[i].kvartal == '3') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";
				}
				else if (Age[i].kvartal == '5') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (Age[i].kvartal == '1') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";

				}
				else if (Age[i].kvartal == '4') {
					switch (Age[i].kvartal) {
					case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
					case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
					case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
					case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
					case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
					}
					std::cout << "\t" << Age[i].ulica;
					std::cout << "\t" << Age[i].plosht << " kv.m";
					std::cout << "\t" << Age[i].cena << " lv.";
					std::cout << "\t" << Age[i].stai << " stai";
				}
			}
		}
    }
	std::cout << "\n\n\n\n\n";
}
void spravka_cena(imot Age[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (Age[j].cena < Age[i].cena) {
				temp = Age[i].cena;
				Age[i].cena = Age[j].cena;
				Age[j].cena = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		switch (Age[i].kvartal) {
		case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
		case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
		case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
		case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
		case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
		}
		cout << "\t" << Age[i].ulica;
		cout << "\t" << Age[i].plosht << " kv.m";
		cout << "\t" << Age[i].cena << " lv.";
		cout << "\t" << Age[i].stai << " stai";
	}
	std::cout << "\n\n\n\n\n";
}
void spravka_stai(imot Age[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (Age[j].stai > Age[i].stai) {
				temp = Age[i].stai;
				Age[i].stai = Age[j].stai;
				Age[j].stai = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		switch (Age[i].kvartal) {
		case '1':	std::cout << endl << "Imot " << i + 1 << endl << "1.Mladost"; break;
		case '2':   std::cout << endl << "Imot " << i + 1 << endl << "2.Chaika"; break;
		case '3':	std::cout << endl << "Imot " << i + 1 << endl << "3.Levski"; break;
		case '4':	std::cout << endl << "Imot " << i + 1 << endl << "4.Center"; break;
		case '5':	std::cout << endl << "Imot " << i + 1 << endl << "5.Grucki"; break;
		}
		cout << "\t" << Age[i].ulica;
		cout << "\t" << Age[i].plosht << " kv.m";
		cout << "\t" << Age[i].cena << " lv.";
		cout << "\t" << Age[i].stai << " stai";
	}
	cout << "\n\n\n\n\n";
}
void spravka_kvadratura(imot Age[], int n) {
	imot p;
	int k = 0;
	int m = Age[0].plosht;
	p = Age[0];
	for (int i = 1; i < n; i++) {
		if (Age[i].cena > m) {
			m = Age[i].plosht;
			p = Age[i];
			k = i;
		}
	}
	cout << endl << "Imota s nai golqma plosht e:" << "Imot " << k << "  " << m << " kv.m" << endl;
	switch (p.kvartal) {
	case '1':	std::cout << endl << "Imot " << k + 1 << endl << "1.Mladost"; break;
	case '2':   std::cout << endl << "Imot " << k + 1 << endl << "2.Chaika"; break;
	case '3':	std::cout << endl << "Imot " << k + 1 << endl << "3.Levski"; break;
	case '4':	std::cout << endl << "Imot " << k + 1 << endl << "4.Center"; break;
	case '5':	std::cout << endl << "Imot " << k + 1 << endl << "5.Grucki"; break;
	}
	cout << "\t" << p.ulica;
	cout << "\t" << p.plosht << " kv.m";
	cout << "\t" << p.cena << " lv.";
	cout << "\t" << p.stai << " stai";
	cout << "\n\n\n\n\n";
}
void spravka_cena_kv(imot Age[], int n) {
	int s;
	imot p;
	int k = 0;
	int m = Age[0].cena / Age[0].plosht;
	p = Age[0];
	for (int i = 1; i < n; i++) {
		s = Age[i].cena / Age[i].plosht;
		if (s < m) {
			m = s;
			p = Age[i];
			k = i;
		}
	}
	cout << endl << "Imota s nai-niska cena na kvadrat:" << "Imot " << k << "  " << m << "lv./kv.m" << endl;
	switch (p.kvartal) {
	case '1':	cout << endl << "Imot " << k + 1 << endl << "Mladost"; break;
	case '2':   cout << endl << "Imot " << k + 1 << endl << "Chaika"; break;
	case '3':	cout << endl << "Imot " << k + 1 << endl << "Levski"; break;
	case '4':	cout << endl << "Imot " << k + 1 << endl << "Center"; break;
	case '5':	cout << endl << "Imot " << k + 1 << endl << "Grucki"; break;
	}
	cout << "\t" << p.ulica;
	cout << "\t" << p.plosht << " kv.m";
	cout << "\t" << p.cena << " lv.";
	cout << "\t" << p.stai << " stai";
	cout << "\n\n\n\n\n";
}