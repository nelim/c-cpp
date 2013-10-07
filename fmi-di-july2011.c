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
	printf("Ден: ");
	scanf("%d", &flight->day);
	printf("Месец: ");
	scanf("%d", &flight->month);
	printf("Година: ");
	scanf("%d", &flight->year);
};

void getFlight(struct flights *flight) {
         printf("%d.%d.%d. %s %s %d eur.\n", newflight[i].day, newflight[i].month, newflight[i].year, newflight[i].destination, newflight[i].company, newflight[i].price);
};


int main(void) {
	struct flights flight[500],tempflight;
	struct maxflights maxflight[500]; // двумерен масив за броене на компаниите

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
	for(i=0;i<n;i++) {
		for(j=0;j<n-1;j++) {
			if(strcmp(flight[j].destination,flight[j+1].destination)>0) {
				tempflight=flight[j]; flight[j]=flight[j+1]; flight[j+1]=tempflight;
			}
		}
	}

	printf("Сортирани по азбучен ред полети: \n");
        for(i=0;i<n;i++) {
                getFlight(&flight[i]);
        }

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

	for(i=0;i<nn;i++) {
		printf("%d.%d.%d. %s %s %d eur.\n", newflight[i].day, newflight[i].month, newflight[i].year, newflight[i].destination, newflight[i].company, newflight[i].price);
	}

return 0;
};

