#include <bits/stdc++.h>
#define MAXWOKER 25

//函数声明放这里
void testsex();
void firstchecker();
void graphmain();
void firstinput(FILE *p,int n);
void findinfo_String(int i,char info[]);
void outputinfo(int n,int i);
void addinfo(FILE *p,int n);
void graphworker();
void deleteworker();

// 全局变量放在这里
int count = 0;
char s[20];
FILE *p=fopen("misinfo.dat", "a+b");
char info[50];  //info字符串用于使用中查找


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
	char wkphonenumber[20];
	char wkemail[20];
	double wksalary;
	char BMJJ[200];
}someworker[MAXWOKER];
//声明25个够用了，实际使用可以修改
//
const int size=sizeof(struct workerinfo);
//

	
/********************************************************************main
**********************************************************************/

int main(int argc, char *argv[]) {
	memset(info, 0, 50*sizeof(char));
	rewind(p);
	firstchecker();
	//从文件中读数据到结构体变量
	while(fread(&someworker[count], size, 1, p)==1)
	{
		count++;
	}
	//并计数员工数
	//findinfo_String(1);
	graphmain();
	return 0;
}

/************************* main函数到此结束
******************************************/

void firstchecker() //检查数据文件是否为空，为空选择是否输入
{
	FILE *p=fopen("misinfo.dat", "a+b");
		rewind(p); //重新定位到文件开头
		if(fread(&someworker[0], size,1, p)==0)
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
	rewind(p);
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
	std::cout<<"---            4.删除员工                              \n";
	std::cout<<"---            5.工资信息                              \n";
	std::cout<<"---            6.退出系统                              \n";
		std::cout<<"---------------------------------------------------------\n";
	std::cout<<"---------------------------------------------------------\n";
	std::cout<<"\n";
	std::cout<<"请选择：";
	std::cin>>choose;
	switch(choose){
		case 1:break;
		case 2:break;
		case 3:graphworker();break;
		case 4:deleteworker();;break;
		case 5:;break;
		case 6:{fclose(p);exit(0);}break;
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


void outputinfo(int i,int n) //i为第几个员工、n为第几项信息
{
	switch(n)
	{
		
			case 1:{
				std::cout<<"工号:";
				puts(someworker[i].wkid);}
				break;
			case 2:{
				std::cout<<"姓名:";
				puts(someworker[i].wkname);}break;
			case 3:{
				std::cout<<"性别:";
				if(someworker[i].wksex==0)
				std::cout<<"男\n";
				else 
				std::cout<<"女\n";
			}
			break;
			case 4:
				{
					std::cout<<"生日:";
					puts(someworker[i].wkbirth);
				}break;
			case 5:
				{
					std::cout<<"入职时间:";
					puts(someworker[i].fstdate);}break;
			case 6:{
				std::cout<<"部门编号:";
				std::cout<<someworker[i].wkBMnum<<"\n";}break;
			case 7 :{
				std::cout<<"部门名称:";
				puts(someworker[i].wkBM);}
			 break;
			case 8:{
				std::cout<<"岗位编号(等级):";
				std::cout<<someworker[i].wkGWnum<<"\n";}
			break;
			case 9:{
				std::cout<<"岗位名称:";
				puts(someworker[i].wkGW);}break;
			case 10:{
				std::cout<<"员工地址:";
				puts(someworker[i].wkaddress);}
			break;
			case 11:{
				std::cout<<"电话号码:";
				std::cout<<someworker[i].wkphonenumber<<"\n";} break;
			case 12:{
				std::cout<<"电子邮箱:";
				puts(someworker[i].wkemail);}break;
	}
				
	
}
//用于查找[字符串]型数据
//按结构体创建时的数据顺序对数据编号,
//i为编号，如查找wkid ，则使用findinfo_String(1,info)
void findinfo_String(int i,char info[]) 
{
	rewind(p);
	int count4= 0;
	while(fread(&someworker[count4], size, 1, p)==1)
		{
			if(someworker[count4].wkid[0]!='#')
			count4++;
		}
	switch(i)				
	{
		case 1:{
		for(int i2=0;i2<count4;i2++)
		{
			if(strcmp(info,someworker[i2].wkid)==0)
			{
				std::cout<<info<<"---"<<someworker[i2].wkname<<"\n";
			std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";			
			}
		} 
		}break;
		case 2:	{
		for(int i2=0;i2<count4;i2++)
		{
			if(strcmp(info,someworker[i].wkname)==0)
			{
				std::cout<<someworker[i].wkname<<"\n";
				std::cout<<"该员工工号："<<someworker[i].wkid<<"\n";
				std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";
			}
		}
		}break;
		case 4:{
			
			for(int i2=0;i2<count4;i2++)
			{
				if(strcmp(info,someworker[i].wkbirth)==0)
				{
					std::cout<<"找到生日为："<<info<<"的职工\n";
					std::cout<<someworker[i].wkname<<"\n";
					std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";
				}
			}
		}break;
			case 5:{
				for(int i2=0;i2<count4;i2++)
				{
					if(strcmp(info,someworker[i].fstdate)==0)
					{
						std::cout<<"找到入职时间为:"<<info<<"的员工\n";
						std::cout<<someworker[i].wkname<<"\n";
						std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";
					}
				}
			}break;
				case 7:
					{
					std::cout<<"部门："<<info<<"\n";
					for(int i2=0;i2<count4;i2++)
					{
						if(strcmp(info,someworker[i].wkBM)==0)
						{
							std::cout<<"员工名称："<<someworker[i].wkname<<"\n";
						std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";	
						}
					}
					}break;
				case 9:
					{
					std::cout<<"岗位："<<info<<std::endl;
					for(int i2=0;i2<count4;i2++)
					{
						if(strcmp(info, someworker[i].wkGW)==0)
						{
							
							std::cout<<someworker[i].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";	
						}
					}
				}break;
				case 10:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(strcmp(info, someworker[i].wkaddress)==0)
						{
							
							std::cout<<someworker[i].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";	
						}
					}
					}break;
				case 11:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(strcmp(info, someworker[i].wkphonenumber)==0)
						{
							
							std::cout<<someworker[i].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";	
						}
						}
					}break;
				case 12:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(strcmp(info, someworker[i].wkemail)==0)
						{
							std::cout<<info<<std::endl;
							std::cout<<someworker[i].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";
						}		
					}break;
					}
				}
}


	void addinfo(FILE *p,int n)
	{
		rewind(p);
		int count3= 0 ;
		while(fread(&someworker[count3], size, 1, p)==1)
			{
				count3++;
			}

		for(int i=count3;i<n+count3;i++)
		{
			std::cout<<"请输入工作证ID:(可包含数字以外的字符)：";
			memset(someworker[i].wkid,0,20*sizeof(char));
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
		rewind(p);
		for (int i=count3;i<n+count3;i++) {
			fwrite(&someworker[i], size, 1, p);
		}
		

	}
	


void graphworker()
{
	std::cout<<"------------------------- 员工基本信息  ----------------------------\n";
	int count2 = 0;
	rewind(p);
	while(fread(&someworker[count2], size, 1, p)==1)
		{
			if(someworker[count2].wkid[0]!='#')
			count2++;
		}
	std::cout<<"目前有"<<count2<<"个员工\n";
	std::cout<<"---                   1.增加员工信息\n";
	std::cout<<"---                   2.浏览全部员工信息\n";
	std::cout<<"---                   0.退出到上一层\n";
	std::cout<<"------------------------------------------------------------------\n";
	int choose;
	std::cin>>choose;
	switch (choose) {
		case 1:{
			std::cout<<"请输入需要增加的员工数:";
			int n; std::cin>>n;
			addinfo(p, n);
		}break;
		case 0:{
			graphmain();
		}break;
		case 2:{
			for(int i=0;i<count2;i++)
			{
				if(someworker[i].wkid[0] == '#') continue;
				std::cout<<"--------"<<i<<"--------\n";
				for(int i2=1;i2<=12;i2++)
				{
				outputinfo(i, i2);
				}
			}
		}break;	
	} 
	graphworker();
}

void deleteworker()
{
	memset(info, 0, 50*sizeof(char));
	std::cin>>info;
	rewind(p);
		int count4= 0;
		while(fread(&someworker[count4], size, 1, p)==1)
			{
				if(someworker[count4].wkid[0]!='#')
				count4++;
			}
			rewind(p);
			int findyes = 0;
			for(int i2=0;i2<count4;i2++)
			{
				if(strcmp(info,someworker[i2].wkid)==0)
				{
		std::cout<<info<<"---"<<someworker[i2].wkname<<"\n";
				std::cout<<"该员工位于数据数组中的:"<<i2<<"\n";
				someworker[i2].wkid[0] = '#';
				findyes = 1;
				}
			}
			if(findyes == 0) std::cout<<"未找到工号为"<<info<<"的员工!\n";
			else std::cout<<"删除成功!\n";
			fclose(p);
			p = fopen("misinfo.dat", "wb+");
			rewind(p);
		for(int i=0;i<count4;i++)
		{
			fwrite(&someworker[i], size, 1, p);
		}
		fclose(p);
		p = fopen("misinfo.dat","a+b");
		graphmain();
				
}
