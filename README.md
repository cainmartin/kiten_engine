# Kiten Engine
An experimental OpenGL engine

# Kiten
輝点 - A stuck pixel, or point of light

# TODO

Rendering

- Controller / gamepad support
- Add an event system instead of using polling
- Add camera capture
- Add geometry generators (spheres / etc)
- Implement texture loading
- Add lighting model to the shaders
  - Ambient
  - Spot / point / directional
- PBR
- Cubemap / skybox
- Asset manager (actual asset manager)
- Add different rendering pipelines (Forward / Deferred)
- Add shadowmapping
- Hot reloading
- Scene graph
- Make root / base path automated, or use config
- Logging system
- Make project into library
- Rename project
- Character controller
- Debug draw functionality
- Picking / ray-casting
- Batch rendering
- Instanced rendering
- Asynch texture loading (optimisation for GPU uploads)
- Config system (TOML? / Json?)
- Framebuffers (Offscreen rendering)
- Post process
  - Bloom / Blur / Tone mapping
- Full screen support
- Physics generation on model import
- OBJ and GLTF support (Try this from scratch, but maybe use ASIMP?)

Audio
- Probably use OpenAL

Physics
- Integrate physics (Bullet?)

Documentation
- Clearly layout hiearchy - this is loosely following a layered system
- i.e. platform independence layer, is below core layer, is below the resources, is below the game specific subsystems

Done
- ImGUI
- Basic camera
- Basic Input system
- Basic rendering
- Added a simple cube generator
