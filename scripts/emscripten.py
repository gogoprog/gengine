#!/usr/bin/python3

import platform
import os
import sys
import argparse
import multiprocessing
import os.path
import common

def build(targetDir):
    common.log("Running emcc...")
    os.chdir(targetDir)
    os.system("rm -rf index.data index.html index.js index.html.mem")
    os.chdir(os.environ['GENGINE']+"/build")
    os.system("emcc " + ('' if common.debugMode else '-O3') + " --bind gengine" + ('d' if common.debugMode else '') + ".bc -o " + targetDir + "/index.html --preload-file " + common.rootPath + "/res/coreData@coreData " + "--preload-file " + common.rootPath + "/res/data@data " + "--use-preload-plugins -s TOTAL_MEMORY=67108864 -s TOTAL_STACK=1048576 --shell-file " + common.rootPath + "/src/shell.html")

def runServer(targetDir):
    os.chdir(targetDir)
    common.log("Running HTTP server in '" + targetDir + "'...")
    os.system("python3 -m http.server");
