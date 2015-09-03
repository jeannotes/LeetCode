#include "iostream"
#include "cstdio"
#include "cstring"

using namespace std;

struct Node {
	int val;
	struct Node *next;//定义一个指向Node的next结点
};

void push(struct Node **top_pt,int new_data){
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->val=new_data;
	new_node->next=*top_pt;

	*top_pt=new_node;//这个语句代表更改名字
}

int pop(struct Node **top_pt){
	//释放内存并且弹出数据
	if (*top_pt==NULL){
		cout<<"stack overflow"<<endl;
		exit(0);
	}
	else{
		struct Node *top=*top_pt;//俩个平起平坐，下一个next都指向下一个数
								 //这个是结构体初始化，与单独*top=*top_pt不同，
								 //它代表top指向*top_pt
		int res=top->val;
		*top_pt=top->next;

		free(top);
		return res;

	}

}

int evalRPN(char *tokens[],int n){
	struct Node *stack=NULL;//定义空堆栈，内容空
	for (int i=0;i<n;i++){
		if (strcmp(tokens[i],"+")==0){
			int r=pop(&stack);
			int l=pop(&stack);

			push(&stack,l+r);
		}
		else if (strcmp(tokens[i],"-")==0){
			int r=pop(&stack);
			int l=pop(&stack);
			
			push(&stack,l-r);
		}
		else if (strcmp(tokens[i],"*")==0){
			int r=pop(&stack);
			int l=pop(&stack);
			
			push(&stack,l*r);
		}
		else if (strcmp(tokens[i],"/")==0){
			int r=pop(&stack);
			int l=pop(&stack);
			
			push(&stack,l/r);
		}
		else{
			push(&stack,atoi(tokens[i]));
		}
	}
	return pop(&stack);
}


int main(){
	char *tokens[]={"3","4","+"};
	cout<<sizeof(tokens[0])<<endl;
}

