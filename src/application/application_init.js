STRING(

    var gengine;

    function __init()
    {
        gengine = Module.gengine;

        Main.start();
        Main.onGuiLoaded();

        function update()
        {
            gengine.runFrame();

            Main.update(gengine.getTimeStep());

            if(gengine.isRunning())
            {
                setTimeout(update, 1);
            }
        }

        update();
    }

    __init();
);
