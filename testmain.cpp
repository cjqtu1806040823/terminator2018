#include <bits/stdc++.h>
#define MAXWOKER 25
void firstchecker();
void graphmain();
void firstinput(FILE *p,int n);

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


	
/********************************************************************main
**********************************************************************/

int main(int argc, char *argv[]) {
	FILE *p=fopen("misinfo.dat", "a+b");
	rewind(p);
	firstchecker();
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

/************************* main函数到此结束
******************************************/

void firstchecker() //检查数据文件是否为空，为空选择是否输入
{
	FILE *p=fopen("misinfo.dat", "a+b");
		rewind(p); //重新定位到文件开头
		if(fread(&someworker[count], size,1, p)==0)
		{
			std::cout<<"目前数据信息为空，是否输入信息(Y/N):";
			char fstc;
			fstc = getchar();
			if(fstc == 'Y')
			{
				int somenum;
			std::cout<<"请输入即将输入的员工信息数：";
			std::cin>>somenum;
			firstinput(p,somenum);
			exit(0);
			}
			else if(fstc == 'N')
			exit(0);
			else std::cout<<"输入错误！下次注意，再见\n";
		}
		rewind(p);
}

void firstinput(FILE *p,int n)
{
	rewind(p);
	for(int i=0;i<n;i++)
	{
		//std::cin>>someworker[i].wkid;
		std::cin>>someworker[i].wkname;
		/*std::cin>>someworker[i].wksex;
		std::cin>>someworker[i].wkbirth;
		std::cin>>someworker[i].fstdate;
		std::cin>>someworker[i].wkBMnum;
		std::cin>>someworker[i].wkBM;
		std::cin>>someworker[i].wkGWnum;
		std::cin>>someworker[i].wkGW;
		std::cin>>someworker[i].wkaddress;
		std::cin>>someworker[i].wkphonenumber;
		std::cin>>someworker[i].wkemail;*/
	}
	for (int i=0;i<n;i++) {
		fwrite(&someworker[i], size, 1, p);
	}
}

void graphmain()
{
	int choose;
	std::cout<<"---------------------------------------------------------\n";
	std::cout<<"---------------------------------------------------------\n";
	std::cout<<"---            简 易 工 资 管 理 系 统 v1.0 release     \n";
	std::cout<<"---            1.部门信息                              \n";
	std::cout<<"---            2.岗位信息及分级                         \n";
	std::cout<<"---            3.员工基本信息                           \n";
	std::cout<<"---            4.工资信息                              \n";
	std::cout<<"---            5.退出系统                              \n";
	std::cout<<"---            6.联系制作团队                    \n";
	std::cout<<"---------------------------------------------------------\n";
	std::cout<<"---------------------------------------------------------\n";
	std::cout<<"\n";
	std::cout<<"请选择：";
	std::cin>>choose;
	switch(choose){
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		case 5:break;
		case 6:break;
		default:std::cout<<"您输入了错误的选项，您的意思是退出？Y|N:";
				char a; std::cin>>a;
				while(a!='Y'&&a!='N')
				{
					std::cout<<"您输入了错误的选项，您的意思是退出？Y|N:";
					std::cin>>a;
				}
				if(a=='Y') exit(0);
				if(a=='N') graphmain();

	}
}
void makerinfo()
{
	std::cout<<"---            QQ群:861692730\n"<<std::endl;
}



