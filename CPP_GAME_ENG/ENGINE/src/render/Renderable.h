#pragma once

#include <utils\SharedPtr\SharedPtr.h>

#include <objects\Moveable.hpp>

#include "Cheesy.h"
#include "Sprite.h"
#include "Texture.h"
#include "Text.h"

#include <string>

namespace Engine{

class Engine::Moveable;

class Renderable
{
public:
    Renderable(Engine::SharedPtr<Engine::Moveable> object_ptr, const std::string & texturefilepath);

    ~Renderable();

    void draw();

    bool isValid()      { return m_pMoveable->isActive(); }

private:

    Engine::SharedPtr<Engine::Moveable> m_pMoveable;
    Cheesy::Sprite * m_pSprite;



};

}