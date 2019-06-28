#pragma once

#ifndef _UDB_H_
#define _UDB_H_


#define M_PI			(3.14159265358979323846)

#define M_PI2           (6.28)

#define UDB_MAX_PATH	(260)

#define UDB_PBSIZE		(65536)


typedef struct {
	char inputWaveFile[UDB_MAX_PATH];
	char outputWaveFile[UDB_MAX_PATH];
	char frqFile[UDB_MAX_PATH];
	char GfrqFile[UDB_MAX_PATH];
	char gFile[UDB_MAX_PATH];

	int noteNum;
	double offset;
	double reqLength;
	double fixedLength;
	double endBlank;
	double fixSpeed;

	double volume;
	double modulation;
	double tempo;
	int nPitchBend;
	int pitchBend[UDB_PBSIZE];


	// Flag
	int noFormantFlg;			// noFormantFlg					("N",Ĭ��OFF)
	int genderFactor;			// �Ա�ֵ[-20cent]				("g",-100��100,��ʼֵ0)
	int pitchShift;				// pitch΢��[10cent]			("t",-240��240,��ʼֵ0)
	int pitchShift2;			// pitch΢��[1cent]				("T",-2400��2400,��ʼֵ0)
	int peekCmp;				// ��ֵ���� 					("P",0��100,��ʼֵ86)
	int lowPassfilter;			// ��ͨ���˲���					("H",0��99,��ʼֵ0)
	int breathiness;			// ����ֵ						("B",0��100,��ʼֵ50)
	int brightness;				// ����ֵ						("O",-100��100,��ʼֵ0)
	int clearness;				// Clearֵ						("S",-100��100,��ʼֵ0)
	int outputVshpFlg;			// ���Vshp�ļ�					("Z",��ʼֵOFF)
	int reGenerateFrqFlg;		// ��������Ƶ�ʱ�				("V",��ʼֵOFF)
	int disablePitchShift;		// PitchShift�ر�				("W",����ֵ0)
	int ShowOption;				// �ļ��������					("D",����ֵ0)

	short* tmpWaveData;
	int tmpSample;
	int tmpSmpFreq;
} UDBOPTION;


typedef struct {
	double freq;
	double dyn;
} FREQDATA;


// Common
double LimitDoubleValue(double value, double min, double max);
int LimitIntValue(int value, int min, int max);
void AddExtStr(char* dstStr, int dstSize, char* extStr);
int CheckFileExist(char* fileName);

// Option
int UDBGetOption(int argc, char* argv[], UDBOPTION* option);
int UDBCnvNoteNum(char* nnStr);
int UDBSetFlgOption(char* flgStr, UDBOPTION* option);
int UDBDecodeBase64(char* str);
int UDBSetPitchBendOption(char* argv[], UDBOPTION* option);
int ShowBPM(UDBOPTION* option);

// Pitch
int UDBStep1(UDBOPTION* option);
HVSPRJ UDBLoadProject(UDBOPTION* option);
int UDBSetTimeStretchPrm(HVSPRJ hVsprj, UDBOPTION* option);
int UDBLoadFrqFile(HVSPRJ hVsprj, UDBOPTION* option);
int UDBCalcAveragePit(HVSPRJ hVsprj, UDBOPTION* option);
int UDBSetPitPrm(HVSPRJ hVsprj, UDBOPTION* option);

// Vol
int UDBStep2(UDBOPTION* option);
int UDBLowPassFilter(UDBOPTION* option);
int UDBVolume(UDBOPTION* option);
int UDBOutputWaveFile(UDBOPTION* option);

#endif 

