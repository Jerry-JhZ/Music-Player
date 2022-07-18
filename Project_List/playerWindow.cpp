#include "playerWindow.h"
#include "playerPage.h"
#include "menuPage.h"

char nowName[100];

// ����ģʽȫ��ö��
enum PLAY_STATUS play_mode = STATUS_PLAY_SEQUENCE;
char play_status[1000];
// ����״̬ȫ��ö��
enum STATUS status = STATUS_STOPPED;
char status_now[1000];
int num = 0;
int progress_length = 90;//����������
double t = 0;
double t1 = 0;
double c = 0;

void createWindow()
{
	initgraph(720, 960,0);
	char a[1000] = "";
	strcpy(a, getPath(num));

	openMusic(a);
	
	setbkcolor(WHITE);

	change();

	//���ñ���ͼƬ
	IMAGE image;
	loadimage(&image, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\background.png");
	putimage(0, 0, &image);
	transparentimage(NULL,0, 0, &image);

	//��ͣ��ť
	IMAGE pause;
	IMAGE play2;
	IMAGE play;
	loadimage(&play2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play2.png", 81, 81);
	loadimage(&pause, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play.png", 81, 81);
	transparentimage(NULL, 334, 652, &pause);

	//��һ��ͼ��
	IMAGE last;
	loadimage(&last, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last.png", 50, 50);
	IMAGE last2;
	loadimage(&last2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last2.png", 50, 50);
	transparentimage(NULL, 194, 666, &last);

	//��һ��ͼ��
	IMAGE next;
	loadimage(&next, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next.png", 50, 50);
	IMAGE next2;
	loadimage(&next2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next2.png", 50, 50);
	transparentimage(NULL, 498, 671, &next);

	//��ģʽͼ��
	IMAGE change;
	loadimage(&change, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change.png",30,30);
	IMAGE change2;
	loadimage(&change2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change2.png",30,30);
	transparentimage(NULL, 92, 678, &change);

	//���ͼ��
	IMAGE up;
	loadimage(&up, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up.png", 36, 36);
	IMAGE up2;
	loadimage(&up2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up2.png", 36, 36);
	transparentimage(NULL, 618, 748, &up);

	//����ͼ��
	IMAGE down;
	loadimage(&down, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down.png", 36, 36);
	IMAGE down2;
	loadimage(&down2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down2.png", 36, 36);
	transparentimage(NULL, 94, 748, &down);

	//������ͼ��
	IMAGE add1;
	loadimage(&add1, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add.png", 40, 40);
	IMAGE add2;
	loadimage(&add2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add2.png", 40, 40);
	transparentimage(NULL, 170, 870, &add1);

	//��������ͼ��
	IMAGE add1_lr;
	loadimage(&add1_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut.png", 40, 40);
	IMAGE add2_lr;
	loadimage(&add2_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut2.png", 40, 40);
	transparentimage(NULL, 230, 870, &add1_lr);

	IMAGE back;
	loadimage(&back, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);

	IMAGE circle;
	loadimage(&circle, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\BREATHE.png", 340, 340);
	transparentimage(NULL, 110, 40, &circle);

	IMAGE issue;
	loadimage(&issue, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\issue.png", 36, 36);
	transparentimage(NULL, 608, 675, &issue);

	setbkmode(TRANSPARENT);//�����������ʱ����Ϊ͸��

	while (1)//Ҫ�ø�ѭ�������ϼ������¼�
	{
		strcpy(nowName, getName(num));
		printtext(242, 755, nowName);
		printtext(91, 598, play_status);	

		//������
		t = getMusicLength();
		t1 = getMusicPosition();
		if (t != 0)
			c = t1 / t;
		progress_length = c * 523 + 90;
		fillroundrect(90, 830, progress_length, 825, 10, 10);

		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			switch (msg.uMsg)
			{

			case WM_LBUTTONDOWN:
				if (msg.x >= 334 && msg.x <= 412 && msg.y <= 732 && msg.y >= 652)//���Ű�ť
				{	
					w_log((char*)"start/stop success");
					printtext(2222, 755, getName(num));
					printtext(91, 598, play_status);
					strcpy(a, (const char*)getPath(num));//������·��
					openMusic(a);
					if (status == STATUS_STOPPED)
					{

						transparentimage(NULL, 334, 652, &play2);//��ɫ�İ�ť
						Sleep(100);
						transparentimage(NULL, 334, 652, &pause);
						playMusic();
						status = STATUS_PLAY;
						strcpy(status_now, "���ڲ�����");
					}
					else if (status == STATUS_PLAY)
					{
						transparentimage(NULL, 334, 652, &play2);//��ɫ�İ�ť
						Sleep(100);
						transparentimage(NULL, 334, 652, &pause);
						pauseMusic();
						status = STATUS_PAUSE;
						strcpy(status_now, "��ͣ��");
					}
					else if (status == STATUS_PAUSE)
					{
						transparentimage(NULL, 334, 652, &play2);//��ɫ�İ�ť
						Sleep(100);
						transparentimage(NULL, 334, 652, &pause);
						resumeMusic();
						status = STATUS_PLAY;
						strcpy(status_now, "���ڲ�����");
					}

				}//������ż�

				if (msg.x >= 202 && msg.x <= 236 && msg.y <= 709 && msg.y >= 676)//��һ��
				{
					w_log((char*)"up next success");
					transparentimage(NULL, 194, 666, &last2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 194, 666, &last);
					if (num > 1)
					{
						num -= 1;
					}
					//�����߼�
					fillroundrect(96, 830, 613, 825, 10, 10);

					closeMusic();
					fundmantual();
	
					printtext(91, 598, play_status);
					strcpy(a, (const char*)getPath(num));//������·��

					openMusic(a);
					playMusic();
				}

				if (msg.x >= 506 && msg.x <= 542 && msg.y <= 711 && msg.y >= 676)//��һ��
				{
					w_log((char*)"down next success");
					transparentimage(NULL, 498, 671, &next2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 498, 671, &next);
					if (num < getNumOfNode())
					{
						num += 1;
					}
					fillroundrect(96, 830, 613, 825, 10, 10);
					closeMusic();
					fundmantual();

					printtext(91, 598, play_status);
					strcpy(a, (const char*)getPath(num));//������·��

					openMusic(a);
					playMusic();
				}

				if (msg.x >= 618 && msg.x <= 654 && msg.y <= 784 && msg.y >= 748)//���
				{
					w_log((char*)"quick up success");
					transparentimage(NULL, 618, 748, &up2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 618, 748, &up);
					//�����߼�
					upTo10s();
				}

				if (msg.x >= 94 && msg.x <= 130 && msg.y <= 784 && msg.y >= 748)//����
				{
					w_log((char*)"quick back success");
					transparentimage(NULL, 94, 748, &down2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 94, 748, &down);
					//�����߼�
					downTo10s();
					fundmantual();
				}

				//���ֲ���ģʽ
				if (msg.x >= 92 && msg.x <= 122 && msg.y <= 708 && msg.y >= 678)
				{
					transparentimage(NULL, 92, 678, &change2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 92, 678, &change);
					if (play_mode == STATUS_PLAY_SEQUENCE)
					{
						w_log((char*)"now play_mode random");
						play_mode = STATUS_PLAY_RANDOM;
						strcpy(play_status, "��ǰ����״̬:  �������");
						fundmantual();
					}
					else if (play_mode == STATUS_PLAY_RANDOM)
					{
						w_log((char*)"now play_mode repeat");
						play_mode = STATUS_PLAY_REPEAT;
						strcpy(play_status, "��ǰ����״̬:  ����ѭ��");
						fundmantual();
					}
					else if (play_mode == STATUS_PLAY_REPEAT)
					{
						w_log((char*)"now play_mode sequence");
						play_mode = STATUS_PLAY_SEQUENCE;
						strcpy(play_status, "��ǰ����״̬:  �б���");
						fundmantual();
					}
				}

				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//����
				{
					closegraph();
					menu();

				}//�������

				if (msg.x >= 170 && msg.x <= 210 && msg.y <= 910 && msg.y >= 870)//������
				{
					w_log((char*)"addVolume");
					transparentimage(NULL, 170, 870, &add2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 170, 870, &add1);
					addVolume();
				}

				if (msg.x >= 230 && msg.x <= 270 && msg.y <= 910 && msg.y >= 870)//������
				{
					w_log((char*)"lowVolume");
					transparentimage(NULL, 230, 870, &add2_lr);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 230, 870, &add1_lr);
					lowVolume();
				}

				if (msg.x >= 608 && msg.x <= 644 && msg.y <= 711 && msg.y >= 675)//����������
				{

				/*	transparentimage(NULL, 608, 675, &issue);*/
					//�����߼�
					WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://www.musicbooks.cn/", 1);
				}

				break;
			}
		}

		if (getMusicLength() == getMusicPosition() && play_mode == STATUS_PLAY_SEQUENCE && num > 0)//�б���״̬���߼�
		{
			if (num > 1)
			{
				num -= 1;
			}
			//�����߼�
			fillroundrect(96, 830, 613, 825, 10, 10);
			closeMusic();
			fundmantual();
			printtext(91, 598, play_status);
			strcpy(a, (const char*)getPath(num));//������·��
			openMusic(a);
			playMusic();
		}
		if (getMusicLength() == getMusicPosition() && play_mode == STATUS_PLAY_REPEAT && num > 0)
		{
			fillroundrect(96, 830, 613, 825, 10, 10);
			closeMusic();
			fundmantual();
			printtext(91, 598, play_status);
			strcpy(a, (const char*)getPath(num));//������·��
			openMusic(a);
			playMusic();
		}
		if (getMusicLength() == getMusicPosition() && play_mode == STATUS_PLAY_RANDOM && num > 0)
		{
			if (num > 0)
			{
				num = rand() % (getNumOfNode()) + 1;
			}
			
			fillroundrect(96, 830, 613, 825, 10, 10);
			closeMusic();
			fundmantual();
			printtext(91, 598, play_status);
			strcpy(a, (const char*)getPath(num));//������·��
			openMusic(a);
			playMusic();
		}
	}
}

void fundmantual()
{
	initgraph(720, 960, 0);
	char a[1000] = "";
	strcpy(a, getPath(num));

	openMusic(a);
	setbkcolor(WHITE);

	change();

	//���ñ���ͼƬ
	IMAGE image;
	loadimage(&image, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\background.png");
	putimage(0, 0, &image);
	transparentimage(NULL, 0, 0, &image);

	//��ͣ��ť
	IMAGE pause;
	IMAGE play2;
	IMAGE play;
	loadimage(&play2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play2.png", 81, 81);
	loadimage(&pause, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play.png", 81, 81);
	transparentimage(NULL, 334, 652, &pause);

	//��һ��ͼ��
	IMAGE last;
	loadimage(&last, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last.png", 50, 50);
	IMAGE last2;
	loadimage(&last2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last2.png", 50, 50);
	transparentimage(NULL, 194, 666, &last);

	//��һ��ͼ��
	IMAGE next;
	loadimage(&next, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next.png", 50, 50);
	IMAGE next2;
	loadimage(&next2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next2.png", 50, 50);
	transparentimage(NULL, 498, 671, &next);

	//��ģʽͼ��
	IMAGE change;
	loadimage(&change, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change.png", 30, 30);
	IMAGE change2;
	loadimage(&change2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change2.png",30, 30);
	transparentimage(NULL, 92, 678, &change);

	//���ͼ��
	IMAGE up;
	loadimage(&up, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up.png", 36, 36);
	IMAGE up2;
	loadimage(&up2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up2.png", 36, 36);
	transparentimage(NULL, 618, 748, &up);

	//����ͼ��
	IMAGE down;
	loadimage(&down, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down.png", 36, 36);
	IMAGE down2;
	loadimage(&down2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down2.png", 36, 36);
	transparentimage(NULL, 94, 748, &down);

	IMAGE back;
	loadimage(&back, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);

	IMAGE circle;
	loadimage(&circle, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\BREATHE.png", 340, 340);
	transparentimage(NULL, 110, 40, &circle);

	//������ͼ��
	IMAGE add1;
	loadimage(&add1, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add.png", 40, 40);
	IMAGE add2;
	loadimage(&add2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add2.png", 40, 40);
	transparentimage(NULL, 170, 870, &add1);

	//��������ͼ��
	IMAGE add1_lr;
	loadimage(&add1_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut.png", 40, 40);
	IMAGE add2_lr;
	loadimage(&add2_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut2.png", 40, 40);
	transparentimage(NULL, 230, 870, &add1_lr);

	IMAGE issue;
	loadimage(&issue, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\issue.png", 36, 36);
	transparentimage(NULL, 608, 675, &issue);

}

char* attainlength(int time) {
	int fen = 0;
	int miao = 0;
	miao = (int)time / 1000;
	fen = (int)miao / 60;
	miao = (int)miao - fen * 60;
	char f[100];//��
	char m[100];//��
	char tatol[100];//�ܵ�
	itoa(miao, m, 10);
	itoa(fen, f, 10);
	strcpy(tatol, f);
	strcat(tatol, " : ");
	if (miao < 10)
	{
		strcat(tatol, "0");
	}
	strcat(tatol, m);
	return tatol;
}

void printtext(int x, int y,char text[100])
{
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);//�����������ʱ����Ϊ͸��
	outtextxy(x, y, text);
}

int getnum()
{
	return num;
}

void setnum(int n)
{
	num = n;
}