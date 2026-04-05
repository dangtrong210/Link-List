# DANH SÁCH LIÊN KẾT (LINK LIST)
## 1. Định nghĩa:
Danh sách liên kết (Linked List) là một dãy các cấu trúc dữ liệu được kết nối với nhau thông qua các liên kết (link). Danh sách liên kết là một cấu trúc dữ liệu bao gồm một nhóm các nút (node) tạo thành một chuỗi. Mỗi nút gồm dữ liệu ở nút đó và tham chiếu đến nút kế tiếp trong chuỗi.
Định nghĩa nút (NODE): Gồm 2 thành phần là dữ liệu và con trỏ tham chiếu tói tới Node tiếp theo.
## 2. Một số thao tác trên khi sử dụng link list trong C:
**2.1. Định nghĩa Node:**
````ruby
typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;
````
**2.2. Định nghĩa danh sách liên kết: gồm phần đầu (head) và phần đuôi (tail).**
````ruby
typedef struct list{
    NODE *head;
    NODE *tail;
}list;
````
**2.3. Tạo một Node mới: hàm sẽ lấy dữ liệu (value) từ hàm main để tạo Node:**
````ruby
NODE *new(int value){
    NODE *newNode=((NODE*)malloc(sizeof(NODE)));  //Cấp phát bộ nhớ động cho Node
    if(newNode==NULL){
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
````
**2.4. Tạo danh sách rỗng: khi chưa nhập dữ liệu thì ta phải cho dữ liệu một giá trị rỗng (NULL) trong danh sách để thực hiện các thao tác khác trong danh sách liên kết**
````ruby
void init(list *l){
    l->head=NULL;
    l->tail=NULL;
}
````
> [!IMPORTANT]
> Mỗi khi phần head hay tail thay đổi thì đều phải cập nhật chúng.

**2.5. Hàm nối các Node mới lần lượt:**
````ruby
void append(list *mylist,int value){
    NODE *newNode=new(value);
    if(mylist->head==NULL){  //Node đầu rỗng -> danh sách rỗng -> Node mới vừa là đầu vừa là duôi  
        mylist->head=newNode;
        mylist->tail=newNode;
    }
    mylist->tail->next=newNode;
    mylist->tail=newNode;
}
````
**2.6. Hàm nối Node mới vào vị trí (position) bất kỳ:**
````ruby
void insert(list *mylist,int value,int position){
    NODE *newNode=new(value);
    if(position==0){                    //Trường hợp 1: Chèn vào đầu danh sách
        if(mylist->head==NULL){
            mylist->head=newNode;
            mylist->tail=newNode;
        }
        newNode->next=mylist->head;     //Con trỏ next của Node mới trỏ tới Node đầu hiện tại 
        mylist->head=newNode;
        return;
    }
    if(position>0){                     //Trường hợp 2: Không chèn vào dầu danh sách
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
````
**2.7. Hàm in dữ liệu các Node trong danh sách:**
````ruby
void printNode(list *mylist){
    NODE *current=mylist->head;     //Tạo một con trỏ tạm thời để duyệt qua danh sách
    while(current!=NULL){           //Duyệt đến khi con trỏ tạm thời bằng NULL
        printf("%d ",current->data);
        current=current->next;      //Di chuyển con trỏ tạm thời đến Node tiếp theo
    }
    printf("NULL");
}
````
> [!NOTE]
> Có thể sử dụng cách duyệt lần lượt các Node như hàm printNode để tạo các hàm như: tìm kiếm (search), xóa (delete),...
## 3. Lợi ích khi sử dung danh sách liên kết so với mảng (array):
* 3.1. Cấp phát bộ nhớ linh hoạt.
* 3.2. Tiết kiệm bộ nhớ hơn so với tạo mảng.
* 3.3. Dễ dàng truy xuất dữ liệu.
