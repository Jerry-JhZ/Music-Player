
#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <io.h>

typedef struct Media {
	char name[200]; //��������
	char path[500]; //����·��
	char short_path[500]; //��·��
	int length;     //ʱ��
};

typedef struct mediaNode {
	Media media;
	int num;        //���
	struct mediaNode* pre;
	struct mediaNode* next;
};

mediaNode* createList();

mediaNode* createNode(Media music);

void headInsert(mediaNode* headNode, Media music);

Media* createMedia(const char* path);

int deleteNode(mediaNode* headNode);
