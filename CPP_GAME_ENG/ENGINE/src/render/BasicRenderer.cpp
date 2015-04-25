#include "BasicRenderer.h"

namespace Engine
{

BasicRenderer* BasicRenderer::m_basic_renderer = nullptr;

BasicRenderer::BasicRenderer()
{
    m_renderables.clear();
    m_ClearColor = { 50, 50, 255, 0 };
}


BasicRenderer::~BasicRenderer()
{
}

bool BasicRenderer::init()
{
    BasicRenderer* new_renderer = new BasicRenderer();
    assert(new_renderer);
    m_basic_renderer = new_renderer;
    return true;
}

void BasicRenderer::shutdown()
{
    if (m_basic_renderer)
        delete m_basic_renderer;
}

bool BasicRenderer::addRenderable(Engine::SharedPtr<GameObject> GameObject_ptr, std::string & texture_file_path)
{
    Renderable * new_renderable_object = new Renderable(GameObject_ptr, texture_file_path);
    assert(new_renderable_object);
    m_renderables.push_back(new_renderable_object);
    return true;
    
}

void BasicRenderer::update(float dt)
{
    bool bQuit = false;

    Cheesy::Service(bQuit);

    if (!bQuit && Cheesy::BeginFrame(m_ClearColor))
    {
        for (unsigned int i = 0; i < m_renderables.size(); i++)
        {
            m_renderables[i]->draw();

            if (!m_renderables[i]->isValid()) m_renderables.erase(m_renderables.begin() + i);
        }

        Cheesy::EndFrame();
    }
}
}