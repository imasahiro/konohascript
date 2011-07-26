#include<mpi.h>
#include<konoha1.h>
#include<errno.h>

#ifdef __cplusplus
extern "C" {
#endif

int main(int argc, const char *argv[])
{
	MPI_Init(&argc, (char***)&argv);
	konoha_ginit(argc, argv);
	konoha_t konoha = konoha_open(4096);
	konoha_main(konoha, argc, argv);
	konoha_close(konoha);
	MPI_Finalize();
	return 0;
}

#ifdef __cplusplus
}
#endif
