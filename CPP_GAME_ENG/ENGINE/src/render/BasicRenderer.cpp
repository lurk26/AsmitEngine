#include "BasicRenderer.h"

BasicRenderer* BasicRenderer::m_basic_renderer = nullptr;

BasicRenderer::BasicRenderer()
{
    m_renderables.clear();
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

bool BasicRenderer::addRenderable(Engine::SharedPtr<Moveable> moveable_ptr, std::string & texture_file_path)
{
    Renderable * new_renderable_object = new Renderable(moveable_ptr, texture_file_path);
    assert(new_renderable_object);
    m_renderables.push_back(new_renderable_object);
    return true;
    
}

void BasicRenderer::update(float dt)
{
    bool bQuit = false;

    Cheesy::Service(bQuit);

    struct Cheesy::ColorRGBA ClearColor(50, 50, 255, 0);

    if (!bQuit && Cheesy::BeginFrame(ClearColor))
    {
        for (unsigned int i = 0; i < m_renderables.size(); i++)
        {
            m_renderables[i]->draw();

            if (!m_renderables[i]->isValid()) m_renderables.erase(m_renderables.begin() + i);
        }

        Cheesy::EndFrame();
    }
}