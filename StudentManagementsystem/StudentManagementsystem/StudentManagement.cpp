#include "studentmanagesystem.h"

void welcome()
{
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");
}

//¼��ѧ����Ϣ
void InputStuent()
{
	//����һ���½ڵ�
	Node* pNewPoint = (Node*)malloc(sizeof(Node));
	pNewPoint->pNext = NULL;

	//ͷ�巨
	if(g_pHead == NULL)
	{
		g_pHead = pNewPoint;
	}
	else
	{
		pNewPoint->pNext = g_pHead;
		g_pHead = pNewPoint;
	}
	printf("������ѧ��������\n");
	scanf("%s",pNewPoint->stu.name,sizeof(pNewPoint->stu.name));//�Ӽ��̸�ʽ������һ���ַ����������ȵ�
	printf("������ѧ�������䣺\n");
	scanf("%d",&pNewPoint->stu.age);//&:ȡ��ַ�����
	printf("������ѧ����ѧ�ţ�\n");
	scanf("%d", &pNewPoint->stu.stuNum);//
	printf("������ѧ���ĳɼ���\n");
	scanf("%d", &pNewPoint->stu.score);//

	printf("ѧ���ɼ�¼��ɹ���\n");
	system("pause");//��ͣ
	system("cls");
}

//��ӡѧ����Ϣ
void PrintStudent()
{
	system("cls");
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t*\n");
	printf("*************************************************\n");
	printf("*\tѧ��\t*\t����\t*\t����\t*\t�ɼ�*\n");
	printf("*************************************************\n");
	
	//��������
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

//����ѧ����Ϣ
void SaveStudent()
{
	//���ļ�
	FILE* fp = fopen("D:\\student.dat", "w");

	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܡ�\n");
		return;
	}
	//��������
	Node* p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}
	//�ر��ļ�
	fclose(fp);
	printf("\n���ݱ���ɹ�\n");
	system("pause");
	system("cls");
}

void ReadStudent()
{
	//���ļ�
	FILE* fp = fopen("D:\\student.dat", "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}

	//���ļ�
	while (1)//�ж�feof()�Ƿ�Ϊ�ļ�ĩβ
	{
		//����һ���½ڵ�
		Node* pNewPoint = (Node*)malloc(sizeof(Node));
		fread(&pNewPoint->stu, 1,sizeof(Student),fp);
		if (feof(fp)) break;
		pNewPoint->pNext = NULL;
		//ͷ�巨
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
	//�ر��ļ�
	fclose(fp);
	printf("\n���ݶ�ȡ�ɹ�\n");
	system("pause");
	system("cls");
}

//ͳ��ѧ������
int CountStudent()
{
	int nCount = 0;//ѧ������

	//��������
	Node* p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	return nCount;
}

//����ѧ��
Node* FindStudent()
{
	int nStuNum;
	char szName[20];
	printf("�������ѧ����ѧ�ţ�\n");
	scanf("%d", &nStuNum);
	printf("�������ѧ����������\n");
	scanf("%s", &szName);
	
	Node* p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum == nStuNum || strcmp(p->stu.name, szName) == 0)//strcmp�ַ����ȽϺ���
		{
			return p;
		}
		p = p->pNext;
	}

	//û���ҵ�
	return NULL;
}

//��ȡѧ����Ϣ
void ModifyStudent()
{
	int nStuNum;
	printf("��������Ҫ�޸ĵ�ѧ����Ϣ��ѧ�ţ�\n");
	scanf("%d", &nStuNum);

	Node* p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum == nStuNum)//strcmp�ַ����ȽϺ���
		{
			printf("������Ҫ�޸ĵ�ѧ�����������䣬�ɼ���\n");
			scanf("%s %d %d", p->stu.name, &p->stu.age, &p->stu.score);
			printf("�޸ĳɹ�.\n");
			break;
		}
		p = p->pNext;
	}

	if (p == NULL)
	{
		printf("û���ҵ���ѧ����Ϣ.\n");
	}
}

//ɾ��ѧ����Ϣ
void DeleteStudent()
{
	int nStuNum;
	printf("������Ҫɾ����ѧ����ѧ�ţ�\n");

	scanf("%d", &nStuNum);
	Node* p1, *p2;

	//�ж��ǲ���ͷ���
	if (g_pHead->stu.stuNum == nStuNum)
	{
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		return;
	}

	//����ͷ���
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
		printf("û���ҵ���ѧԱ");
	}
}


int main()
{
	
	while (1)
	{
		welcome();//��ӭ
		//�Ӽ��̽���һ���ַ�
		char ch = _getch();

		switch (ch)
		{
		case '1'://¼��ѧ����Ϣ
			InputStuent();
			break;
		case '2'://��ӡѧ����Ϣ
			PrintStudent();
			break;
		case '3'://����ѧ����Ϣ 
			SaveStudent();
			break;
		case '4'://��ȡѧ����Ϣ
			ReadStudent();
			break;
		case '5'://ͳ������ѧ������
			printf("ѧ��������Ϊ��%d\n", CountStudent());
			system("pause");
			system("cls");
			break;
		case '6'://����ѧ����Ϣ
		{
			Node* p = FindStudent();
			if (p != NULL)
			{
				printf("ѧ�ţ�%d\t������%s\t���䣺%d\t�ɼ���%d\n",
					p->stu.stuNum,
					p->stu.name,
					p->stu.age,
					p->stu.score);
			}
			else
				printf("û���ҵ���ѧԱ\n");
			system("pause");
			system("cls");
			break;
		}
		case '7'://�޸�ѧ����Ϣ
			ModifyStudent();
			system("pause");
			system("cls");
			break;
		case '8'://ɾ��ѧ����Ϣ
			DeleteStudent();
			system("pause");
			system("cls");
			break;
		case '0'://�˳�ϵͳ
			printf("Bye Bye");
			return 0;
		default:
			printf("���������������������\n");
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}