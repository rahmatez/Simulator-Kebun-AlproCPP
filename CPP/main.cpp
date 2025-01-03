#include <iostream>
#include <iomanip>

using namespace std;

//PROGRAM SIMULATOR KEBUN INI DIBUAT OLEH :
// 1. Jovi Inzagi (21102064)
// 2. Muhammad Arif(21102058)
// 3. Rahmat Ashari(21102043)
// 4. Rizal Fahmi Yofiawan (21102045
// 5. Tegar Setio (21102307)

void menu();
void tanam(int, int);
void tebang(int, int);
void tumbuh();
void cetak_kebun();
void tanaman(int);
char pilih;

int kebun[5][5]; // asumsi kebun 5x5
int panjang_kebun = 5;
int lebar_kebun = 5;

int main()
{
	int pilih_menu;
	int input_baris;
	int input_kolom;

	do {
		menu();

		cin >> pilih_menu;

		switch (pilih_menu)
		{
		case 1:
			do {
				do {
					cout << "\nTanam pada baris : ";
					cin >> input_baris;
				} while (input_baris <= 0 || input_baris > 5);

				do {
					cout << "\nTanam pada kolom : ";
					cin >> input_kolom;
				} while (input_kolom <= 0 || input_kolom > 5);

				tanam(input_baris, input_kolom);

				do {
					cout << endl << "Ingin melihat kebun (y/n)? ";
					cin >> pilih;
					pilih = tolower(pilih);
				} while (pilih != 'n' && pilih != 'y');

				if (pilih == 'y') {
					cetak_kebun();
				}

				do {
					cout << endl << "Apakah lanjut tanam (y/n)? ";
					cin >> pilih;
					pilih = tolower(pilih);
				} while (pilih != 'n' && pilih != 'y');

			} while (pilih != 'n');
			system("clear");

			break;
		case 2:
			do {
				do {
					cout << "\Tebang pada baris : ";
					cin >> input_baris;
				} while (input_baris <= 0 || input_baris > 5);

				do {
					cout << "\Tebang pada kolom : ";
					cin >> input_kolom;
				} while (input_kolom <= 0 || input_kolom > 5);

				tebang(input_baris, input_kolom);

				do {
					cout << endl << "Ingin melihat kebun (y/n)? ";
					cin >> pilih;
					pilih = tolower(pilih);
				} while (pilih != 'n' && pilih != 'y');

				if (pilih == 'y') {
					cetak_kebun();
				}

				do {
					cout << endl << "Apakah lanjut tebang (y/n)? ";
					cin >> pilih;
					pilih = tolower(pilih);
				} while (pilih != 'n' && pilih != 'y');

			} while (pilih != 'n');
            system("clear");

			break;
		case 3:
			cetak_kebun();

			do {
				do {
					cout << "\nIngin mengulang lihat kebun (y/n)? ";
					cin >> pilih;
					pilih = tolower(pilih);
				} while (pilih != 'n' && pilih != 'y');

				if (pilih == 'y') {
					tumbuh();

					cetak_kebun();
				}

			} while (pilih != 'n');
            system("clear");

			break;
		}
	} while (pilih_menu != 4);

	return 0;
}

void tanam(int baris, int kolom) {
	if (kebun[baris - 1][kolom - 1] == 0) {
		kebun[baris - 1][kolom - 1] = 1;
	}
	else {
		cout << endl << "Lokasi tersebut sudah ada tanaman" << endl;
	}
}

void tebang(int baris, int kolom) {
	kebun[baris - 1][kolom - 1] = 0;
}

void tumbuh() {
	int kebun_baru[5][5];

	for (int i = 0; i < panjang_kebun; i++) {
		for (int j = 0; j < lebar_kebun; j++) {
			if (kebun[i][j] == 1) { // Jika masih biji
				kebun[i][j] = 2;
			}
			else if (kebun[i][j] == 2) { // Jika masih benih
				kebun[i][j] = 3;
			}
			else if (kebun[i][j] == 3) { // Jika masih benih
				kebun[i][j] = 4;

				int baris_baru;
				int kolom_baru;

				do {
					srand(time(NULL));
					int r = rand() % (8 - 0 + 1) + 0;

					if (r == 0) {
						baris_baru = i - 1;
						kolom_baru = j - 1;
					}
					else if (r == 1) {
						baris_baru = i - 1;
						kolom_baru = j;
					}
					else if (r == 2) {
						baris_baru = i - 1;
						kolom_baru = j + 1;
					}
					else if (r == 3) {
						baris_baru = i;
						kolom_baru = j - 1;
					}
					else if (r == 4) {
						baris_baru = i;
						kolom_baru = j;
					}
					else if (r == 5) {
						baris_baru = i;
						kolom_baru = j + 1;
					}
					else if (r == 6) {
						baris_baru = i + 1;
						kolom_baru = j - 1;
					}
					else if (r == 7) {
						baris_baru = i + 1;
						kolom_baru = j;
					}
					else if (r == 8) {
						baris_baru = i + 1;
						kolom_baru = j + 1;
					}
				} while (baris_baru < 0 || baris_baru > 4 || kolom_baru < 0 || kolom_baru > 4 || kebun[baris_baru][kolom_baru] != 0); // validasi agar tidak melebihi batas kebun

				kebun_baru[baris_baru][kolom_baru] = 1;
			}
		}
	}

	for (int i = 0; i < panjang_kebun; i++) {
		for (int j = 0; j < lebar_kebun; j++) {
			if (kebun_baru[i][j] == 1) kebun[i][j] = 1;
		}
	}
}

void cetak_kebun() {
	cout << endl << endl;
	for (int i = 0; i < panjang_kebun; i++) {
		cout << "\t| ";
		for (int j = 0; j < lebar_kebun; j++) {
			tanaman(kebun[i][j]);
		}
		cout << "|" << endl;
	}
	cout << endl << endl;
}

void menu() {
	cout << endl << endl;
	cout << "* Simulator Kebun *" << endl;
	cout << "1. Tanam" << endl;
	cout << "2. Tebang (Buang)" << endl;
	cout << "3. Lihat Kebun" << endl;
	cout << "4. Exit" << endl << endl;
	cout << "Pilih menu : ";

}

void tanaman(int status) {
	if (status == 0) {
		cout << " ";
	}
	else if (status == 1) {
		cout << ".";
	}
	else if (status == 2) {
		cout << "v";
	}
	else if (status == 3) {
		cout << "0";
	}
	else if (status == 4) {
		cout << "X";
	}

	cout << " ";
}
