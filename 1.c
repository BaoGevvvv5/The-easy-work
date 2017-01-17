#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define MAX 1000
struct goods{      //定义一个结构体 
char name[MAX];    // 
char number[MAX];  //结构体包含编号 名字 价格 数量 
float price;       //
int quantity;      //
}goods[MAX];       //定义一个结构体数组 
	
void search_goods(void){                  //查找函数 
	int search_number,a=0,b=0; 
	char snumber[MAX],sname[MAX]; 
    printf("请选择查找商品方式\n");
	printf("编号查找请输入1\n"); 
	printf("名称查找请输入2\n");
	scanf("%d",&search_number);
	switch(search_number){
		case 1:
		printf("输入你要查找的编号\n");   //通过编号来查找 
		scanf("%s",snumber);
		printf("商品序号\t商品编号\t商品名称\t商品价格\t商品数量\n");           
		for(a=0;a<MAX;a++){	
		for(;;){
		if(snumber[b]==goods[a].number[b])//通过结构体数组的加减和结构中的编号数组 
			b++;                          //通过比较和加加 
		    else break;                   //达到模糊搜索的目的 
		if(snumber[b]=='\0'){
			printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[a].number,goods[a].name,goods[a].price,goods[a].quantity);
			break;
			}
		}
		b=0;
		}
		break;	
			
 	    case 2:                           //通过名称来查找 
 	    printf("输入你要查找的名称\n");     //名称的模糊查询和编号的模糊查询相同 
	    scanf("%s",sname);
	    printf("商品编号\t商品名称\t商品价格\t商品数量\n");
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
		printf("请输入正确的执行码\n\n\n\n");
		break; 	
	    }
 }





void delete_goods(void){                        //删除物品函数 
	int c,d=0;
	char dnumber[MAX],dname[MAX];
	printf("输入你要删除的商品编号或者名称\n");
	printf("输入编号删除请输入1\n");
	printf("输入名称删除请输入2\n");
	scanf("%d",&c);
	switch(c){
		case 1:
		printf("请输入编号\n");
		scanf("%s",&dnumber);
		for(d=0;d<MAX;d++){                     //通过精确搜索选择物品 
		if(strcmp(dnumber,goods[d].number)==0){
		strcpy(goods[d].name,"\0");
		strcpy(goods[d].number,"\0");
		printf("删除成功！\n"); 
		break;
		}
	}   
	break;
	    case 2:
	    printf("请输入名称\n");
	    scanf("%s",&dname);
	    for(d=0;d<MAX;d++){
    		if(strcmp(dname,goods[d].name)==0){
   			strcpy(goods[d].name,goods[MAX].name);
	        strcpy(goods[d].number,goods[MAX].number);
    		printf("删除成功！\n"); 
			break;
			}
    	}break;
        default:
		printf("请输入正确的执行码\n\n\n\n");
		break; 
	}
}

void change_goods(void){                         //改变物品属性函数 
	 int e,f=0;                                  //通过精确查找找到物品所在结构 
	 char cnumber[MAX],cname[MAX];
     printf("输入你要修改的商品编号或者名称\n");
     printf("输入编号修改请输入1\n");
     printf("输入名称修改请输入2\n");
     scanf("%d",&e);
     switch(e){
     	 case 1:
	     printf("请输入编号\n");
	 	 scanf("%s",&cnumber);
		 for(f=0;f<MAX;f++){
	     if(strcmp(cnumber,goods[f].number)==0){	
	     printf("输入修改后的商品属性（编号，名称，价格，数量）\n");
	     printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[f].number,goods[f].name,goods[f].price,goods[f].quantity);
	     scanf("%s%s%f%d",goods[f].number,goods[f].name,&goods[f].price,&goods[f].quantity);
	     printf("修改成功！\n");
	     break;
		 }
     }   
	     break;
         case 2:
         printf("请输入名称\n");
         scanf("%s",&cname);
         for(f=0;f<MAX;f++){
     	 if(strcmp(cname,goods[f].name)==0){  	
     	 printf("输入修改后的商品属性（编号，名称，价格，数量）\n");
	     printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[f].number,goods[f].name,goods[f].price,goods[f].quantity);
     	 scanf("%s%s%f%d",goods[f].number,goods[f].name,&goods[f].price,&goods[f].quantity);
     	 printf("修改成功！\n");
     	 break;
     	 }
     }
     
         break;
    	 default:
		 printf("请输入正确的执行码\n\n\n\n");
		 break; 
     }
}

void save_goods(char* file_name,FILE *fp,int A){   //保存函数 
	    int z;
	    int x=0;
		if((fp=fopen(file_name,"w+"))==NULL){     //利用W+型来截去原有的文件 
    	printf("文件未找到/n");                   //将缓冲区的文件写入到TXT文件中达到保存目的 
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
		printf("保存成功！");
		return;
}


void print_goods(int A){                         //打印所有函数操作 
        int B;
        int X=0;
       	printf("商品编号\t商品名称\t商品价格\t商品数量\n");                                   
        for(B=0;B<A;B++){
        	if(goods[B].number[X]=='\0'){
	        	continue;
	        }
	    	printf("%-10s\t%-10s\t%-10f\t%-10d\n",goods[B].number,goods[B].name,goods[B].price,goods[B].quantity);
   }
}



void read_line(char* file_name,FILE *fp,int *A){         //打开文件函数 
		printf("输入你要导入的文件全名\n");
	    scanf("%s",file_name);
	    if((fp=fopen(file_name,"r"))==NULL){
	         printf("文件未找到/n");                    //判断文件是否打开成功 
	}
	    else{
	    	while(feof(fp)==0){
			    fscanf(fp,"%s\t%s\t%f\t%d\n",goods[*A].number,goods[*A].name,&goods[*A].price,&goods[*A].quantity);
			    (*A)++;
		}
		    printf("文件导入成功\n"); 
	 }
	    fclose(fp);
}



void add_goods(int *A){                      //添加商品 
	    printf("请依次输入商品编号，商品名称，商品价格，商品数量\n");
		scanf("%s%s%f%d",&goods[*A].number,&goods[*A].name,&goods[*A].price,&goods[*A].quantity);	
		(*A)++;
		printf("输入成功\n\n");
}





int main(){                                //主函数 
	int A=0;
	char file_name[MAX];
	FILE *fp;
	read_line(file_name,fp,&A);           //用户在开始选择导入的文件6
	while(1){
    int choice;
	printf("Scanf the number which is after the operation\n");
	printf("输入商品信息----1\n");
	printf("修改商品信息----2\n");
    printf("删除商品信息----3\n");
	printf("查找商品----4\n");
	printf("显示所有商品----5\n");
	printf("退出系统并保存----6\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
	    add_goods(&A);
		break;

		case 2:
		change_goods();                           //修改商品信息 
		break;
		 
		case 3:
		delete_goods();                           //删除商品信息 
		break;
		
		case 4:
		search_goods();                           //搜索商品信息 
		break;

		case 5:
		print_goods(A);                           //打印所有商品信息 
        break;
		
		case 6:                                   //保存函数操作 
		save_goods(file_name,fp,A);               //直接结束程序 
		return;
		
		default:                                  //考虑到错误的操作码过程 
		printf("请输入正确的执行码\n\n\n\n");
		break; 
		}
	}
	return 0;	

}
