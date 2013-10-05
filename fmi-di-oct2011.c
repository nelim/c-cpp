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

float avg_promo_price(struct buslines busline[], char company[20]) {
	int i, count = 0, price = 0;
        for (i=0;i<n;i++) {
                if(strcmp(busline[i].company,company)==0) {
                        price += busline[i].promo_price;
                        count++;
                }
        }
        return (float)price/count;
}

void enterBusLine(struct buslines *busline, int i) {

	printf("Въведете начална точка за автобусна линия номер %d:", i);
	scanf("%s", &busline->start_point);
	//fgets(busline->start_point, sizeof busline->start_point, stdin);

	printf("Въведете цена за автобусна линия номер %d:", i);
	scanf("%d", &busline->price);
	printf("Въведете преференциална цена за автобусна линия номер %d:", i);
	scanf("%d", &busline->promo_price);

	/* Коментирам ги за да мога по-лесно да тествам
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

	*/
	printf("Въведете компания за автобусна линия номер %d:", i);
	scanf("%s", &busline->company);
}

void printBusLine(struct buslines *busline, int i) {
	printf("Автобус %d: направление: %s, цена: %d, промо: %d, компания: %s\n", 
	i, busline->start_point, busline->price, busline->promo_price, busline->company); 
	// за по лесно тестване
	//printf("Дата за автобус номер %d e %d.%d.%d\n", i, busline->date.day, busline->date.month, busline->date.year);
	//printf("Час за автобус номер %d e %d:%d\n", i, busline->time.hour, busline->time.min);
}

void sortBusLinesPrice(struct buslines busline[], int n) {
	int i,j;
	struct buslines temp;
	for(i=0;i<n;i++) {
		for(j=0;j<n-1;j++) {
			if(busline[j].price>busline[j+1].price) {
				temp=busline[j+1]; busline[j+1]=busline[j]; busline[j]=temp;
			}
		}
	}
}

int cmpByStartPoint(struct  buslines busline1, struct buslines busline2) {
    return strcmp(busline1.start_point, busline2.start_point);
}

void sortBusLinesNameDate(struct buslines busline[], int n) {
	int i,j;
	struct buslines temp;
	for(i=0;i<n;i++) {
		for(j=0;j<n-1;j++) {
			if(cmpByStartPoint(busline[j],busline[j+1])>0) {
				temp=busline[j+1]; busline[j+1]=busline[j]; busline[j]=temp;
			}
			   else if((cmpByStartPoint(busline[j],busline[j+1])==0)&&(busline[j].date.year>busline[j+1].date.year)) {
			 	temp=busline[j+1]; busline[j+1]=busline[j]; busline[j]=temp;
			  } else if((cmpByStartPoint(busline[j],busline[j+1])==0)&&(busline[j].date.year == busline[j+1].date.year)&&(busline[j].date.month>busline[j+1].date.month)) {
				temp=busline[j+1]; busline[j+1]=busline[j]; busline[j]=temp;
			  } else if((cmpByStartPoint(busline[j],busline[j+1])==0)&&(busline[j].date.month == busline[j+1].date.month) && (busline[j].date.day>busline[j+1].date.day)) {
				temp=busline[j+1]; busline[j+1]=busline[j]; busline[j]=temp;
			}
		}
	}
}


int main(void) {
	do {
		printf("Въведете брои на линии (макс. 1000): ");
		scanf("%d", &n);
	} while (n<1 || n>1000);

	struct buslines busline[n]; // syzdawane na obektite

	int i; // cikyl

	// Input
	for(i=0;i<n;i++) {
		enterBusLine(&busline[i],i);
	}

	// sort whole array by price
	sortBusLinesPrice(busline,n);

	// Output
	for(i=0;i<n;i++) {
		printBusLine(&busline[i],i);
	}

        // sort whole array by name and date
        //sortBusLinesNameDate(busline,n);

	float hebros_avg = avg_promo_price(busline, "hebros");
	printf("Средна промоционална цена за автобусите на ХебросБус е %f \n", hebros_avg);

return 0;
}
