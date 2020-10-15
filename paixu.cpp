// paixu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <MALLOC.H>
#include <stdlib.h>
#pragma  pack(1);
int arraydata[]={38, 65, 97, 76, 13, 27, 49};
void InsertSort(int _arraydata[],int n)
{

	int i,j;
	for (i=1;i<n;i++)
	{
		int temp = _arraydata[i];
		j=i;
		while(j>0 && temp<_arraydata[j-1])
		{
			_arraydata[j]=_arraydata[j-1];
			j--;
		}
		_arraydata[j]=temp;

	}
}
void SelectSort(int _arraydata[],int n)
{
	int i,j;
	for (i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (_arraydata[j]<_arraydata[i])
			{
				int temp = _arraydata[i];
				_arraydata[i]=_arraydata[j];
				_arraydata[j]=temp;
			}
		}
	}
}
void bubble_sort(int _arraydata[],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-1;j++)
		{
			int temp = _arraydata[j];
			if (temp>_arraydata[j+1])
			{
				_arraydata[j]=_arraydata[j+1];
				_arraydata[j+1]=temp;
			}
		}
	}
}


struct mp3info
{
	char Header[3];//           1-3                3                   标签头
	char Title[30];//              4-33               30                  标题
	char Artist[30];//             34-63             30                  艺术家
	char Album[30];//            64-93             30                  专辑
	char Year[4];//               94-97             4                   出品年代
	char Comment[30];//       98-127           30                  备注
    char Cenre[1];//             128                1                   类型
};
	
FILE *fp ;	

int mypaixu(const void* a,const void* b)
{
	//return (*(int*)a-*(int*)b);
	return (*(int*)b-*(int*)a);
}

int main(int argc, char* argv[])
{
	//InsertSort(arraydata,sizeof(arraydata)/sizeof(int));
	//SelectSort(arraydata,sizeof(arraydata)/sizeof(int));
	//bubble_sort(arraydata,sizeof(arraydata)/sizeof(int));
	qsort(arraydata,sizeof(arraydata)/sizeof(int),sizeof(int),mypaixu);

	int c = sizeof(mp3info);
	mp3info *m_mp3info = (mp3info *)malloc(sizeof(mp3info));
	char filename[128];
	strcpy(filename,"c:\\1.mp3");
	//scanf("%s",filename);
	fp = fopen(filename,"r");
	fseek(fp,-128,SEEK_END);
	fread(m_mp3info,1,sizeof(mp3info),fp);
	fclose(fp);
	if (strcmp(m_mp3info->Header,"TAG")!=0)
	{
		printf("no info");
	}
	free(m_mp3info);

	m_mp3info=NULL;




	printf("Hello World!\n");
	return 0;
}

