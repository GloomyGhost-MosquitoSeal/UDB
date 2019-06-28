
//--------------------------------------------------------------
// VocalShifter - VSLIB
//--------------------------------------------------------------

#ifndef _VSLIB_H_
#define _VSLIB_H_

#pragma comment( lib, "vslib.lib" )

#ifdef __cplusplus
#define VSLIB_IMPORT extern "C" __declspec(dllimport)
#else
#define VSLIB_IMPORT __declspec(dllimport)
#endif

//--------------------------------------------------------------
// �}�N����`
//--------------------------------------------------------------

#define VSLIB_MAX_PATH		(256)
#define VSLIB_MAX_TRACK		(64)	// �g���b�N�ő吔
#define VSLIB_MAX_ITEM		(1024)	// �A�C�e���ő吔

// �G���[�R�[�h
#define VSERR_NOERR			(0)		// �G���[�Ȃ�
#define VSERR_PRM			(1)		// �p�����[�^�s��
#define VSERR_PRJOPEN		(2)		// PRJ�t�@�C���I�[�v���Ɏ��s
#define VSERR_PRJFORMAT		(3)		// PRJ�t�@�C���t�H�[�}�b�g�s��
#define VSERR_WAVEOPEN		(4)		// WAVE�t�@�C���I�[�v���Ɏ��s
#define VSERR_WAVEFORMAT	(5)		// WAVE�t�@�C���t�H�[�}�b�g�s��
#define VSERR_FREQ			(6)		// �T���v�����O���g���s��
#define VSERR_MAX			(7)		// �ő吔����
#define VSERR_NOMEM			(8)		// �������s��

// ������������
#define SYNTHMODE_M			(0)		// �P��
#define SYNTHMODE_MF		(1)		// �P���t�H���}���g�␳
#define SYNTHMODE_P			(2)		// �a��

// �n���h����`
typedef struct HVSPRJ__ { int unused; } *HVSPRJ;

// ASAnalyzer �`�����l��
#define AS_CH_LPR			(0)
#define AS_CH_LMR			(1)
#define AS_CH_L				(2)
#define AS_CH_R				(3)

// ASAnalyzer �G���[�R�[�h
#define AS_ERR_NOERR		(0)
#define AS_ERR_NOMEM		(1)
#define AS_ERR_BADPRM		(2)
#define AS_ERR_OPEN			(3)
#define AS_ERR_FROMAT		(4)


//--------------------------------------------------------------
// �\���̒�`
//--------------------------------------------------------------

// �v���W�F�N�g���
typedef struct {
	double masterVolume;	// (R/W) �}�X�^�[�{�����[��[�{]
	int sampFreq;			// (R/W) �T���v�����O���g��[Hz]
} VSPRJINFO;

// �g���b�N���
typedef struct {
	double volume;			// (R/W) �{�����[��[�{]
	double pan;				// (R/W) �p��(-1.0�`1.0)
	int invPhaseFlg;		// (R/W) �t���t���O
	int soloFlg;			// (R/W) �\���t���O
	int muteFlg;			// (R/W) �~���[�g�t���O
} VSTRACKINFO;

// �A�C�e�����
typedef struct {
	char fileName[VSLIB_MAX_PATH];	// (R/-) �t�@�C����
	int sampFreq;			// (R/-) �T���v�����O���g��[Hz]
	int channel;			// (R/-) �`�����l����
	int sampleOrg;			// (R/-) �I���W�i���̉����t�@�C���̃T���v����
	int sampleEdit;			// (R/-) �ҏW��̃T���v����
	int ctrlPntPs;			// (R/-) 1�b������̐���_��
	int ctrlPntNum;			// (R/-) �S����_��
	int synthMode;			// (R/W) ������������
	int trackNum;			// (R/W) �g���b�N�ԍ�
	int offset;				// (R/W) �I�t�Z�b�g[sample]
} VSITEMINFO;

