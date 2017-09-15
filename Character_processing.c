/****�X���[�W���O�A�֊s���o�A���K�����s���܂�****/

#include<stdio.h>
#include <stdlib.h>

FILE *fin;
FILE *fdr;

void property();

void printimg(char data[512])//��ʓ���
{
	int k,i,j;
	unsigned char msk;
	
	for(k=0;k<64;k++){
		for(i=k*8;i<k*8+8;i++){
			msk=0x80;
			for(j=0;j<8;j++){
				if((data[i]&msk)==0){
					printf(".");
				}else{
					printf("*");
				}
				msk=msk>>1;
			}
		}
		printf("\n");
	}	
}

void compress( char data[512], char pattern[64][64])
{
	
	int a,i,j,k=0,n,x;
	unsigned char msk = 0;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
		n=j%8;
			if(pattern[i][j]==1){
				a=1;
				for(x=n;x<7;x++){
					a=a*2;
				}
				if(n==7){
					a=1;
				}
				msk=msk+a;
			}
			
			if(n==7){
				data[k]=msk;
				k++;
				a=1;
				msk=0;
			
			}
		}
		
	}
/*
	���Ƃ��΁Cptn[40][30]��data[512]�ɓ����ꍇ
	�Eptn[40][30]�́C���ォ��40*64+30�Ԗځi������W�Ŋ���
	�Ed[]�̉��Ԗڂ̃f�[�^��
	�E���̂P�o�C�g�f�[�^�̍����牽�Ԗڂ��H
		(40*60+30)%8=30%8=6
		
		������U�Ԗڂ������P(00000010)�ɂȂ��Ă���
		�P�o�C�g�̃f�[�^�̍���
			unsugned char m = 128 (2�i����10000000
			m=m>>6	
		
*/	
}

void printingd(char p[64][64])
{
	int i,j;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(p[i][j]==0){
				printf(".");
			}
			if(p[i][j]==1){
				printf("*");
			}
		}
		printf("\n");
	}
}


void expand(char data[512],char pattern [64][64])
/*1�������̉摜�f�[�^���󂯎��Cchar�^��2�����z��
�ɓW�J���ĕۑ�����֐�*/
{
	int i,j,k=0,n;
	unsigned char msk;
	msk = 0x80;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(j%8==7){
				msk = 0x80;
				k++;
			}
			if((data[k]&msk)==0){
				pattern[i][j] = 0;
			}else{
				pattern[i][j] = 1;
			}
		msk=msk>>1;
		
		}
		
	}
	
	
	
}

void smooth( char p [64][64] )/* �X���[�W���O */
{
	
	char num[64][64];
	int i,j;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			num[i][j]=2;
			
			if(p[i-1][j] == 0 && p[i][j] ==1 && p[i+1][j] == 0 && p[i-1][j-1] == 1 && p[i][j-1] ==1 && p[i+1][j-1] ==1 && p[i-1][j-2] ==1 && p[i][j-2] ==1 && p[i+1][j-2] ==1 ){
				p[i][j] = 1;
			}
			
			if(p[i-1][j] == 1 && p[i][j] == 0 && p[i+1][j] == 1 && p[i-1][j-1] == 1 && p[i][j-1] ==1 && p[i+1][j-1] ==1 && p[i-1][j-2] ==1 && p[i][j-2] ==1 && p[i+1][j-2] ==1 ){
				p[i][j] = 0;
			}
			
			
			if(p[i-1][j] == 0 && p[i][j] == 1 && p[i+1][j] == 1 && p[i-1][j-1] == 1 && p[i][j-1] ==1 && p[i+1][j-1] ==1 && p[i-1][j-2] ==0 && p[i][j-2] ==1 && p[i+1][j-2] ==1 ){
				p[i-1][j-1] = 0;
			}
			
			if(p[i-1][j] == 1 && p[i][j] == 1 && p[i+1][j] == 1 && p[i-1][j-1] == 0 && p[i][j-1] ==1 && p[i+1][j-1] ==1 && p[i-1][j-2] ==1 && p[i][j-2] ==1 && p[i+1][j-2] ==1 ){
				p[i-1][j-1] = 1;
			}
			
			
			if(p[i-1][j] == 1 && p[i][j] == 1 && p[i+1][j] == 1 && p[i-1][j-1] == 1 && p[i][j-1] ==1 && p[i+1][j-1] ==1 && p[i-1][j-2] == 0 && p[i][j-2] ==1 && p[i+1][j-2] == 0 ){
				p[i][j-2] = 0;
			}
			
			if(p[i-1][j] == 1 && p[i][j] == 1 && p[i+1][j] == 1 && p[i-1][j-1] == 1 && p[i][j-1] ==1 && p[i+1][j-1] ==1 && p[i-1][j-2] == 1 && p[i][j-2] == 0 && p[i+1][j-2] == 1 ){
				p[i][j-2] = 1;
			}
			
			
			if(p[i-1][j] == 1 && p[i][j] == 1 && p[i+1][j] == 0 && p[i-1][j-1] == 1 && p[i][j-1] ==1 && p[i+1][j-1] ==1 && p[i-1][j-2] ==1 && p[i][j-2] ==1 && p[i+1][j-2] ==0 ){
				p[i+1][j-1] = 0;
			}
			
			if(p[i-1][j] == 1 && p[i][j] == 1 && p[i+1][j] == 1 && p[i-1][j-1] == 1 && p[i][j-1] ==1 && p[i+1][j-1] == 0 && p[i-1][j-2] ==1 && p[i][j-2] ==1 && p[i+1][j-2] ==1 ){
				p[i+1][j-1] = 1;
			}
		}
	}
}

