#!/usr/bin/python3

import platform
import os
import sys
import argparse
import multiprocessing
import os.path
import common

def emcc(appDir, outputDir, includeEmptyData):
    previous_dir = os.getcwd()
    os.chdir(os.environ['GENGINE']+"/build")
    cmd = "emcc "
    cmd += "" if common.debugMode else "-O3"
    cmd += " --bind gengine" + ('d' if common.debugMode else '') + ".bc"
    cmd += " -o " + outputDir + "/index.html"
    cmd += " --preload-file " + common.rootPath + "/res/coreData@coreData"
    if includeEmptyData:
        cmd += " --preload-file " + common.rootPath + "/res/data@data "
    else:
        cmd += " --preload-file " + appDir + "/data@data "
    cmd += " --use-preload-plugins -s TOTAL_MEMORY=134217728 -s TOTAL_STACK=1048576"
    cmd += " --shell-file " + common.rootPath + "/src/shell.html"
    os.system(cmd)
    os.chdir(previous_dir)

def build(appDir, outputDir):
    common.log("Running emcc...")
    current_dir = os.getcwd()
    os.chdir(appDir)
    os.system("rm -rf index.data index.html index.js index.html.mem")
    emcc(current_dir, outputDir, True)
    os.chdir(current_dir)

def runServer(targetDir):
    os.chdir(targetDir)
    common.log("Running HTTP server in '" + targetDir + "'...")
    os.system("python -m http.server");
