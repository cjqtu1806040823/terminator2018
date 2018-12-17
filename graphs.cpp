#include <iostream>
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
#if 0
int main(int argc, char const *argv[])
{
	graphmain();
	int chooser;
	std::cin>>chooser;
	makerinfo();
	return 0;
}
#endif