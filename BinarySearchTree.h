#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <iostream>
#include <memory>
#include "Tree.h"


template <typename T>
class BinarySearchTree: public Tree<T>{
    private:
        struct Node{
            T m_data;
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;

            Node (const T& data)
                :m_data(data)
            {}
        };
        std::unique_ptr<Node> root;
        
        void insert_help(const T &data, std::unique_ptr<Node> &checked_node){
            
            if (checked_node->m_data > data){
                if (!checked_node->left) {
                    std::cout<<"inserted "<<data<<" left from "<<checked_node->m_data<<std::endl;
                    checked_node->left=std::make_unique<Node>(Node(data));
                    return;
                } 
                insert_help(data, checked_node->left);
                return;
            }

            if (checked_node->m_data < data){
                if (!checked_node->right) {
                    std::cout<<"inserted "<<data<<" right from "<<checked_node->m_data<<std::endl;
                    checked_node->right=std::make_unique<Node>(Node(data));
                    return;
                } 
                insert_help(data, checked_node->right);
                return;
            }

            // checked_node->m_data==data
            std::cout<<"repeat insert"<<std::endl;
        }

        const T& getMaxValue_help (std::unique_ptr<Node> &checked_node) const{
            if (!checked_node->right) {
                return checked_node->m_data;
            }

            return getMaxValue_help(checked_node->right);
        }

        const T& getMinValue_help (std::unique_ptr<Node> &checked_node) const{
            if (!checked_node->left) {
                return checked_node->m_data;
            }

            return getMinValue_help(checked_node->left);
        }

        bool find_help(const T &data, const std::unique_ptr<Node> &checked_node) const{
            
            if (checked_node->m_data > data){
                if (!checked_node->left) {
                    return false;
                } 
                return find_help(data, checked_node->left);
            }

            if (checked_node->m_data < data){
                if (!checked_node->right) {
                    return false;
                } 
                return find_help(data, checked_node->right);
            }
            return true;
        }

        void remove_help(const T &data, std::unique_ptr<Node> &checked_node){
            if(checked_node->left){
                if (checked_node->left->m_data == data){
                    remove_node(checked_node, checked_node->left);
                }
            }

            if(checked_node->right){        
                if (checked_node->right->m_data == data){
                    remove_node(checked_node, checked_node->right);
                }
            }

            if (checked_node->m_data > data){
                remove_help(data, checked_node->left);
            }

            if (checked_node->m_data < data){
                remove_help(data, checked_node->right);
            }     
        }

        void remove_node(std::unique_ptr<Node> &parent_node, std::unique_ptr<Node> &delete_node){
                std::cout<<"Value of parent = "<<parent_node->m_data<<std::endl;
                std::cout<<"Value to remove = "<<delete_node->m_data<<std::endl;
        }
    public:
        BinarySearchTree(T data):Tree<T>(){
            root= std::make_unique<Node> (Node(data));
        }

        virtual void traversal() const{};
        virtual void insert (const T &data){
            
            if (!root){
                root=std::make_unique<Node>(Node(data));
                std::cout<<"inserted "<<data<<" in root"<<std::endl;
                return;
            }

            insert_help(data, root);
        }

        virtual void remove (const T &data){
            if (!root){
                std::cout<<"root not exist"<<std::endl;
            }

            if(root->m_data == data){
                std::cout<<"remove root not ready"<<std::endl;
                if (root->left) {
                    std::cout<<"value before root"<<getMaxValue_help(root->left)<<std::endl;
                }

                if (root->right) {
                    std::cout<<"value after root"<<getMinValue_help(root->right)<<std::endl;
                }
                std::cout<<"remove root not ready"<<std::endl;
                    //remove_node(root, root->left);
            }

            if((root->m_data > data) && (root->left)){
                if (root->left->m_data == data) {
                    remove_node(root, root->left);
                } else {
                    remove_help(data, root->left);
                }
            }

            if((root->m_data < data) && (root->right)){
                if (root->right->m_data == data) {
                    remove_node(root, root->right);
                } else {
                    remove_help(data, root->right);
                }
            }
        };

        virtual const T& getMaxValue () const{
            if (!root) {
                std::cout<<"Tree is empty"<<std::endl;
            }

             return getMaxValue_help(root->right);            
        }

        virtual const T& getMinValue () const{ 
            if (!root) {
                std::cout<<"Tree is empty"<<std::endl;
            }

            return getMinValue_help(root->left);            
        }

        virtual bool find(const T &data) const{
            if (!root){
                return false;
            }

            return find_help(data, root);
        }
};


#endif //BinarySearchTree_h