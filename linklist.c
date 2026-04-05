#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{    //Định nghĩa Node
    int data;
    struct NODE *next;
}NODE;

typedef struct list{    //ĐỊnh nghĩa danh sách
    NODE *head;
    NODE *tail;
}list;

NODE *new(int value){   //Tạo một Node mới
    NODE *newNode=((NODE*)malloc(sizeof(NODE)));
    if(newNode==NULL){
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void init(list *l){     //Tạo một danh sách rỗng
    l->head=NULL;
    l->tail=NULL;
}

void append(list *mylist,int value){    //Nối các Node mới
    NODE *newNode=new(value);
    if(mylist->head==NULL){         //Node đầu rỗng
        mylist->head=newNode;       //Cập nhập vị trí Node
        mylist->tail=newNode;
    }
    mylist->tail->next=newNode;     //Con trỏ đuôi (next) của trỏ tới Node mới
    mylist->tail=newNode;
}

void insert(list *mylist,int value,int position){    //Chèn một Node mới vào vị trí (position) bất kì
    NODE *newNode=new(value);
    if(position==0){                    //Chen vào đầu danh sách
        if(mylist->head==NULL){         //Node đầu rỗng
            mylist->head=newNode;
            mylist->tail=newNode;
        }
        newNode->next=mylist->head;     //Con trỏ next của Node mới trỏ tới Node đầu hiện tại
        mylist->head=newNode;           //Cập nhập vị trí Node đầu mới
        return;
    }
    if(position>0){
        NODE *current=mylist->head;     //Tạo một con trỏ tạm thời để duyệt qua danh sách
        int count=0;
        while(current!=NULL && count<position-1){   //Duyệt đến vị trí trước vị trí cần chèn
            current=current->next;
            count++;
        }
        if(current==NULL){   //Nếu vị trí vượt quá độ dài của danh sách, chèn vào cuối danh sách
            mylist->tail->next=newNode;
            mylist->tail=newNode;
        }else{                             //Chèn vào vị trí thứ position trong danh sách
            newNode->next=current->next;   //Con trỏ next của Node mới trỏ tới Node tiếp theo của Node hiện tại
            current->next=newNode;         //Con trỏ next của Node hiện tại trỏ tới Node mới
            if(newNode->next==NULL){       //Nếu Node mới được chèn vào cuối danh sách, cập nhật con trỏ đuôi
                mylist->tail=newNode;
            }
        }
    }
}

void printNode(list *mylist){    //In ra các Node
    NODE *current=mylist->head;     //Tạo một con trỏ tạm thời để duyệt qua danh sách
    while(current!=NULL){           //Duyệt đến khi con trỏ tạm thời bằng NULL
        printf("%d ",current->data);   //In ra giá trị của Node hiện tại
        current=current->next;          //Di chuyển con trỏ tạm thời đến Node tiếp theo
    }
    printf("NULL");
}

int main(){
    list mylist;
    init(&mylist);
    int n, value,position;

    printf("nhap vao so Node: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Gia tri Node %d: ",i+1);
        scanf("%d",&value);
        append(&mylist,value);
    }

    printNode(&mylist);
    printf("\nNhap vao gia tri Node can chen: ");
    scanf("%d",&value);
    printf("Nhap vao vi tri chen: ");
    scanf("%d",&position);
    insert(&mylist,value,position);
    printf("Danh sach sau khi chen: ");
    printNode(&mylist);
    return 0;

}