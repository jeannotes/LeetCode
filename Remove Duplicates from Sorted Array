#include "stdio.h"
#include "memory.h"

#define MAXIN 75

char board[MAXIN+2][MAXIN+2];//定义面板

int minstep,w,h,to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//定义标记方向
bool mark[MAXIN+2][MAXIN+2];//定义标记数组

void search(int now_x,int now_y,int end_x,int end_y,int step,int f){
	if (step>minstep){
		return;
	}//完全可以不设置这个判断，只是为了判断step的

	if (now_x==end_x&&now_y==end_y){
		if (step<minstep){//更新 因为在这之前minstep一直等于100000
			minstep=step;
			return;
		}
	}
	//开始枚举方向
	for (int i=0;i<4;i++){
		int x=now_x+to[i][0];//得到新的位置
		int y=now_y+to[i][1];

		if (((-1<x)&&(x<w+2)&&(-1<y)&&(y<h+2))
			&&(((board[y][x]==' ')&&(mark[y][x]==false))||			
			(board[y][x]=='X')&&(x==end_x)&&(y=end_y))){
			//在范围之内
			//普通选择，即是空格，且不曾被标记。因为一开始都是false
			//最后一种情况，即到达终点，且终点存放X

			//开始判断
			mark[y][x]=true;//说明有效
			if (f==i){
				search(x,y,end_x,end_y,step,i);
			}
			else{
				search(x,y,end_x,end_y,step+1,i);
			}
			//注意，此处判断完全可以没有任何返回值的。就是不起作用，比如说遇到墙而不是空白  
		    //那就直接返回，反正不会有任何返回值的。 

			//如果无效，则记为没有作用
			//记为没有走过
			mark[y][x]=false;
		}
	}
}

int main()
{
	int Boardnum=0;

	while (scanf("%d %d",&w,&h)){
		if(w==0&&h==0)
			break;

		Boardnum++;
		printf("Board #%d:\n",Boardnum);
		//先是输入几行几列，再输出第几块板子

		int i,j;
		for (i=0;i<MAXIN+2;i++){
			board[0][i]=board[i][0]=' ';
		}//初始化全部空格

		for (i=1;i<=h;i++){
			getchar();
			for(j=1;j<=w;j++){
				board[i][j]=getchar();
			}
		}//读入矩形板的布局

		for (i=0;i<=w;i++){
			board[h+1][i+1]=' ';
		}
		for (i=0;i<=h;i++){
			board[i+1][w+1]=' ';
		}//板子最外层赋空格
		
		int begin_x,begin_y,end_x,end_y,count=0;

		while (scanf("%d %d %d %d",&begin_x,&begin_y,&end_x,&end_y)&&begin_x){
			count++;
			minstep=100000;
			memset(mark,false,sizeof(mark));
			//开始递归搜索
			search(begin_x,begin_y,end_x,end_y,0,-1);
			if (minstep<100000){
				printf("Pair %d:%d segments.\n",count,minstep);
			}
			else{
				printf("Pair %d: impossible.\n",count);
			}
		}

		printf("\n");
	}

	return 0;
}


