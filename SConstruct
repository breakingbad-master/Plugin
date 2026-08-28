#!/usr/bin/env python3
import os
from SCons.Script import Environment, ARGUMENTS, Dir

ROOT = os.path.abspath(str(Dir('#').abspath))
UVE_ROOT = os.path.join(ROOT, 'thirdparty', 'uvestudio', 'Animation')
RUNTIME_SOURCES = []
RUNTIME_INCLUDES = []
for module in ('control_rig', 'motion_query'):
    runtime = os.path.join(UVE_ROOT, module, 'Source', 'Runtime')
    RUNTIME_INCLUDES.extend([os.path.join(runtime, 'include')])
    RUNTIME_SOURCES.extend([os.path.join(runtime, 'src', f) for f in os.listdir(os.path.join(runtime, 'src')) if f.endswith('.cpp')])

godot_cpp = os.path.abspath(ARGUMENTS.get('godot_cpp', os.environ.get('GODOT_CPP', 'godot-cpp')))
target = ARGUMENTS.get('target', 'template_debug')
platform = ARGUMENTS.get('platform', 'linux')
arch = ARGUMENTS.get('arch', 'x86_64')

if not os.path.isdir(os.path.join(godot_cpp, 'include')):
    raise RuntimeError('godot_cpp must point to a godot-cpp checkout root')

env = Environment(ENV=os.environ)
cpp_paths = [os.path.join(godot_cpp, 'include'), os.path.join(godot_cpp, 'gen', 'include'), os.path.join(godot_cpp, 'gdextension'), 'native/include', os.path.join(ROOT, 'native', 'third_party')] + RUNTIME_INCLUDES
env.Append(CPPPATH=cpp_paths)
env.Append(CXXFLAGS=['-std=c++17', '-fPIC', '-O2'])
env.Append(LIBPATH=[os.path.join(godot_cpp, 'bin')])

if platform == 'android':
    ndk = os.environ.get('ANDROID_NDK_ROOT')
    if ndk:
        toolchain = os.path.join(ndk, 'toolchains', 'llvm', 'prebuilt', 'linux-x86_64', 'bin')
        env['CC'] = os.path.join(toolchain, 'aarch64-linux-android26-clang') if arch == 'arm64' else os.path.join(toolchain, 'armv7a-linux-androideabi26-clang')
        env['CXX'] = env['CC'] + '++'
        env['LINK'] = env['CXX']
    env.Append(CPPDEFINES=['ANDROID_ENABLED'])
    env.Append(SHLIBSUFFIX='.so')
    android_name = 'armeabi-v7a' if arch in ('arm32', 'armeabi-v7a') else arch
    output = 'addons/uve_animation/bin/libuve_animation.android.%s' % android_name
    # godot-cpp builds a static archive with this naming convention.
    env.Append(LIBS=['godot-cpp.%s.%s.%s' % (platform, target, arch)])
elif platform == 'windows':
    env.Append(SHLIBSUFFIX='.dll')
    output = 'addons/uve_animation/bin/uve_animation.windows.%s' % arch
    env.Append(LIBS=['godot-cpp.%s.%s' % (platform, target)])
else:
    env.Append(SHLIBSUFFIX='.so')
    output = 'addons/uve_animation/bin/libuve_animation.%s.%s' % (platform, arch)
    env.Append(LIBS=['godot-cpp.%s.%s' % (platform, target)])

env.SharedLibrary(output, ['native/src/uve_animation.cpp'] + RUNTIME_SOURCES)