// �A�C�e������_���
typedef struct {
	double dynOrg;			// (R/-) �ҏW�O�_�C�i�~�N�X[�{]
	double dynEdit;			// (R/W) �ҏW��_�C�i�~�N�X[�{]
	double volume;			// (R/W) �{�����[��[�{]
	double pan;				// (R/W) �p��(-1.0�`1.0)
	double spcDyn;			// (R/-) �X�y�N�g���_�C�i�~�N�X
	int pitAna;				// (R/-) �s�b�`��͒l[cent]
	int pitOrg;				// (R/W) �ҏW�O�s�b�`[cent]
	int pitEdit;			// (R/W) �ҏW��s�b�`[cent]
	int formant;			// (R/W) �t�H���}���g[cent]
	int pitFlgOrg;			// (R/-) �ҏW�O�s�b�`�L���t���O
	int pitFlgEdit;			// (R/W) �ҏW��s�b�`�L���t���O
	int breathiness;		// (R/W) �u���V�l�X[-10000�`10000]
	int eq1;				// (R/W) EQ1[-10000�`10000]
	int eq2;				// (R/W) EQ2[-10000�`10000]
} VSCPINFOEX;

// ASAnalyzer AWDINFO�\����
typedef struct {
	int wavdatasize;	// �f�[�^�̃T�C�Y[�T���v��]
	int wavsampleps;	// �T���v�����O���g��[Hz]
	int wavbit;			// �r�b�g��(8or16)
	int wavchannel;		// �`�����l����(1or2)
	int nnoffset;		// ��͂���Œቹ[�m�[�g�i���o�[]
	int nnrange;		// ��͂��鉹�K�͈̔�[����]
	int blockpn;		// ����������̃u���b�N��(1-20)
	int dynsize;		// ���ʌ��o���[�T���v��]
	int targetch;		// �Ώۂ̃`�����l��
} AWDINFO;


//--------------------------------------------------------------
// �v���g�^�C�v�錾
//--------------------------------------------------------------

// ���C�u����
VSLIB_IMPORT int __stdcall VslibGetVersion(void);

// �v���W�F�N�g
VSLIB_IMPORT int __stdcall VslibCreateProject(HVSPRJ* hVsprj);
VSLIB_IMPORT int __stdcall VslibOpenProject(HVSPRJ* hVsprj, char* fileName);
VSLIB_IMPORT int __stdcall VslibSaveProject(HVSPRJ hVsprj, char* fileName);
VSLIB_IMPORT int __stdcall VslibDeleteProject(HVSPRJ hVsprj);
VSLIB_IMPORT int __stdcall VslibGetProjectInfo(HVSPRJ hVsprj, VSPRJINFO* vsPrjInfo);
VSLIB_IMPORT int __stdcall VslibSetProjectInfo(HVSPRJ hVsprj, VSPRJINFO* vsPrjInfo);

// �g���b�N
VSLIB_IMPORT int __stdcall VslibGetTrackMaxNum(HVSPRJ hVsprj, int* trackMaxNum);
VSLIB_IMPORT int __stdcall VslibAddTrack(HVSPRJ hVsprj);
VSLIB_IMPORT int __stdcall VslibCopyTrack(HVSPRJ hVsprjDst, int* trackNumDst, HVSPRJ hVsprjSrc, int trackNumsrc);
VSLIB_IMPORT int __stdcall VslibUpTrack(HVSPRJ hVsprj, int trackNum);
VSLIB_IMPORT int __stdcall VslibDownTrack(HVSPRJ hVsprj, int trackNum);
VSLIB_IMPORT int __stdcall VslibDeleteTrack(HVSPRJ hVsprj, int trackNum);
VSLIB_IMPORT int __stdcall VslibGetTrackInfo(HVSPRJ hVsprj, int trackNum, VSTRACKINFO* vsTrackInfo);
VSLIB_IMPORT int __stdcall VslibSetTrackInfo(HVSPRJ hVsprj, int trackNum, VSTRACKINFO* vsTrackInfo);

// �A�C�e��
VSLIB_IMPORT int __stdcall VslibGetItemMaxNum(HVSPRJ hVsprj, int* itemMaxNum);
VSLIB_IMPORT int __stdcall VslibAddItem(HVSPRJ hVsprj, char* fileName, int* itemNum);
VSLIB_IMPORT int __stdcall VslibAddItemEx(HVSPRJ hVsprj, char* fileName, int* itemNum,
	int nnOffset, int nnRange, int skipPitFlg);
VSLIB_IMPORT int __stdcall VslibCopyItem(HVSPRJ hVsprjDst, int* itemNumDst, HVSPRJ hVsprjSrc, int itemNumSrc);
VSLIB_IMPORT int __stdcall VslibDeleteItem(HVSPRJ hVsprj, int itemNum);
VSLIB_IMPORT int __stdcall VslibGetItemInfo(HVSPRJ hVsprj, int itemNum, VSITEMINFO* vsItemInfo);
VSLIB_IMPORT int __stdcall VslibSetItemInfo(HVSPRJ hVsprj, int itemNum, VSITEMINFO* vsItemInfo);
VSLIB_IMPORT int __stdcall VslibGetCtrlPntInfoEx(HVSPRJ hVsprj, int itemNum, int pntNum, VSCPINFOEX* vsCpInfo);
VSLIB_IMPORT int __stdcall VslibSetCtrlPntInfoEx(HVSPRJ hVsprj, int itemNum, int pntNum, VSCPINFOEX* vsCpInfo);

