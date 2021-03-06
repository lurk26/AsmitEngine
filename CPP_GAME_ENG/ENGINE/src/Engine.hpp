#ifndef HEADER_ENGINE_HPP
#define HEADER_ENGINE_HPP

/*
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif 
*/

#include "memory\Allocators.h"
#include "render\BasicRenderer.h"
#include "physics\PhysicsWorld.h"
#include "utils\AutoPtr\AutoPtr.h"
#include "utils\FloatHelpers.h"
#include "utils\NamedBitSet\NamedBitSet.h"
#include "utils\StringPool\StringPool.h"
#include "timing\Timing.h"

namespace Engine
{
    bool        init();

    bool        shutdown();
};

//class Engine
//{
//public:
//    Engine();
//    ~Engine();
//    static void shutdown();
//};

#endif HEADER_ENGINE_HPP