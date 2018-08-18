#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

template <class T>
class BinarySearchTree
{
   public:
       BinarySearchTree() : root(NULL) {}

       BinarySearchTree(const T* arr, int size)
       {
           root = createBalanced(arr, size, 0, size-1);
       }

       BinarySearchTree(const BinarySearchTree& bstree)
       {
           root = copy(bstree.root);
       }

       BinarySearchTree& operator=(const BinarySearchTree& bstree)
       {
           if(this != &bstree)
           {
               destroy(root);
               root = copy(bstree.root);
           }
           return *this;
       }

       ~BinarySearchTree()
       {
           destroy(root);
       }

       void insert(const T& element)
       {
           insert(root, element);
       }

       void remove(const T& element)
       {
           remove(root, element);
       }

       bool find(const T& element)
       {
           find(root, element);
       }

       void printTree() const
       {
           print(root);
       }

   private:

        struct Node;

        bool find(const Node* r, const T& key)
        {
            if(!r)
            {
                return false;
            }
            if(r->data == key)
            {
                return true;
            }
            if(key > r->data)
            {
                return find(r->right, key);
            }
            else
            {
                return find(r->left, key);
            }
        }

        void insert(Node *& r, const T& key)
        {
            if(!r)
            {
                r = new Node(key);
            }
            else if(key > r->data)
            {
                insert(r->right, key);
            }
            else if(key < r->data)
            {
                insert(r->left, key);
            }
        }

        void remove(Node *& r, const T& key)
        {
            if(!r)
            {
                return;
            }
            if(key > r->data)
            {
                remove(r->right, key);
            }
            else if(key < r->data)
            {
                remove(r->left, key);
            }
            else
            {
                Node* toDel = r;
                if(!r->left)
                {
                    r = r->right;
                }
                else if(!r->right)
                {
                    r = r->left;
                }
                else
                {
                    r = removeMax(r->left);
                    r->left = toDel->left;
                    r->right = toDel->right;
                }
                delete toDel;
            }
        }

        Node* removeMax(Node *& r)
        {
            if(!r->right)
            {
                Node* max = r;
                r = r->left;
                return max;
            }
            return removeMax(r->right);
        }

        Node* copy(const Node* r)
        {
            if(!r)
            {
                return r;
            }
            Node* n = new Node;
            n->data = r->data;
            n->left = copy(r->left);
            n->right = copy(r->right);
            return n;
        }

        void destroy(Node* r)
        {
            if(r)
            {
                destroy(r->left);
                destroy(r->right);
                delete r;
            }
        }

        void print(const Node* r) const
        {
            if(!r)
            {
                return;
            }
            print(r->left);
            std::cout << r->data << " ";
            print(r->right);
        }

        Node* createBalanced(const T* arr, int size, int l, int r)
        {
            if(r < l)
            {
                return NULL;
            }
            int mid = (l+r)/2;
            Node* n = new Node(arr[mid]);
            n->left = createBalanced(arr, size, 1, mid-1);
            n->right = createBalanced(arr,size, mid+1, r);
            return n;
        }

   private:

       struct Node
       {
           T data;
           Node* left;
           Node* right;

           Node(const T& data, Node* left = NULL, Node* right = NULL) : data(data), left(left), right(right) {}
       };

       Node* root;

};
#endif
