// DI 05July2011
// @author nelim

#include <stdio.h>

#define FL_MAX_LEN 30
#define COMP_MAX_LEN 20
#define MAX_FLIGHTS 500;

int n; // broq bileti

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

void addFlight(struct flights *flight) {
	printf("Въведете дестинация: ");
	scanf("%s", &flight->destination);
};

void getFlight(struct flights *flight) {
	printf("дестинация: %s\n", flight->destination);
};


int main(void) {
	struct flights flight[500],tempflight;
	int i,j; //loops
	do {
	printf("Въведете брой полети: ");
	scanf("%d", &n);
	} while (n<1 || n>500);

	for(i=0;i<n;i++) {
		addFlight(&flight[i]);
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

