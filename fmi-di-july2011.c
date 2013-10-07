// DI 05July2011
// @author nelim

#include <stdio.h>

#define FL_MAX_LEN 30
#define COMP_MAX_LEN 20
#define MAX_FLIGHTS 500;

int n; // broq poleti

struct date {
	int day, month, year;
};

struct flights {
	char destination[FL_MAX_LEN];
	int price;
	int promo_price;
	struct date date;
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
	scanf("%s", (char*)&flight->destination);
};

void getFlight(struct flights *flight) {
	printf("дестинация: %s\n", flight->destination);
};


int main(void) {
	struct flights flight[500],tempflight;
	struct maxflights maxflight[500]; // dvumeren masiv za broene na kompaniite ot kompaniite

	int k = 0; // broi wywedeni kompanii
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
		for(j=0;j<k;j++)
			if(strcmp(flight[i].company,maxflight[j].company)==0) {
				maxflight[j].count++;
				found = 1;
				break;
			}
		if(found==0) {
			k++; // increase-wame k s edno i prawim zapis za posledniq
			maxflight[k].company=(char[20])flight[i].company;
			maxflight[k].count=1;
		}
	}

	for(i=0;i<n;i++) {
		getFlight(&flight[i]);
	}


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

return 0;
};

