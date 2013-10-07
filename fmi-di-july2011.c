// DI 05July2011
// @author nelim

#include <stdio.h>
#include <string.h>

#define FL_MAX_LEN 30
#define COMP_MAX_LEN 20
#define MAX_FLIGHTS 500;

int n; // broq poleti

struct flights {
	char destination[FL_MAX_LEN];
	int price;
	int promo_price;
	int day,month,year;
	char company[COMP_MAX_LEN];
};

struct maxflights {
	char company[COMP_MAX_LEN];
	int count;
};

void addFlight(struct flights *flight) {
	printf("Дестинация: ");
	scanf("%s", (char*)&flight->destination);
	printf("Компания: ");
	scanf("%s", (char*)&flight->company);
	printf("Цена: ");
	scanf("%d", &flight->price);
	printf("Промо Цена: ");
	scanf("%d", &flight->promo_price);
	printf("Ден: ");
	scanf("%d", &flight->day);
	printf("Месец: ");
	scanf("%d", &flight->month);
	printf("Година: ");
	scanf("%d", &flight->year);
};

void getFlight(struct flights *flight) {
         printf("%d.%d.%d. %s %s %d eur. promo: %d eur.\n", flight->day, flight->month, flight->year, flight->destination, flight->company, flight->price, flight->promo_price);
};


int main(void) {
	struct flights flight[500],tempflight;
	struct maxflights maxflight[500],tempmax; // двумерен масив за броене на компаниите

	int k = 0; // броя въведени компании
	int i,j; //loops
	int found = 0;
	do {
	printf("Въведете брой полети: ");
	scanf("%d", &n);
	} while (n<1 || n>500);

	for(i=0;i<n;i++) {
		addFlight(&flight[i]);

		// sled wywejdane na noviq polet, pretyrswame masiva s kompaniite i wijdame ima li wywedeni poleti za tazi kompaniq
		// ako ima - increase-wame count-a s edno
		// ako nqma namereni, dobawqme nov i increase-wame k;
		for(j=0;j<k;j++) {
			if(strcmp(flight[i].company,maxflight[j].company)==0) {
				maxflight[j].count++;
				found = 1;
				break;
			}
		}
		if(k==0||(found==0&&k>0)) {
			strcpy(maxflight[k].company,flight[i].company);
			maxflight[k].count=1;
			k++; //increase-wame k s 1
		}
		found = 0; //zanulqwame found
	}


	// т.1 печатаме цялата информация въведена за полетите
	for(i=0;i<n;i++) {
		getFlight(&flight[i]);
	}

	// т.2 сортиране на масива с полетите по име на дестинация
	int total_promo_price = 0; // сума на всички промо цени
	for(i=0;i<n;i++) {
		for(j=0;j<n-1;j++) {
			if(strcmp(flight[j].destination,flight[j+1].destination)>0) {
				tempflight=flight[j]; flight[j]=flight[j+1]; flight[j+1]=tempflight;
			}
		}
		total_promo_price += flight[i].promo_price;
	}

	printf("Сортирани по азбучен ред полети: \n");
        for(i=0;i<n;i++) {
                getFlight(&flight[i]);
        }

        printf("Средна промо цена: %d / %d \n", total_promo_price, n);
	printf("%3.2lf\n", (float)total_promo_price/n);

	// т.3 списък на полетите до Париж и Лондон от 08.2011 подредени по дата на полета
	struct flights newflight[500];
	int nn=0;
	for(i=0;i<n;i++) {
		if( (strcmp(flight[i].destination,"parij")==0 || strcmp(flight[i].destination,"london")==0)
		&& ((flight[i].month==8) && (flight[i].year==2011)) ) {
			newflight[nn]=flight[i]; nn++;
		}
	}

	// сортиране на полетите до париж и лондон от август 2011
	for(i=0;i<nn;i++) {
		for(j=0;j<nn-1;j++) {
			if(newflight[j].day>newflight[j+1].day) {
				tempflight=newflight[j]; newflight[j]=newflight[j+1]; newflight[j+1]=tempflight;
			}
		}
	}
	printf("Сортирани по дата полети от август месец за Париж и Лондон\n");

	// печатаме по заложения от условието начин
	for(i=0;i<nn;i++) {
		printf("%d.%d.%d. %s %s %d eur.\n", newflight[i].day, newflight[i].month, newflight[i].year, newflight[i].destination, newflight[i].company, newflight[i].price);
	}

	// т.4 Авиокомпанията с най-много полети и средната отстъпка за тях + 3-те най ниски цени и тяхните направления
	// от самото въвеждане на полетите имаме масив с големина k, в който имаме запис за всяка компания и колко полета има, сортираме го така че в 0-левия запис да стане тази с най-много полети
	for(i=0;i<k;i++) {
		for(j=0;j<k-1;j++)
			if(maxflight[j].count<maxflight[j+1].count) {
				tempmax=maxflight[j]; maxflight[j]=maxflight[j+1]; maxflight[j+1]=tempmax;
			}
	}

	// след като вече имаме компанията с най-много полети в maxflight[0].company претърсваме целия масив за компанията и вадим отстъпката за всеки полет
	int avg_promo = 0;
	for(i=0;i<n;i++) {
		if(strcmp(flight[i].company,maxflight[0].company)==0) {
			avg_promo += (flight[i].price-flight[i].promo_price);
		}
	}
	// делим на полетите за компанията и вадим средна отстъпка 
	printf("Средна отстъпка за полетите на %s e %3.2lf\n", maxflight[0].company, (float)avg_promo/maxflight[0].count);

	// т.4.2
	// сортираме целия масив по промо цените в възходящ ред
        for(i=0;i<n;i++) {
                for(j=0;j<n-1;j++) {
                        if(flight[j].promo_price>flight[j+1].promo_price) {
                                tempflight=flight[j]; flight[j]=flight[j+1]; flight[j+1]=tempflight;
                        }
                }
        }

	// и вадим първите 3 резултата
        printf("Трите полета с най-ниска промо цена\n");
        for(i=0;i<3;i++) {
                getFlight(&flight[i]);
        }

return 0;
};

