/****46文字20個のデータを平均化してアベレージファイルを作ります****/

#include <stdio.h>
#include <stdlib.h>
FILE *fp;
FILE *fdr;
/*
  0,  0,  0,  0;1
 40, 40, 38, 37;2
 48, 48, 45, 45;3
 48, 48, 45, 45;4
 32, 32, 31, 32;5
 93, 93, 92, 93;6
108,108,107,107;7
108,108,107,107;8
 22, 22, 22, 22;9
 78, 78, 73, 78;10
 78, 78, 73, 78;11
 78, 78, 73, 78;12
 64, 64, 62, 64;13
122,122,119,120;14
176,176,173,174;15
234,234,231,232;16
*/

int main(int arg,char *a[])
{
	int x,y,z,count,c,i,j,k;
	int vlc,hlc,udlc,ddlc;
	int fvlc,fhlc,fudlc,fddlc;
	char data[512];
	char filename[0x80];
	int pattern[980][4],ave[20][4];
	int side,upside,right,left;
	/*
	for(i=0;i<49;i++){
		for(j=0;j<4;j++){
			ave[i][j]=0;
		}
	}
	*/
	
	if(arg==1){
		printf("画像データをドラッグアンドドロップしてください\n");
		exit(0);
	}
	/*
	printf("ファイル名を入力＞＞");
	scanf("%s",&filename);
	*/
	/*
	if((fdr=fopen(filename,"r"))== NULL){
		printf("cannot open %s\n",filename);
	exit(1);
	}
	*/
	
	fp=fopen("ave.dic","w");
	fclose(fp);
	
	for(c=0;c<arg-1;c++){
		sprintf(filename,"%02d.ftr",c+1);
		fdr=fopen(filename,"r");
		fp=fopen("ave.dic","a");
		
		fvlc=0;
		fhlc=0;
		fudlc=0;
		fddlc=0;
		
		for(j=0;j<20;j++){
			fscanf(fdr,"%d,%d,%d,%d",&vlc,&hlc,&udlc,&ddlc);
			fvlc=fvlc+vlc;
			fhlc=fhlc+hlc;
			fudlc=fudlc+udlc;
			fddlc=fddlc+ddlc;
		}
		
		vlc=fvlc/20;
		hlc=fhlc/20;
		udlc=fudlc/20;
		ddlc=fddlc/20;
		
		fprintf(fp,"%d,%d,%d,%d\n",vlc,hlc,udlc,ddlc);
		/*
		for(i=0;i<980;i++){
			for(j=0;j<4;j++){
				fscanf(fdr,"%d,",&pattern[i][j]);
			}
			x=i%49;
			for(j=0;j<4;j++){
				ave[x][j]=ave[x][j]+pattern[i][j];
			}
		}
		for(i=0;i<49;i++){
			for(j=0;j<4;j++){
				ave[i][j]=ave[i][j]/20;
				fprintf(fp,"%5d,",ave[i][j]);
				ave[i][j]=0;
			}
			fprintf(fp,"\n");
		}
		*/
	}
	fclose(fp);
	fclose(fdr);
	return 0;
}
