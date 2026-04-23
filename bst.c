#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;

};
struct node*getNode(int data){
    struct node*ptrNew;
    ptrNew=(struct node*)malloc(sizeof(struct node));
    if(ptrNew==NULL){
        printf("memory allocation failed. program will terminate now.");
        fflush(stdin);
        getchar();
        exit(0);

    }
    ptrNew->data=data;
    ptrNew->left=ptrNew->right=NULL;
    return ptrNew;
}
void insert(struct node*root){
    int data;
    struct node* ptrNew,*curr,*parent;
    printf("enter a number: ");
    scanf("%d",&data);
    ptrNew=getNode(data);
    if(root=NULL){
        root=ptrNew;
        printf("%d inserted as the root node.\n",data);
    }
    else{
        parent=NULL;
        curr=root;
        while(curr!=NULL){
            parent=curr;
             if(data <curr->data){
                curr=curr->left;


             }
             else
             curr=curr->right;
        }


    }
}
void search(){
    int key;
    struct node *curr=root,*parent=NULL;
    if(root==NULL){
        printf("tree is empty");
        return;

    }
    printf("\nEnter a number your want to add");
    scanf("%d",&key);
    while(curr!=NULL){
        if(curr->data==key){
            if(parent=NULL)
                printf("%d exists in the tree.",key);
            else if(key<parent->data)
                printf("%d exists in the left of  %d",key,parent->data);
            else
                printf("%d exists in the right of %s",key,parent->data);
        }
    }
    printf("%d does not exist in the treee",key);
}

void preorder(struct node*ptr){
if(ptr!=NULL){
    printf("%d",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);

}
}
void inorder(struct node*ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%d",ptr->data);
        inorder(ptr->right);

    }
    
}
void postorder(struct node*ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d",ptr->data);
    }
}
int main(){
    char choice;
    struct node*root=NULL;
    do{
        system("cls");
        printf("select an option:\n1.insert\n2.remove\n3.Find\n4.preorder\n5.IN-order\n6.postorder\n7.exit");
        fflush(stdin);
        choice=getchar();
        switch(choice){
            case '1':insert(root);break;
            case '2':break;
            case '3':search();
                        break;
            case '4':printf("pre order list\n");
                        preorder(root); break;
            case '5':printf("inorder list");
                    inorder(root);
                    break;
            case '6':printf("Post order list");
                    postorder(root);
                    break;
            case '7':return 0;
            default: printf("dher janne vois");
        }
        fflush(stdin);
        printf("press any key to continue");
        getchar();

    }while(1);
}