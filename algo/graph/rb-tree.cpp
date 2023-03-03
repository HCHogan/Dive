#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int val;
    Color color;
    Node* left_child;
    Node* right_child;
    Node* parent;

    Node(int v) : val(v), color(RED), left_child(nullptr), right_child(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int val) {
        Node* node = new Node(val);
        if(root == nullptr) {
            root = node;
            node->color = BLACK;
            return;
        }

        // find the correct position to insert
        Node* cur_node = root;
        while(cur_node != nullptr) {
            if(node->val < cur_node->val) {
                if(cur_node->left_child == nullptr) {
                    cur_node->left_child = node;
                    break;
                }
                else
                    cur_node = cur_node->left_child;
            }
            else {
                if(cur_node->right_child == nullptr) {
                    cur_node->right_child = node;
                    break;
                }
                else
                    cur_node = cur_node->right_child;   
            }
        }

        // maintain the red-black tree property
        fix_color_and_rotation(node);
        
        // update the root pointer in case it changes during rotation
        while(root != nullptr && root->parent != nullptr)
            root = root->parent;    
    }

private:
    void fix_color_and_rotation(Node* node){
        
       while (node!=root && node!=nullptr && node -> parent -> color==RED){

           auto p=node -> parent;

           auto g=p -> parent;

           if (p==g -> left_child){

               auto u=g -> right_child;

               if (u!=nullptr && u -> color==RED){

                   p -> color=BLACK;

                   u -> color=BLACK;

                   g -> color=RED;

                   node=g;                       

               }else{

                   if (node==p -> right_child){

                       rotate_left(p);

                       swap(p,node);

                   }

                   rotate_right(g);

                   swap(p,g);

               } 

           }else{

               auto u=g -> left_child;

               if (u!=nullptr && u -> color==RED){

                   p -> color=BLACK;

                   u -> color=BLACK;

                   g -> color=RED; 

                   node=g;                      

               }else{

                  if (node==p->left_child){

                     rotate_right(p);   

                     swap(p,node);                     

                  }

                  rotate_left(g);  

                  swap(g,p);                

               }

           }

       }
       
       // make sure that the root is black after any rotations or coloring operations
       root->color=BLACK;    

   }


   void rotate_left(Node *node){     

      auto r=node->right_child;      

      replace_with_parent(node,r);      

      connect_r_to_l(node,r);

      connect_p_to_c(node,r,rightchild,leftchild);        

   }



   void rotate_right(Node *node){     

      auto l=node->left_child;       

      replace_with_parent(node,l);     

      connect_l_to_r(l,node);

      connect_p_to_c(node,l,leftchld,rightchd);         

   }


   void replace_with_parent(Node *oldn,Node *newn){   

       // replace oldn with newn as a child of oldn's parent

       if(oldn->parent!=nullptr){

         oldn->parent-child(newn)=oldn.parent.child(oldn);

         newn->parent=oldn->parent;            

       }else{         

         //if old n is a rooot then make new n as the root too.

         this.root=newn;

         newn.parent=nullptr;;

       }  

     }



     inline void connect_r_to_l(Node *l,Node *r){       

     l.rightchild=r.leftchild;if(r.leftchild!=null)

     r.leftchild.parent=l;} 



     inline void connect_l_to_r(Node *l,Node *r){       

     l.leftchid=r.rightchd;if(r.rightchd!=null)

     r.rightchd.parent=l;} 



     inline void connect_p_to_c(Node *p,Node*c1,int whichc1,

                                int whichc2){  

          c1.parent=p;p.color=RED;c1.color=BLACK;p.child(whichc2)=c1.child(whichc1);

          c1.child(whichc1).parent=p;}

};
