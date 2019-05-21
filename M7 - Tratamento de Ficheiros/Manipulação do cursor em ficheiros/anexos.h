//Anexos

//Carlos Tojal
//nº5
//1º TSI

//Código extraído da biblioteca padrão do C stdio.h

//Anexo 1 - Constantes (stdio.h)
#define SEEK_SET	     0 //representa o início do ficheiro
#define SEEK_CUR	     1 //representa a posição atual
#define SEEK_END	     2 //representa o fim do ficheiro

//Anexo 2 - Funções (stdio.h)
_CRTIMP __cdecl __MINGW_NOTHROW  int    fseek (FILE *, long x, int c); //posiciona o cursor x posições à frente da constante c (anexo 1)
_CRTIMP __cdecl __MINGW_NOTHROW  long   ftell (FILE *); //retorna o número de caracteres no ficheiro
_CRTIMP __cdecl __MINGW_NOTHROW  void   rewind (FILE *); //coloca o ponteiro no início do ficheiro
