#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int n; // broi koli

struct cars_t { // tip na struktorata za kolite
       char marka[50];
       int year;
       int price;
}
*cars=new cars_t[500],buffer; // informaciq za 500 koli, plus buffer pri sortirowki i etc.


void enter();
void spisak1();
void spisak2();
void spisak3();
void edit();
void sort1();
void sort2();       

 int main() {

int menu;   
do {
    cout << "\n\n-< Avtomobilen okazion v1.0 by Milen >-\n\n";    
    cout << "1. Wywejdane na avtomobili\n";
    cout << "2. Spisak na avtomobilite\n";
    cout << "3. Spisak na tezi s cena po-malka ot (N) \n";
    cout << "4. Spisak na avtomobilite po marka i obshtata im stoinost w leva\n";
    cout << "5. Dobawqne na nov avtomobil, iztrivane ili promqna na weche waweden\n";
    cout << "6. Sortirane po marka\n";
    cout << "7. Sortirane po cena za edin broi\n";
    cout << "8. Izhod ot programata\n";
    cout << "Molq wawedete svoia izbor: ";
    cin >> menu;
    cout << endl;
    if (1<=menu&&menu<=8) {
                          switch (menu) 
                          {
                                 case 1:enter();break;
                                 case 2:spisak1();break;
                                 case 3:spisak2();break;
                                 case 4:spisak3();break;
                                 case 5:edit();break;
                                 case 6:sort1();break;
                                 case 7:sort2();break;
                                 case 8:cout <<"Izhod";break;
                                 }
                          }      
    else cout << "Greshka";
 } while (menu!=8);
                       
	return 0;
}