void outline( char p [64][64] )//�֊s���o
{
	char num[64][64];
	int i,j;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			num[i][j]=3;
			if(p[i][j] == 1 && p[i-1][j+1] == 1 && p[i][j+1] == 1 && p[i-1][j+1] == 1 && p[i-1][j] ==1 && p[i+1][j] == 1 && p[i-1][j-1] ==1 && p[i][j-1] ==1 && p[i+1][j-1] ==1 ){
				num[i][j] = 0;
			}
			
			
			if(p[i][j] == 1 && p[i][j+1] == 1 && p[i-1][j+1] == 1 && p[i+1][j] == 1 && p[i-1][j] ==1 && p[i+1][j-1] == 1 && p[i][j-1] ==1){
				num[i][j] = 0;
			}
			
			if(p[i][j] == 1 && p[i+1][j+1] == 1 && p[i][j+1] == 1 && p[i-1][j] == 1 && p[i+1][j] ==1 && p[i][j-1] == 1 && p[i-1][j-1] ==1){
				num[i][j] = 0;
			}
			
			if(p[i][j] == 1 && p[i][j+1] == 1 && p[i-1][j] == 1 && p[i+1][j] ==1 && p[i][j-1] == 1){
				num[i][j] = 0;
			}
			
		}
	}
	
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(num[i][j]==0){
				p[i][j]=0;
			}
			if(num[i][j]==1){
				p[i][j]=1;
			}
		}
	}
	
}

void normalize( char p[64][64] )//���K��
{
	int right=0,left=0,upper=0,lower=0;
	int i,j,u,v;
	int wide,high;
	char tmp[64][64];
	
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(p[i][j]==1){
				break;
			}
		}
		if(p[i][j]==1){
			break;
		}
		upper++;
	}
	
	for(j=0;j<64;j++){
		for(i=0;i<64;i++){
			if(p[i][j]==1){
				break;
			}
		}
		if(p[i][j]==1){
			break;
		}
		left++;
	}
	
	for(i=63;i>0;i--){
		for(j=0;j<64;j++){
			if(p[i][j]==1){
				break;
			}
		}
		if(p[i][j]==1){
			break;
		}
		lower++;
	}
	
	for(j=63;j>0;j--){
		for(i=0;i<64;i++){
			if(p[i][j]==1){
				break;
			}
		}
		if(p[i][j]==1){
			break;
		}
		right++;
	}
	
	printf("upper=%d,lower=%d,right=%d,left=%d \n",upper,lower,right,left);
	wide=63-left-right;
	high=63-lower-upper;
	printf("wide==%d�Chigh==%d\n",wide,high);
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(p[(int)(i * high/63+upper+0.5)][(int)(j * wide/63+left+0.5)]==0){
				tmp[i][j]=0;
			}	else if(p[(int)(i * high/63+upper+0.5)][(int)(j * wide/63+left+0.5)]==1){
				tmp[i][j]=1;
			}
		}
	}
	
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(tmp[i][j]==0){
				p[i][j]=0;
			}	else if(tmp[i][j]==1){
				p[i][j]=1;
			}
		}
	}
			
	
}

int label(char p[64][64])/*���x�����O*/
{
	int i,j,x,count=2,check=0,flag=0,cnt;
	do{
		for(i=0;i<64;i++){
			for(j=0;j<64;j++){
				if(p[i][j]==1 && check==0){
					p[i][j]=count;
					check=1;
				}
			}
		}
		for(x=0;x<64;x++){
			for(i=0;i<64;i++){
				for(j=0;j<64;j++){
					if(p[i][j]==1 && (p[i-1][j]==count || p[i][j-1]==count || p[i+1][j]==count || p[i][j+1]==count || (p[i-1][j-1]==count && (p[i-1][j]==1 || p[i][j-1]==1) || p[i+1][j-1]==count && (p[i-1][j]==1 || p[i][j+1]==1) ||p[i+1][j+1]==count && (p[i+1][j]==1 || p[i][j+1]==1) ||p[i-1][j+1]==count && (p[i-1][j]==1 || p[i][j+1]==1)))){
						p[i][j]=count;
					}
				}
			}
		}
		if(count>=255) break;
		count++;
		
		check=0;
	}while(1);
	/*
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(p[i][j]==0){
				printf(".");
			}	else {
				for(cnt=2;cnt<11;cnt++){
					if(p[i][j]==cnt){
						printf("%d",cnt);
					}
				}
			}
		}
		printf("\n");
	}
	*/
	return 1;
}

