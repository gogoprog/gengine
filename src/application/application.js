STRING(

    var gengine = new Module.App();

    Main.init();

    gengine.setup();
    gengine.start();

    Main.start();

    while(1)
    {
        gengine.runFrame();
        Main.update(gengine.getTimeStep());
    }

);