void enter() { 
     
     if (n>0) { // prowerka dali weche ima wawejdano N
              cout << "!!! Veche ima wawedeni nachalen broi avtomobili !!!\n!!! Ako prodaljite te shte badat avtomatichno iztriti !!!\n";
              char check;
              cout << "Iskate li da prodaljite? <y/n>:"; cin >> check; // not yet
              if  (check == 'n' || check == 'N') return;
     }
     cout << "Vavedete broi avtomobili za parwonachalno wawejdane: ";
     cin >> n;
     for (int i=1;i<=n;i++) {
         cin.get();
         cout << "Vavedete marka na avtomobil nomer"<<i<<": "; cin.getline(cars[i].marka,50);
         cout << "Godina na proizwodstwo na awtomobila: "; cin >> cars[i].year;
         cout << "Cena: "; cin >> cars[i].price;
         }    
}
void spisak1() { 
     
     cout << "Spisak na awtomobilite v okaziona\n";
     cout << setw(15) << "marka" << setw(20) << "God. na proizv." << setw(15) << "Cena" << endl;
     for (int i=1;i<=n;i++) {
         cout << setw(15) << cars[i].marka << setw(20) << cars[i].year << setw(15) << cars[i].price << endl;
         }
}
void spisak2() { 
     cout << "Spisak na avtomobilite v okaziona s cena po-malka ot wawedenata\n";
     int price;
     cout << "Vavedete cena: "; cin >> price;
     cout << setw(15) << "marka" << setw(15) << "Cena" << endl;
     for (int i=1;i<=n;i++) {
         if (cars[i].price<price) {
                                   cout << setw(15) << cars[i].marka << setw(15) << cars[i].price << endl;
                                   }
         }
}
void spisak3() { 
     cout << "Spisak na avtomobilite po marka w azbuchen red, i obshtata cena na avtomobilite w okaziona\n"; 
     for (int i=1;i<=n;i++)   
       for (int j=1;j<=n-1;j++)
         if (strcmp(cars[j+1].marka,cars[j].marka)<0)  // sortirane po azbuchen red, chrez funkciqta strcmp i srawnqwane na stringowete
	      			{ buffer=cars[j+1]; cars[j+1]=cars[j]; cars[j]=buffer; } // izpolwane na buffer za da se naprawi razmqnata
     cout << "V okaziona ima v nalichnost slednite marki avtomobili:\n";
     double totalprice=0;
     for (int i=1;i<=n;i++) { // izkarwane na modelite, plus iz4islqwane na obshtata cena za wsi4ki, priswoena na totalprice
         totalprice=totalprice+cars[i].price; 
         cout << cars[i].marka << endl;;
         }
     cout << "Obshtata cena na avtomobilite e: " << totalprice << " leva" << endl;
     
         
}
void edit() { 
     cout << "--> Promqna na bazata\n";
     int choise;   // menu za funkciqta po rabota s bazata danni
     do {
         cout << "    1. Dobaviane na novi koli\n";
         cout << "    2. Promqna na danni za kola w okaziona\n";
         cout << "    3. Iztrivane na kola ot okaziona\n";
         cout << "    4. Wrashtane kam glawnoto menu\n";
         cout << "    Molq wawedete svoq izbor: ";
         cin >> choise;
         if (choise>=1&&choise<=4) 
                switch(choise) {
                               case 1:{
                                    int novi; // novite avtomobili kojto shte se wawedat
                                    cout << "V momenta w okaziona ima " << n << " avtomobila\n"; 
                                    cout << "Vavedete broi na novite avtomobili za wawejdane w okaziona:"; cin >> novi;
                                    for (int i=n+1;i<=n+novi;i++) {
                                               cin.get();
                                               cout << "Vavedete marka na avtomobil nomer"<<i<<": "; cin.getline(cars[i].marka,50);
                                               cout << "Godina na proizwodstwo na awtomobila: "; cin >> cars[i].year;
                                               cout << "Cena: "; cin >> cars[i].price;
                                               }    
                                    cout << "Novite " << novi << " avtomovila sa dobaveni w okaziona\n";
                                    n=n+novi;
                                    cout << "W okaziona weche ima " << n << " avtomovila\n";
                                    break; }
                               case 2:{
                                    int change;
                                    cout << "Molq wawedete nomer na kolata koqto iskate da promenite: "; cin >> change;
                                    cin.get();
                                    cout << "Vavedete marka na kola N" << change << ": "; cin.getline(cars[change].marka,50);
                                    cout << "Godina na proizwodstwo: "; cin >> cars[change].year;
                                    cout << "Cena: "; cin >> cars[change].price; 
                                    break;
                                    }
                               case 3:{
                                    int del;
                                    cout << "Wawedete nomer na kola koqto izkate da iztriete ot okaziona: "; cin >> del;
                                    for (int i=del;i<=n;i++) { // razmenqne na mestata na kolite w masiwa sled iztritiq s edin nagore
                                        cars[i]=cars[i+1];
                                    }
                                    cars[n]=cars[n+1]; // anulirane na posledniq
                                    n=n-1;  // sled iztriwaneto, n weche e s 1 po-malko
                                    break;
                                    }
                               }
         else cout << "Greshen izbor";
         } while(choise!=4);
}                              

void sort1() { 
          cout << "Spisak na avtomobilite po marka w azbuchen red:" << endl; 
           for (int i=1;i<=n;i++)   
            for (int j=1;j<=n-1;j++)
               if (strcmp(cars[j+1].marka,cars[j].marka)<0)  // sortirane po azbuchen red, chrez funkciqta strcmp i srawnqwane na stringowete
	      	      		{ buffer=cars[j+1]; cars[j+1]=cars[j]; cars[j]=buffer; } // izpolwane na buffer za da se naprawi razmqnata 
           for (int i=1;i<=n;i++) { // izkarwane na modelite 
               cout << cars[i].marka << endl;;
               }
}
void sort2() { 
     for (int i=1;i<=n;i++)   
         for (int j=1;j<=n-1;j++)
             if(cars[j+1].price<cars[j].price) // sortirane po cena w vazhodqsht red
                    { buffer=cars[j+1]; cars[j+1]=cars[j]; cars[j]=buffer; } 
     cout << "Spisak na kolite sortirani po cena za edin broi\n";
     cout << setw(2) << "ID" << setw(15) << "Marka" << setw(20) << "God. na proizv." << setw(15) << "Cena" << endl;
     for (int i=1;i<=n;i++) {
          cout << setw(2) << i << setw(15) << cars[i].marka << setw(20) << cars[i].year << setw(15) << cars[i].price << endl;
          }
}

