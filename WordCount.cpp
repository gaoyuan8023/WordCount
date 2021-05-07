#include<stdio.h>
#include<string.h>
int main(int argc, char** argv)
{
	if (argc < 3)
	{
		printf("参数不完整\n");
		printf("-c:统计字符数\n");
		printf("-w:统计单词数\n");
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
			printf("字符数：%d\n", count);
		}
		else
		{
			printf("文件打开失败\n");
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
			printf("单词数：%d\n", count);
		}
		else
		{
			printf("文件打开失败\n");
		}
	}
	else
	{
		printf("参数错误\n");
		printf("-c:统计字符数\n");
		printf("-w:统计单词数\n");
	}
	return 0;
}
