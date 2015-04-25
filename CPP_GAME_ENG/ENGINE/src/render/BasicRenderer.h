#pragma once

#include <render/Renderable.h>
#include <utils/SharedPtr/SharedPtr.h>

#include <vector>

namespace Engine{

class GameObject;
class BasicRenderer
{
private:
    static BasicRenderer* m_basic_renderer;
    std::vector<Renderable*> m_renderables;
    
    struct Cheesy::ColorRGBA m_ClearColor;

    BasicRenderer();
    ~BasicRenderer();

public:
    static BasicRenderer * get()    { return m_basic_renderer; }
    static bool    init();
    static void    shutdown();

    bool    addRenderable(Engine::SharedPtr<GameObject> GameObject_ptr, std::string & texture_file_path);

    void    update(float dt);
    void    setClearColor(struct Cheesy::ColorRGBA c_c) { m_ClearColor = c_c; }
};

}