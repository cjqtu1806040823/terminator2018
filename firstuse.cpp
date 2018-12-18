#include <bits/stdc++.h>
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
