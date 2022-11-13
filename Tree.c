#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//노드 구조체
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NODE;

//함수 선언
NODE* make_node(int);
NODE* make_tree_by_code();
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);
NODE* copy(NODE*);
int equal(NODE*, NODE*);
NODE* swap(NODE*);
NODE* random_node(NODE*, int);
NODE* random_tree(int);

//메인 함수
int main ()
{
    //직접 코드로 트리를 구현
    printf("8.1.1. 트리 구성 (A = make_tree_by_code())\n");
    NODE* root_A = make_tree_by_code();
    //트리 순회
    printf("8.1.2. 트리 순회 (A)\n");
    printf("inorder(A) : ");
    inorder(root_A);
    printf("\n");
    printf("preorder(A) : ");
    preorder(root_A);
    printf("\n");
    printf("postorder(A) : ");
    postorder(root_A);
    printf("\n\n");
    //트리 복사
    printf("8.2.1. 트리 복사 (B = copy(A))\n");
    NODE* root_B = copy(root_A);
    //복사한 트리 순회 
    printf("8.2.2. 트리 순회 (B)\n");
    printf("inorder(B) : ");
    inorder(root_B);
    printf("\n");
    printf("preorder(B) : ");
    preorder(root_B);
    printf("\n");
    printf("postorder(B) : ");
    postorder(root_B);
    printf("\n\n");
    //트리 동질성
    printf("8.2.3. 트리 동질성 검사 (equal(A,B))\n");
    printf("equal(A,B) : %d\n\n", equal(root_A, root_B));
    //트리 스왑
    printf("8.2.4. 트리 swap (C = swap(A))\n");
    NODE* root_C = swap(root_A);
    //swap한 트리 순회
    printf("8.2.5. 트리 순회 (C)\n");
    printf("inorder(C) : ");
    inorder(root_C);
    printf("\n");
    printf("preorder(C) : ");
    preorder(root_C);
    printf("\n");
    printf("postorder(C) : ");
    postorder(root_C);
    printf("\n\n");
    //랜덤 트리 자동 생성
    printf("8.3.1. 랜덤 트리 자동 생성 (D)\n");
    //사용자로부터 정수 user_input을 입력받음
    printf("Input n : ");
    int user_input;
    scanf("%d", &user_input);
    //예외처리: 1보다 작은 수를 입력받을 때
    if (user_input<1){
        printf("err: wrong number\n");
        return(0);
    }
    NODE* root_D = random_tree(user_input);
    //랜덤으로 생성한 트리 순회
    printf("8.3.2. 트리 순회 (D)\n");
    printf("inorder(D) : ");
    inorder(root_D);
    printf("\n");
    printf("preorder(D) : ");
    preorder(root_D);
    printf("\n");
    printf("postorder(D) : ");
    postorder(root_D);
    printf("\n\n");

    return 0;
}

//새로운 노드를 생성하는 함수
NODE* make_node(int data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//주어진 트리를 생성하는 함수
NODE* make_tree_by_code() 
{
    NODE* root_A = make_node(5);
    root_A->left = make_node(3);
    root_A->right = make_node(8);
    root_A->left->left = make_node(1);
    root_A->left->right = make_node(4);
    return root_A;
}

//inorder
void inorder(NODE* node) 
{
    if (node){
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

//preorder
void preorder(NODE* node) 
{
    if (node) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

//postorder
void postorder(NODE* node)
{
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

//트리 복사
NODE* copy(NODE* origin)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE*));
    if(origin) {
        //NODE* temp = (NODE*)malloc(sizeof(NODE*));
        temp->left = copy(origin->left);
        temp->right = copy(origin->right);
        temp->data = origin->data;
        return temp;
    }
    return NULL;
}

//트리 동일성 검사
int equal(NODE* first, NODE* second)
{
    return ((!first &&!second) || (first&&second) &&
        (first->data == second->data) &&
        equal(first->left, second->left) &&
        equal(first->right, second->right));
}

//노드 swap
NODE* swap(NODE* origin)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE*));
    if(origin) {
        temp->left = swap(origin->right);
        temp->right = swap(origin->left);
        temp->data = origin->data;
        return temp;
    }
    return NULL;
}

//랜덤으로 노드를 생성, 왼쪽 또는 오른쪽에 노드를 생성한다. 
//temp는 기존의 노드, data는 추가할 노드에 들어갈 데이터
NODE* random_node(NODE* temp, int data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    srand(time(NULL));
    int random = rand()%2;
    if (random==0) {
        if (temp->left==NULL) temp->left=node;
        else random_node(node,data);
    }
    else {
        if (temp->right==NULL) temp->right=node;
        else random_node(node,data);
    }
    return temp;
}

//랜덤 트리를 생성하는 함수
NODE* random_tree(int n)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE*));
    temp->data=1;
    for(int i=2; i<=n; i++)
    {
        random_node(temp, i);
    }
    return temp;
}