#include "studentmanagesystem.h"

void welcome()
{
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\t请选择功能列表\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.保存学生信息\t\t\t*\n");
	printf("*\t\t4.读取学生信息\t\t\t*\n");
	printf("*\t\t5.统计所有学生人数\t\t*\n");
	printf("*\t\t6.查找学生信息\t\t\t*\n");
	printf("*\t\t7.修改学生信息\t\t\t*\n");
	printf("*\t\t8.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("*************************************************\n");
}

//录入学生信息
void InputStuent()
{
	//创建一个新节点
	Node* pNewPoint = (Node*)malloc(sizeof(Node));
	pNewPoint->pNext = NULL;

	//头插法
	if(g_pHead == NULL)
	{
		g_pHead = pNewPoint;
	}
	else
	{
		pNewPoint->pNext = g_pHead;
		g_pHead = pNewPoint;
	}
	printf("请输入学生姓名：\n");
	scanf("%s",pNewPoint->stu.name,sizeof(pNewPoint->stu.name));//从键盘格式化接受一个字符串，整数等等
	printf("请输入学生的年龄：\n");
	scanf("%d",&pNewPoint->stu.age);//&:取地址运算符
	printf("请输入学生的学号：\n");
	scanf("%d", &pNewPoint->stu.stuNum);//
	printf("请输入学生的成绩：\n");
	scanf("%d", &pNewPoint->stu.score);//

	printf("学生成绩录入成功。\n");
	system("pause");//暂停
	system("cls");
}

//打印学生信息
void PrintStudent()
{
	system("cls");
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩*\n");
	printf("*************************************************\n");
	
	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d*\n",
			p->stu.stuNum,
			p->stu.name,
			p->stu.age,
			p->stu.score);
		printf("*************************************************\n");
		p = p->pNext;
	}

	system("pause");
	system("cls");
}

//保存学生信息
void SaveStudent()
{
	//打开文件
	FILE* fp = fopen("D:\\student.dat", "w");

	if (fp == NULL)
	{
		printf("打开文件失败。\n");
		return;
	}
	//遍历链表
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}
	//关闭文件
	fclose(fp);
	printf("\n数据保存成功\n");
	system("pause");
	system("cls");
}

void ReadStudent()
{
	//打开文件
	FILE* fp = fopen("D:\\student.dat", "r");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		return;
	}

	//读文件
	while (1)//判断feof()是否为文件末尾
	{
		//创建一个新节点
		Node* pNewPoint = (Node*)malloc(sizeof(Node));
		fread(&pNewPoint->stu, 1,sizeof(Student),fp);
		if (feof(fp)) break;
		pNewPoint->pNext = NULL;
		//头插法
		if (g_pHead == NULL)
		{
			g_pHead = pNewPoint;
		}
		else
		{
			pNewPoint->pNext = g_pHead;
			g_pHead = pNewPoint;
		}
	}
	//关闭文件
	fclose(fp);
	printf("\n数据读取成功\n");
	system("pause");
	system("cls");
}

//统计学生人数
int CountStudent()
{
	int nCount = 0;//学生总数

	//遍历数据
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	return nCount;
}

//查找学生
Node* FindStudent()
{
	int nStuNum;
	char szName[20];
	printf("输入查找学生的学号：\n");
	scanf("%d", &nStuNum);
	printf("输入查找学生的姓名：\n");
	scanf("%s", &szName);
	
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum == nStuNum || strcmp(p->stu.name, szName) == 0)//strcmp字符串比较函数
		{
			return p;
		}
		p = p->pNext;
	}

	//没有找到
	return NULL;
}

//读取学生信息
void ModifyStudent()
{
	int nStuNum;
	printf("请输入需要修改的学生信息的学号：\n");
	scanf("%d", &nStuNum);

	Node* p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum == nStuNum)//strcmp字符串比较函数
		{
			printf("请输入要修改的学生姓名，年龄，成绩：\n");
			scanf("%s %d %d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("修改成功.\n");
			break;
		}
		p = p->pNext;
	}

	if (p == NULL)
	{
		printf("没有找到该学生信息.\n");
	}
}

//删除学生信息
void DeleteStudent()
{
	int nStuNum;
	printf("请输入要删除的学生的学号：\n");

	scanf("%d", &nStuNum);
	Node* p1, *p2;

	//判断是不是头结点
	if (g_pHead->stu.stuNum == nStuNum)
	{
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		return;
	}

	//不是头结点
	Node* p = g_pHead;
	while (p->pNext != NULL)
	{
		if (p->pNext->stu.stuNum == nStuNum)
		{
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			return;
		}

		p = p->pNext;

		if (p->pNext == NULL)
		{
			break;
		}
	}
	if (p->pNext == NULL)
	{
		printf("没有找到该学员");
	}
}


int main()
{
	
	while (1)
	{
		welcome();//欢迎
		//从键盘接受一个字符
		char ch = _getch();

		switch (ch)
		{
		case '1'://录入学生信息
			InputStuent();
			break;
		case '2'://打印学生信息
			PrintStudent();
			break;
		case '3'://保存学生信息 
			SaveStudent();
			break;
		case '4'://读取学生信息
			ReadStudent();
			break;
		case '5'://统计所有学生人数
			printf("学生总人数为：%d\n", CountStudent());
			system("pause");
			system("cls");
			break;
		case '6'://查找学生信息
		{
			Node* p = FindStudent();
			if (p != NULL)
			{
				printf("学号：%d\t姓名：%s\t年龄：%d\t成绩：%d\n",
					p->stu.stuNum,
					p->stu.name,
					p->stu.age,
					p->stu.score);
			}
			else
				printf("没有找到该学员\n");
			system("pause");
			system("cls");
			break;
		}
		case '7'://修改学生信息
			ModifyStudent();
			system("pause");
			system("cls");
			break;
		case '8'://删除学生信息
			DeleteStudent();
			system("pause");
			system("cls");
			break;
		case '0'://退出系统
			printf("Bye Bye");
			return 0;
		default:
			printf("你的输入有误，请重新输入\n");
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}