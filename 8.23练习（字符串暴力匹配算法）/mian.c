#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct String
{
	char* data;
	int len;
}String;

String* Origin(String* string)
{
	assert(string);

	string->len = 0;
	string->data = NULL;
	char c = getchar();

	while (c != '\n')
	{
		char* new = string->data;
		new = (char*)realloc(new, sizeof(char) * (string->len + 2));
		if (new == NULL)
		{
			exit(0);
		}
		string->data = new;
		*(string->data + string->len) = c;
		string->len++;
		c = getchar();
	}

	if (string->data + string->len)
	{
		*(string->data + string->len) = 0;
	}

	return string;
}

void StringPairing(String* s, String* data)
{
	char* master = s->data;
	char* pairing = data->data;
	int i = 1;
	int n = 0;

	while (*master != '\0')
	{
		if (*master == *pairing)
		{
			master++;
			pairing++;
			n++;
			if (n == data->len)
			{
				printf("These string are pairing success\n");
				break;
			}
		}
		else
		{
			n = 0;
			master = s->data+(++i);
			pairing = data->data;
		}
	}

	if (n != data->len)
	{
		printf("These string are not pairing success\n");
	}
}

void Prin(String* s)
{
	char* ptr = s->data;
	printf("%s\n", ptr);
}

void main()
{
	String* s = (String*)malloc(sizeof(String));
	String* s1 = (String*)malloc(sizeof(String));
	//String* s2 = NULL;//¥ÌŒÛ”√¿˝
	Origin(s);
	Origin(s1);
	/*Prin(s);
	Prin(s1)*/;
	StringPairing(s,s1);
}