void noise( char p[64][64] , int size ){

	int	i,j,count,cnt=0;
	int tmp[64][64];
	
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			tmp[i][j]=p[i][j];
		}
	}
	
	label(p);
	
	for(count=2;count<225;count++){
		for(i=0;i<64;i++){
			for(j=0;j<64;j++){
				if(p[i][j]==count){
					cnt++;
				}
			}
		}
		
		if(cnt<size){
			for(i=0;i<64;i++){
				for(j=0;j<64;j++){
					if(p[i][j]==count){
						p[i][j]=0;
					}
				}
			}
		}
		cnt=0;
	}
	/*
	printf("�m�C�Y������\n");
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(p[i][j]==0){
				printf(".");
			}	else {
				for(cnt=2;cnt<11;cnt++){
					if(p[i][j]==cnt){
						printf("%d",cnt);
					}
				}
			}
		}
		printf("\n");
	}
	*/
}

int labelcount(char p[64][64])
{
	int count=1;
	int i,j;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(p[i][j]>=count){
				count=p[i][j];
			}
		}
	}
	
	return count;
}

void noizer(char p[64][64])
{
	int count=1;
	int i,j,cnt;
	printf("�m�C�Y�����ɂ��ǂ��܂�");
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(p[i][j]==0){
				p[i][j]=0;
			}	else {
				for(cnt=2;cnt<11;cnt++){
					if(p[i][j]==cnt){
						p[i][j]=1;
					}
				}
			}
		}
		printf("\n");
	}
}

/* 4�����d�ݕt�������Z���X�J�E���g�v���O���� 8���炵*/
/*void PropertySub(char p[64][64])
{
	int i,j;
	
	for(i=0;i<56;i+=8){
		for(j=0;j<56;j+=8){
			property(p,i,j);
		}
	}
}
void property(char p[64][64],int a,int b)

{
	int i=0,j=0;
	int right=0,left=0,upside=0,side=0;
	
	for(i=a;i<a+16;i++){
		for(j=b;j<b+16;j++){
			if(p[i][j]==1){
				if(j!=63 && p[i][j+1]==1){
					side++;
				}
				if(j!=0  && p[i][j-1]==1){
				side++;
				}
				
				if(i!=63 && p[i+1][j]==1){
					upside++;
				}
				if(i!=0  && p[i-1][j]==1){
					upside++;
				}
				
				if(i!=0  && j!=63 && p[i-1][j+1]==1){
					right++;
				}
				if(i!=63 && j!=0  && p[i+1][j-1]==1){
					right++;
				}
				
				if(i!=0  && j!=0  && p[i-1][j-1]==1){
					left++;
				}
				if(i!=63 && j!=63 && p[i+1][j+1]==1){
					left++;
				}
			}
		}
	}
	fprintf(fin,"%d,%d,%d,%d\n",side,upside,right,left);
}
*/

int VerticalLineCount(char p[64][64])/* �c�̕������f�J�E�� */
{
	int i,j,count=0;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(i==0){
				if(p[i][j]==1 && p[i+1][j]==1) count++;
			}	else if (i==63)	{
				if(p[i][j]==1 && p[i-1][j]==1) count++;
			}	else	{
				if(p[i][j]==1 && p[i+1][j]==1) count++;
				if(p[i][j]==1 && p[i-1][j]==1) count++;
			}
		}
	}
	return count;
}

int HorizontalLineCount(char p[64][64])/* ���̕������f�J�E���g */
{
	int i,j,count=0;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(j==0){
				if(p[i][j]==1 && p[i][j+1]==1) count++;
			}	else if (j==63)	{
				if(p[i][j]==1 && p[i][j-1]==1) count++;
			}	else {
				if(p[i][j]==1 && p[i][j+1]==1) count++;
				if(p[i][j]==1 && p[i][j-1]==1) count++;
			}
		}
	}
	return count;
}

