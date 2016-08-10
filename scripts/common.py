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
buildUrho3D = False
targetPlatform = "undefined"
targetMode = "undefined"

def printn(*args):
    sys.stdout.write(*args)

def log(*args):
    sys.stdout.write("[gengine] ")
    print(*args)

def exitWithError(err):
    sys.exit("[gengine] " + '\033[91m' + "Error: " + err + '\033[0m')

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
    global buildUrho3D
    global targetPlatform
    global targetMode

    parser = argparse.ArgumentParser()
    parser.add_argument('-d', help='Debug mode', default=False, action='store_true')
    parser.add_argument('-r', help='Run', default=False, action='store_true')
    parser.add_argument('--html5', help='HTML5 mode (emscripten)', default=False, action='store_true')
    parser.add_argument('--urho3d', help='Build Urho3D lib', default=False, action='store_true')
    parser.add_argument('dir', help='Target directory', default='.', nargs='?')
    args = parser.parse_args()

    debugMode = args.d
    itMustRun = args.r
    html5Mode = args.html5
    buildUrho3D = args.urho3d
    targetDir = os.getcwd() + "/" + args.dir + "/"
    rootPath = os.environ['GENGINE']
    buildPath = rootPath + "/build/"
    binaryPath = rootPath + "/build/gengine" + ('d' if debugMode else '')

    if not os.path.isdir(targetDir):
        exitWithError("Target directroy does not exist.")

    if html5Mode:
        targetPlatform = "emscripten"
    elif isLinux():
        targetPlatform = "linux"
    else:
        targetPlatform = "windows"

    if debugMode:
        targetMode = "debug"
    else:
        targetMode = "release"

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

def build():
    if buildUrho3D:
        log("Building Urho3D lib...")
        os.chdir(os.environ['GENGINE']+"/deps/common/Urho3D")
        buildDir = 'build/' + targetPlatform + '/' + targetMode
        options = ('-DCMAKE_BUILD_TYPE=Debug' if debugMode else '')
        command = ('./cmake_generic.sh' if not html5Mode else './cmake_emscripten.sh')

        os.system(command + ' ' + buildDir + " " + options + " -DURHO3D_LUA=0")

        os.chdir(buildDir)
        os.system("make Urho3D -j" + str(multiprocessing.cpu_count()))

    current_dir = os.getcwd()

    if not html5Mode:
        getDeps()

    log("Building gengine...")
    os.chdir(os.environ['GENGINE']+"/build")

    if isLinux():
        config = ('debug' if debugMode else 'release') + ('emscripten' if html5Mode else '') + ('64' if isPlatform64() else '32')
        os.system("premake4 gmake")
        os.system(('emmake ' if html5Mode else '') + "make config=" + config + " -j" + str(multiprocessing.cpu_count()))
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

    os.system("rm -rf " + targetDir + "generated/main.js")

    if not os.path.exists(targetDir + "/build.hxml"):
        log("Running haxe default command line...")
        os.system("haxe -cp $GENGINE/deps/common/Ash-Haxe/src/ -cp $GENGINE/src/haxe/ -cp " + targetDir +  " -cp " + targetDir + "/src -main gengine.Main -js " + targetDir + "generated/main.js")
    else:
        log("Running haxe with build.hxml...")
        os.system("cd " + targetDir + "; haxe build.hxml")

    if not os.path.exists(targetDir + "generated/main.js"):
        exitWithError("Haxe compilation failed.")

    os.chdir(current_dir)
