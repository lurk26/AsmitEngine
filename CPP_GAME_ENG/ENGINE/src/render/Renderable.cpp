#include "Renderable.h"

#include "objects\Moveable.hpp"

#include "utils\Vec3.hpp"
#include "utils\Matrix4.h"

#include "string"

namespace Engine{

Renderable::Renderable(Engine::SharedPtr<Moveable> object_ptr, 
                        const std::string& texturefilepath) :
                        m_pMoveable(object_ptr)
{
    
    // some defaults
    Cheesy::UVSet				UVs = { Cheesy::UV(0.0f, 0.0f), Cheesy::UV(1.0f, 0.0f), Cheesy::UV(0.0f, 1.0f), Cheesy::UV(1.0f, 1.0f) };
    struct Cheesy::ColorRGBA White(255, 255, 255, 255);
    struct Cheesy::Point2D		center(0.0f, 0.0f);
    struct Cheesy::Point2D		size(50.0f, 50.0f);


    Cheesy::Texture * texture = Cheesy::Texture::CreateTextureFromFile(texturefilepath.c_str());
    assert(texture);

    m_pSprite = Cheesy::Sprite::Create(center, 0.1f, size, White, *texture, UVs);
    assert(m_pSprite);

    texture->Release();
}


Renderable::~Renderable()
{
    delete m_pSprite;
}


void Renderable::draw()
{
    Vec3 pos_vec3 = m_pMoveable->getPosition();
    //Transform trans = m_pMoveable->getTrans();
    Vec3 rot_rpy = m_pMoveable->getRotation();

    struct Cheesy::Point2D pos(pos_vec3.getX(), pos_vec3.getY());

    m_pSprite->Draw(pos, rot_rpy.Z() /* rotation */);
}
}