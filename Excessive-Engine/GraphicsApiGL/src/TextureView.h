#pragma once

#include "ITextureView.h"

class TextureView : public ITextureView
{
  public:
    GLuint id;
    GLenum target;
    eDimensions dim;
    rTextureData d;
    
    void destroy();
    void setSamplerState(const rTextureSamplerData* data);
    void update(const rTextureUpdateData* data);
    void getSubData(const rTextureUpdateData* data);
    rTextureData getFormat();
    void genMipChain();
};