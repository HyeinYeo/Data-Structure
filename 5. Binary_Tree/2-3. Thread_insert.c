// ������ ����Ʈ�� ��� ����
#define TRUE 1
#define FALSE 0
typedef struct TNode{
	int data;
	struct TNode *left, *right;
	short right_thread; // ���ǻ� ������ ������ ���� �ʵ常 ���� 
};

// �����ʿ� ���� 
void thread_insert_right(TNode *parent, int data){
	TNode *node = (TNode*)malloc(sizeof(TNode));
	node->data = data;
	
	// 1) �� ��忡 �θ��� �ļ��ڿ� right_thread ���¸� �Űܿ�
	node->right = parent->right;
	node->right_thread = parent->right_thread;
	
	// 2) �θ���� �� ��� �ձ�
	parent->right = node;
	
	// 3) �θ����� right_thread ���� ��ȭ��Ű��
	parent->right_thread = FALSE; 
	
	// 4) �� ����� ���� ��ũ�� null�� �ʱ�ȭ
	node->left = NULL; 
}

// ���ʿ� ����
void thread_insert_left(TNode *parent, int data){
	TNode *ptr;
	TNode *node = (TNode*)malloc(sizeof(TNode));
	node->data = data;
	
	// 1. �ܸ���� ��ġ�� �����ϴ� ���
	if (!(parent->left)){
		parent->left = node;
		node->right = parent;
		node->right_thread = TRUE;
	}
	// 2. �߰� ��ġ�� �����ϴ� ��� 
	else{
		// 1) �θ����� ���� �ڽĳ�� => ���� ������ ����� �ļ��ڸ� �� ���� ����
		ptr = parent->left;
		while (!(ptr->right_thread))
			ptr = ptr->right;
		ptr->right = node;
		
		// 2) �θ����� ���� �ڽĳ��� �� ��� ����
		node->left = parent->left;
		
		// 3) �θ���� ����
		parent->left = node;
		
		// 4) �� ����� �ļ��ڸ� �θ���� ����
		node->right = parent;
		node->right_thread = TRUE; 
	}		
} 
