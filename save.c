#include"la03.h"

//保存到文件
void save(struct drug* head, const char* filename)
{
	FILE* fp = fopen(filename, "w");

	for (struct drug* cur = head; cur != NULL; cur = cur->next)
	{
		fprintf(fp, "%s %s %s %d\n", cur->name, cur->type, cur->usage, cur->amount);
	}

	fclose(fp);
}
