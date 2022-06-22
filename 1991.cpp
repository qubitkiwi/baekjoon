#include <iostream>

struct node{
    char data;
    node* right;
    node* left;    
};

class Tree
{
private:
    
public:
    node* root;
    Tree(const char& data);
    node* find(node* root, char data);
    bool add_node(const char &par, const char &son_r, const char &son_l);
    ~Tree();

    void pre_order(node* start);
    void in_order(node* start);
    void post_order(node* start);    
};

Tree::Tree(const char& data){
    root = new node {data, NULL, NULL};
}

Tree::~Tree(){
}

node* Tree::find(node* root, char data){
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    
    node *right = find(root->right, data);

    if(right != NULL)
        return right;
    
    return find(root->left, data);
}

bool Tree::add_node(const char &par, const char &son_r, const char &son_l){

    auto parent = find(root, par);

    if(!parent)
        return false;
    
    if (son_r != '.')
        parent->right = new node {son_r, NULL, NULL};
    if (son_l != '.')
        parent->left = new node {son_l, NULL, NULL};
    return true;
}

void Tree::pre_order(node* start){
    if(!start)
        return ;
    
    std::cout << start->data;
    pre_order(start->left);
    pre_order(start->right);    
}

void Tree::in_order(node* start){
    if(!start)
        return ;
    
    in_order(start->left);
    std::cout << start->data;
    in_order(start->right);    
}

void Tree::post_order(node* start){
    if(!start)
        return ;
    
    post_order(start->left);
    post_order(start->right);
    std::cout << start->data;
}



int main(){

    int N;
    std::cin >> N;
    char root, right, left;

    Tree tree('A');

    for (int i = 0; i < N; i++){
        std::cin >> root >> right >> left;
        tree.add_node(root, left, right);
    }

    tree.pre_order(tree.root);
    std::cout << std::endl;

    tree.in_order(tree.root);
    std::cout << std::endl;

    tree.post_order(tree.root);
    std::cout << std::endl;

    return 0;
};