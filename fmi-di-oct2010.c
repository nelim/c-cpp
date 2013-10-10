#include <stdio.h>

#define NAME_MAX_LEN 60
#define UNI_MAX_LEN 30
#define TASKS 5

int n; // broi na studentite

struct students {
	int id;
	char name[NAME_MAX_LEN];
	char uni[UNI_MAX_LEN];
	int task[TASKS];
};

int total_points(struct students *student) {
	int temp;
	// sortirane 5-te zadachi po tochki
	int i,j;
	for(i=0;i<TASKS;i++) {
		for(j=0;j<TASKS-1;j++) {
			if(student->task[j]<student->task[j+1]) {
				temp=student->task[j]; student->task[j]=student->task[j+1]; student->task[j+1]=temp;
			}
		}
	}
	// sumirame samo tochkite ot pyrwite 3 rezultata (poslednite 2 sa naj-niski i gi ignorirame)
	int totalpoints=0;
	for(i=0;i<3;i++) {
	 	totalpoints += student->task[i];
	}
	return totalpoints;
}

int main(void) {

	int i,j; // deklarirane za cikli 
	struct students student[200],tempstu; // syzdawane na studentite

	// wywejdane broq na studentite
	do {
	printf("Broi studenti: ");
	scanf("%d", &n);
	} while (1>n>200);

	for(i=0;i<n;i++) {
		// po uslovie ne e qsno, towa ID shte se wywejdali ili shte e poreden nomer?
		// prawq go da e poreden nomer kato zapochwame ot 1;
		student[i].id  = i+1;
		printf("Ime: "); 		scanf("\n%[^\n]s", (char*)&student[i].name);
		printf("Univeristet: ");	scanf("\n%[^\n]s", (char*)&student[i].uni);
		for(j=0;j<5;j++) {
			do {
				printf("Tochki zadacha %d: ", j+1); scanf("%d", &student[i].task[j]);
			} while (0>student[i].task[j]>100);
		}
	}

	// tochka 2
	// Sortirame wsichki po obsht broi tochki w nizhodqsht red, ako sa ravni po ime
        for(i=0;i<n;i++) {
		for(j=0;j<n-1;j++) {
			if(total_points(&student[j])<total_points(&student[j+1])) {
				tempstu=student[j]; student[j]=student[j+1]; student[j+1]=tempstu;
			}
			else if ((total_points(&student[j])==total_points(&student[j+1]))&&(strcmp(student[j].name, student[j+1].name)>0)) {
				tempstu=student[j]; student[j]=student[j+1]; student[j+1]=tempstu;
			}
		}
	}

	// pechatame sortiranite + smqtame obshtiq broi tochki na PU (za tochka 3)
	int totalpu = 0;
	int totalpucnt = 0;
        for(i=0;i<n;i++) {
		printf("%s, %s, -> %d\n", student[i].name,student[i].uni, total_points(&student[i]));
		if(strcmp(student[i].uni,"PU\n")) { totalpu += total_points(&student[i]); totalpucnt++; }
	}

	// tochka 3
	// Sredniq broi tochki za wsichki studenti ot PU
	printf("Sreden broi tochki za studentite ot PU e %f\n", (float)totalpu/totalpucnt);



return 0;
};
