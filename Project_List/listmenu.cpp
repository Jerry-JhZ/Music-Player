#include"listmenu.h"

void listmenu() 
{
	initgraph(640, 480, 0);

	//����ͼƬ
	IMAGE img;
	loadimage(&img, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\musiclist.png");
	putimage(0, 0, &img);
	transparentimage(NULL, 0, 0, &img);

	//����ͼ��
	IMAGE back;
	loadimage(&back, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);
	printList();

	//���ͼ��
	IMAGE add1;
	loadimage(&add1, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add.png", 40, 40);
	IMAGE add2;
	loadimage(&add2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add2.png", 40, 40);
	transparentimage(NULL, 238, 284, &add1);

	//����ͼ��
	IMAGE add1_lr;
	loadimage(&add1_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut.png", 40, 40);
	IMAGE add2_lr;
	loadimage(&add2_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut2.png", 40, 40);
	transparentimage(NULL, 238, 359, &add1_lr);

	while (1)
	{

		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//����
				{
					closegraph();
					menu();

				}//�������

				if (msg.x >= 238 && msg.x <= 278 && msg.y <= 324 && msg.y >= 284)//���
				{
					w_log((char*)"add one music");
					transparentimage(NULL, 92, 576, &add2);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 92, 576, &add1);
					setnum(getnum() + 1);
					add();
					//���ñ���ͼƬ
					fundmantual2();
				}

				if (msg.x >= 238 && msg.x <= 278 && msg.y <= 419 && msg.y >= 359)//ɾ��
				{
					w_log((char*)"delete one music");
					transparentimage(NULL, 612, 576, &add2_lr);//��ɫ�İ�ť
					Sleep(100);
					transparentimage(NULL, 612, 576, &add1_lr);
					if (getnum() == getNumOfNode()) {
						setnum(getnum() - 1);
						closeMusic();
					}
					del();
					//���ñ���ͼƬ
					fundmantual2();
				}
			}
		}
	}
}

void fundmantual2()
{
	initgraph(640, 480, 0);

	//����ͼƬ
	IMAGE img;
	loadimage(&img, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\musiclist.png");
	putimage(0, 0, &img);
	transparentimage(NULL, 0, 0, &img);

	//����ͼ��
	IMAGE back;
	loadimage(&back, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);
	printList();

	//���ͼ��
	IMAGE add1;
	loadimage(&add1, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add.png", 40, 40);
	IMAGE add2;
	loadimage(&add2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add2.png", 40, 40);
	transparentimage(NULL, 238, 284, &add1);

	//����ͼ��
	IMAGE add1_lr;
	loadimage(&add1_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut.png", 40, 40);
	IMAGE add2_lr;
	loadimage(&add2_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut2.png", 40, 40);
	transparentimage(NULL, 238, 359, &add1_lr);
}