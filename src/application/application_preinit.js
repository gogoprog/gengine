STRING(
    var gengine;

    function __preinit()
    {
        gengine = Module.gengine;

        Main.init();

        gengine.setup();
        gengine.start();
    }

    __preinit();
);
