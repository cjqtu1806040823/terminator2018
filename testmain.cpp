#include <bits/stdc++.h>
#define MAXWOKER 25

//函数声明放这里
void testsex();
void firstchecker();
void graphmain();
void firstinput(FILE *p,int n);
int findinfo_String(int i,char info[]);
void outputinfo(int n,int i);
void addinfo(FILE *p,int n);
void graphworker();
void deleteworker();
void searchforinfo();
int  _strcmp(char a[],char b[]);
int readinfo();
void changeinfo();
void outputsalary();
void BMinfo();
void GWinfo();

// 全局变量放在这里
int count = 0;
//char s[20];
FILE *p=fopen("misinfo.dat", "a+b");
char info[50];  
//info字符串用于使用中查找



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
	double essential_salary;
	double GWsalary_level;
	char wkaddress[50];
	char wkphonenumber[20];
	char wkemail[20];
	double wksalary;
	double factsalary;
	double tax_rate;
	double extra_salary;
	char BMJJ[200];
	char GWZZ[200];
}someworker[MAXWOKER];
//声明25个够用了，实际使用可以修改
//
struct workerinfo countworker[MAXWOKER];
const int size=sizeof(struct workerinfo);
//

	
/********************************************************************main
**********************************************************************/

int main(int argc, char *argv[]) {
	memset(info, 0, 50*sizeof(char));
	rewind(p);
	firstchecker();
	//从文件中读数据到结构体变量
	readinfo();
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
		memset(someworker[i].wkid, 0, 20*sizeof(char));
		std::cin>>someworker[i].wkid;
		std::cout<<"请输入姓名:(请使用拼音):";
		memset(someworker[i].wkname, 0, 20*sizeof(char));
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
		memset(someworker[i].wkbirth, 0, 13*sizeof(char));
		std::cin>>someworker[i].wkbirth;
		std::cout<<"请输入员工入职日期  年-月-日:";
		memset(someworker[i].fstdate, 0, 13*sizeof(char));
		std::cin>>someworker[i].fstdate;
		std::cout<<"请输入员工部门编号:";
		std::cin>>someworker[i].wkBMnum;
		std::cout<<"请输入员工部门名称:";
		memset(someworker[i].wkBM, 0, 50*sizeof(char));
		std::cin>>someworker[i].wkBM;
		std::cout<<"请输入员工岗位编号 (岗位编号代表岗位等级 由低到高 最低为1) : ";
		std::cin>>someworker[i].wkGWnum;
		std::cout<<"请输入员工岗位名称:";
		memset(someworker[i].wkGW, 0, 50*sizeof(char));
		std::cin>>someworker[i].wkGW;
		std::cout<<"请输入岗位基本工资:";
		std::cin>>someworker[i].essential_salary;
		std::cout<<"请输入岗位工资系数:";
		std::cin>>someworker[i].GWsalary_level;
		std::cout<<"请输入个人税率:(如10%即输入0.1)";
		std::cin>>someworker[i].tax_rate;
		std::cout<<"请输入奖金和加班费的和:(额外工资)";
		std::cin>>someworker[i].extra_salary;
		std::cout<<"请输入员工家庭地址:";
		memset(someworker[i].wkaddress, 0, 50*sizeof(char));
		std::cin>>someworker[i].wkaddress;
		std::cout<<"请输入员工电话:";
		memset(someworker[i].wkphonenumber, 0, 20*sizeof(char));
		std::cin>>someworker[i].wkphonenumber;
		std::cout<<"请输入员工工作邮箱:";
		memset(someworker[i].wkemail, 0, 20*sizeof(char));
		std::cin>>someworker[i].wkemail;
		someworker[i].wksalary = someworker[i].essential_salary * someworker[i].GWsalary_level + someworker[i].extra_salary;
		someworker[i].factsalary = someworker[i].wksalary * (0.75 - someworker[i].tax_rate) - 2;
		std::cout<<"------------------------------\n";
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
		case 1:BMinfo();break;
		case 2:GWinfo();break;
		case 3:graphworker();break;
		case 4:deleteworker();;break;
		case 5:outputsalary();break;
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
				puts(someworker[i].wkid);
				}
				break;
			case 2:{
				std::cout<<"姓名:";
				puts(someworker[i].wkname);
			//std::cout<<strlen(someworker[i].wkname)<<"\n";
				}break;
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
			case 13:{
				std::cout<<"岗位基本工资:";
				std::cout<<someworker[i].essential_salary<<"\n";
			}break;
			case 14:{
				std::cout<<"岗位工资系数：";
				std::cout<<someworker[i].GWsalary_level<<"\n";
			}break;
			case 15:{
				std::cout<<"个人税率:"<<someworker[i].tax_rate<<"\n";
			}break;
			case 16:{
				std::cout<<"额外工资:"<<someworker[i].extra_salary<<"\n";
			}break;
			case 17:{
				std::cout<<"应发工资:"<<someworker[i].wksalary<<"\n";
				std::cout<<"实发工资:"<<someworker[i].factsalary<<"\n";
			}break;
	}
				
	
}
//用于查找[字符串]型数据
//按结构体创建时的数据顺序对数据编号,
//i为编号，如查找wkid ，则使用findinfo_String(1,info)
int findinfo_String(int i,char info[]) 
{
	int count4= count ;
	int found = 0;
	switch(i)				
	{
		case 1:{
		for(int i2=0;i2<count4;i2++)
		{
			if(strcmp(info,someworker[i2].wkid)==0)
			{
				std::cout<<info<<"---"<<someworker[i2].wkname<<"\n";
			std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
			std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";
			found = 1;
			return i2;		
			}
		} 
		if(found == 0) std::cout<<"未找到相应信息.\n";
		}break;
		case 2:	{
		for(int i2=0;i2<count4;i2++)
		{
//			std::cout<<_strcmp(info,someworker[i].wkname);
//			std::cout<<"\n"<<someworker[i].wkname<<"\n";
			if(_strcmp(info,someworker[i2].wkname)==0)
			{
				std::cout<<someworker[i2].wkname<<"\n";
				std::cout<<"该员工工号："<<someworker[i2].wkid<<"\n";
				std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
				found = 1;
				return i2;
			}
		}
		if(found == 0) std::cout<<"未找到相应信息.\n";
		}break;
		case 4:{
			
			for(int i2=0;i2<count4;i2++)
			{
				if(_strcmp(info,someworker[i2].wkbirth)==0)
				{
					std::cout<<"找到生日为："<<info<<"的职工\n";
					std::cout<<someworker[i2].wkname<<"\n";
					std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
					std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";
					found = 1;
					return i2;
				}
			}
			if(found == 0) std::cout<<"未找到相应信息.\n";
		}break;
			case 5:{
				for(int i2=0;i2<count4;i2++)
				{
					if(_strcmp(info,someworker[i2].fstdate)==0)
					{
						std::cout<<"找到入职时间为:"<<info<<"的员工\n";
						std::cout<<someworker[i2].wkname<<"\n";
						std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
//						std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
						std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";
						found = 1;
						return i2;
					}
				}
				if(found == 0) std::cout<<"未找到相应信息.\n";
			}break;
				case 7:
					{
					std::cout<<"部门："<<info<<"\n";
					for(int i2=0;i2<count4;i2++)
					{
						if(_strcmp(info,someworker[i2].wkBM)==0)
						{
							std::cout<<"员工名称："<<someworker[i2].wkname<<"\n";
						std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
						std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";	
						found = 1;
						return i2;
						}
					}
					if(found == 0) std::cout<<"未找到相应信息.\n";
					}break;
				case 9:
					{
					std::cout<<"岗位："<<info<<std::endl;
					int i2;
					for( i2=0;i2<count4;i2++)
					{
						if(_strcmp(info, someworker[i2].wkGW)==0)
						{
							
							std::cout<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
							std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";
							found =1 ;
							
						}
					}
					return i2;
					if(found == 0) std::cout<<"未找到相应信息.\n";
				}break;
				case 10:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(_strcmp(info, someworker[i2].wkaddress)==0)
						{
							
							std::cout<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
							std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";
							found = 1;
							return i2;
						}
					}
					if(found == 0) std::cout<<"未找到相应信息.\n";
					}break;
				case 11:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(_strcmp(info, someworker[i2].wkphonenumber)==0)
						{
							
							std::cout<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
							std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";
							found = 1;
							return i2;
						}
						}
						if(found == 0) std::cout<<"未找到相应信息.\n";
					}break;
				case 12:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(_strcmp(info, someworker[i2].wkemail)==0)
						{
							std::cout<<info<<std::endl;
							std::cout<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"该员工位于数据库中的:"<<i2<<"\n";
							std::cout<<"该员工工号:"<<someworker[i2].wkid<<"\n";
							found = 1;
							return i2;
						}		
					}
					if(found == 0) std::cout<<"未找到相应信息.\n";
					}break;
				}
				return -1;
}


	void addinfo(FILE *p,int n)
	{
//		rewind(p);
		readinfo();
		for(int i=count;i<n+count;i++)
		{
			std::cout<<"请输入工作证ID:(可包含数字以外的字符)：";
			memset(someworker[i].wkid,0,20*sizeof(char));
			std::cin>>someworker[i].wkid;
			std::cout<<"请输入姓名:(请使用拼音):";
			memset(someworker[i].wkname,0,20*sizeof(char));
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
			memset(someworker[i].wkbirth,0,13*sizeof(char));
			std::cin>>someworker[i].wkbirth;
			std::cout<<"请输入员工入职日期  年-月-日:";
			memset(someworker[i].fstdate,0,13*sizeof(char));
			std::cin>>someworker[i].fstdate;
			std::cout<<"请输入员工部门编号:";
			memset(someworker[i].wkBM,0,50*sizeof(char));
			memset(someworker[i].wkGW,0,50*sizeof(char));
			memset(someworker[i].wkemail,0,20*sizeof(char));
			memset(someworker[i].wkaddress,0,50*sizeof(char));
			memset(someworker[i].wkphonenumber,0,20*sizeof(char));
			std::cin>>someworker[i].wkBMnum;
			std::cout<<"请输入员工部门名称:";
			std::cin>>someworker[i].wkBM;
			std::cout<<"请输入员工岗位编号 (岗位编号代表岗位等级 由低到高 最低为1) : ";
			std::cin>>someworker[i].wkGWnum;
			std::cout<<"请输入员工岗位名称:";
			std::cin>>someworker[i].wkGW;
			std::cout<<"请输入岗位基本工资:";
			std::cin>>someworker[i].essential_salary;
			std::cout<<"请输入岗位工资系数:";
			std::cin>>someworker[i].GWsalary_level;
			std::cout<<"请输入个人税率:(如10%即输入0.1)";
			std::cin>>someworker[i].tax_rate;
			std::cout<<"请输入奖金和加班费的和:(额外工资)";
			std::cin>>someworker[i].extra_salary;
			std::cout<<"请输入员工家庭地址:";
			std::cin>>someworker[i].wkaddress;
			std::cout<<"请输入员工电话:";
			std::cin>>someworker[i].wkphonenumber;
			std::cout<<"请输入员工工作邮箱:";
			std::cin>>someworker[i].wkemail;
			someworker[i].wksalary = someworker[i].essential_salary * someworker[i].GWsalary_level + someworker[i].extra_salary;
			someworker[i].factsalary = someworker[i].wksalary * (0.75 - someworker[i].tax_rate) - 2;
			std::cout<<"-----------------------------------------\n";
		}
		for (int i=count;i<n+count;i++) {
			fwrite(&someworker[i], size, 1, p);
		}
		rewind(p);
		readinfo();
		

	}
	


