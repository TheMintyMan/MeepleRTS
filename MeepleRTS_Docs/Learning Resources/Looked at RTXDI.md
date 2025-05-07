Not sure if it is worth getting the whole NvRTX branch of Unreal.
Probably just get the DLSS plugin and some of their Nvidia plugins to increase performance.
RTXDI and RTXGI seems like it's really to boost performance on high quality PBR games. So, I don't think it's too worth on indie games.

Unreal Engine RTXDI

Nvidia's branch of Unreal engine:
https://github.com/NvRTX/UnrealEngine/tree/nvrtx-5.5

Video Playlist
https://www.nvidia.com/en-us/on-demand/session/other2022-uesprimer/?playlistId=playList-da3472ed-1de5-492d-a6de-b03f1063ecaa

Part 1
https://youtu.be/Y9XPCKQBg8E
Part 2
https://youtu.be/K9TM5tWvNI0

Lumen is the way to go from the guy in video.


## Installation

In the nvrtx folder, run "Setup.bat".

Once setup is fully complete run "GenerateProjectFiles.bat".
Development Build, Win64.

Once that's done, you have the sln file.

UnrealEditor.exe to run the NVRTX version

Search "nvidia" in the plugin window to look at all the NVIDIA plugins.

The executables for the different OS are kept here
E:\UnrealRTX_55\Engine\Binaries

It's called "UnrealEditor.exe"

## Project Settings (Recommended by the Nvidia Unreal Evangelist)

### Rendering

Global Illumination:
- Dynamic Global Illumination Method - Lumen

Reflection:
- Reflection Method - Lumen

Lumen:
- Use Hardware Ray Tracing when available - on
- Software Ray Tracing Mode - Detail Tracing (preferred), Global Tracing (simpler)
- Ray Lighting mode - Hit Lighting for reflection (higher quality), Surface cache (Lower quality)
- High Quality Translucency Reflections - on

Hardware Ray Tracing:
- Path Tracing - on

### Platforms
SM5 - on
SM6 - on
Default RHI - DirectX 12


## Useful Info
RTXDI works directly with Lumen. So Lumen is highly recommended.
Portal RTX and Cyberpunk RTX overdrive both uses RTXDI for their direct rendering.
The Finals, Star Wars Outlaws.

Target 16 ms. roughly 60 fps

Useful Commands:

Turn on/off raytracing
r.RayTracingForceAllRayTracingEffect 

Turn RTXDI completely off, just Lumen. (This should dramatically make the performance worse turning RTXDI off). Lights cost can cut in half
r.SampledLighting 0

Getting nanite to work with hardware raytracing
r.Nanite.Mode

Turning this off can give 5%~15% boost.
r.RayTracing.SampledLighting.Spatial.ApplyApproxVisibility

The amount of reservoirs will change the quality of the lighting. 1 is better for performance. (good to adjust)
r.RayTracing.SampledLighting.NumReservoirs 1
The denoiser. Default is set to 2. Setting it to 0 will disable denoising which could save 1 ms. But it'll look grainy/noisy. Typically, denoiser cost is quite low. Turning the denoiser off is a great way to test what it actually looks like.
r.RayTracing.SampledLighting.Denoiser

You can completely turn specular off. Usually, you want it on. Not really a performance improvement but more a stylistic choice.
r.RayTracing.SampledLighting.CompositeSpecular

At 0, when you whip the camera, it should look fine, and if it does, then leave it at 0. Adding values should cost more.
r.RayTracing.SampledLighting.TestInitialVisibility

This could help with animated lights. Setting it to 1 does not consider much history data.
Maybe like 2?
r.RayTracing.SampledLighting.Temporal.MaxHistory

NRD Plugin stuff.

r.NRD.Relax.History

Tightening the history of diffuse might help. by default this is at "63". try setting it to 4
r.NRD.Relax.History.DiffuseMaxAccumulatedFrameNum 4

BVH Viewer
Bounding Volume Hierarchy
Every Ray Traced object will generate a simple cube volume around its size to determine whether or not rays are going to strike the surface or not.

Show>Visualise>Visualise BVH Complexity and the other BVH Overlap

More objects overlapping will make BVH more complex. 

If kit bashing with lots of things overlapping, it might be worth turning raytracing off on certain objects.

HLOD or combining assets

There isn't too much that you can or should do to optimise?
Engine scalability setting and changing the default.

Lights are usually the most expensive thing on the gpu. Lights alone can take up 2 to 3 ms. And the denoising could cost 1 ms. But that could be acceptable

Check GPU stats
stat gpu