int UpDiagonalLineCount(char p[64][64])//�΂ߏ�̕������f�J�E���g
{
	int i,j,count=0;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(i==0){
				if(j==0){
				}	else if(j==63)	{
					if(p[i][j]==1 && p[i+1][j-1]==1) count++;
				}	else	{
					if(p[i][j]==1 && p[i-1][j+1]==1) count++;
					if(p[i][j]==1 && p[i+1][j-1]) count++;
				}
			}	else if (i==63)	{
				if(j==0)	{
				if(p[i][j]==1 && p[i-1][j+1]==1) count++;
				}	else if(j==63)	{/* �Ȃɂ����Ȃ� */
				}	else{
					if(p[i][j]==1 && p[i-1][j+1]==1) count++;
				}
			}	else	{
				if(j==0){
					if(p[i][j]==1 && p[i-1][j+1]==1) count++;
				}	else if(j==63)	{
					if(p[i][j]==1 && p[i+1][j-1]==1) count++;
				}	else	{
					if(p[i][j]==1 && p[i+1][j-1]==1) count++;
					if(p[i][j]==1 && p[i-1][j+1]==1) count++;
				}
			}
		}
	}
	return count;
}

int  DownDiagonalLineCount(char p[64][64])/* �΂߉��̕������f�J�E���g */
{
	int i,j,count=0;
	for(i=0;i<64;i++){
		for(j=0;j<64;j++){
			if(i==0){
				if(j==0){
					if(p[i][j]==1 && p[i+1][j+1]) count++;
				}	else if(j==63)	{/* �Ȃɂ����Ȃ� */
				}	else	{
					if(p[i][j]==1 && p[i+1][j+1]) count++;
				}
			}	else if (i==63)	{
				if(j==0){
				}	else if(j==63)	{
					if(p[i][j]==1 && p[i-1][j-1]) count++;
				}	else	{
					if(p[i][j]==1 && p[i-1][j-1]) count++;
				}
			}	else	{
				if(j==0){
					if(p[i][j]==1 && p[i+1][j+1]) count++;
				}	else if(j==63)	{
					if(p[i][j]==1 && p[i-1][j-1]) count++;
				}	else	{
					if(p[i][j]==1 && p[i+1][j+1]) count++;
					if(p[i][j]==1 && p[i-1][j-1]) count++;
				}
			}
		}
	}
	return count;
}



int main(int arg,char *a[])
{
	int x,y,i,j,k,l,size=6,countl;
	int vlc,hlc,udlc,ddlc;
	unsigned char pic[512],b,data[512],filename[0x80];
	char pattern[64][64];
	
	
	/*printf("�摜�t�@�C��������͂��Ă�������");
	scanf("%s",&a);
	
	
	if((fdr=fopen(a,"rb"))== NULL){
	fprintf(stderr,"cannot open %s\n",a);
	exit(1);
	}
	*/
	
	if(arg==1){
		printf("�摜�f�[�^���h���b�O�A���h�h���b�v���Ă�������\n");
		exit(0);
	}
	
	/*if(fread(data,512,1,fdr)!=1){
		fprintf(stderr,"cannot read %s\n",a);
		exit(2);
	}
	*/
	for(i=1;i<arg;i++){
		fdr=fopen(a[i],"rb");
		strcpy(filename,a[i]);
		
		for(j=strlen(filename)-1;j>=0;j--){
			if(filename[j]=='.'){
				filename[j]='\0';
				break;
			}
		}
		
		strcat(filename,".ftr");
		fin=fopen(filename,"w");
		
		while(1){
			if(fread(data,512,1,fdr)!=1) break;
			printf("\n�f�[�^��񎟌��z�񉻂��Ă��܂�\n\n");
			
			/* data[]�ɉ摜�f�[�^��ǂݍ��� */
			/*printimg( data ) ;*/
			expand( data, pattern ) ;
			/*
			for( y = 0 ; y < 64 ; y++ ) {
				for( x = 0 ; x < 64 ; x++ ) {
					putchar( pattern[y][x] == 1 ? '@' : 'o' ) ;
				}
				putchar( '\n' ) ;
			}
			*/
			printf("\n�X���[�W���O���s���܂�\n");
			smooth(pattern);
			
			noise(pattern,size);
			
			
			
			printf("\n���x�������J�E���g���܂�\n\n");
			countl=labelcount(pattern);
			countl=countl-1;
			printf("�J�E���g���ʁ�%d",countl);
			
			printf("\n�m�C�Y�����������摜�����Ƃɂ��ǂ��܂�\n\n");
			noizer(pattern);
			compress( data, pattern ) ;
			
			
			printf("\n�f�[�^�𐳋K�����܂�\n\n");
			normalize( pattern );
			compress( data, pattern ) ;
			outline(pattern);
			
			printf("�f�[�^�𒊏o���܂�");
			/*PropertySub(pattern);*/
			vlc=VerticalLineCount(pattern);
			hlc=HorizontalLineCount(pattern);
			udlc=UpDiagonalLineCount(pattern);
			ddlc=DownDiagonalLineCount(pattern);
			fprintf(fin,"%d,%d,%d,%d\n",vlc,hlc,udlc,ddlc);
		}
		fclose(fdr);
		fclose(fin);
	}
}

