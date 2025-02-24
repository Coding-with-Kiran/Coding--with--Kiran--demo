Tree , Preorder,inorder, postorder 



#include <iostream>
using namespace std;
struct node 
{
    int data;
    node* left;
    node* right;
};

class tree 
{
private:
    node* start;

public:
    tree() 
    {
        start = NULL;
    }

    void create(int x) 
    {    
        if (start == NULL) 
        {
            start = new node;
            start->data = x;
            start->left = NULL;
            start->right = NULL;
        } 
        else 
        {    
            node* cur = start;
            node* parent = NULL;
            while (cur != NULL) 
            {
                if (cur->data == x) 
                {
                    cout << "Data already exists" << endl;
                    return;
                }
                parent = cur;
                if (cur->data < x)
                    cur = cur->right;
                else
                    cur = cur->left;
            }

            node* temp = new node;
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;

            if (parent->data > x)
                parent->left = temp;
            else
                parent->right = temp;
        }
    }

    void search(int x) 
    {
        if (start == NULL) 
        {
            cout << "Tree is empty" << endl;
            return;
        } 
        else 
        {
            node* cur = start;
            while (cur != NULL) 
            {
                if (cur->data == x) 
                {
                    cout << "Data Found" <<cur->data<< endl;
                    return;
                }
                if (cur->data < x)
                    cur = cur->right;
                else
                    cur = cur->left;
            }
            cout << "Value not found" << endl;
        }
    }

    void preorder(node* cur) 
    {
        if (cur == NULL) 
            return;
        cout << cur->data << " ";
        preorder(cur->left);
        preorder(cur->right);
    }

    void inorder(node* cur) 
    {
        if (cur == NULL) 
            return;
        inorder(cur->left);
        cout << cur->data << " ";
        inorder(cur->right);
    }

    void postorder(node* cur) 
    {
        if (cur == NULL) 
            return;
        postorder(cur->left);
        postorder(cur->right);
        cout << cur->data << " ";
    }

    node* getStart() 
    {
        return start;
    }
};

int main() 
{
    tree obj;
    int val, s, opt = 0;

    while (opt != 6) 
    {
        cout << "\n1: Create new Binary Tree\n";
        cout << "2: Search Value from Binary Tree\n";
        cout << "3: Preorder Traverse\n";
        cout << "4: Inorder Traverse\n";
        cout << "5: Postorder Traverse\n";
        cout << "6: Exit\n";
        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt) 
        {
            case 1:
                cout << "Enter 5 values to insert into the tree:\n";
                for (int i = 0; i < 5; i++) 
                {
                    cin >> val;
                    obj.create(val);
                }
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> s;
                obj.search(s);
                break;
            case 3:
                cout << "Preorder Traversal: ";
                obj.preorder(obj.getStart());
                cout << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                obj.inorder(obj.getStart());
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                obj.postorder(obj.getStart());
                cout << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}