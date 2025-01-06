//
// Created by lepag on 1/5/2025.
//

#ifndef TIMER_H
#define TIMER_H

namespace Vertex3D {

class Timer {
public:
    float deltaTime = 0.0f;
    void Update();
private:
    float lastFrameTime = 0.0f;
};

} // Vertex3D

#endif //TIMER_H