VSLIB_IMPORT int __stdcall VslibGetEQGain(HVSPRJ hVsprj, int itemNum, int eqNum, int* gain);
VSLIB_IMPORT int __stdcall VslibSetEQGain(HVSPRJ hVsprj, int itemNum, int eqNum, int* gain);

// �^�C�~���O
VSLIB_IMPORT int __stdcall VslibGetTimeCtrlPntNum(HVSPRJ hVsprj, int itemNum, int* timeCtrlPntNum);
VSLIB_IMPORT int __stdcall VslibGetTimeCtrlPnt(HVSPRJ hVsprj, int itemNum, int pntNum, int* time1, int* time2);
VSLIB_IMPORT int __stdcall VslibSetTimeCtrlPnt(HVSPRJ hVsprj, int itemNum, int pntNum, int time1, int time2);
VSLIB_IMPORT int __stdcall VslibAddTimeCtrlPnt(HVSPRJ hVsprj, int itemNum, int time1, int time2);
VSLIB_IMPORT int __stdcall VslibDeleteTimeCtrlPnt(HVSPRJ hVsprj, int itemNum, int pntNum);

VSLIB_IMPORT int __stdcall VslibGetStretchOrgSec(HVSPRJ hVsprj, int itemNum, double time_edt, double* time_org);
VSLIB_IMPORT int __stdcall VslibGetStretchEditSec(HVSPRJ hVsprj, int itemNum, double time_org, double* time_edt);
VSLIB_IMPORT int __stdcall VslibGetStretchOrgSample(HVSPRJ hVsprj, int itemNum, double time_edt, double* time_org);
VSLIB_IMPORT int __stdcall VslibGetStretchEditSample(HVSPRJ hVsprj, int itemNum, double time_org, double* time_edt);

// �~�L�T�[
VSLIB_IMPORT int __stdcall VslibGetMixSample(HVSPRJ hVsprj, int* mixSample);
VSLIB_IMPORT int __stdcall VslibGetMixData(HVSPRJ hVsprj, void* waveData, int bit, int channel, int index, int size);
VSLIB_IMPORT int __stdcall VslibExportWaveFile(HVSPRJ hVsprj, char* fileName, int bit, int channel);

// �P�ʕϊ�
VSLIB_IMPORT double __stdcall VslibCent2Freq(int cent);
VSLIB_IMPORT int __stdcall VslibFreq2Cent(double freq);
VSLIB_IMPORT double __stdcall VslibNoteNum2Freq(int noteNum);
VSLIB_IMPORT int __stdcall VslibFreq2NoteNum(double freq);

// ���̑�
VSLIB_IMPORT int __stdcall VslibSetPitchArray(HVSPRJ hVsprj, int itemNum, int* pitData, int nPitData, double interval);

// ASAnalyzer
VSLIB_IMPORT int __stdcall AS_GetDllVer(void);
VSLIB_IMPORT double __stdcall AS_Cent2Freq(int cent, double freqa4);
VSLIB_IMPORT int __stdcall AS_Freq2Cent(double freq, double freqa4);
VSLIB_IMPORT double __stdcall AS_Nnum2Freq(int nnum, double freqa4);
VSLIB_IMPORT int __stdcall AS_Freq2Nnum(double freq, double freqa4);

VSLIB_IMPORT int __stdcall AS_AnalyzeWaveData(void* wavdata, unsigned short sndspc[], int* pitch, int wavdatasize,
	int wavsampleps, int wavbit, int wavchannel, int nnoffset, int nnrange, int blockpn, int targetch, double freqa4);
VSLIB_IMPORT int __stdcall AS_AnalyzeWaveDataEX(void* wavdata, unsigned short* sndspc,
	int* pitch, int* dynamics, AWDINFO* awdi, double freqa4);
VSLIB_IMPORT int __stdcall AS_AnalyzeWaveFile(char* wavfile, char* txtfile, int blockps, int nnoffset, int nnrange);


#endif /* _VSLIB_H_ */

