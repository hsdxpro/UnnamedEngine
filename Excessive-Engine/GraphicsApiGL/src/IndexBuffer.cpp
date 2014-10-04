#include "IndexBuffer.h"

#include <string>

void IndexBuffer::destroy()
{
  glDeleteBuffers( 1, &id );
  id = 0;
}

void IndexBuffer::update(char* data, unsigned size, unsigned offset)
{
  if( data )
  {
    void* ptr = glMapNamedBufferRange( id, offset, size, GL_MAP_WRITE_BIT );
    memcpy( ptr, data, size );
    glUnmapNamedBuffer( id );
  }
}

void IndexBuffer::getSubData(char* data, unsigned size, unsigned offset)
{
  if( data )
  {
    glGetNamedBufferSubData( id, offset, size, data );
  }
}

rAllocData IndexBuffer::getAllocData()
{
  return adata;
}