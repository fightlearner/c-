#define _CRT_SECURE_NO_WARNINGS

#pragma once
# include <stdio.h>
# include <memory.h>
# include <assert.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>

#define MAX 3
#define INC 2
#define MAX_NAME 10
#define MAX_gender 5
#define MAX_TELE 20
#define MAX_ADDRESS 30

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_gender];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}PeoInfo;

//��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int count;
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
}Contact;

int InitContact(Contact* pc);
void AddContact(Contact* pc);
void DeleteContact(Contact* pc);
void ShowContact(Contact* pc);
void SearchContact(Contact* pc);
void ModifyContact(Contact* pc);
void SortContact(Contact* pc);
void DestoryContact(Contact* pc);
void SaveContact(Contact* pc);
void LoadContact(Contact* pc);