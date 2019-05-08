#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define NO_OF_CHARS 256
 
int main(int argc, char **argv) {
	char *semnsFile = NULL;
	FILE *sFile = NULL;
	char *execsFile = NULL;
	FILE *eFile = NULL;
	char eBuf[50],sBuf[50];
	int fd1, fd2, rc;
	int infected=0, clear=0;
	if (argc == 3) {
		execsFile = argv[1];
		semnsFile = argv[2];
	}
	else {
		printf("Numar incorect de parametri!");
		exit(-1);
	}

	eFile = fopen(execsFile, "r");
		if (eFile == NULL)
			printf("Nu s-a putut deschide fisierul %s!",execsFile);
	sFile = fopen(semnsFile, "r");
		if (sFile == NULL)
			printf("Nu s-a putut deschide fisierul %s!",semnsFile);

	printf("Raport:\n");
	while (!feof(eFile)) {
		int s;
		fgets(eBuf,50,eFile);  
		eBuf[strlen(eBuf)-1]=NULL;
		FILE *eCurrent = fopen(eBuf,"rb");
		unsigned char *bufExec,*bufSemns;
		int sizeExec,sizeSemns;
		if(feof(eFile))
			continue;
		if (eCurrent == NULL) {
			printf("Nu s-a putut deschide fisierul %s!",eBuf);
			continue;
		}

		fseek(eCurrent,0,SEEK_END);
		sizeExec = ftell(eCurrent);
		rewind(eCurrent);

		bufExec = (unsigned char *)malloc(sizeExec);
		fread(bufExec,1,sizeExec,eCurrent);
		fclose(eCurrent);
		int ret=1;
		while (!feof(sFile)) {

			fgets(sBuf, 50, sFile);
				
			if(feof(sFile))
				continue;

			sBuf[strlen(sBuf)-1]=NULL;
			FILE *sCurrent = fopen(sBuf, "rb");
			if (sCurrent == NULL)
				printf("Nu s-a putut deschide fisierul %s!", sBuf);

			fseek(sCurrent, 0, SEEK_END);
			sizeSemns = ftell(sCurrent);
			rewind(sCurrent);

			bufSemns = (unsigned char *)malloc(sizeSemns);

			fread(bufSemns, 1, sizeSemns, sCurrent);
			int offset=0;
 			while(offset<sizeExec)
			{
				ret=memcmp(bufExec+offset,bufSemns,sizeof(bufSemns));
				offset+=sizeof(bufSemns);
				if(ret==0){
					printf("%s\t->\t infectat\n",eBuf);
					infected++;
					break;
				}
			}
			fclose(sCurrent);

			free(bufSemns);
			if(ret==0) break;

		}
		if(ret!=0){
			printf("%s\t->\t neinfectat\n",eBuf);
			clear++;
		}
		rewind(sFile);	
			
	}
	printf("\nTotal: %d.\n",clear+infected);
	printf("Infectate: %d.\n",infected);
	
	return 0;
}


