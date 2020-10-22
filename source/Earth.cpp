#include <iostream>
#include <string>
#include "Earth.h"
#include "Vector3D.h"

Earth* Earth::instance = nullptr;

Earth::Earth():MobileHeavy("Earth", Vector3D(0.0,0.0,0.0) , Vector3D(0.0,0.0,0.0),6378000.0,5513584.0){
}

Earth* Earth::GetInstance() {
    if (instance == nullptr) {
        instance = new Earth();
    }
    return instance;
}
