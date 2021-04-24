#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <windows.h>


#include "vslib.h"
#include "udb.h"


void pause() { system("pause"); }


//--------------------------------------------------------------
// ��Ҫ����
//--------------------------------------------------------------
int main(int argc, char* argv[])
{
	// ������Ͷ�
	if (argc <= 1)
	{
		SetColor(14);
		printf(" -------------------------------\n");
		printf("|        UDB ver 0.0.3.1        |\n");
		printf("| Copyright(C) 2020 GloomyGhost |\n");
		printf("| Copyright(C) 2020 AckieSound  |\n");
		printf(" -------------------------------\n");
		printf("|    ��������UTAU����������   |\n");
		printf("|    UDBֻ����UTAU�����ŶOwO   |\n");
		printf(" -------------------------------\n");
		SetColor(15);
		pause();
		return -1;
	}


	// ��ʼʱ���ȡ
	ULONGLONG time_start = GetTickCount64();


	// ѡ������
	UDBOPTION option;
	if (UDBGetOption(argc, argv, &option) != 0) { return 0; }

	// ��࣬ʱ�䣬��չ
	if (UDBStep1(&option) != 0) { return 0; }

	// ������������
	if (UDBStep2(&option) != 0) { return 0; }


	// ���ʱ���ȡ
	ULONGLONG time_end = GetTickCount64();

	// �������
	SetColor(6);
	printf("����������%d\n", argc);
	SetColor(15);

	if (argc != 14 && argc != 13)
	{
		SetColor(4);
		printf("�������������ز���\n");
		SetColor(15);
		for (int i = 0; i < argc; i++) { printf(" %s ", argv[i]); }
		pause();
	}
	else
	{
		SetColor(3);
		printf("������ȷ�����ںϳ�OwO\n");
		SetColor(15);
	}

	// �����Ƶ��Ϣ
	SetColor(10);
	printf("\n������Դ�ļ���%s", argv[1]);
	printf("\n�����Դ�ļ���%s", argv[2]);
	printf("\n����        ��%s", argv[3]);
	printf("\nFLAG        ��%s", argv[5]);
	printf("\nOTO         ��%s %s %s %s", argv[6], argv[7], argv[8], argv[9]);
	SetColor(15);

	// ��ʾʱ��
	SetColor(11);
	printf("\n");
	printf("\nUDB:�������OwO��ʱ��:%I64ums\n", time_end - time_start);
	printf("\n");
	SetColor(15);
	return 0;
}
