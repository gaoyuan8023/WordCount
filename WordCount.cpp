#include<stdio.h>
#include<string.h>
int main(int argc, char** argv)
{
	if (argc < 3)
	{
		printf("����������\n");
		printf("-c:ͳ���ַ���\n");
		printf("-w:ͳ�Ƶ�����\n");
		return 0;
	}
	if (strcmp("-c", argv[1])==0) {
		char str[1024];
		FILE* fp;
		if (fopen_s(&fp, argv[2], "r")==0)
		{
			int count = 0;
			while (fgets(str, 1024, fp) != NULL)
			{
				int j = 0;
				while (str[j] != '\0')
				{
					count++;
					j++;
				}
			}
			printf("�ַ�����%d\n", count);
		}
		else
		{
			printf("�ļ���ʧ��\n");
		}
	}
	else if (strcmp("-w", argv[1]) == 0)
	{
		char str[1024];
		FILE* fp;
		if (fopen_s(&fp, argv[2], "r") == 0)
		{
			int count = 0;
			while (fgets(str, 1024, fp) != NULL)
			{
				int j = 0;
				while (str[j] != '\0')
				{
					if(str[0] != '\0' && (str[0] == ' ' || str[0] == ',' || str[0] == '.'))
						while (str[j] == ' ' || str[j] == ',' || str[j] == '.') j++;

					if (str[j]!='\0' && (str[j] == ' ' || str[j] == ',' || str[j] == '.'))
					{
						count++;
						while (str[j] == ' ' || str[j] == ',' || str[j] == '.') j++;
					}
					j++;
				}
				if (j != 0) count++;
			}
			printf("��������%d\n", count);
		}
		else
		{
			printf("�ļ���ʧ��\n");
		}
	}
	else
	{
		printf("��������\n");
		printf("-c:ͳ���ַ���\n");
		printf("-w:ͳ�Ƶ�����\n");
	}
	return 0;
}
