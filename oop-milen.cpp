// --------------------------------------//
// Uprajnenie na zadacha za avto okazion //
//					 //
// @author nelim			 //
// --------------------------------------//


#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int n; // broi koli

class Car {
		private: // promenlivi s dannite za kolite, skriti, otdolu ima publichni funkcii za izkarwane na infoto
			string make;
			int price;
			int year;

		public:
			Car() { // konstruktor po podrazbirane
				make = "";
				price = 0;
				year = 0;
			}

		void setMake(string sMake) { make = sMake; }
		void setPrice(int sPrice) { price = sPrice; }
		void setYear(int sYear) { year = sYear; }

		string getMake() { return make; }
		int getPrice() { return price; }
		int getYear()	{ return year; }
		int getPriceVAT() { return price*1.2; }


		void enterData() {
			cout << "\nМарка:";	cin >> make;
			cout << "Цена:";	cin >> price;

			do { cout << "Година:";	cin >> year; }
			while(year < 1980 || year > 2013);
		}

		void printData() {
			cout << setw(15) << make << setw(25) << year << setw(15) << price << setw(15) << getPriceVAT() << endl;
		}

};

void spisak1(Car cars[]) {

     cout << "List of available cars:" << endl;
     cout << setw(15) << "Make" << setw(25) << "Year of produce" << setw(15) << "Price" << setw(15) << "VAT Price" << n << endl;
     for (int i=0;i<n;i++) {
		cars[i].printData();
         }
}

void spisak2(Car cars[]) {
	int Nprice;
	cout << "Въведете цена: "; cin >> Nprice;
	cout << "List of available cars with price lower than " << Nprice << ":" << endl;
        cout << setw(15) << "Make" << setw(25) << "Year of produce" << setw(15) << "Price" << setw(15) << "VAT Price" << endl;
	for(int i=0;i<n;i++) {
		if(cars[i].getPrice()<Nprice) {
			cars[i].printData();
		}
	}
}

void spisak3(Car cars[])  {
	Car* tempcar = new Car[1]; // nov wremenen obekt za sotrirane

	int totalprice = 0;
	for(int i=0;i<n;i++) {
		for (int j=0;j<n-1;j++) {
			string j1 = cars[j+1].getMake();
			string j0 = cars[j].getMake();

// 			obryshtane na stringowete w char za polzwane na strcmp 
//			char *b0 = (char*)j0.c_str();
//			char *b1 = (char*)j1.c_str();
//			if(strcmp(cars[j+1].getMake(),cars[j].getMake())<0) {
//			if(strcmp(b1,b0)<0) {

			if(j1.compare(j0)<0) {
				tempcar[0]=cars[j+1]; cars[j+1]=cars[j]; cars[j]=tempcar[0];
				}
		}
	}
	for(int i=0;i<n;i++) {
		cars[i].printData();
		totalprice = totalprice + cars[i].getPrice();
	}
	cout << totalprice;
	delete[] tempcar;
}

void spisak6(Car cars[]) {
	Car* tempcar = new Car[1]; // za sortirovki

	for(int i=0;i<n;i++) {
		for(int j=0;j<n-1;j++) {
			if(cars[j].getPrice()>cars[j+1].getPrice()) {
				tempcar[0]=cars[j+1]; cars[j+1]=cars[j]; cars[j]=tempcar[0];
			}
		}
	}
	delete[] tempcar;
}


int main() {

     cout << "Въведете брой автомобили за първоначално въвеждане: ";
     cin >> n;

Car* cars = new Car[n]; // Заделяме памет за n на брой коли
for(int i = 0; i < n; i++) {
        cars[i].enterData();
   }

int menu;   
do {
    cout << "\n\n-< Avtomobilen okazion v1.0 by Milen >-\n\n";    
    cout << "1. Spisak na avtomobilite\n";
    cout << "2. Spisak na tezi s cena po-malka ot (N) \n";
    cout << "3. Spisak na avtomobilite po marka i obshtata im stoinost w leva\n";
    cout << "4. Dobawqne na nov avtomobil, iztrivane ili promqna na weche waweden\n";
    cout << "5. Sortirane po marka\n";
    cout << "6. Sortirane po cena za edin broi\n";
    cout << "7. Izhod ot programata\n";
    cout << "Molq wawedete svoia izbor: ";
    cin >> menu;
    cout << endl;
    if (1<=menu&&menu<=7) {
                          switch (menu) 
                          {
                                 case 1:spisak1(cars);break;
                                 case 2:spisak2(cars);break;
                                 case 3:spisak3(cars);break;
                                 case 6:spisak6(cars);break;
                                 case 7:cout <<"Izhod";break;
                                 }
                          }      
    else cout << "Greshka";
 } while (menu!=7);
delete[] cars;	// освобождаване на паметта за динамичния масив
return 0;
}
