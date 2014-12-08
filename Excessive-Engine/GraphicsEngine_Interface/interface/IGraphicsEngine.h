#pragma once

#include "../../GraphicsApi_Interface/interface/IGapi.h"

// namespace
namespace ge {

class IScene;
class IMesh;
class IMaterial;
class ITexture;

struct rGraphicsEngine {
	IGapi* gapi;
};


////////////////////////////////////////////////////////////////////////////////
/// GraphicsEngine manages and displays the graphical world.
/// No descrption yet.
////////////////////////////////////////////////////////////////////////////////

class IGraphicsEngine
{
public:
	// interface
	virtual void release() = 0;

	// create stuff
	virtual IScene* createScene() = 0;
	virtual IMesh* createMesh() = 0;
	virtual IMaterial* createMaterial() = 0;
	virtual ITexture* createTexture() = 0;

	// states | just as examples, not stable yet
		// virtual void setTargetWindow();
		// virtual void setScreenSize(int width, int height);

	// interact
	virtual void update() = 0;

	// getters
	virtual IGapi* getGapi() = 0;
};


} // namespace