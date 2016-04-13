STRING(

    var gengineApp = new Module.App();

    Main.init();

    gengineApp.setup();
    gengineApp.start();

    Main.start();

    while(1)
    {
        gengineApp.runFrame();
        Main.update(gengineApp.getTimeStep());
    }
);