void graphworker()
{
	std::cout<<"------------------------- 员工基本信息  ----------------------------\n";
	int count2 = 0;
	rewind(p);
	while(fread(&countworker[count2], size, 1, p)==1)
		{
			if(someworker[count2].wkid[0]!='#' && someworker[count2].wkname[0] != '\0' && someworker[count2].wkid[0] != '\0')
			count2++;
		}
	std::cout<<"目前有"<<count2<<"个员工\n";
	std::cout<<"---                   1.增加员工信息\n";
	std::cout<<"---                   2.浏览全部员工信息\n";
	std::cout<<"---                   3.查找员工信息\n";
	std::cout<<"---                   4.修改员工信息\n";
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
				for(int i2=1;i2<=16;i2++)
				{
				outputinfo(i, i2);
				}
				std::cout<<"-------------------------\n";
			}
		}break;	
		case 3:{
			searchforinfo();
		}break;
		case 4:{
			changeinfo();
		}break;
	} 
	graphworker();
}

void deleteworker()
{
	std::cout<<"请输入要删除员工的工号:";
	memset(info, 0, 50*sizeof(char));
	std::cin>>info;
	rewind(p);
		int count4= 0;
		while(fread(&someworker[count4], size, 1, p)==1)
			{
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
				memset(someworker[i2].wkid, 0, 20*sizeof(char));
				memset(someworker[i2].wkname, 0, 20*sizeof(char));
				memset(someworker[i2].wkbirth, 0, 13*sizeof(char));
				memset(someworker[i2].fstdate, 0, 13*sizeof(char));
				memset(someworker[i2].wkBM, 0, 50*sizeof(char));
				memset(someworker[i2].wkGW, 0, 50*sizeof(char));
				memset(someworker[i2].wkaddress, 0, 50*sizeof(char));
				memset(someworker[i2].wkphonenumber, 0, 20*sizeof(char));
				memset(someworker[i2].wkemail, 0, 20*sizeof(char));
				memset(someworker[i2].BMJJ, 0, 200*sizeof(char));
				someworker[i2].wkid[0] = '#';
				someworker[i2].wkname[0] = '#';
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

void searchforinfo()
{
	std::cout<<"---                 1.通过工号查找\n";
	std::cout<<"---                 2.通过姓名查找\n";
	std::cout<<"---                 5.通过入职日期查找(格式如2018-12-20)\n";
	std::cout<<"---                 7.通过部门名称查找\n";
	std::cout<<"---                 9.通过岗位名称查找\n";
	std::cout<<"---                 11.通过电话号码查找\n";
	int mode;
	std::cin>>mode;
	switch(mode)
	{
		case 1:
			{
				std::cout<<"请输入工号:";
				memset(info, 0, 20*sizeof(char));
				std::cin>>info;
				findinfo_String(1, info);
			}break;
		case 2:
			{
				std::cout<<"请输入姓名:";
				memset(info,0,20*sizeof(char));
				std::cin>>info;
				findinfo_String(2,info);
			}break;
		case 5:
			{
				std::cout<<"请输入入职日期:";
				memset(info, 0, 13*sizeof(char));
				std::cin>>info;
				findinfo_String(5, info);
			}break;
		case 7:
			{
				std::cout<<"请输入岗位名称:";
				memset(info,0,50*sizeof(char));
				std::cin>>info;
				findinfo_String(7, info);
			}break;
		case 9:
			{
				std::cout<<"请输入部门名称:";
				memset(info, 0, 50*sizeof(char));
				std::cin>>info;
				findinfo_String(9, info);	
			}break;
		case 11:
			{
				std::cout<<"请输入电话号码:";
				memset(info, 0, 20*sizeof(char));
				std::cin>>info;
				findinfo_String(11,info);	
			}break;
	}
	graphworker();
}

int _strcmp(char a[],char b[])
{
	int lena =strlen(a);
//	std::cout<<"len a="<<lena<<"\n";
//	std::cout<<a;
	int lenb =strlen(b);
//	std::cout<<"len b="<<lenb<<"\n";
//	std::cout<<b;
	if(lena != lenb) return 1;
	for(int i=0;i<lena;i++)
	{
		if(a[i]!=b[i]) {break;return 1;}
	}
	return 0;
}

int  readinfo()
{
	count = 0 ;
	while(fread(&someworker[count], size, 1, p)==1)
		{
			count++;
		}
		return count;
}

void changeinfo()
{
	std::cout<<"---                 1.修改工号\n";
	std::cout<<"---                 2.修改姓名\n";
	std::cout<<"---                 3.修改生日\n";
	std::cout<<"---                 4.修改入职日期\n";
	std::cout<<"---                 5.修改岗位\n";
	std::cout<<"---                 6.修改岗位编号(等级)\n";
	std::cout<<"---                 7.修改部门\n";
	std::cout<<"---                 8.修改部门编号\n";
	std::cout<<"---                 9.修改电话\n";
	std::cout<<"---                 10.修改电子邮箱\n";
	std::cout<<"---                 11.修改住址\n";
	std::cout<<"---                 12.修改岗位基本工资\n";
	std::cout<<"---                 13.修改岗位工资系数\n";
	std::cout<<"---                 14.修改个人税率\n";
	std::cout<<"---                 15.修改额外工资\n";
	std::cout<<"---                 0.返回上一层\n";
	std::cout<<"请选择:";
	int mode = 0 ;
	std::cin>>mode;
	std::cout<<"请输入即将操作的工号：";
	memset(info, 0, 50*sizeof(char));
	std::cin>>info;
	int test = findinfo_String(1, info);
	if(test == -1)
	{
		std::cout<<"未找到工号！\n\n";
		graphworker();
	}
	
	switch(mode)
	{
		case 1:
			{
			std::cout<<"请输入新的工号:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkid, newid);
		std::cout<<"修改成功！"<<"工号:"<<someworker[test].wkid<<"\n";
			}break;
		case 2:
			{
			std::cout<<"请输入新的姓名:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkname, newid);
	std::cout<<"修改成功！"<<"姓名:"<<someworker[test].wkname<<"\n";			
			}break;
		case 3:
			{
			std::cout<<"请输入新的生日:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkbirth, newid);
		std::cout<<"修改成功！"<<"生日:"<<someworker[test].wkbirth<<"\n";
			}break;
		case 4:
			{
			std::cout<<"请输入新的入职日期:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].fstdate, newid);
		std::cout<<"修改成功！"<<"入职日期:"<<someworker[test].fstdate<<"\n";	
			}break;
		case 5:
			{
			std::cout<<"请输入新的岗位:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkGW, newid);
		std::cout<<"修改成功！"<<"岗位:"<<someworker[test].wkGW<<"\n";
			}break;
		case 6:
			{
			std::cout<<"请输入新的岗位编号:";
			std::cin>>someworker[test].wkGWnum;
			std::cout<<"修改成功！岗位编号:"<<someworker[test].wkGWnum<<"\n";	
			}break;
		case 7:
			{
			std::cout<<"请输入新的部门:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkBM, newid);
		std::cout<<"修改成功！"<<"部门:"<<someworker[test].wkBM<<"\n";	
			}break;
		case 8:
			{
			std::cout<<"请输入新的部门编号:";
			std::cin>>someworker[test].wkBMnum;
			std::cout<<"修改成功！部门编号:"<<someworker[test].wkBMnum<<"\n";
			}break;
		case 9:
			{
			std::cout<<"请输入新的电话:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkphonenumber, newid);
		std::cout<<"修改成功！"<<"电话:"<<someworker[test].wkphonenumber<<"\n";		
			}break;
		case 10:
			{
				std::cout<<"请输入新的电子邮箱:";
				char newid[200];
				memset(newid, 0, 200*sizeof(char));
				std::cin>>newid;
				strcpy(someworker[test].wkemail, newid);
			std::cout<<"修改成功！"<<"部门:"<<someworker[test].wkemail<<"\n";	
			}break;
		case 11:
			{
				std::cout<<"请输入新的住址:";
				char newid[200];
				memset(newid, 0, 200*sizeof(char));
				std::cin>>newid;
				strcpy(someworker[test].wkaddress, newid);
			std::cout<<"修改成功！"<<"部门:"<<someworker[test].wkaddress<<"\n";	
			}break;
		case 12:{
				std::cout<<"请输入新的岗位基本工资:";
				std::cin>>someworker[test].essential_salary;
				std::cout<<"修改成功！"<<"岗位基本工资:"<<someworker[test].essential_salary<<"\n";
				someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
				someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
		}break;
		case 13:{
				std::cout<<"请输入新的岗位工资系数:";
				std::cin>>someworker[test].GWsalary_level;
				std::cout<<"修改成功！岗位工资系数:"<<someworker[test].GWsalary_level<<"\n";
				someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
				someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
		}break;
		case 14:
			{
				std::cout<<"请输入新的个人税率:";
				std::cin>>someworker[test].tax_rate;
				std::cout<<"修改成功！个人税率:"<<someworker[test].tax_rate<<"\n";
				someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
				someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
			}break;
		case 15:{
			std::cout<<"请输入新的额外工资:";
			std::cin>>someworker[test].extra_salary;
			std::cout<<"修改成功！额外工资:"<<someworker[test].extra_salary<<"\n";
			someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
			someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
		}break;
		default :
			{
				std::cout<<"请检查您的输入是否合法！\n";
			}break;
	}
	fclose(p);
	p = fopen("misinfo.dat", "wb+");
	rewind(p);
for(int i=0;i<count;i++)
{
	fwrite(&someworker[i], size, 1, p);
}
fclose(p);
p = fopen("misinfo.dat","a+b");
graphworker();
}

void outputsalary()
{
	for(int i =0 ; i < count ; i++)
	{
		if(someworker[i].wkid[0] == '#') continue;
		outputinfo(i, 1);
		outputinfo(i, 2);
		outputinfo(i, 17);
		std::cout<<"-----------------------\n";
	}
	graphmain();
}

void BMinfo()
{	
	int c = 0;
	for(int i = 0 ;i <count ;i++)
	{
		if(someworker[i].wkBMnum > c) c = someworker[i].wkBMnum;
	}
	std::cout<<"-------------------------------------\n";
	std::cout<<"现有"<<c<<"个部门\n";
	std::cout<<"---               1.更改部门简介\n";
	std::cout<<"---               2.显示部门简介\n";
	std::cout<<"---               3.浏览部门信息\n";
	std::cout<<"---               0.返回上一层\n";
	int mode;
	std::cout<<"请输入选项：";
	std::cin>>mode;
	switch (mode)
	{
		case 0 :
			{
				graphmain();
			}break;
		case 1 :
			{
				std::cout<<"请输入要修改简介的部门编号:";
				int a = 0;
				std::cin>>a;
			if (a <= 0 || a >= c) 
			{
			std::cout<<"输入错误！目前只有"<<c<<"个部门!\n";
			}
			for(int i =0 ;i< count; i++)
			{
				if(someworker[i].wkBMnum == a)
				{
				std::cout<<"部门:"<<someworker[i].wkBM<<"\n";
				break;
				}
			}
			std::cout<<"请输入部门简介(用英文或者拼音):";
			char tempjj[200];
			memset(tempjj, 0, 200*sizeof(char));
			std::cin>>tempjj;
			for(int i = 0; i< count ;i++)
			{
				if(someworker[i].wkid[0]=='#') continue;
				if(someworker[i].wkBMnum == a )
				strcpy(someworker[i].BMJJ, tempjj);
			}
			}break;
		case 2 :
			{
			int putter = 0;
			std::cout<<"请输入要显示简介的部门编号：";
			std::cin>>putter;
			while(putter <= 0 || putter > c)
			{
				std::cout<<"输入错误！请重新输入:";
				std::cin>>putter;
			}
			for(int i =0 ;i <count ;i++)
			{
				if(someworker[i].wkid[0]=='#') continue;
				if(someworker[i].wkBMnum == putter)
				{
					if(someworker[i].BMJJ[0]== '\0')
					std::cout<<"该部门暂无部门简介!\n";
					std::cout<<someworker[i].wkBM<<"\n";
					std::cout<<someworker[i].BMJJ<<"\n";
					break;
				}
			}
			BMinfo();
			}break;
			case 3:
				{
				for(int i =1; i <= c ;i++)
				{
					for(int i2=0 ; i2< count ;i2 ++)
					{
						if(someworker[i2].wkid[0]=='#') continue;
						if(someworker[i2].wkBMnum == i)
						{
							std::cout<<"部门编号:"<<someworker[i2].wkBMnum<<"\n";
							std::cout<<"部门名称:"<<someworker[i2].wkBM<<"\n";
							break;
						}
					}
				}
					}break;
				}
	fclose(p);
	p = fopen("misinfo.dat", "wb+");
	rewind(p);
for(int i=0;i< count;i++)
{
	fwrite(&someworker[i], size, 1, p);
}
fclose(p);
p = fopen("misinfo.dat","a+b");
BMinfo();
}

void GWinfo()
{
	std::cout<<"-----------------------------------\n";
	std::cout<<"---                1.搜索岗位信息\n";
	std::cout<<"---                2.修改岗位职责\n";
	std::cout<<"---                3.显示岗位职责\n";
	std::cout<<"---                0.回到主菜单\n";
	int mode = 0;
	std::cout<<"请选择:";
	std::cin>>mode;
	switch (mode)
	{
		case 0 :
			{
				graphmain();
			}break;
		case 1 :
			{
				std::cout<<"请输入该岗位名称:";
				char tempGW[50];
				memset(tempGW, 0, 50*sizeof(char));
				std::cin>>tempGW;
				 int test = findinfo_String(9, tempGW);
				if(test == -1)
				{
				 std::cout<<"未找到岗位:";
				 std::cout<<tempGW<<"\n";
				GWinfo();
				}	
			}break;
		case 2 :
			{
			std::cout<<"请输入要修改简介的岗位名称:";
			char tempGW[50];
			memset(tempGW, 0, 50*sizeof(char));
			std::cin>>tempGW;
			int test = findinfo_String(9, tempGW);
			if(test == -1)
			{
				std::cout<<"无此岗位！\n";
				GWinfo();
			}
			std::cout<<"请输入岗位职责:";
			char tempZZ[200];
			memset(tempZZ, 0, 200*sizeof(char));
			std::cin>>tempZZ;
			for(int i = 0; i< count ;  i++)
			{
				if(someworker[i].wkid[0]=='#')
				continue;
				if(_strcmp(someworker[i].wkGW,tempGW)==0)
				strcpy(someworker[i].GWZZ,tempZZ);
			}
			}break;
		case 3:
			{
			std::cout<<"请输入要查看职责的岗位:";
			char tempGW[50];
			memset(tempGW,0,50*sizeof(char));
			std::cin>>tempGW;
			int test = findinfo_String(9, tempGW);
			if( test == -1)
			{
				std::cout<<"无此岗位!\n";
				GWinfo();
			}
			for(int i = 0; i< count ;  i++)
			{
				if(someworker[i].wkid[0]=='#')
				continue;
				if(_strcmp(someworker[i].wkGW,tempGW)==0)
				{
				if(someworker[i].GWZZ[0]=='\0')
				{
				std::cout<<"暂无职责信息！";
				break;
				}
				std::cout<<someworker[i].GWZZ<<"\n";
				break;
				}
			}
			}break;
	}
	fclose(p);
	p = fopen("misinfo.dat", "wb+");
	rewind(p);
	for(int i=0;i< count;i++)
	{
		fwrite(&someworker[i], size, 1, p);
	}
	fclose(p);
	p = fopen("misinfo.dat","a+b");
	GWinfo();
}