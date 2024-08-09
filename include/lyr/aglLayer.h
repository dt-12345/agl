#pragma once

#include <container/seadBuffer.h>
#include <container/seadListImpl.h>
#include "container/seadTList.h"
#include <gfx/seadViewport.h>
#include <mc/seadJob.h>
#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>

namespace sead {
class DirectCamera;
class Heap;
class Projection;
} // namespace sead

namespace agl::lyr {

class LayerJob;
class Renderer;
class RenderDisplay;
class RenderStep;

class Layer {
    SEAD_RTTI_BASE(Layer)
public:
    virtual ~Layer();

    struct CreateArg {
        sead::Heap* heap;
        sead::SafeString* label;
        u8 _10[8];
        sead::SafeString name;
        u8 _20;
    };

private:
    sead::Heap* mContainedHeap;
    sead::TListNode<sead::Heap*> mHeapListNode;
    Renderer* mRenderer;
    sead::Viewport mRenderInfoViewport;
    sead::Viewport mRenderViewport;
    sead::DirectCamera* mCamera;
    sead::Projection* mProjection;
    u16 _88;
    u16 _8A;
    char _8C[4];
    u8 _90;
    char _91[2];
    u8 _93;
    u32 _94;
    char _98[0x18];
    sead::Buffer<RenderStep> mRenderStepArray;
    u32 mMostCommonlyUsedCommandMemory;
    LayerJob* _C8[3];
    sead::FixedSafeString<256> mLayerName;
    char _1F0[8];
};

class LayerJob : public sead::Job {
public:
    ~LayerJob() override;

private:
    u32 _10;
    RenderDisplay* mDisplay;
    char _28[8];
};

} // namespace agl::lyr