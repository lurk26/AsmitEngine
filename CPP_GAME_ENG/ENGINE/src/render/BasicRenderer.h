#pragma once

#include <render/Renderable.h>
#include <utils/SharedPtr/SharedPtr.h>

#include <vector>

class Moveable;
class BasicRenderer
{
private:
    static BasicRenderer* m_basic_renderer;
    std::vector<Renderable*> m_renderables;
    BasicRenderer();
    ~BasicRenderer();

public:
    static BasicRenderer * get()    { return m_basic_renderer; }
    static bool    init();
    static void    shutdown();

    bool    addRenderable(Engine::SharedPtr<Moveable> moveable_ptr, std::string & texture_file_path);

    void    update(float dt);
};

