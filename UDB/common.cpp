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


//--------------------------------------------------------------
// ʵ����ֵ��Χ����
//
// ����
//  int value	ʵ��
//  int min		��Сֵ
//  int max		���ֵ
//
// ����ֵ
//  ��Χ���ƺ��ʵ����ֵ
//
// ժҪ
//  ��Сֵ���µ���Сֵ����������ֵ���ϵĻ�����ת��Ϊ���ֵ��
//--------------------------------------------------------------
double LimitDoubleValue(double value, double min, double max)
{
	if (value < min) {
		value = min;
	}
	else if (value > max) {
		value = max;
	}
	return value;
}

//--------------------------------------------------------------
// ������Χ����
// 
// ����
//  int value	���ތ���ֵ
//	int min		��Сֵ
//	int max		���ֵ
// 
// ����
//  ��Χ���ƺ������ֵ
// 
// ��Ҫ
//  ��Сֵ���µ���Сֵ����������ֵ���ϵĻ�����ת��Ϊ���ֵ��
//--------------------------------------------------------------
int LimitIntValue(int value, int min, int max)
{
	if (value < min) {
		value = min;
	}
	else if (value > max) {
		value = max;
	}
	return value;
}


//--------------------------------------------------------------
// ��չ������
//
// ����
//  char *dstStr	�ļ���
//  int dstSize		�ļ��������С
//  char *extStr	��չ��
//
// ����
//  ��
//
// ��Ҫ
//  ����չ�����ӵ��ļ�����
//--------------------------------------------------------------
void AddExtStr(char* dstStr, int dstSize, char* extStr)
{
	int len = strlen(dstStr);

	//�ļ�������չ����.��ת��Ϊ��_��
	for (int i = len - 1; i >= 0; i--) {
		if (dstStr[i] == '\\') {
			break;
		}
		if (dstStr[i] == '.') {
			dstStr[i] = '_';
			break;
		}
	}

	// ��չ������
	strcat_s(dstStr, dstSize, extStr);
}


//--------------------------------------------------------------
// ȷ���ļ�����
//
// ����
//  char *fileName	�ļ���
//
// ����
//  ���ļ���1��û���ļ���0
//
// ��Ҫ
//  �������ָ�����ļ��Ļ�������1������ļ������ڣ��򷵻�0��
//--------------------------------------------------------------
int CheckFileExist(char* fileName)
{
	int existFlg = 0;
	FILE* fp;

	fopen_s(&fp, fileName, "rb");
	if (fp != NULL) {
		fclose(fp);
		existFlg = 1;
	}

	return existFlg;
}