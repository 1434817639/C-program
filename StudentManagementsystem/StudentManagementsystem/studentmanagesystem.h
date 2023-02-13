#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//定义一个学生
typedef struct _student
{
	char name[20];  //姓名
	int age;		//年龄
	int stuNum;		//学号
	int score;		//成绩
}Student;

//节点
typedef struct _Node
{
	Student stu;		 //学生
	struct _Node* pNext; //指向下一个节点的指针
}Node;

//头结点
Node *g_pHead = NULL;

//录入学生信息
void InputStuent();

//欢迎
void welcome();

//打印学生信息
void PrintStudent();

//保存学生信息
void SaveStudent();

//读取学生信息
void ReadStudent();

//统计所有学生人数
int CountStudent();

//查找学生
Node* FindStudent();

//读取学生信息
void ModifyStudent();

//删除学生信息
void DeleteStudent();
