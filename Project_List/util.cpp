#include "util.h"
#include<graphics.h>
char* wday[] = { (char*)"Sun", (char*)"Mon", (char*)"Tue", (char*)"Wed", (char*)"Thu", (char*)"Fri", (char*)"Sat" };

using namespace std;
//ͨ��MCI�ӿ�APIָ����������ļ�
// �ɹ�: return 0
// ʧ��: return !=0
// returnString: ���ش����ַ�����Ϣ
//
int mciSendStringUtil(const char* url, char* returnString)
{
	if (url == NULL)
	{
		if (0 != mciSendString(url, NULL, 0, NULL))
		{
			return -1;
		}
		else {
			return 0;
		}
	}
	else
	{
		if (0 != mciSendString(url, returnString, 1024, NULL)) 
		{
			return -2;
		}
		else {
			return 0;
		}
	}
}

//���豸: Ĭ��MP3
// ͨ��MCI�ӿ�APIָ����������ļ�
// ����mciSendStringָ���װ��mciSendStringUtil��
// ͨ��open�ַ���ƴ�Ӵ��β��������"MyMusic"
// ������ͬ����ֻ��ָ������
// �ɹ�: return 0
// ʧ��: return !=0
//
int openMusic(const char* url)
{
	if (url != NULL) 
	{
		char cmd[500] = "";
		strcpy_s(cmd, "open \"");
		strcat_s(cmd, url);
		strcat_s(cmd, "\"");
		strcat_s(cmd, " alias MyMusic");
		if (mciSendStringUtil(cmd, NULL) == 0)
		{
			return 0;
		}
	}
}

//���º����н�����MyMusic����
// ͨ��������mciSendString�ӿڴ���
// ��������open����:
// ����open�豸����ΪMyMusic
//

//�豸��ʼ��������
int playMusic()
{
	char cmd[500] = "play MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//�豸��ͣ��������
int pauseMusic()
{
	char cmd[500] = "pause MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//�豸������������
int resumeMusic() 
{
	char cmd[500] = "resume MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//�豸ֹͣ��������
int stopMusic()
{
	char cmd[500] = "stop MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//�豸�ظ���������
int playMusicRepeat()
{
	char cmd[1000] = "play MyMusic repeat";
	return mciSendStringUtil(cmd, NULL);
}

//�豸�ر�
// �豸�رսӿڣ���������ֹͣ�ӿ�
int closeMusic()
{
	char cmd[1000] = "close MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//���ص�ǰ����λ��
int getMusicPosition()
{
	char szTimeBuffer[1024];
	mciSendStringUtil("status MyMusic position", szTimeBuffer);
	return atoi(szTimeBuffer);
}

//���ز������ֵ��ܳ���
int getMusicLength()
{
	char szTimeBuffer[1024];
	mciSendStringUtil("status MyMusic length", szTimeBuffer);
	return atoi(szTimeBuffer);
}

//����ָ������λ��
// ͨ���ⲿ����positionʵ��
// ִ��"seek ���� to λ��"ָ��
// ʹ���ֵ���ָ��λ��:
// ����˵��: 
// //����λ��: position
// //��λ���ֿ�ͷλ��: start
// //��λ�������λ��: end
//
int gotoPosition(int position)
{
	char cmd[1000] = "";
	sprintf(cmd, "seek MyMusic to %d", position);
	return mciSendStringUtil(cmd, NULL);
}

int getMusicSpeed()
{
	char szSpeedBuffer[1024];
	mciSendStringUtil("status MyMusic speed", szSpeedBuffer);
	return atoi(szSpeedBuffer);
}

void setMusicSpeed(int speed)
{
	char cmd[1000] = "";
	sprintf(cmd, "set MyMusic speed %d", speed);
	mciSendStringUtil(cmd, NULL);
}

void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// �ṹ��ĵ�������Ա��ʾ�����͸���ȣ�0 ��ʾȫ͸����255 ��ʾ��͸����
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	// ʹ�� Windows GDI ����ʵ�ְ�͸��λͼ
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void change() //ʵ���ޱ߿򴰿�
{
	HWND hnd = GetHWnd();//��ȡ���ھ��
	SetWindowText(hnd, "���������ֲ�����");
}

void upTo10s()
{
	int time = getMusicPosition() + 10000;
	if (time > getMusicLength())
	{
		time = getMusicLength();
	}
	gotoPosition(time);
	playMusic();
}

void downTo10s()
{
	int time = getMusicPosition() - 10000;
	if (time < 0)
	{
		time = 0;
	}
	gotoPosition(time);
	playMusic();
}

void addVolume() 
{
	char vo[20];
	char res[260];
	char file1[100] = "setaudio MyMusic volume to "; // to����һ��Ҫ�пո񣬲�Ȼ�ᱨ��
	
	mciSendString("status MyMusic volume", res, 260, NULL);
	int volume = 0;
	volume = atoi(res); // ת�����
	volume += 200;
	if (volume >= 1000)
		volume = 1000;
	itoa(volume, vo, 10); //ת�����
	strcat(file1, vo); // ��vo����file1����
	mciSendString(file1, 0, 0, 0); // �趨�ɹ�
}

void lowVolume() 
{
	char vo[20];
	char res[260];
	char file1[100] = "setaudio MyMusic volume to "; // to����һ��Ҫ�пո񣬲�Ȼ�ᱨ��
	mciSendString("status MyMusic volume", res, 260, NULL);
	int volume = 0;
	volume = atoi(res); // ת�����
	volume -= 200;
	if (volume <= 0)
		volume = 0;
	itoa(volume, vo, 10); //ת�����
	strcat(file1, vo); // ��vo����file1����
	mciSendString(file1, 0, 0,0); // �趨�ɹ�
}

int w_log(char a[100])
{
	FILE* fpWrite = fopen("D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\log.txt", "a");
	if (fpWrite == NULL)
	{
		return 0;
	}
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(fpWrite, "%d.%d.%d ", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	fprintf(fpWrite, "%s %d:%d:%d -- %s\n", wday[p->tm_wday], p->tm_hour - 4, p->tm_min, p->tm_sec, a);
	fclose(fpWrite);
}
//���ɾ������MCI��APIָ���װΪ�򵥵Ľӿ�
// mci���ɹ��߼�: util.cpp
//