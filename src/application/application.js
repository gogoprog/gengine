STRING(

    var gengineApp;

    function __init()
    {
        gengineApp = Module.gengineApp;

        Main.init();

        gengineApp.setup();
        gengineApp.start();

        Main.start();

        while(1)
        {
            gengineApp.runFrame();
            Main.update(gengineApp.getTimeStep());
        }
    }

    __init();
);
