#include <stdio.h>
#include <windows.h>

// Lembre de excluir da build (fazer um .h se for importar o arquivo em um projeto serio)!
#include "cls.c"

int program();

int main(void)
{
	// API do windows para mudar a CodePage do terminal
	UINT codepage = GetConsoleOutputCP();
	// Unicode
	SetConsoleOutputCP(65001);

	int status = helloworld();

	// Boa pratica - restaurar a configuracao original
	SetConsoleOutputCP(codepage);
	return status;
}

int helloworld()
{
	FILE* fp;

	char s[1024];

	fopen_s(&fp, "helloworld.txt", "r");

	if (fp) {
		int c;

		// Prefiro deixar a declaracao junto com o fgetc, mas vou deixar assim pra lembrar que isso eh C valido
		while ((c = fgetc(fp)) != EOF) {
			printf("%c", c);
		}

		printf("\n\n");
		fseek(fp, 0, 0);

		while ((fgets(s, sizeof s, fp)) != NULL) {
			printf("%s", s);
		}
	}
	else
	{
		return 1;
	}

	return 0;
}

