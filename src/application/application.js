STRING(

    var gengineApp;

    function __init()
    {
        gengineApp = Module.gengineApp;

        Main.init();

        gengineApp.setup();
        gengineApp.start();

        Main.start();

        while(true)
        {
            gengineApp.runFrame();

            if(!gengineApp.isRunning())
            {
                break;
            }

            Main.update(gengineApp.getTimeStep());
        }
    }

    __init();
);
