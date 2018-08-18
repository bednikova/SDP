#ifndef __TREE_H__
#define __TREE_H__

//left son right brother
template <class T>
class Tree
{
    public:
        Tree() : root(NULL) {}

        Tree(const Tree& t)
        {
            root = copy(t.root);
        }

        Tree& operator=(const Tree& t)
        {
            if(this != &t)
            {
                destroy(root);
                root = copy(t.root);
            }
            return *this;
        }

        ~Tree()
        {
           destroy(root);
        }

        void addSon(const T& key, const T& element)
        {
            Node* parent = find(root, key);
            Node* newNode = new Node(element);
            if(newNode == NULL)
                return;
            newNode->bro = parent->son;
            parent->son = newNode;
        }

        void addBro(const T& key, const T& element)
        {
            Node* brother = find(root, key);
            Node* newNode = new Node(element);

            if(newNode == NULL)
            {
                return;
            }
            newNode->bro = brother->bro;
            brother->bro = newNode;
        }

        void setRoot(const T& x)
        {
            if(!root)
            {
                root = new Node(x);
            }
            else
            {
                root->data = x;
            }
        }

        void printTree() const
        {
            print(root);
        }

    private:
        struct Node;

        void destroy(Node* r)
        {
            if(r)
            {
                destroy(r->bro);
                destroy(r->son);
                delete r;
            }
        }

        Node* copy(const Node* r) const
        {
            if(!r)
                return r;
            Node* n = new Node;
            n->data = r->data;
            n->bro = copy(r->bro);
            n->son = copy(r->son);
        }

        Node* find(Node* r, int key)
        {
            if(!r)
                return NULL;
            if(key == r->data)
            {
                return r;
            }
            else
            {
                Node* res = find(r->bro, key);
                if(!res)
                {
                    return find(r->son, key);
                }
                return res;
            }

        }

        void print(const Node* r) const
        {
            if(!r)
                return;
            std::cout << r->data;
            print(r->son);
            print(r->bro);
        }
    private:
        struct Node
        {
            T data;
            Node* bro;
            Node* son;

            Node(const T* data, Node* bro = NULL, Node* son = NULL) : data(data), bro(bro), son(son) {}
        };

        Node* root;

};
#endif
