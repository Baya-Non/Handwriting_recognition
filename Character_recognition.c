/***�A�x���[�W�t�@�C����p���ĔF��������������F�����܂�***/
#include <stdio.h>
#include <stdlib.h>

FILE *fp;
FILE *fdr;
FILE *fin;
/*fdr��fdr�t�@�C��*/
/*fp��ave.dic*/

int judge(int ave[46][4] ,int p[20][4] ,int pk)
{
	int i,j,check=0,count=0,juge[46];
	int vlc[46],hlc[46],udlc[46],ddlc[46];
	int a[46],a1[46];
	
	for(i=0;i<46;i++){//������
		juge[i]=0;
		vlc[i]=0;
		hlc[i]=0;
		udlc[i]=0;
		ddlc[i]=0;;
	}
	
	for(i=0;i<46;i++){
		vlc[i]=(p[pk][0]-ave[i][0])*(p[pk][0]-ave[i][0]);
		hlc[i]=(p[pk][1]-ave[i][1])*(p[pk][1]-ave[i][1]);
		udlc[i]=(p[pk][2]-ave[i][2])*(p[pk][2]-ave[i][2]);
		ddlc[i]=(p[pk][3]-ave[i][3])*(p[pk][3]-ave[i][3]);
	}
	
	for(i=0;i<46;i++){
		juge[i]=vlc[i]+hlc[i]+udlc[i]+ddlc[i];
	}
	
	for(i=1;i<46;i++){
		if(juge[i]<juge[count])	{
			count=i;
		}
	}
	return count;
}

/* �l�����z��̃��[�N���b�h�v�Z�@*/
/*
int judge(int ave[2254][4] ,int p[980][4] ,int k)
{
	int i,j,check=0,count[46],x,y,z;
	int a[46],a1[46];
	
	for(i=0;i<46;i++){//����������/
		a[i]=0;
		count[i]=0;
	}
	
	for(x=0;x<49;x++){
		
		check=0;
		
		for(i=0;i<46;i++){
			for(j=0;j<4;j++){
				a[i]=a[i]+(p[x+49*k][j]-ave[x+49*i][j])*(p[x+49*k][j]-ave[x+49*i][j]);
			}
		}
		
		for(i=0;i<46;i++){
			if(a[i]<a[check]){
				check=i;
			}
		}
		
		count[check-1]++;
	}
	
	check=0;
	
	for(i=0;i<46;i++){
		if(count[i]>count[check]){
			check=i;
		}
	}
	
	return check;
	
}
*/
int main(int arg,char *a[])
{
	char filename[100];
	int p[20][4],ave[46][4];
	int length,check,ans=0,cnt;
	int i,j,n,x,y,c,k;
	double count=0.0;
	
	if(arg==1){
		printf("�摜�f�[�^���h���b�O�A���h�h���b�v���Ă�������\n");
		exit(0);
	}else if(arg>2){
		printf("����h���b�N���h���b�v���Ă�������\n");
		exit(0);
	}
	
	printf("�m���߂���.ftr�t�@�C���̔ԍ�����́���");
	scanf("%d",&c);
	
	fp=fopen("ave.dic","r");
	for(i=0;i<46;i++){//ave�ǂݎ��
		fscanf(fp,"%d,%d,%d,%d\n",&ave[i][0],&ave[i][1],&ave[i][2],&ave[i][3]);
	}
	fclose(fp);
	
	fin=fopen("answer.txt","w");
	
	/*
	sprintf(filename,"%02d",c);
	strcpy(fdr,filename);//filename�̖��O��\0�܂�copy
	strcat(fdr,".fdr");//copy�������O�����ɓ\��t��
	*/
	
	fdr=fopen(a[1],"r");
	for(i=0;i<20;i++){//ftr�ǂݎ��
		fscanf(fdr,"%d,%d,%d,%d\n",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
	}
	
	fclose(fdr);
	
	cnt=0;
	for(k=0;k<20;k++){
		ans=judge(ave,p,k);
		fprintf(fin,"%02d�̔��茋�ʁ���%02d\n\n",k+1,ans);
		if(c==ans){
			cnt++;
		}
	}
	fprintf(fin,"c=%d ans=%d",c,cnt);
	fprintf(fin,"����=��%02d/20\n\n",cnt);
	fclose(fin);
	return 0;
}
