#include <memory>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::unique_ptr<int> a;

    if (!a) {
        std::cout<<"bez problemu"<<std::endl;
    }

    std::cout<<"przeszlo"<<std::endl;

    return 0;
}





