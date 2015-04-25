#pragma once

#include <utils\SharedPtr\SharedPtr.h>

#include <objects\GameObject.hpp>

#include "Cheesy.h"
#include "Sprite.h"
#include "Texture.h"
#include "Text.h"

#include <string>

namespace Engine{

class Engine::GameObject;

class Renderable
{
public:
    Renderable(Engine::SharedPtr<Engine::GameObject> object_ptr, const std::string & texturefilepath);

    ~Renderable();

    void draw();

    bool isValid()      { return m_pGameObject->isActive(); }

private:

    Engine::SharedPtr<Engine::GameObject> m_pGameObject;
    Cheesy::Sprite * m_pSprite;



};

}