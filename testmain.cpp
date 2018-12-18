#include <bits/stdc++.h>
#define MAXWOKER 25

//函数声明放这里
void  testsex();
void firstchecker();
void graphmain();
void firstinput(FILE *p,int n);
// 全局变量放在这里
int count = 0;
char s[20]; 

//结构体信息
struct workerinfo {
	char wkid[20];
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
//声明25个够用了，实际使用可以修改
//
const int size=sizeof(struct workerinfo);
//

	
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
		puts(someworker[i].wkid);
		puts(someworker[i].wkname);
		std::cout<<someworker[i].wksex<<"\n";
		puts(someworker[i].wkbirth);
		puts(someworker[i].fstdate);
		std::cout<<someworker[i].wkBMnum<<"\n";
		puts(someworker[i].wkBM);
		std::cout<<someworker[i].wkGWnum<<"\n";
		puts(someworker[i].wkGW);
		puts(someworker[i].wkaddress);
		std::cout<<someworker[i].wkphonenumber<<"\n";
		puts(someworker[i].wkemail);
		std::cout<<"\n\n\n";			}
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
			else std::cout<<"输入错误！下次注意，再见\n [进程已结束]";
		}
		rewind(p);
}

void firstinput(FILE *p,int n)//第一次输入
{
	rewind(p);
	for(int i=0;i<n;i++)
	{
		std::cout<<"请输入工作证ID:(可包含数字以外的字符)：";
		std::cin>>someworker[i].wkid;
		std::cout<<"请输入姓名:(请使用拼音):";
		std::cin>>someworker[i].wkname;
		std::cout<<"请输入性别: 0(man)或1(female)：";
		std::cin>>someworker[i].wksex;
		if(someworker[i].wksex!=0&&someworker[i].wksex!=1){
				std::cout<<"输入错误！还有一次输入机会\n";
				std::cin>>someworker[i].wksex;
			}
		if(someworker[i].wksex!=0&&someworker[i].wksex!=1){
			std::cout<<"错误代码worker sex!\n[进程已结束]";
			exit(1);
		}	
		std::cout<<"请输入员工生日  年-月-日:";
		std::cin>>someworker[i].wkbirth;
		std::cout<<"请输入员工入职日期  年-月-日:";
		std::cin>>someworker[i].fstdate;
		std::cout<<"请输入员工部门编号:";
		std::cin>>someworker[i].wkBMnum;
		std::cout<<"请输入员工部门名称:";
		std::cin>>someworker[i].wkBM;
		std::cout<<"请输入员工岗位编号 (岗位编号代表岗位等级 由低到高 最低为1) : ";
		std::cin>>someworker[i].wkGWnum;
		std::cout<<"请输入员工岗位名称:";
		std::cin>>someworker[i].wkGW;
		std::cout<<"请输入员工家庭地址:";
		std::cin>>someworker[i].wkaddress;
		std::cout<<"请输入员工电话:";
		std::cin>>someworker[i].wkphonenumber;
		std::cout<<"请输入员工工作邮箱:";
		std::cin>>someworker[i].wkemail;
	}
	for (int i=0;i<n;i++) {
		fwrite(&someworker[i], size, 1, p);
	}
}

void graphmain()   //主要界面
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