#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define MAX 1000
struct goods{      //����һ���ṹ�� 
char name[MAX];    // 
char number[MAX];  //�ṹ�������� ���� �۸� ���� 
float price;       //
int quantity;      //
}goods[MAX];       //����һ���ṹ������ 
	
void search_goods(void){                  //���Һ��� 
	int search_number,a=0,b=0; 
	char snumber[MAX],sname[MAX]; 
    printf("��ѡ�������Ʒ��ʽ\n");
	printf("��Ų���������1\n"); 
	printf("���Ʋ���������2\n");
	scanf("%d",&search_number);
	switch(search_number){
		case 1:
		printf("������Ҫ���ҵı��\n");   //ͨ����������� 
		scanf("%s",snumber);
		printf("��Ʒ���\t��Ʒ���\t��Ʒ����\t��Ʒ�۸�\t��Ʒ����\n");           
		for(a=0;a<MAX;a++){	
		for(;;){
		if(snumber[b]==goods[a].number[b])//ͨ���ṹ������ļӼ��ͽṹ�еı������ 
			b++;                          //ͨ���ȽϺͼӼ� 
		    else break;                   //�ﵽģ��������Ŀ�� 
		if(snumber[b]=='\0'){
			printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[a].number,goods[a].name,goods[a].price,goods[a].quantity);
			break;
			}
		}
		b=0;
		}
		break;	
			
 	    case 2:                           //ͨ������������ 
 	    printf("������Ҫ���ҵ�����\n");     //���Ƶ�ģ����ѯ�ͱ�ŵ�ģ����ѯ��ͬ 
	    scanf("%s",sname);
	    printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\t��Ʒ����\n");
	    for(a=0;a<MAX;a++){
    	for(;;){
	    if(sname[b]==goods[a].name[b])
		   b++;
		   else break;
		   if(sname[b]=='\0'){
		   printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[a].number,goods[a].name,goods[a].price,goods[a].quantity);
		   break;
   		   }	
    	}
    	b=0;
	    }
   		break; 
	   	default:
		printf("��������ȷ��ִ����\n\n\n\n");
		break; 	
	    }
 }





void delete_goods(void){                        //ɾ����Ʒ���� 
	int c,d=0;
	char dnumber[MAX],dname[MAX];
	printf("������Ҫɾ������Ʒ��Ż�������\n");
	printf("������ɾ��������1\n");
	printf("��������ɾ��������2\n");
	scanf("%d",&c);
	switch(c){
		case 1:
		printf("��������\n");
		scanf("%s",&dnumber);
		for(d=0;d<MAX;d++){                     //ͨ����ȷ����ѡ����Ʒ 
		if(strcmp(dnumber,goods[d].number)==0){
		strcpy(goods[d].name,"\0");
		strcpy(goods[d].number,"\0");
		printf("ɾ���ɹ���\n"); 
		break;
		}
	}   
	break;
	    case 2:
	    printf("����������\n");
	    scanf("%s",&dname);
	    for(d=0;d<MAX;d++){
    		if(strcmp(dname,goods[d].name)==0){
   			strcpy(goods[d].name,goods[MAX].name);
	        strcpy(goods[d].number,goods[MAX].number);
    		printf("ɾ���ɹ���\n"); 
			break;
			}
    	}break;
        default:
		printf("��������ȷ��ִ����\n\n\n\n");
		break; 
	}
}

void change_goods(void){                         //�ı���Ʒ���Ժ��� 
	 int e,f=0;                                  //ͨ����ȷ�����ҵ���Ʒ���ڽṹ 
	 char cnumber[MAX],cname[MAX];
     printf("������Ҫ�޸ĵ���Ʒ��Ż�������\n");
     printf("�������޸�������1\n");
     printf("���������޸�������2\n");
     scanf("%d",&e);
     switch(e){
     	 case 1:
	     printf("��������\n");
	 	 scanf("%s",&cnumber);
		 for(f=0;f<MAX;f++){
	     if(strcmp(cnumber,goods[f].number)==0){	
	     printf("�����޸ĺ����Ʒ���ԣ���ţ����ƣ��۸�������\n");
	     printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[f].number,goods[f].name,goods[f].price,goods[f].quantity);
	     scanf("%s%s%f%d",goods[f].number,goods[f].name,&goods[f].price,&goods[f].quantity);
	     printf("�޸ĳɹ���\n");
	     break;
		 }
     }   
	     break;
         case 2:
         printf("����������\n");
         scanf("%s",&cname);
         for(f=0;f<MAX;f++){
     	 if(strcmp(cname,goods[f].name)==0){  	
     	 printf("�����޸ĺ����Ʒ���ԣ���ţ����ƣ��۸�������\n");
	     printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[f].number,goods[f].name,goods[f].price,goods[f].quantity);
     	 scanf("%s%s%f%d",goods[f].number,goods[f].name,&goods[f].price,&goods[f].quantity);
     	 printf("�޸ĳɹ���\n");
     	 break;
     	 }
     }
     
         break;
    	 default:
		 printf("��������ȷ��ִ����\n\n\n\n");
		 break; 
     }
}

