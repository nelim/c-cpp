// --------------------------------------//
// Uprajnenie 10 oct 2011                //
// chisto C                              //
// @author nelim                         //
// --------------------------------------//

#include <stdio.h>
#include <string.h>

int n; // broi na avtobusnite linii 

struct date {
	unsigned int day,month,year;
};

struct time {
	unsigned int hour,min;
};

struct buslines {
	char start_point[30];
	int  price;
	int  promo_price;
	struct date date;
	struct time time;
	char company[20];
};

void enterBus(struct buslines *busline, int i) {

	printf("Въведете начална точка за автобусна линия номер %d:", i);
	scanf("%s", &busline->start_point);
	//fgets(busline->start_point, sizeof busline->start_point, stdin);

	printf("Въведете цена за автобусна линия номер %d:", i);
	scanf("%d", &busline->price);
	printf("Въведете преференциална цена за автобусна линия номер %d:", i);
	scanf("%d", &busline->promo_price);
		// wywejdane na data
		do {
			printf("Въведете ден за автобусна линия номер %d:", i);
			scanf("%d", &busline->date.day);
		} while (busline->date.day > 31);
		do {
			printf("Въведете месец за автобусна линия номер %d:", i);
			scanf("%d", &busline->date.month);
		} while (busline->date.month > 12);
		do {
			printf("Въведете година за автобусна линия номер %d:", i);
			scanf("%d", &busline->date.year);
		} while (busline->date.month > 2012);

		// wywejdane na chasa
		do {
			printf("Въведете час за автобусна линия номер %d:", i);
			scanf("%d", &busline->time.hour);
		} while (busline->time.hour > 24);
		do {
			printf("Въведете минути за автобусна линия номер %d:", i);
			scanf("%d", &busline->time.min);
		} while (busline->time.min > 60);

	printf("Въведете компания за автобусна линия номер %d:", i);
	scanf("%s", &busline->company);
}


int main(void) {
	do {
		printf("Въведете брои на линии (макс. 1000): ");
		scanf("%d", &n);
	} while (n<1 || n>1000);


	printf("N= %d\n", n);
	struct buslines busline[n]; // syzdawane na obektite

	int i; // cikyl
		for(i=0;i<n;i++) {
			enterBus(&busline[i],i);
		}

	for(i=0;i<n;i++) {
	printf("Начална точка за автобус номер %d e %s\n", i, busline[i].start_point);
	printf("Компанията на автобус номер %d e %s\n", i, busline[i].company);
	printf("Дата за автобус номер %d e %d.%d.%d\n", i, busline[i].date.day, busline[i].date.month, busline[i].date.year);
	printf("Час за автобус номер %d e %d:%d\n", i, busline[i].time.hour, busline[i].time.min);
	}


return 0;
}