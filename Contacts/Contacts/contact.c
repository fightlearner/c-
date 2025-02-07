#include "contact.h"

void LoadContact(Contact* pc)
{
	assert(pc);
	FILE* pr = fopen("Contact.txt", "rb");
	if (pr == NULL)
	{
		perror("LoadContact");
		return;
	}
	else
	{
		PeoInfo temp = { 0 };
		while (fread(&temp, sizeof(PeoInfo), 1, pr) == 1)
		{
			if (pc->count == pc->capacity)
			{
				PeoInfo* prt = (PeoInfo*)realloc(pc->data, (pc->capacity + INC) * sizeof(PeoInfo));
				if (prt == NULL)
				{
					printf("%s\n", strerror(errno));
					return;
				}
				else
				{
					pc->data = prt;
					pc->capacity = pc->capacity + INC;
				}
			}
			pc->data[pc->count] = temp;
			pc->count++;
		}
	}
	fclose(pr);
	pr = NULL;
}

int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(MAX, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = MAX;
	LoadContact(pc);
	return 0;
}

void ShowContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-20s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (int i = 0;i < pc->count;i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-20s\t%-30s\n", pc->data[i].name,
				pc->data[i].age,
				pc->data[i].gender,
				pc->data[i].tele,
				pc->data[i].address);

		}
	}
	
}
//静态版本
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->count == MAX)
//	{
//		printf("通讯录已满\n");
//		return;
//	}
//	else
//	{
//		printf("姓名：");
//		scanf("%s", pc->data[pc->count].name);
//		printf("年龄：");
//		scanf("%d", &(pc->data[pc->count].age));
//		printf("性别：");
//		scanf("%s", pc->data[pc->count].gender);
//		printf("电话：");
//		scanf("%s", pc->data[pc->count].tele);
//		printf("地址：");
//		scanf("%s", pc->data[pc->count].address);
//		pc->count++;
//	}
//}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		PeoInfo* prt = (PeoInfo*)realloc(pc->data, (pc->capacity + INC) * sizeof(PeoInfo));
		if (prt == NULL)
		{
			printf("%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = prt;
			pc->capacity = pc->capacity + INC;
		}
	}
	printf("姓名：");
	scanf("%s", pc->data[pc->count].name);
	printf("年龄：");
	scanf("%d", &(pc->data[pc->count].age));
	printf("性别：");
	scanf("%s", pc->data[pc->count].gender);
	printf("电话：");
	scanf("%s", pc->data[pc->count].tele);
	printf("地址：");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
	
}
int FindContact(Contact* pc, char* name)
{
	for (int i = 0;i < pc->count;i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DeleteContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("输入想要删除的姓名：");
		scanf("%s", name);
		int i = FindContact(pc, name);
		if (i == -1)
		{
			printf("找不到联系人\n");
		}
		else
		{
			for (;i < pc->count - 1;i++)
			{
				pc->data[i] = pc->data[i + 1];

			}
			pc->count--;
		}
	}
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("输入想要查找的姓名：");
	scanf("%s", name);
	int i = FindContact(pc, name);
	if (i == -1)
	{
		printf("找不到联系人\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-20s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-10s\t%-4d\t%-5s\t%-20s\t%-30s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].gender,
			pc->data[i].tele,
			pc->data[i].address);
	}
}
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_by_name);
}
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("输入想要修改的姓名：");
	scanf("%s", name);
	int i = FindContact(pc, name);
	if (i == -1)
	{
		printf("找不到联系人\n");
	}
	else
	{
		printf("姓名：");
		scanf("%s", pc->data[i].name);
		printf("年龄：");
		scanf("%d", &(pc->data[i].age));
		printf("性别：");
		scanf("%s", pc->data[i].gender);
		printf("电话：");
		scanf("%s", pc->data[i].tele);
		printf("地址：");
		scanf("%s", pc->data[i].address);
	}
}
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pr = fopen("Contact.txt", "wb");
	if (pr == NULL)
	{
		perror("SaveContact");
		return;
	}
	else
	{
		for (int i = 0;i < pc->count;i++)
		{
			fwrite(pc->data + i, sizeof(PeoInfo), 1, pr);
		}
		
	}
	fclose(pr);
	pr = NULL;
	
}
