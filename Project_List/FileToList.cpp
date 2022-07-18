#include "FileToList.h"

mediaNode* createList() 
{
	mediaNode* headNode = (mediaNode*)malloc(sizeof(mediaNode));
	headNode->next = NULL;
	headNode->pre = NULL;
	headNode->num = 0;
	return headNode;
}
//�������
mediaNode* createNode(Media music) 
{
	mediaNode* newNode = (mediaNode*)malloc(sizeof(mediaNode));
	newNode->media = music;
	newNode->next = NULL;
	newNode->pre = NULL;
	newNode->num = 0;
	return newNode;
}
//��ͷ��������
void headInsert(mediaNode* headNode, Media music) 
{
	mediaNode* node = createNode(music);
	node->media = music;
	if (headNode->next == NULL) 
	{
		//����Ϊ��
		node->next = NULL;
		node->pre = headNode;
		headNode->next = node;
		node->num = 1;
		for (int i = 2; node->next != NULL; i++) 
		{
			node = node->next;
			node->num = i;
		}
	}
	else 
	{
		node->pre = headNode;
		node->next = headNode->next;
		headNode->next->pre = node;
		headNode->next = node;
		node->num = 1;
		for (int i = 2; node->next != NULL; i++) 
		{
			node = node->next;
			node->num = i;
		}
	}
}

Media* createMedia(const char* path)
{
	struct _finddata_t* musicInfo = (struct _finddata_t*)malloc(sizeof(struct _finddata_t));
	long handle = _findfirst(path, musicInfo);
	if (handle == -1)
	{
		return NULL; //δ�ҵ��ļ��򷵻�NULL
	}
	else
	{
		// Ϊ�½���Media�ṹ�����һ���ڴ�
		Media* newMedia = (Media*)malloc(sizeof(Media));
		// ��ʼ��Media�ṹ���еĲ���
		strcpy_s(newMedia->name, sizeof(newMedia->name), musicInfo->name);
		strcpy_s(newMedia->path, sizeof(newMedia->path), path);
		return newMedia;
	}
}
//β��ɾ�����
int deleteNode(mediaNode* headNode) {
	mediaNode* node = headNode->next;
	if (node == NULL)
	{
		return -1;
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->pre->next = NULL;
	free(node);
	return 0;
}