# Pytr - A Path Tracing Renderer
Pytr is a cross-platform path tracing renderer that could be configured to run on both CPU and Nvidia GPU. Its framework APIs are designed to be as volatile as possible to work with most C++ projects, supporting a real-time progressive UI/UX.

author: Wei Guo wei.parker.guo.sg@gmail.com
Date Initiated: 2020-08-20

# Usage
This project is platform independant and uses cmake to build. You do need an  **Nvidia GTX GPU**  if you plan to build the Cuda version.

## General Build Steps for Developers
Should work for any IDEs as long as you have cmake version >= 2.8.

1.  ‘cd’ into your clone directory, type into the Terminal the following step by step
2.  mkdir build
3.  cd build
4.  cmake ..
5.  make
6.  run the pytr.exe in build
7.  Supply the root folder of your scene to load, otherwise default to existent one called testScene (make sure your textures and materials are named properly!)
8.  If you wish to use custom setup for options, type the options line by line in a txt file in build and specify it when program opens.
9.  There is a template options.txt inside src, you can copy, rename and modify it to start quicker.

## For Windows Visual Studio Build Only
This is the exact repulication of the implementer's build process.

1.  Launch Visual Studio, under File tab open the root CMakeList as CMakeList project.
2.  Edit the CMakeSettings.json in root to specify your own output directory (like out or something).
3.  Select pytr.exe to be the startup item.
4.  Run.

# Features
1. Multiple model file formats supporting.
2. Material editing and creating.
3. Viewport customization.
4. Midpoint Partitioning BVH Tree acceleration for ray hits.
5. Render result saving to jpeg image on program exit.

## Accepted Model Files:
The files accepted by this raytracer will be synced with the accepted file types of Assimp.

**Collada** ( .dae, .xml ) **Blender** ( .blend ) **Biovision BVH** ( .bvh ) **3D Studio Max 3DS** ( .3ds ) **3D Studio Max ASE** ( .ase ) **Wavefront Object** ( .obj ) **Stanford Polygon Library** ( .ply ) **AutoCAD DXF** ( .dxf ) **IFC-STEP** ( .ifc ) **Neutral File Format** ( .nff ) **Sense8 WorldToolkit** ( .nff ) **Valve Model** ( .smd, .vta ) **Quake I** ( .mdl ) **Quake II** ( .md2 ) **Quake III** ( .md3 ) **Quake 3 BSP** ( .pk3 ) **RtCW** ( .mdc ) **Doom 3** ( .md5mesh, .md5anim, .md5camera ) **DirectX X** ( .x ) **Quick3D** ( .q3o, .q3s ) **Raw Triangles** ( .raw ) **AC3D** ( .ac ) **Stereolithography** ( .stl ) **Autodesk DXF** ( .dxf ) **Irrlicht Mesh** ( .irrmesh, .xml ) **Irrlicht Scene** ( .irr, .xml ) **Object File Format** ( .off ) **Terragen Terrain** ( .ter ) **3D GameStudio Model** ( .mdl ) **3D GameStudio Terrain** ( .hmp ) **Ogre** ( .mesh.xml, .skeleton.xml, .material ) **Milkshape 3D** ( .ms3d ) **LightWave Model** ( .lwo ) **LightWave Scene** ( .lws ) **Modo Model** ( .lxo ) **CharacterStudio Motion** ( .csm ) **Stanford Ply** ( .ply ) **TrueSpace** ( .cob, .scn )

# Referenced Codes
1.  GLFW Version 3.3.2
2.  GLEW
3.  ASSIMP Version 5.0.1
4.  CUDA
5.  dirent.h for directory/file manipulations
6.  linmath.h under GLFW Dependencies
7.  Ultralight UX for front-end HTML UI Engine
8.  tooljpeg jpeg encoder from  [https://create.stephan-brumme.com/toojpeg/](https://create.stephan-brumme.com/toojpeg/)
9.  Code references are enclosed as inline comments.
