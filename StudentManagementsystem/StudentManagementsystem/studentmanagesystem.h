#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//����һ��ѧ��
typedef struct _student
{
	char name[20];  //����
	int age;		//����
	int stuNum;		//ѧ��
	int score;		//�ɼ�
}Student;

//�ڵ�
typedef struct _Node
{
	Student stu;		 //ѧ��
	struct _Node* pNext; //ָ����һ���ڵ��ָ��
}Node;

//ͷ���
Node *g_pHead = NULL;

//¼��ѧ����Ϣ
void InputStuent();

//��ӭ
void welcome();

//��ӡѧ����Ϣ
void PrintStudent();

//����ѧ����Ϣ
void SaveStudent();

//��ȡѧ����Ϣ
void ReadStudent();

//ͳ������ѧ������
int CountStudent();

//����ѧ��
Node* FindStudent();

//��ȡѧ����Ϣ
void ModifyStudent();

//ɾ��ѧ����Ϣ
void DeleteStudent();
