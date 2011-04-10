/* 
 * File:   main.cpp
 * Author: Fran_2
 *
 * Created on 21 de marzo de 2011, 11:19
 */

#include <cstdlib>
#include <iostream>
#include <Demo/DemoSystemManager.h>

int main(int argc, char** argv) {
    if (DemoSystemManager::getInstance()->initSystem()) {
        std::cout << "Wasabi Engine loaded." << std::endl;
        DemoSystemManager::getInstance()->run();
    } else {
        std::cout << "Error loading Wasabi Engine." << std::endl;
    }
    return 0;
}
