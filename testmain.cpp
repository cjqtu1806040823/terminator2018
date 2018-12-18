#include <bits/stdc++.h>
#define MAXWOKER 25
int count = 0;
struct workerinfo {
	int wkid;
	char wkname[20];
	int wksex;
	char wkbirth[13];
	char fstdate[13];
	int wkBMnum;
	char wkBM[50];
	int wkGWnum;
	char wkGW[50];
	char wkaddress[50];
	int wkGWlevel;
	long long int wkphonenumber;
	char wkemail[20];
	double wksalary;
}someworker[MAXWOKER];
static int size=sizeof(struct workerinfo);


	

int main(int argc, char *argv[]) {
	FILE *p=fopen("misinfo.dat", "a+b");
	rewind(p);
	while(fread(&someworker[count], size, 1, p)==1)
	{
		count++;
	}
	for(int i=0;i<count;i++)
	{
		puts(someworker[i].wkname);
		printf("\n");
	}
	return 0;
}