void save_goods(char* file_name,FILE *fp,int A){   //���溯�� 
	    int z;
	    int x=0;
		if((fp=fopen(file_name,"w+"))==NULL){     //����W+������ȥԭ�е��ļ� 
    	printf("�ļ�δ�ҵ�/n");                   //�����������ļ�д�뵽TXT�ļ��дﵽ����Ŀ�� 
   }                                              
        else{
			for(z=0;z<A;z++){
				if(goods[z].number[x]=='\0'){
					continue;
				}
				fprintf(fp,"%-10s\t\t%-10s\t\t%-10f\t\t%-10d\n",goods[z].number,goods[z].name,goods[z].price,goods[z].quantity);
			}
       	}
		fclose(fp);
		printf("����ɹ���");
		return;
}


void print_goods(int A){                         //��ӡ���к������� 
        int B;
        int X=0;
       	printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\t��Ʒ����\n");                                   
        for(B=0;B<A;B++){
        	if(goods[B].number[X]=='\0'){
	        	continue;
	        }
	    	printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[B].number,goods[B].name,goods[B].price,goods[B].quantity);
   }
}



void read_line(char* file_name,FILE *fp,int *A){         //���ļ����� 
		printf("������Ҫ������ļ�ȫ��\n");
	    scanf("%s",file_name);
	    if((fp=fopen(file_name,"r"))==NULL){
	         printf("�ļ�δ�ҵ�/n");                    //�ж��ļ��Ƿ�򿪳ɹ� 
	}
	    else{
	    	while(feof(fp)==0){
			    fscanf(fp,"%s\t%s\t%f\t%d\n",goods[*A].number,goods[*A].name,&goods[*A].price,&goods[*A].quantity);
			    (*A)++;
		}
		    printf("�ļ�����ɹ�\n"); 
	 }
	    fclose(fp);
}



void add_goods(int *A){                      //�����Ʒ 
	    printf("������������Ʒ��ţ���Ʒ���ƣ���Ʒ�۸���Ʒ����\n");
		scanf("%s%s%f%d",&goods[*A].number,&goods[*A].name,&goods[*A].price,&goods[*A].quantity);	
		(*A)++;
		printf("����ɹ�\n\n");
}





int main(){                                //������ 
	int A=0;
	char file_name[MAX];
	FILE *fp;
	read_line(file_name,fp,&A);           //�û��ڿ�ʼѡ������ļ�6
	while(1){
    int choice;
	printf("Scanf the number which is after the operation\n");
	printf("������Ʒ��Ϣ----1\n");
	printf("�޸���Ʒ��Ϣ----2\n");
    printf("ɾ����Ʒ��Ϣ----3\n");
	printf("������Ʒ----4\n");
	printf("��ʾ������Ʒ----5\n");
	printf("�˳�ϵͳ������----6\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
	    add_goods(&A);
		break;

		case 2:
		change_goods();                           //�޸���Ʒ��Ϣ 
		break;
		 
		case 3:
		delete_goods();                           //ɾ����Ʒ��Ϣ 
		break;
		
		case 4:
		search_goods();                           //������Ʒ��Ϣ 
		break;

		case 5:
		print_goods(A);                           //��ӡ������Ʒ��Ϣ 
        break;
		
		case 6:                                   //���溯������ 
		save_goods(file_name,fp,A);               //ֱ�ӽ������� 
		return;
		
		default:                                  //���ǵ�����Ĳ�������� 
		printf("��������ȷ��ִ����\n\n\n\n");
		break; 
		}
	}
	return 0;	

}
