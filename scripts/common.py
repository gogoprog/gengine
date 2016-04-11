#!/usr/bin/python3

import platform
import os
import sys
import argparse
import multiprocessing
import os.path

debugMode = False
targetDir = None
rootPath = None
buildPath = None
binaryPath = None
itMustRun = False
html5Mode = False

def printn(*args):
    sys.stdout.write(*args)

def log(*args):
    sys.stdout.write("[gengine] ")
    print(*args)

def isPlatform64():
    if getPlatformName() == "Windows":
        return False
    return "_64" in platform.machine()

def isLinux():
    return platform.system() == "Linux"

def getPlatformName():
    system = platform.system()
    if "CYGWIN" in system:
        return "Windows"
    return system

def sanityCheck():
    printn("Sanity check... ")
    if not "GENGINE" in os.environ:
        print("GENGINE environment variable is not set.")
        exit(1)
    print("Ok!")

def init():
    log("Init script...")

    global binaryPath
    global debugMode
    global targetDir
    global rootPath
    global buildPath
    global itMustRun
    global html5Mode

    parser = argparse.ArgumentParser()
    parser.add_argument('-d', help='Debug mode', default=False, action='store_true')
    parser.add_argument('-r', help='It must run', default=False, action='store_true')
    parser.add_argument('--html5', help='HTML5 mode', default=False, action='store_true')
    parser.add_argument('dir', help='Target directory', default='.', nargs='?')
    args = parser.parse_args()

    debugMode = args.d
    itMustRun = args.r
    html5Mode = args.html5
    targetDir = os.getcwd() + "/" + args.dir + "/"
    rootPath = os.environ['GENGINE']
    buildPath = rootPath + "/build/"
    binaryPath = rootPath + "/build/gengine" + ('d' if debugMode else '')

def getDeps():
    log("Downloading dependencies...")
    directory = rootPath+"/deps/"+getPlatformName().lower()+"/lib"+('64' if isPlatform64() else ('32' if isLinux() else ''))
    os.chdir(directory)
    if getPlatformName() == "Linux":
        if not os.path.isfile(directory+"/libcef.so"):
            os.system("./get-libs")
    if getPlatformName() == "Windows":
        if not os.path.isfile(directory+"/windows-32.tar.gz"):
            os.system("./get-libs")
            os.system("cp *.dll " + rootPath + "/build/")

def build(emscripten=False):
    current_dir = os.getcwd()
    if not emscripten:
        getDeps()

    log("Building gengine...")
    os.chdir(os.environ['GENGINE']+"/build")

    if isLinux():
        config = ('debug' if debugMode else 'release') + ('emscripten' if emscripten else '') + ('64' if isPlatform64() else '32')
        os.system("premake4 gmake")
        os.system(('emmake ' if emscripten else '') + "make config=" + config + " -j" + str(multiprocessing.cpu_count()))
    else:
        msbuild = "/cygdrive/c/Program Files (x86)/MSBuild/12.0/Bin/MSBuild.exe"

        if not os.path.exists(msbuild):
            msbuild = "/cygdrive/c/Program Files/MSBuild/12.0/Bin/MSBuild.exe"

        msbuild = msbuild.replace(" ", "\\ ")
        msbuild = msbuild.replace("(", "\\(")
        msbuild = msbuild.replace(")", "\\)")

        os.system("./premake4.exe vs2012")
        os.system("sed -i 's/v110/v120/g' *.vcxproj")
        os.system(msbuild + " /p:Configuration=Release")

    os.chdir(current_dir)
