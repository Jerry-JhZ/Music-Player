#pragma once
#include "all.h"

// �������ֲ�ͬ�Ĳ���ģʽ
enum PLAY_STATUS
{
	STATUS_PLAY_SEQUENCE = 0,
	STATUS_PLAY_REPEAT,
	STATUS_PLAY_RANDOM,
};

// ����ǰ���ֵĲ���״̬
enum STATUS
{
	STATUS_PLAY = 0,
	STATUS_PAUSE,
	STATUS_STOPPED,
};

//ͨ��MCI�ӿ�APIָ����������ļ�
// �ɹ�: return 0
// ʧ��: return !=0
// returnString: ���ش����ַ�����Ϣ
//
int mciSendStringUtil(const char* url, char* returnString);

//���豸: Ĭ��MP3
// ͨ��MCI�ӿ�APIָ����������ļ�
// ����mciSendStringָ���װ��mciSendStringUtil��
// ͨ��open�ַ���ƴ�Ӵ��β��������"MyMusic"
// ������ͬ����ֻ��ָ������
// �ɹ�: return 0
// ʧ��: return !=0
//
int openMusic(const char* url);

//���º����н�����MyMusic����
// ͨ��������mciSendString�ӿڴ���
// ��������open����:
// ����open�豸����ΪMyMusic
//

//�豸��ʼ��������
int playMusic();

//�豸��ͣ��������
int pauseMusic();

//�豸������������
int resumeMusic();

//�豸ֹͣ��������
int stopMusic();

//�豸�ظ���������
int playMusicRepeat();

//�豸�ر�
// �豸�رսӿڣ���������ֹͣ�ӿ�
//
int closeMusic();

//���ص�ǰ����λ��
int getMusicPosition();

//���ز������ֵ��ܳ���
int getMusicLength();

//����ָ������λ��
// ͨ���ⲿ����positionʵ��
// ִ��"seek ���� to λ��"ָ��
// ʹ���ֵ���ָ��λ��:
// ����˵��: 
// //����λ��: position
// //��λ���ֿ�ͷλ��: start
// //��λ�������λ��: end
//
int gotoPosition(int position);

int getMusicSpeed();

void setMusicSpeed(int speed);

void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);

void change();

void addVolume();

void lowVolume();

int w_log(char a[100]);

//���ɾ������MCI��APIָ���װΪ�򵥵Ľӿ�
// mci���ɹ��߼�: util.cpp
//