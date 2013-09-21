#include <iostream.h>
#include <iomanip.h> //setwidth function

// Programa za obslujwane na ski-sastezateli - Zaprian Bogunski

int n; //  broi na sastezatelite
struct {
       int nomer;
       char name[50];
       double postijenie;
       char darjava[25];
       } sastezatel[50],sort;

double srednovreme; // globalna promenliva za srednoto wreme

void vavejdane();
void spisak1();
void spisak2();
void spisak3();
void spisak4();

int main() {
    cout << "Programa za obslujwane na ski sastezateli\n";
    vavejdane();
    
    cout << "Dannite sa vavedeni molq izberete spisak ot menuto" << endl;
    int menu; // promenliva za izbor w menuto
    do {
        cout << "1. Spisak na vsichki sastezateli s vavedenite danni za tqh" << endl;
        cout << "2. Spisak po postijeniq" << endl;
        cout << "3. Izvejdane na sredno vreme za sastezatelite" << endl;
        cout << "4. Spisak na sastezatelite ot dadena darjava, s postijenie po-dobro ot srednoto za sastezanieto" << endl;
        cout << "5. Izhod" << endl;
        cout << "Molq izberete <1-5>: ";
        cin >> menu;
        if (menu<=5&&menu>=1) 
            switch (menu) {
                   case 1:spisak1();
                   case 2:spisak2();break;
                   case 3:spisak3();break;
                   case 4:spisak4();break;
                   case 5:cout << "Izhod";break;
                   }
        else 
             cout << "Greshen izbor ot menuto\n";
                   
        } while (menu!=5);
}

void vavejdane() {
     cout << "Vavedete broi na systezatelite: "; cin >> n;
     for (int i=1;i<=n;i++) {
         cout << "Vavedete nomer na sastezatel N." << i << ": "; cin >> sastezatel[i].nomer;  
         cin.get();
         cout << "Ime na sastezatelq: "; cin.getline(sastezatel[i].name,50);
         cout << "Postijenie na sastezatelq: "; cin >> sastezatel[i].postijenie;
         cin.get();
         cout << "Darjava: "; cin.getline(sastezatel[i].darjava,25);
         }
         cout << "Press Enter to continue...";
         getchar();
     }
void spisak1() {
     cout << endl;
     cout << "Spisak na sastezatelite\n";
     cout << setw(3) << "ID" 
          << setw(6) << "Nomer" 
          << setw(25) << "Ime na sastezatelq" 
          << setw(11) << "Postijenie" 
          << setw(15) << "Darjava" 
          << endl; 
     for (int i=1;i<=n;i++) {
         cout << setw(3) << i 
              << setw(6) << sastezatel[i].nomer 
              << setw(25) << sastezatel[i].name 
              << setw(11) << sastezatel[i].postijenie 
              << setw(15) << sastezatel[i].darjava
              << endl;    
         }
     cout << endl;
     }
void spisak2() {
     cout << endl;
     cout << "Spisak na sastezatelite po postijenie w nizhodqsht red:" << endl; 
          for (int i=1;i<=n;i++)   
            for (int j=1;j<=n-1;j++) {
                if (sastezatel[j+1].postijenie>sastezatel[j].postijenie) // sortirane po postijenie
                   { sort=sastezatel[j+1]; sastezatel[j+1]=sastezatel[j]; sastezatel[j]=sort; }
                if (sastezatel[j+1].postijenie==sastezatel[j].postijenie&&strcmp(sastezatel[j+1].name,sastezatel[j].name)<0)  // sortirane po azbuchen red, chrez funkciqta strcmp i srawnqwane na stringowete
   	      		   { sort=sastezatel[j+1]; sastezatel[j+1]=sastezatel[j]; sastezatel[j]=sort; } // izpolwane na sort za da se naprawi razmqnata 
               }
           for (int i=1;i<=n;i++) { // izkarwane na sastezatelite 
               cout << setw(3) << i
               << setw(6) << sastezatel[i].nomer 
               << setw(25) << sastezatel[i].name
               << setw(11) << sastezatel[i].postijenie 
               << endl;
               }
     cout << endl;
     }
void spisak3() {
     cout << endl << "Sredno vreme za sastezatelite: ";
     double totaltime=0.00;
     for (int i=1;i<=n;i++) {
         totaltime=totaltime+sastezatel[i].postijenie;
         }
     srednovreme=totaltime/n;
     cout << srednovreme << endl << endl;
     }
void spisak4() {
     cout << endl;
     char darjava_izbor[25];
     cin.get();
     cout << "Vavedete darjava: \n"; cin.getline(darjava_izbor,25);
     cout << "Darjava: " << darjava_izbor << endl;
     cout << setw(5) << "Nomer"
          << setw(25) << "Ime"
          << setw(11) << "Postijenie"
          << endl;
     int found=0;
     for (int i=1;i<=n;i++)
         if (strcmp(sastezatel[i].darjava,darjava_izbor)==0&&sastezatel[i].postijenie>srednovreme) 
            {  found=found+1;
               cout << setw(5) << sastezatel[i].nomer
                    << setw(25) << sastezatel[i].name
                    << setw(11) << sastezatel[i].postijenie
                    << endl;
                    }
               if (found==0) cout << "Nqma namereni sastezateli ot " << darjava_izbor \
               << " s vreme po-dobro ot srednoto: " << srednovreme << endl;
                                                                                     
     cout << endl;
     }

