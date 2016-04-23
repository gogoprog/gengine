STRING(

    var gengineApp;

    function __init()
    {
        gengineApp = Module.gengineApp;

        Main.start();

        function update()
        {
            gengineApp.runFrame();

            Main.update(gengineApp.getTimeStep());

            if(gengineApp.isRunning())
            {
                setTimeout(update, 1);
            }
        }

        update();
    }

    __init();
);
