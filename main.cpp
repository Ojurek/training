#include <iostream>
#include "BinarySearchTree.h"


int main(int argc, char const *argv[])
{
    BinarySearchTree<int> tree(12);
    tree.insert(4);    
    tree.insert(5);    
    tree.insert(20);  
    tree.insert(4);
    tree.insert(1);  
    tree.insert(22);  
    tree.insert(19);  

    std::cout<<"Tree max value = "<<tree.getMaxValue()<<std::endl;    
    std::cout<<"Tree min value = "<<tree.getMinValue()<<std::endl;   

    std::cout<<"Find 5 = "<<tree.find(5)<<std::endl;
    std::cout<<"Find 100 = "<<tree.find(100)<<std::endl;


    return 0;
}
