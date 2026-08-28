#!/usr/bin/env python3
import os
from SCons.Script import Environment, ARGUMENTS

godot_cpp = ARGUMENTS.get('godot_cpp', os.environ.get('GODOT_CPP', 'godot-cpp'))
target = ARGUMENTS.get('target', 'template_debug')
platform = ARGUMENTS.get('platform', 'linux')
arch = ARGUMENTS.get('arch', 'x86_64')

env = Environment()
env.Append(CPPPATH=[os.path.join(godot_cpp, 'godot-cpp', 'include'), os.path.join(godot_cpp, 'include'), 'native/include'])
env.Append(CPPDEFINES=['TOOLS_ENABLED'] if target == 'editor' else [])
env.Append(CXXFLAGS=['-std=c++17', '-fPIC', '-O2'])
env.Append(LIBS=['godot-cpp'])
env.Append(LIBPATH=[os.path.join(godot_cpp, 'bin')])

if platform == 'android':
    env.Append(CPPDEFINES=['ANDROID_ENABLED'])
    env.Append(SHLIBSUFFIX='.so')
    output = 'addons/uve_animation/bin/libuve_animation.android.%s' % arch
elif platform == 'windows':
    env.Append(SHLIBSUFFIX='.dll')
    output = 'addons/uve_animation/bin/uve_animation.windows.%s' % arch
else:
    env.Append(SHLIBSUFFIX='.so')
    output = 'addons/uve_animation/bin/libuve_animation.%s.%s' % (platform, arch)

env.SharedLibrary(output, ['native/src/uve_animation.cpp'])
